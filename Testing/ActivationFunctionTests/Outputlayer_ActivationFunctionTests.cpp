#include <gtest/gtest.h>
#include <string>
#include <format>
#include <iostream>
#include "ActivationFunctions/OutputLayer/OutputLayer_ActivationFunctionsFactory.h"


using std::cout;
using std::endl;
using std::format;
using std::vector;



//*
// @ brief Test Helper For Value Equality
// 
// @param expectedValue - The expected value
// @param actualValue - The actual value
// */
void ValueEqualityTestHelper(double expectedValue, double actualValue) {
	SCOPED_TRACE(format("Value Inequality -> Expected Value : {} Actual Value : {}", expectedValue, actualValue));
	ASSERT_EQ(expectedValue, actualValue);
}



TEST(OutputLayerActivationFunctionTesting, FactoryTesting) {
	cout << "In place holder factory test" << endl;

}


TEST(OutputLayerActivationFunctionTesting, ActivationFucntionTesting_ArgMax) {

	auto activationFunction = OutputLayerActivation_FunctionFactory::create<ArgMax>();


	vector<double> testVectorA = { 1, 2, 3, 4 };
	vector<double> testVectorB = { 2.3, 3.1, 4.6, 5.9 };
	vector<double> testVectorC = {-1, -2.1, 4, 10};

	double resultA = activationFunction(testVectorA);
	double resultB = activationFunction(testVectorB);
	double resultC = activationFunction(testVectorC);

	ValueEqualityTestHelper(3, resultA);
	ValueEqualityTestHelper(3, resultB);
	ValueEqualityTestHelper(3, resultC);

}



TEST(OutputLayerActivationFunctionTesting, ActivationFucntionTesting_SoftMax) {


}