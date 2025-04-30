#include "OutputLayer_ActivationFunctions.h"

#include <functional>
#include <vector>

using std::function;
using std::vector;
using std::distance;
using std::max_element;

using FunctionType = function<double(vector<double>)>;

//*
// @ Brief ArgMax OutputLayer "activation"
// - Prefered for discreate actions of the given project - 
// Function will find the index of the highest value in a vector
// 
// @param value - Input vector
// @return index of highest value of input vector
// */
FunctionType ArgMax::operator()() const {
	return [](vector<double> value) -> double {
		return distance(value.begin(), max_element(value.begin(), value.end()));
		};
};


// SOFTARGMAX is not currently implemented in a usable format due to the type of learning taking palce aka not 
// using a backpropergating learning method
//*
// SoftMax Activation**
// - Perfered for probabilistic action selection (stochastic policy)/back propergation  - 
// Gives a value which takes into account the other values while also indecation the most likely outcome(index)
//*/
FunctionType SoftArgMax::operator()() const {
	return [](vector<double> value) -> double {
		vector<double> exponentials(value.size());
		double sum = 0.0;

		// Calculate exponentials
		for (size_t i = 0; i < value.size(); i++) {
			exponentials[i] = exp(value[i]);
			sum += exponentials[i];
		};


		double soft_argmax_result = 0.0;
		for (size_t i = 0; i < value.size(); i++) {
			double softmax_i = exponentials[i] / sum;
			soft_argmax_result += i * softmax_i;
		};

		return soft_argmax_result;

		};

};