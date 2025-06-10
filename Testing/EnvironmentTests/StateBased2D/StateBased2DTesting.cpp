#include <gtest/gtest.h>

#include "../Environment/EnvironmentObservtions/StateBased2DEnvironmentObservation.h"
#include "../Environment/EnvironmentNodes/StateBased/StateBasedNode.h"
#include "../SupportingEnvironmentTestFunctions/SupportingTestFunctions.cpp"

#include <string>
#include <fmt/format.h>
#include <stdexcept>
#include <tuple>;
#include <utility>
#include <functional>
#include <iostream>


using std::string;
using std::cout;
using std::endl;
using fmt::format;
using std::tuple;
using std::unordered_map;
using std::pair;
using std::find;


//TEST_F(EnvironmentTestFixtures, TestRewardCalculation) {
//	cout << "In the test" << endl;
//
//	/*Environment newEnv = generateDummyEnvironment();
//
//	StateBasedNode currentNode = newEnv.getCurrentNode();
//
//	int currentX = currentNode.nodeCoordX;
//	int currentY = currentNode.nodeCoordY;
//
//	int newY = currentY + 1;
//
//	StateBasedNode newLocationNode = newEnv.getNodeAtEnvironmentLocation(currentX, newY);
//
//	double reward = newEnv.calcualteReward(newLocationNode);
//
//
//	cout << reward << endl;*/
//
//	ASSERT_EQ(1, 4); // fail point for testing
//
//}

TEST(Base, NewTest) {
	cout << "In the test" << endl;

	ASSERT_EQ(1, 4); // fail point for testing

}


