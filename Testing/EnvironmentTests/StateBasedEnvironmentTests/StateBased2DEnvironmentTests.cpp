#include <gtest/gtest.h>
#include <iostream>
#include <fmt/format.h>
#include "../TestEnvironmentGeneration/StateBase2DTestEnvironmentGeneration.cpp"
#include "../../../Environment/EnvironmentNodes/StateBased/StateBasedNode.h"
#include "../../../Environment/ANNEnvironment.h"

// C++20 - compatibility issue potential
using enum DirectionalEnum::Direction;

using Direction = DirectionalEnum::Direction;

using std::cout;
using std::endl;
using std::make_pair;
using fmt::format;

template<typename T1,typename T2>
void traceAssertEQ(const T1& actual, const T2& expected, const string& scopeTraceMessage) {
	SCOPED_TRACE(scopeTraceMessage);
	ASSERT_EQ(expected, actual);
}


//*
// @brife Test generated environment variables
// */
TEST_F(EnvironmentTestFixtures, EnvironmentSetUpTest) {
	cout << "Test Start " << endl;

	
	vector<vector<StateBasedNode>> envMap = testEnv.getEnvironmentMap();

	{
		SCOPED_TRACE("Environment Map incorrectly set");
		ASSERT_GT(envMap.size(), 0);
	}
	StateBasedNode testNode = testEnv.getCurrentNode();

	traceAssertEQ(testNode.state, StateBasedNode::State::START, "Environment Attribute set incorrectly -> StartNode");
	traceAssertEQ(testEnv.path.size(), 0, "Environment Attribute set incorrectly -> path");
	traceAssertEQ(testEnv.getActionCount(), 0, "Environment Attribute set incorrectly -> ActionCount");

	
}

//*
// @Brife Test the Environment reward generation on a OPEN state node
// Calls expectedRewardAt() from test Fixture 
// */
TEST_F(EnvironmentTestFixtures, RewardGenerationOpenNode) {
	
	EnvironmentPrintHelper();
	expectedRewardAt(1,2,0.1);
}

//*
// @Brife Test the Environment reward generation on a GOAL state node
//  Calls expectedRewardAt() from test Fixture 
// */
TEST_F(EnvironmentTestFixtures, RewardGenerationGoalNode) {

	EnvironmentPrintHelper();
	expectedRewardAt(0, 4, 2.5);
} 

//*
// @Brife Test the Environment reward generation on a OBSTICAL state node
// Calls expectedRewardAt() from test Fixture 
// */
TEST_F(EnvironmentTestFixtures, RewardGenerationObsticalNode) {

	EnvironmentPrintHelper();
	expectedRewardAt(0, 1, 0.0);
}


pair<int, int> generateExpectedCoords(StateBasedNode& currentNode, Direction action) {
	pair<int, int> offSet = DirectionalEnum::getDirectionOffsef(action);

	pair<int, int> currentCoords = make_pair(currentNode.nodeCoordX, currentNode.nodeCoordY);

	pair<int, int> expectedNewCoords = applyOffsetToCoords(currentCoords, offSet);

	return expectedNewCoords;
}

//*
// @ Brife Test the evironment step function
// 
// Test the process of takign a single "Step" in a 2D environment
// Expcted result -> 
// - Agent moves to a new Node
// - New node, Reward and Termination condition returned
// */
TEST_F(EnvironmentTestFixtures, SingleStep_Direction_UP_LEFT ) {
	EnvironmentPrintHelper();

	Direction action = UP_LEFT;

	StateBasedNode currentNode = testEnv.getCurrentNode();

	pair<int, int> expectedNewCoords = generateExpectedCoords(currentNode, action);

	tuple<StateBasedNode, double, bool> results = testEnv.step(action);

	traceAssertEQ(get<0>(results).nodeCoordX, expectedNewCoords.first, "SingleStepInEnvironment_Direction_UP_LEFT -> X Coord after step not as expected");
	traceAssertEQ(get<0>(results).nodeCoordY, expectedNewCoords.second, "SingleStepInEnvironment_Direction_UP_LEFT -> X Coord after step not as expected");

	traceAssertEQ(get<1>(results), 0.1, "SingleStepInEnvironment_Direction_UP_LEFT -> Reward not as expected");

	traceAssertEQ(get<2>(results), 0, "SingleStepInEnvironment_Direction_UP_LEFT -> Termination flag not as expected");
}

//*
// @ Brife Test the evironment step function
// 
// Test the process of takign a single "Step" in a 2D environment
// Expcted result -> 
// - Agent moves to a new Node
// - New node, Reward and Termination condition returnedImp
// 
// 
// 
// Bug - Not setting termination flag for Obstical node - should be true
// Bug - Returning a reward for obstical node - should givce 0.0 
//	
// 
// */
TEST_F(EnvironmentTestFixtures, SingleStep_Direction_UP) {
	EnvironmentPrintHelper();

	Direction action = UP;

	StateBasedNode currentNode = testEnv.getCurrentNode();

	pair<int, int> expectedNewCoords = generateExpectedCoords(currentNode, action);

	tuple<StateBasedNode, double, bool> results = testEnv.step(action);

	cout << get<0>(results).state_to_string() << endl;

	cout << "New x Coord " << get<0>(results).nodeCoordX << endl;
	cout << "New y Coord " << get<0>(results).nodeCoordY << endl;

	traceAssertEQ(get<0>(results).nodeCoordX, expectedNewCoords.first, "SingleStepInEnvironment_Direction_UP -> X Coord after step not as expected");
	traceAssertEQ(get<0>(results).nodeCoordY, expectedNewCoords.second, "SingleStepInEnvironment_Direction_UP -> Y Coord after step not as expected");

	traceAssertEQ(get<1>(results), 0, "SingleStepInEnvironment_Direction_UP -> Reward not as expected");

	traceAssertEQ(get<2>(results), true, "SingleStepInEnvironment_Direction_UP -> Termination flag not as expected");
}



//*
// @ Brife Test if termination is given on obstical nodes
// Expected reslt -> 
// - Returns true on node with state = OBSTICAL
// - Returns false on node with state = GOAL / OPEN
// - else returns false
// */
TEST_F(EnvironmentTestFixtures, NodeTerminationCheck) {
	EnvironmentPrintHelper();
	int obsticalLocationX = 0;
	int obsticalLocationY = 1;

	int goalNodeLocationX = 4;
	int goalNodeLocationY = 4;
	

	StateBasedNode obsticalNode = testEnv.getNodeAtEnvironmentLocation(obsticalLocationX, obsticalLocationY);
	StateBasedNode goalNode = testEnv.getNodeAtEnvironmentLocation(goalNodeLocationX, goalNodeLocationY);

	bool terminationCondition_ObsticalNode = testEnv.nodeTerminationCheck(obsticalNode);
	bool terminationCondition_GoalNode = testEnv.nodeTerminationCheck(goalNode);

	traceAssertEQ(terminationCondition_ObsticalNode, true, "NodeTerminationCheck -> Obstical Node -> Termination flag not as expected");
	traceAssertEQ(terminationCondition_GoalNode, false, "NodeTerminationCheck -> Goal Node -> Termination flag not as expected");

}

//*
// @brife Testing if the getNodeAtEnvironmentLocation returns as expected
// Expected Result ->
// - Returns the node at the given x,y coordinates
// */
TEST_F(EnvironmentTestFixtures, EnvironmentGetAtCoords) {
	EnvironmentPrintHelper();

	StateBasedNode nodeA = testEnv.getNodeAtEnvironmentLocation(0, 0);

	StateBasedNode nodeB = testEnv.getNodeAtEnvironmentLocation(1, 0);

	StateBasedNode nodeC = testEnv.getNodeAtEnvironmentLocation(0, 1);

	StateBasedNode nodeD = testEnv.getNodeAtEnvironmentLocation(1, 1);

	StateBasedNode nodeE = testEnv.getNodeAtEnvironmentLocation(0, 4);

	nodeA.printHelper_StateBasedNode();
	nodeB.printHelper_StateBasedNode();
	nodeC.printHelper_StateBasedNode();
	nodeD.printHelper_StateBasedNode();
	nodeE.printHelper_StateBasedNode();
	
}