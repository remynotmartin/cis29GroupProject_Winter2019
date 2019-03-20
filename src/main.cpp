#include "fxx/directors/game.h"
#include <memory> // For std::make_unique

int main() {
	auto game = std::make_unique<fxx::directors::game>();
}