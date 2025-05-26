#include <gtest/gtest.h>
#include "../SupportingEnvironmentTestFunctions/SupportingTestFunctions.cpp"
#include "Environment/EnvironmentObservtions/StateBased2DEnvironmentObservation.cpp"


TEST_F(EnvironmentTestFixtures, Testing2DSightLineDataCollation) {
	vector<vector<StateBasedNode>> testEnvironment = GenerateBlankTest2DEnvironment(5);

	testEnvironment = Populate2DTestEnvironment_Dimesnions5(testEnvironment);

	vector<double> placeHolder = PerformObservationFromLocation({ 1,1 }, testEnvironment);


	tuple<int, int> observationPointA;
	vector<double> expectedResultA;


	

	ASSERT_EQ(1, 2);



}

TEST_F(EnvironmentTestFixtures, CalculateAccumulativeInputDataAlongSightline_FunctionTest) {
	vector<vector<StateBasedNode>> testEnvironment = GenerateBlankTest2DEnvironment(5);

	testEnvironment = Populate2DTestEnvironment_Dimesnions5(testEnvironment);

	int envSize = testEnvironment.size();

	vector<StateBasedNode> testData = GenerateDummySightLineData();

	vector<int> processedSightLineData =  CalculateAccumulativeInputDataAlongSightline(testData, envSize);

	SCOPED_TRACE("Returned Value not as expected -> value : processedSightLineData");
	ASSERT_EQ(processedSightLineData[0], 11);
	ASSERT_EQ(processedSightLineData[1], 1);
	ASSERT_EQ(processedSightLineData[2], 3);

}

TEST_F(EnvironmentTestFixtures, UpdateMinAndMaxValues_FunctionTest) {
	vector<vector<StateBasedNode>> testEnvironment = GenerateBlankTest2DEnvironment(5);

	testEnvironment = Populate2DTestEnvironment_Dimesnions5(testEnvironment);

	int envSize = testEnvironment.size();

	vector<StateBasedNode> testData = GenerateDummySightLineData();

	vector<int> processedSightLineData = CalculateAccumulativeInputDataAlongSightline(testData, envSize);

	tuple<int,int> minMaxValues = DetermineMinAndMaxValues(processedSightLineData);

	// Test values hard coded based on the GenerateDummySightLineData() function
	SCOPED_TRACE("Value not as expected -> Value: minValue");
	ASSERT_EQ(get<0>(minMaxValues), 1);

	SCOPED_TRACE("Value not as expected -> Value: maxValue");
	ASSERT_EQ(get<1>(minMaxValues), 11);

}




