#ifndef DIRECTIONAL_ENUMERATION_H
#define DIRECTIONAL_ENUMERATION_H

#include <iostream>
using std::invalid_argument;


//*
// @brife Provides enumeration of sighlines/direction in  state based environment
// */
struct DirectionalEnum {

	enum class Direction {
		UP_LEFT = 0,
		UP = 1,
		UP_RIGHT = 2,
		LEFT = 3,
		RIGHT = 4,
		DOWN_LEFT = 5,
		DOWN = 6,
		DOWN_RIGHT = 7
	};
	Direction direcrtion;

	DirectionalEnum(Direction d) : direcrtion(d) {}

	static Direction from_int(int value) {
		switch (value) {
			case 0: return Direction::UP_LEFT;
			case 1: return Direction::UP;
			case 2: return Direction::UP_RIGHT;
			case 3: return Direction::LEFT;
			case 4: return Direction::RIGHT;
			case 5: return Direction::DOWN_LEFT;
			case 6: return Direction::DOWN;
			case 7: return Direction::DOWN_RIGHT;
			default: throw  "Value Does not corispond to a direction";
		}
	}

	static int direction_to_int(Direction d) {
		return static_cast<int>(d);
	}
};





#endif // !DIRECTIONAL_ENUMERATION_H