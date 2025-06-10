#ifndef STATE_BASED_NODE_H
#define STATE_BASED_NODE_H

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::invalid_argument;



//*
// @Brife Provides a enumearation of possible node states
// 
// Provides anumeration of possible nodes in an state baseed environment
// 
// */
struct StateBasedNode {

	enum class State {
		START = 1,
		OPEN = 0,
		OBSTICAL = 2,
		GOAL = 3
	};

	// Stored state of the node
	State state;

	int nodeCoordX;
	int nodeCoordY;

	int environmentDimension;
	// Default constructor
	StateBasedNode() : state(State::OPEN), nodeCoordX(0), nodeCoordY(0), environmentDimension(0) {}

	StateBasedNode(State s, size_t nodeCoordX, size_t nodeCoordY, size_t environmentDimension) : state(s), nodeCoordX(nodeCoordX), nodeCoordY(nodeCoordY) ,environmentDimension (environmentDimension){}

	static State state_from_int(int value) {
		switch (value) {
		case 0: return State::OPEN;
		case 1: return State::START;
		case 2: return State::OBSTICAL;
		case 3: return State::GOAL;
		default: throw invalid_argument("Invalid Node State value");
		};
	};

	static int state_to_int(State state) {
		return static_cast<int>(state);
	};

	static string state_to_string(State state) {
		switch (state) {
		case State::OPEN: return "open";
		case State::START: return "start";
		case State::OBSTICAL: return "obstical";
		case State::GOAL: return "goal";
		default: return "unknown";

		};
	};


	//*
	// @brife Update the current node state
	// 
	// @param newState - New node state
	// */
	void updateNodeState(StateBasedNode::State newState) {
		state = newState;


	};

	// Outside the struct (recommended)
	bool operator==(const StateBasedNode& other) const {
		return state == other.state &&
			nodeCoordX == other.nodeCoordX &&
			nodeCoordY == other.nodeCoordY &&
			environmentDimension == other.environmentDimension;
	};

};





#endif // !STATE_BASED_NODE_H
