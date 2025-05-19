#include <gtest/gtest.h>

#include "../Environment/EnvironmentObservtions/StateBased2DEnvironmentObservation.h"


#include <string>
#include <fmt/format.h>



using std::string;
using std::cout;
using std::endl;
using fmt::format;

vector<vector<int>> GenerateTest2DEnvironment(int dimensions) {
	int start = 0;
	int emptyValue = 1;
	int obstical = 2;
	int goal = 3; 

	vector<vector<int>> testEnvironment;

	vector<int> row(dimensions, emptyValue);
	



}



TEST(ObservationTesting_StateBased_2D, TestFunctionCall) {
	string testResponse = testFunctionCall();
	string printString = format("ObservationTesting_StateBased_2D -> Retrun from test function call {}", testResponse);
	cout << printString << endl;
	
	ASSERT_EQ(1, 2);

}