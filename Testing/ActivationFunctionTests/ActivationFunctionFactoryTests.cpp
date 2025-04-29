#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <format>

#include "ActivationFunctions/HiddenLayer/ActivationFunctionsFactory.h"

using std::cout;
using std::endl;
using std::string;
using std::format;




//*
// @ Brief Test the creation of ActivationFunctions
// 
// Will be removed during development
// 
// */
TEST(ActivationFunctionTesting, ActivationFunctionFactoryTest) {
	auto hello = FunctionFactory::create<LinearActivation>();

	hello(2.2);
	cout << "In the test function" << endl;


	ASSERT_EQ(1, 2);
}


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


//*
// @brief Test Linear Activation Function
// 
// Expected result: Values returned unchanged
// i.e testValueA == reusltValueA
// */
TEST(ActivationFunctionTesting, ActivationFunctionsTest_LinearActivation) {
	auto activationFunction = FunctionFactory::create<LinearActivation>();

	double testValueA = 2;
	double testValueB = 2.2;
	double testValueC = -1;

	double resultA = activationFunction(testValueA);
	double resultB = activationFunction(testValueB);
	double resultC = activationFunction(testValueC);

	ValueEqualityTestHelper(resultA, testValueA);
	ValueEqualityTestHelper(resultB, testValueB);
	ValueEqualityTestHelper(resultC, testValueC);
	
}