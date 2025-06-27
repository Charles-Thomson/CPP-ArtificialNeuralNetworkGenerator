#ifndef DIRECTIONAL_ENUMERATION_H
#define DIRECTIONAL_ENUMERATION_H

#include <iostream>
using std::invalid_argument;
using std::pair;


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

	//*
	// @brife Convert Direction to offset 
	// Provides "direction" of movement in a 2D vector/data structure
	// 
	// @param dir enum direction
	// @return pair<int, int> Offset to be applied
	// */
	static pair<int, int> getDirectionOffsef(Direction dir) {
		switch (dir) {
			case Direction::UP_LEFT:    return { -1,-1};
			case Direction::UP:		    return {  0,-1};
			case Direction::UP_RIGHT:   return {  1,-1};
			case Direction::LEFT:       return { -1, 0};
			case Direction::RIGHT:      return {  1, 0};
			case Direction::DOWN_LEFT:  return { -1, 1};
			case Direction::DOWN:       return {  0, 1};
			case Direction::DOWN_RIGHT: return {  1, 1};
			default: return {0,0};
		}
	
	}

	
	static int direction_to_int(Direction d) {
		return static_cast<int>(d);
	}
};





#endif // !DIRECTIONAL_ENUMERATION_H