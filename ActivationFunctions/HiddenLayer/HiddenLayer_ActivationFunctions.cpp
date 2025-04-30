#include "HiddenLayer_ActivationFunctions.h"

#include <iostream>
#include <algorithm>
#include <cmath>

using std::round;
using std::max;
using std::exp;


//*
// @brief Linear Activation 
// Returns gven value
// 
// @param value
// @return value - unchanged
// */
FunctionType LinearActivation::operator()() const {
	return [](double value) -> double {
		return value;
		};

};

//*
// @brief Recitied Linear Activation (ReLU)
// If a given value is bleow the 0.0 thershold it is set to 0.0
// Else the value is rounded to 3 decimal places
// 
// @param value
// @return value roudned or set to 0.0
// */
FunctionType RectifiedLinearActivation::operator()() const {
	return [](double value) -> double {
		return round(max(0.0, value) * 1000) / 1000;

		};
};

//*
// @brief Leaky Rectified Linear Activation (LREL) 
// Handles the "leaky" use case around 0.0 
// Returned value is value or 0.01*value
// 
// Addreses Dying ReLU issue - keeps values above 0.0
// Reduces negitive activation using a small Alpha(0.01)
// 
// @param value
// @return value 
// */
FunctionType LeakyRectifiedLinearActivation::operator()() const {
	return [](double value) -> double {
		if (value > 0.0) {
			return value;
		}
		else {
			return value * 0.01;
		};
	};
};


//*
// @brief Sigmoid Activation Function
// Maps numbers into a (0,1) range 
// Produces a smooth gradient 
// 
// Rounds resulting value to 3 decimal places
// 
// */
FunctionType SigmoidActivation::operator()() const {
	return[](double value) -> double {
		double sumResult = 1.0 / (1.0 + exp(-value));
		double roundedResult = round(sumResult * 1000) / 1000;
		return roundedResult;
		};

};


//*
// @brief Hyperbolic Tangent Activation
// value is normalized between -1 and 1 
// rounds value to 3 dp 
// */ 
FunctionType HyperbolicTangentActivation::operator()()const {
	return [](double value) -> double {
		double sumResult = tanh(value);
		double roundedResult = round(sumResult * 1000) / 1000;
		return roundedResult;
		};
};

