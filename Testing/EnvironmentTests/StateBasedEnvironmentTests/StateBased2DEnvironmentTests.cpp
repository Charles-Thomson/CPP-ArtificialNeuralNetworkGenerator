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
	traceAssertEQ(testEnv.pathLength, 0, "Environment Attribute set incorrectly -> pathLength");
	traceAssertEQ(testEnv.path.size(), 0, "Environment Attribute set incorrectly -> path");
	traceAssertEQ(testEnv.getCurrentStep(), 0, "Environment Attribute set incorrectly -> CurentStep");
	traceAssertEQ(testEnv.getActionCount(), 0, "Environment Attribute set incorrectly -> ActionCount");
}