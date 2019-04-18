#ifndef FXX_HANDS_RANDOMIZER_H
#define FXX_HANDS_RANDOMIZER_H

#include <iostream>
#include <vector>


namespace fxx {
	namespace hands {
		class Randomizer;
	}
}


std::ostream & operator<<(std::ostream & level_file, fxx::hands::Randomizer & randomizer);


class fxx::hands::Randomizer {
public:
	Randomizer(unsigned char level_width, unsigned char level_height);
	friend std::ostream & ::operator<<(std::ostream & level_file, ::fxx::hands::Randomizer & randomizer);

private:
	std::vector<std::vector<unsigned char>> level;
	unsigned char width;
	unsigned char height;
};

#endif
