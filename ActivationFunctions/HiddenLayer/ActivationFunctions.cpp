#include "ActivationFunctions.h"

#include <iostream>
#include <algorithm>
#include <cmath>

using std::round;
using std::max;


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

