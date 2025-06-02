#include <gtest/gtest.h>
#include "../SupportingEnvironmentTestFunctions/SupportingTestFunctions.cpp"
#include "Environment/EnvironmentObservtions/StateBased2DEnvironmentObservation.cpp"



//*
// @Brife Test the fll process of sight line data collection
// 
// Test the full porcess of data observation and collerction from and env
// 
// Expected result:
// - REturns a set of souble values normalized to: -0.1 < n < 1.1
// 
// */
TEST_F(EnvironmentTestFixtures, Testing2DSightLineDataCollation){
	vector<vector<StateBasedNode>> testEnvironment = GenerateBlankTest2DEnvironment(5);

	testEnvironment = Populate2DTestEnvironment_Dimesnions5(testEnvironment);

	vector<double> sightLineData = PerformObservationFromLocation({ 1,1 }, testEnvironment);

	for (double& val : sightLineData) {
		SCOPED_TRACE("Value not normalized within bounds - -0.1 < n < 1.1");
		ASSERT_GT(val, -0.1);
		ASSERT_LT(val, 1.1);
	};
	
	ASSERT_EQ(sightLineData.size(),  24) << "Returned sightline data setis of an incorrect size" << endl;

	
}

//*
// @Brife Fucntion test : CalculateAccumulativeInputDataAlongSightline
// Expected Result:
// - returns int values based on the content of a sight line
// 
// Curently hard coded to work with the GenerateDummySightLineData function
// 
// 
// */
TEST_F (EnvironmentTestFixtures, CalculateAccumulativeInputDataAlongSightline_FunctionTest) {
	
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


//*
// @ Brife Test if min and max valus can be found from a data set
// 
// - Test is somewhat overkill - may remove as dead code 
// 
// */
TEST_F(EnvironmentTestFixtures, UpdateMinAndMaxValues_FunctionTest) {
	vector<vector<StateBasedNode>> testEnvironment = GenerateBlankTest2DEnvironment(5);

	testEnvironment = Populate2DTestEnvironment_Dimesnions5(testEnvironment);

	int envSize = testEnvironment.size();

	vector<StateBasedNode> testData = GenerateDummySightLineData();

	vector<int> processedSightLineData = CalculateAccumulativeInputDataAlongSightline(testData, envSize);

	tuple<double, double> minMaxValues = DetermineMinAndMaxValues(processedSightLineData);

	// Test values hard coded based on the GenerateDummySightLineData() function
	SCOPED_TRACE("Value not as expected -> Value: minValue");
	ASSERT_EQ(get<0>(minMaxValues), 1);

	SCOPED_TRACE("Value not as expected -> Value: maxValue");
	ASSERT_EQ(get<1>(minMaxValues), 11);

}




