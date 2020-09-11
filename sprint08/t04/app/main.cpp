#include "Serializer.h"
#include "SomeClass.h"

static void deserializer(std::string& input, Serializer& s) {
    if (input == "int") {
        int value = s.deserialize<int>(input);
        std::cout << "Deserialized int: " << value << std::endl;
    } else if (input == "float") {
        float value = s.deserialize<float>(input);
        std::cout << "Deserialized float: " << value << std::endl;
    } else {
        SomeClass value = s.deserialize<SomeClass>(input);
        std::cout << "Deserialized SomeClass: ";
        value.output();
        std::cout << std::endl;
    }
}

static void serializer_int(char *argv[], int& intArg, Serializer& s) {
    std::regex r_int("([0-9]+)");

    if (!std::regex_match(argv[2], r_int))
        throw std::runtime_error("error");

    intArg = std::stoi(argv[2]);
    int value = intArg;
    s.serialize(&value, argv[1]);
    std::cout << "int: " << value << " serialized" << std::endl;
}

static void serializer_float(char *argv[], float& floatArg, Serializer& s) {
    std::regex r_int("([0-9]+)");
    std::regex r_float("(\\d+\\.\\d+)");

    if (!std::regex_match(argv[2], r_float) && !std::regex_match(argv[2], r_int))
        throw std::runtime_error("error");

    floatArg = std::stof(argv[2]);
    float value = floatArg;
    s.serialize(&value, argv[1]);
    std::cout << "float: " << value << " serialized" << std::endl;
}

static void serializer_any(char *argv[], int& intArg, char& charArg,
                            float& floatArg, Serializer& s) {
    std::regex r_int("([0-9]+)");
    std::regex r_float("(\\d+\\.\\d+)");
    std::regex r_char("(\\S)");

    if (!std::regex_match(argv[2], r_int)
        || !std::regex_match(argv[3], r_char)
        || !std::regex_match(argv[4], r_float))
        throw std::runtime_error("error");

    intArg = std::stoi(argv[2]);
    charArg = argv[3][0];
    floatArg = std::stof(argv[4]);

    SomeClass value(intArg, charArg, floatArg);
    s.serialize(&value, argv[1]);
    std::cout << "SomeClass: ";
    value.output();
    std::cout << " serialized" << std::endl;
}

int main(int argc, char *argv[]) {

    if (argc != 2 && argc != 3 && argc != 5) {
        std::cout << "usage: ./serializer [arg1] [arg2] [arg3] [arg4]" << std::endl;
        exit(EXIT_FAILURE);
    }

    int intArg = 0;
    char charArg = 0;
    float floatArg = 0;
    std::string str = std::string(argv[1]);
    Serializer srlz;

    try {
        if (argc == 2) {
            deserializer(str, srlz);
        } else if (argc == 3) {
            if (str == "int")
                serializer_int(argv, intArg, srlz);
            else if (str == "float")
                serializer_float(argv, floatArg, srlz);
            else
                throw std::runtime_error("error");
        } else
            serializer_any(argv, intArg, charArg, floatArg, srlz);

    } catch (std::runtime_error& re) {
        std::cerr << re.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    // system("leaks -q serializer");
    return 0;
}
