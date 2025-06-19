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


TEST(BaseTest, PrintTest) {
	cout << "Printed" << endl;
	std::cerr << "Coords: " << endl;
	std::cerr.flush();

	EXPECT_EQ(1, 2);
}

//*
// @brife Test generated environment variables
// */
//TEST_F(EnvironmentTestFixtures, EnvironmentSetUpTest) {
//	cout << "Test Start " << endl;
//
//	
//	vector<vector<StateBasedNode>> envMap = testEnv.getEnvironmentMap();
//
//	{
//		SCOPED_TRACE("Environment Map incorrectly set");
//		ASSERT_GT(envMap.size(), 0);
//	}
//	StateBasedNode testNode = testEnv.getCurrentNode();
//
//	traceAssertEQ(testNode.state, StateBasedNode::State::START, "Environment Attribute set incorrectly -> StartNode");
//	traceAssertEQ(testEnv.path.size(), 0, "Environment Attribute set incorrectly -> path");
//	traceAssertEQ(testEnv.getActionCount(), 0, "Environment Attribute set incorrectly -> ActionCount");
//
//	
//}
//
//void printHelp() {
//	cout << "Printed" << endl;
//	std::cerr << "Coords: " << endl;
//	std::cerr.flush();
//
//}
//
//
////*@Brife Test the Environment reward generation*/
//TEST_F(EnvironmentTestFixtures, RewardGeneration) {
//	printHelp();
//
//
//
//	int newXCoord = 1;
//	int newYCoord = 2;
//
//	StateBasedNode newNodeLocation = testEnv.getNodeAtEnvironmentLocation(newXCoord, newYCoord);
//
//	try {
//		double reward = testEnv.calculateReward(newNodeLocation);
//		std::cerr << "Reward: " << reward << std::endl;
//		ASSERT_EQ(reward, 0.1);
//	}
//	catch (const std::exception& e) {
//		std::cerr << "Exception in calculateReward: " << e.what() << std::endl;
//		FAIL() << "calculateReward threw an exception.";
//	}
//
//	/*double reward = testEnv.calculateReward(newNodeLocation);
//
//	std::cerr << "Coords: " << newNodeLocation.nodeCoordX << ", " << newNodeLocation.nodeCoordY << std::endl;
//	std::cerr.flush();
//
//	SCOPED_TRACE(format("Reward amount incorrect {}", reward));
//	EXPECT_EQ(reward, 0.1);*/
//
//
//}