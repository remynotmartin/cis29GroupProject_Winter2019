#include "fxx/directors/Game.h"
#include <cstring>
#include <memory> // For std::make_unique
#include <stdexcept>

int main(int argc, char * argv[]) {
	bool randomize = true;

	if (argc == 2 && argv[1][0] == '0') {
		randomize = false;
	}

	try {
		auto game = std::make_unique<fxx::directors::Game>(randomize);
	} catch (const std::runtime_error& error) {
		std::cerr << error.what() << std::endl;
	}
	return 0;
}
