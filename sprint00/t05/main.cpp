#include <iostream>

int main(int argc, char *argv[]) {

	if (argc < 5) 
		std::cerr << "usage:./automaton [name] [level] [health] [stamina]";
	auto name = argv[1];
	auto level = argv[2];
	auto health = argv[3];
	auto stamina = argv[4];

	if (typeid(level) != typeid(int)) {
		std::cerr << "Invalid argument: " << level;
		return 1;
	}
	if (typeid(health) != typeid(float)) {
		std::cerr << "Invalid argument: " << health;
		return 1;
	}
	if (typeid(stamina) != typeid(float)) {
		std::cerr << "Invalid argument: " << stamina;
		return 1;
	}

	std::cout << "Name = " << name << std::endl
			  << "Level = " << level << std::endl
  			  << "Health = " << health << std::endl
  			  << "Stamina = " << stamina << std::endl;
  	return 0;
}

// std::string arg = argv[1];
// try {
//   std::size_t pos;
//   int x = std::stoi(arg, &pos);
//   if (pos < arg.size()) {
//     std::cerr << "Trailing characters after number: " << arg << '\n';
//   }
// } catch (std::invalid_argument const &ex) {
//   std::cerr << "Invalid argument: " << arg << '\n';
// } catch (std::out_of_range const &ex) {
//   std::cerr << "Number out of range: " << arg << '\n';
// }