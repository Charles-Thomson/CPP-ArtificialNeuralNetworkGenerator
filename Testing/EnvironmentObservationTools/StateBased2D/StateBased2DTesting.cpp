#include <gtest/gtest.h>

#include "../Environment/EnvironmentObservtions/StateBased2DEnvironmentObservation.h"
#include "../Environment/EnvironmentNodes/StateBased/StateBasedNode.h"

#include <string>
#include <fmt/format.h>



using std::string;
using std::cout;
using std::endl;
using fmt::format;

//vector<vector<StateBasedNode>> GenerateTest2DEnvironment(int dimensions) {
//	vector<vector<StateBasedNode>> testEnvironment(dimensions, vector<StateBasedNode>(dimensions, StateBasedNode::OPEN));
//
//
//
//	
//
//
//
//}



TEST(ObservationTesting_StateBased_2D, TestFunctionCall) {
	string testResponse = testFunctionCall();
	string printString = format("ObservationTesting_StateBased_2D -> Retrun from test function call {}", testResponse);
	cout << printString << endl;
	
	ASSERT_EQ(1, 2);

}