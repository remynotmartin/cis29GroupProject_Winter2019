#include "fxx/hands/Randomizer.h"
#include <cstdlib>
#include <ctime>

fxx::hands::Randomizer::Randomizer(unsigned char level_width, unsigned char level_height)
		: level(level_height, std::vector<unsigned char>(level_width)), width(level_width), height(level_height) {

}

std::ostream & operator<<(std::ostream & level_file, fxx::hands::Randomizer & randomizer) {
	std::srand(std::time(0));

	unsigned char y = randomizer.height - 1;
	unsigned char next = std::rand() % 15;
	int sign = 1;

	for (int i = 0; i < randomizer.height; i++) {
		randomizer.level[i][0] = 15;
	}

	for (int j = 1; j < randomizer.width; j++) {
		if (j % next == 0) {
			y += sign * std::rand() % 5;

			if (y > randomizer.height - 1 || y < 5) {
				y = randomizer.height - 1;
			}

			sign *= -1;
			next = std::rand() % 15 + 5;
		}

		for (int i = 0; i < randomizer.height; i++) {
			if (i < y) {
				randomizer.level[i][j] = 5;
			} else {
				randomizer.level[i][j] = 9;
			}
		}
	}

	unsigned char i = 0;
	unsigned char j = 0;
	unsigned char k = 0;
	unsigned char previous;
	unsigned char cell;
	unsigned char level_index = 0;


	level_file.write(reinterpret_cast<char *>(&level_index), 1);
	level_file.write(reinterpret_cast<char *>(&randomizer.width), 1);
	level_file.write(reinterpret_cast<char *>(&randomizer.height), 1);


	while (i < randomizer.height) {
		cell = randomizer.level[i][j];
		k++;

		if (i == 0 && j == 0) {
			previous = cell;
		}

		if (cell != previous || ((i == randomizer.height - 1) && (j == randomizer.width - 1))) {
			if (!((i == randomizer.height - 1) && (j == randomizer.width - 1))) {
				k--;
			}

			level_file.write(reinterpret_cast<char *>(&k), 1);
			level_file.write(reinterpret_cast<char *>(&previous), 1);
			previous = cell;
			k = 0;

			if (!((i == randomizer.height - 1) && (j == randomizer.width - 1))) {
				continue;
			}
		}

		j++;

		if (j >= randomizer.width) {
			i++;
			j = 0;
		}
	}

	return level_file;
}
