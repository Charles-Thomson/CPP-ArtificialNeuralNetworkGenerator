#include "../Environment/EnvironmentObservtions/StateBased2DEnvironmentObservation.h"
#include "../Environment/EnvironmentNodes/StateBased/StateBasedNode.h"

#include <string>
#include <fmt/format.h>
#include <stdexcept>
#include <tuple>;
#include <utility>
#include <functional>

using std::string;
using std::cout;
using std::endl;
using fmt::format;
using std::tuple;
using std::unordered_map;
using std::pair;
using std::find;


class EnvironmentTestFixtures : public ::testing::Test {
protected:

	//*
	// @ Brief Helper function to generate blank(all open state) 2d State based Envionments
	// 
	// @param dimensions Dimensions of the environment to be generated
	// */
	vector<vector<StateBasedNode>> GenerateBlankTest2DEnvironment(int dimensions) {
		vector<vector<StateBasedNode>> testEnvironment(dimensions, vector<StateBasedNode>(dimensions, StateBasedNode::State::OPEN));

		return testEnvironment;
	}

	//*
	// @ Brief Helper function for environment visualization
	// 
	// @param env Environment to be printed / visualized 
	// */
	void EnvironmentPrintHelper(vector<vector<StateBasedNode>> env) {
		for (vector<StateBasedNode> layer : env) {
			for (StateBasedNode node : layer) {
				int nodeValue = StateBasedNode::state_to_int(node.state);
				cout << nodeValue << " , ";
			};
			cout << endl;
		}
		cout << endl;
	}

	//*
	// @brief Populate a blank environment dimension = 5 
	// Populate a blank environment with dimensions of 5 x5 with content 
	// 
	// @param blankEnv Given blank Enviornment
	// @return Populated environment
	// */
	vector<vector<StateBasedNode>> Populate2DTestEnvironment_Dimesnions5(vector<vector<StateBasedNode>> blankEnv) {

		tuple<int, int> startLocation = { 1, 1 };

		vector<tuple<int, int>> obsticalLocations = { {0,1},{2,1},{3,3} };
		vector<tuple<int, int>> goalLocations = { {4,0},{4,4},{0,4} };

		// Set the start node

		blankEnv[get<0>(startLocation)][get<1>(startLocation)] = StateBasedNode::State::START;


		// Refactor to single loop

		// Set obstical Nodes
		for (tuple<int, int> coords : obsticalLocations) {
			blankEnv[get<0>(coords)][get<1>(coords)] = StateBasedNode::State::OBSTICAL;
		};

		//Set Goal Nodes
		for (tuple<int, int> coords : goalLocations) {
			blankEnv[get<0>(coords)][get<1>(coords)] = StateBasedNode::State::GOAL;
		};

		return blankEnv;
	}

	//*
	// @ Brife Generate a dummy set of sight line data of StateBasedNodes
	// 
	// @return vector<StateBasedNode - Dummy sight line data
	// */
	vector<StateBasedNode> GenerateDummySightLineData() {
	

		vector<StateBasedNode> returnVector = {
			StateBasedNode::State::OPEN,
			StateBasedNode::State::OPEN,
			StateBasedNode::State::GOAL,
			StateBasedNode::State::OPEN,
			StateBasedNode::State::OBSTICAL
		};

		return returnVector;
	}
	
};




