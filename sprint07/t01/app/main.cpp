#include <iostream>
#include <string>
#include <cassert>

#include "algorithmUtils.h"
#include "mylib.h"

#include "CBLBasicString.h"

// #include "CBLString.h"
// #include "CBLWString.h"

using namespace CBL;

static bool checkSimple() {

    {
        CBL::BasicString<char> str;
        std::basic_string<char> stdstr;
        assert(str.length() == stdstr.length());
        assert(strcmp(str.c_str(), stdstr.c_str()) == 0);
    }
    {
        BasicString<char> s;
        BasicString s1("stroka");
        std::basic_string<char> ss1("stroka");

        std::basic_string<char> stdstr;
        BasicString s2(s1);
        BasicString s3(s1, 2);
        BasicString s4(s1, 2, 3);
        BasicString s5(4, 'c');
        BasicString s6(s1.begin() + 2, s1.end());

        assert(strcmp(s1.c_str(), "stroka") == 0 && s1.length() == 6);
        assert(strcmp(s2.c_str(), "stroka") == 0 && s2.length() == 6);
        assert(strcmp(s3.c_str(), "roka") == 0 && s3.length() == 4);
        assert(strcmp(s4.c_str(), "rok") == 0 && s4.length() == 3);
        assert(strcmp(s5.c_str(), "cccc") == 0 && s5.length() == 4);
        assert(strcmp(s6.c_str(), "roka") == 0 && s6.length() == 4);

        BasicString s7(s1, 2, 20);
        // std::basic_string<char> ss7(ss1, 2, 20);
        // std::cout << "s7: " << s7.c_str() << " length: " << s7.length() << std::endl;
        // std::cout << "ss7: " << ss7.c_str() << " length: " << ss7.length() << std::endl;
        assert(strcmp(s7.c_str(), "roka") == 0 && s7.length() == 4);

        // ------ exeption - out of range
        // BasicString s8(s1, 20, 2);
        // std::basic_string<char> ss8(ss1, 20, 2);
        // std::cout << "s8: " << s8.c_str() << " length: " << s8.length() << std::endl;
        // std::cout << "ss8: " << ss8.c_str() << " length: " << ss8.length() << std::endl;
    }
    std::cout << "Simple string OK" << std::endl;
    return true;
}

static bool AccsessCheck() {
    {
        BasicString v("stroka");
        assert(v[0] == 's' && v.at(1) == 't');
        v[0] = 'v'; v.at(1) = 's';
        assert(v[0] == 'v' && v.at(1) == 's');
    }
    {
        try {
            BasicString v("stroka");
            v.at(12);
        }
        catch (std::exception& e) {
            // std::cout << e.what() << std::endl;
            std::string s = "BasicString: out of range";
            assert(e.what() == s);
        }
    }
    {
        BasicString v("sta");
        std::basic_string<char> v1("stroka");
        assert(v.back() == v1.back());
        assert(v.front() == v1.front());
        // std::cout << v.back() << ' ' << v1.back() << '\n';
    }
    std::cout << "Accsess OK" << std::endl;
    return true;
}

static bool CheckC_strCompare() {
    {
        BasicString s1("stroka");
        BasicString s2("stroka");
        assert(s1.compare("stroka") == 0);
        assert(s1.compare(s2) == 0);
        assert(s1.compare(s2.c_str()) == 0);
    }
    std::cout << "c_str OK\nCompare OK" << std::endl;
    return true;
}

static bool CheckOperators() {
    {
        BasicString s1("aaaa");
        BasicString s3("aaa");

        s1 = s3;
        // outputAny(s1);
        // outputAny(s3);
        assert(s3.compare(s1) == 0);
        assert(s3.compare("aaa") == 0);
        s1 = 'c';
        assert(s1.compare("c") == 0);
    }
    {
        BasicString s1("aaaa");
        BasicString s2("bbb");
        BasicString s3("aaa");

        s3 += s2;
        assert(s3.compare("aaabbb") == 0);
        s3 += s1;
        assert(s3.compare("aaabbbaaaa") == 0 && s3.length() == 10);
        // outputAny(s3);
        // std::cout << '\n' << s3.length() << '\n';
        s1 += '5';
        assert(s1.compare("aaaa5") == 0);
    }
    std::cout << "Operators OK" << std::endl;
    return true;
}

static bool CheckAppend() {
    {
        BasicString s1("aaaa");
        BasicString s2("bbb");
        BasicString s3("aaa");

        s3.append(s2);
        assert(s3.compare("aaabbb") == 0);
        s3.append("c");
        assert(s3.compare("aaabbbc") == 0 && s3.length() == 7);
        s2.append(3, 'c');
        assert(s2.compare("bbbccc") == 0);
        s1.append("zzzzz", 2);
        // outputAny(s1);
        assert(s1.compare("aaaazz") == 0 && s1.length() == 6);
        s1.append(s3.begin() + 6, 1);
        assert(s1.compare("aaaazzc") == 0 && s1.length() == 7);

        s1.append(s3.begin() + 6, 2);
        assert(s1.compare("aaaazzcc") == 0 && s1.length() == 8);
        // outputAny(s1);
        // std::cout << s1.length() << '\n';
        // std::basic_string<char> v1("stroka");
        // v1.append(s3.begin() + 6, 2);
        // std::cout << s1.length() << '\n';
    }
    std::cout << "Append OK" << std::endl;
    return true;
}

static bool CheckSwap() {
    {
        BasicString s1("aa");
        BasicString s2("bb");
        s1.swap(s2);
        assert(s1.compare("bb") == 0);
        assert(s2.compare("aa") == 0);
        // std::cout << s1.c_str() << " " << s2.c_str() << std::endl;
    }
    std::cout << "Swap OK" << std::endl;
    return true;
}

static bool CheckOperatorsPlus() {
    {
        BasicString s1("aa");
        BasicString s3("bb");

        BasicString s2 = s1 + s3;
        // outputAny(s1);
        // outputAny(s3);
        assert(s2.compare("aabb") == 0);

    }
    std::cout << "Operators Plus OK" << std::endl;
    return true;
}

// void StringFind() {
//     String s("This is a string");

//     std::cout << "find T in: " << s.c_str() << " == " << s.find('T') << std::endl;
//     std::cout << "find i in: " << s.c_str() << " from 4 == " << s.find('i', 4) << std::endl;
//     std::cout << "find t in: " << s.c_str() << " == " << s.find('t') << std::endl;
//     std::cout << "R FIND" << std::endl;
//     std::cout << "find T in: " << s.c_str() << " == " << s.rfind('T', 5) << std::endl;
//     std::cout << "find i in: " << s.c_str() << " from 4 == " << s.rfind('i', 4) << std::endl;
//     std::cout << "find t in: " << s.c_str() << " == " << s.rfind('t', 12) << std::endl;
// }

int main() {
    checkSimple();
    AccsessCheck();
    CheckC_strCompare();
    CheckOperators();
    CheckAppend();
    CheckSwap();
    CheckOperatorsPlus();

    std::cout << "\nAssessment complete!\n\n";
    system("leaks -q basicString");
    return 0;
}
