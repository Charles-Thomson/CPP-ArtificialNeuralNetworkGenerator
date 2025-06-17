#include <gtest/gtest.h>
#include <iostream>
#include "../TestEnvironmentGeneration/StateBase2DTestEnvironmentGeneration.cpp"
#include "../../../Environment/EnvironmentNodes/StateBased/StateBasedNode.h"

using std::cout;
using std::endl;

template<typename T1,typename T2>
void traceAssertEQ(const T1& actual, const T2& expected, const string& scopeTraceMessage) {
	SCOPED_TRACE(scopeTraceMessage);
	ASSERT_EQ(expected, actual);
}

//*
// @brife Test generated environment variables
// */
TEST_F(EnvironmentTestFixtures, EnvironmentSetUpTest) {

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

void printHelp() {
	cout << "Printed" << endl;
	std::cerr << "Coords: " << endl;
	std::cerr.flush();

}


//*@Brife Test the Environment reward generation*/
TEST_F(EnvironmentTestFixtures, RewardGeneration) {
	printHelp();

	int newXCoord = 1;
	int newYCoord = 2;

	StateBasedNode newNodeLocation = testEnv.getNodeAtEnvironmentLocation(newXCoord, newYCoord);

	double reward = testEnv.calculateReward(newNodeLocation);

	std::cerr << "Coords: " << newNodeLocation.nodeCoordX << ", " << newNodeLocation.nodeCoordY << std::endl;
	std::cerr.flush();

	SCOPED_TRACE(format("Reward amount incorrect {}", reward));
	ASSERT_EQ(reward, 0.1);


}