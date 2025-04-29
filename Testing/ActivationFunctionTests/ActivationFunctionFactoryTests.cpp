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

	ValueEqualityTestHelper(testValueA, resultA);
	ValueEqualityTestHelper(testValueB, resultB);
	ValueEqualityTestHelper(testValueC, resultC);
}

//*
// @ brief Test Rectified Linear Activation Function (ReLU)
// Expected result: 
// test value should return unchanged unless below 0.0 threshold
// Below Threshold values should be returned as 0.0
// */
TEST(ActivationFunctionTesting, ActivationFunctionsTest_RectifiedLinearActivation) {
	auto activationFunction = FunctionFactory::create<RectifiedLinearActivation>();

	double testValueA = 2;
	double testValueB = 2.2;
	double testValueC = -2;

	double resultA = activationFunction(testValueA);
	double resultB = activationFunction(testValueB);
	double resultC = activationFunction(testValueC);

	ValueEqualityTestHelper(testValueA, resultA);
	ValueEqualityTestHelper(testValueB, resultB);
	ValueEqualityTestHelper(0.0, resultC);
}

//*
// @ brief Test Leaky Rectified Linear Activation Function (LREL)
// 
// Expected result: 
// test value should return unchanged unless below 0.0 threshold
// Below Threshold values should be returned as value * 0.01
// 
// */
TEST(ActivationFunctionTesting, ActivationFunctionsTest_LeakyRectifiedLinearActivation) {
	auto activationFunction = FunctionFactory::create<LeakyRectifiedLinearActivation>();

	double testValueA = 2;
	double testValueB = 2.2;
	double testValueC = -2;

	double resultA = activationFunction(testValueA);
	double resultB = activationFunction(testValueB);
	double resultC = activationFunction(testValueC);

	ValueEqualityTestHelper(testValueA, resultA);
	ValueEqualityTestHelper(testValueB, resultB);
	ValueEqualityTestHelper(-0.02, resultC);
}


//*
// brief Test Sigmoid Activation Function
// Expected result:
// Test values normalized to between 0 and 1 
// */
TEST(ActivationFunctionTesting, ActivationFunctionsTest_SigmoidActivation) {
	auto activationFunction = FunctionFactory::create<SigmoidActivation>();

	double testValueA = 2;
	double testValueB = 2.2;
	double testValueC = -2;
	double testValueD = 20;

	double resultA = activationFunction(testValueA);
	double resultB = activationFunction(testValueB);
	double resultC = activationFunction(testValueC);
	double resultD = activationFunction(testValueD);

	ValueEqualityTestHelper(0.881, resultA);
	ValueEqualityTestHelper(0.9, resultB);
	ValueEqualityTestHelper(0.119 ,resultC);
	ValueEqualityTestHelper(1, resultD);


}
//*
// @ brief Test Hyperbolid Tangent Activation function
// Expected result:
// 
// Test values normalized between -1 and 1

// */
TEST(ActivationFunctionTesting, ActivationFunctionsTest_HyperbolicTangentActivation) {
	auto activationFunction = FunctionFactory::create<HyperbolicTangentActivation>();

	double testValueA = 2;
	double testValueB = 2.2;
	double testValueC = -2;
	double testValueD = 20;

	double resultA = activationFunction(testValueA);
	double resultB = activationFunction(testValueB);
	double resultC = activationFunction(testValueC);
	double resultD = activationFunction(testValueD);

	ValueEqualityTestHelper(0.964, resultA);
	ValueEqualityTestHelper(0.975, resultB);
	ValueEqualityTestHelper(-0.9640, resultC);
	ValueEqualityTestHelper(1.0, resultD);




}