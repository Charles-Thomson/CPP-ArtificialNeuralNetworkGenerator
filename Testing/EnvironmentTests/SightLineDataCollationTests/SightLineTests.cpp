#include <gtest/gtest.h>
#include "../SupportingEnvironmentTestFunctions/SupportingTestFunctions.cpp"


TEST_F(EnvironmentTestFixtures, Testing2DSightLineDataCollation) {
	vector<vector<StateBasedNode>> testEnvironment = GenerateBlankTest2DEnvironment(5);

	testEnvironment = Populate2DTestEnvironment_Dimesnions5(testEnvironment);

	vector<double> placeHolder = PerformObservationFromLocation({ 1,1 }, testEnvironment);


	tuple<int, int> observationPointA;
	vector<double> expectedResultA;

	ASSERT_EQ(1, 2);



}




