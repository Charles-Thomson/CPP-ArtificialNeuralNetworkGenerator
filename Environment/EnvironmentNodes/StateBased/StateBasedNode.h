#ifndef STATE_BASED_NODE_H
#define STATE_BASED_NODE_H

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::invalid_argument;

struct StateBasedNode {

	enum class State {
		START = 1,
		OPEN = 0,
		OBSTICAL = 2,
		GOAL = 3
	};


	// Stored state of the node
	State state;

	StateBasedNode(State s) : state(s) {}

	static State from_int(int value) {
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

};





#endif // !STATE_BASED_NODE_H
