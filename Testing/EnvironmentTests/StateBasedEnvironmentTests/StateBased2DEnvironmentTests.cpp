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


//TEST(BaseTest, PrintTest) {
//	cout << "Printed" << endl;
//	std::cerr << "Coords: " << endl;
//	std::cerr.flush();
//
//	EXPECT_EQ(1, 2);
//}

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