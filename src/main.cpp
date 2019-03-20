#include "fxx/directors/game.h"
#include <memory> // For std::make_unique
#include <stdexcept>

int main() {
	try {
		auto game = std::make_unique<fxx::directors::game>();
	} catch (const std::runtime_error& error) {
		std::cerr << error.what() << std::endl;
	}
	return 0;
}