#include "../Environment/EnvironmentObservtions/StateBased2DEnvironmentObservation.h"
#include "../Environment/EnvironmentNodes/StateBased/StateBasedNode.h"
#include "../Environment/ANNEnvironment.h"

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

	Environment testEnv;
	vector<vector<StateBasedNode>> blankEnvironment;
	vector<vector<StateBasedNode>> populatedEnvironment;
	vector<StateBasedNode> dummySightLine;

	void SetUp() override {
		try {
			cout << "SetUp called" << endl;

			//Generate and store a dummy environment and related data
			blankEnvironment = GenerateBlankTest2DEnvironmentMap(5);
			populatedEnvironment = Populate2DTestEnvironment_Dimesnions5(blankEnvironment);
			testEnv.setEnvironmentMap(populatedEnvironment);

			pair<int, int> envDimensions = { blankEnvironment.size(),blankEnvironment[0].size() };
			testEnv.setEnviromentMapDimensions(envDimensions);


			// Set current node to START
			testEnv.setCurrentNode(StateBasedNode(StateBasedNode::State::START, 1, 1, 5));

			// Generate dummy sight line data
			dummySightLine = GenerateDummySightLineData();
			
		}
		catch (const std::exception& e) {
			std::cerr << "Exception in SetUp: " << e.what() << std::endl;
			throw;  // Rethrow so test still fails
		}

	
	}

	void TearDown() override {
		if (HasFailure()) {
			std::cerr << "Test failed, printing debug info..." << endl;
		}
	}

	//*
	// @ Brief Helper function to generate blank(all open state) 2d State based Envionments
	// 
	// @param dimensions Dimensions of the environment to be generated
	// */
	vector<vector<StateBasedNode>> GenerateBlankTest2DEnvironmentMap(int dimensions) {
		/*vector<vector<StateBasedNode>> testEnvironment(dimensions, vector<StateBasedNode>(dimensions, StateBasedNode::State::OPEN));*/

		vector<vector<StateBasedNode>> testEnvironment;

		for (size_t row = 0; row < dimensions; ++row) {

			vector<StateBasedNode> rowVec; // temp vector
			for (size_t col = 0; col < dimensions; ++col) {
				rowVec.emplace_back(StateBasedNode::State::OPEN, row, col, dimensions);
			}
			testEnvironment.emplace_back(move(rowVec));
		}
		return testEnvironment;
	}

	//*
	// @ Brief Helper function for environment visualization
	// 
	// @param env Environment to be printed / visualized 
	// */
	void EnvironmentPrintHelper_old() {

		vector<vector<StateBasedNode>> envMap = testEnv.getEnvironmentMap();
		for (vector<StateBasedNode> layer : envMap) {
			for (StateBasedNode node : layer) {
				int nodeValue = StateBasedNode::state_to_int(node.state);
				cout << nodeValue << " , ";
			};
			cout << endl;
		}
		cout << endl;
	}

	//*
// @ Brief Helper function for environment visualization
// 
// @param env Environment to be printed / visualized 
// */
	void EnvironmentPrintHelper() {

		vector<vector<StateBasedNode>> envMap = testEnv.getEnvironmentMap();

		while (envMap.size() > 0) {
			vector<StateBasedNode> layer = envMap.back();
			for (StateBasedNode node : layer) {

				int nodeValue = StateBasedNode::state_to_int(node.state);
				cout << nodeValue << " , ";
			
			}
			cout << endl;
			envMap.pop_back();
		}
		cout << endl;
		

		/*for (int y = yLayerSize; y > 0; --y) {
			for (int x = xLayerSize; x > 0; --x) {
				StateBasedNode node = envMap[x][y];
				int nodeValue = StateBasedNode::state_to_int(node.state);
				cout << nodeValue << " , ";
			};
			cout << endl;
		
		}
		cout << endl;*/

		/*for (vector<StateBasedNode> layer : envMap) {
			for (StateBasedNode node : layer) {
				int nodeValue = StateBasedNode::state_to_int(node.state);
				cout << nodeValue << " , ";
			};
			cout << endl;
		}
		cout << endl;*/
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
		blankEnv[get<0>(startLocation)][get<1>(startLocation)].state = StateBasedNode::State::START;
		
		// Refactor to single loop

		// Set obstical Nodes
		for (tuple<int, int> coords : obsticalLocations) {
			blankEnv[get<0>(coords)][get<1>(coords)].state = StateBasedNode::State::OBSTICAL;
		};
		

		//Set Goal Nodes
		for (tuple<int, int> coords : goalLocations) {
			blankEnv[get<0>(coords)][get<1>(coords)].state = StateBasedNode::State::GOAL;
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
			StateBasedNode(StateBasedNode::State::OPEN, 0, 0, 5),
			StateBasedNode(StateBasedNode::State::OPEN, 0, 1, 5),
			StateBasedNode(StateBasedNode::State::GOAL, 0, 2, 5),
			StateBasedNode(StateBasedNode::State::OPEN, 0, 3, 5),
			StateBasedNode(StateBasedNode::State::OBSTICAL, 0, 4, 5)
		
		};

		return returnVector;
	}

	
	//*
	// @brife Test reward generation for given node
	// 
	// Test the reward given for a given node type in the environment
	// @param coordX - x coord of test node
	// @param coordY - y coord of test node
	// @param expectedReward - the expected reward generated
	// */
	void expectedRewardAt(int coordX, int coordY, double expectedReward) {
		testEnv.setActionCount(1);
		StateBasedNode testNode = testEnv.getNodeAtEnvironmentLocation(coordX, coordY);
		double reward = testEnv.calculateReward(testNode);
		SCOPED_TRACE(format("Reward amount incorrect {}", reward));
		EXPECT_EQ(reward, expectedReward);
	}
	
};




