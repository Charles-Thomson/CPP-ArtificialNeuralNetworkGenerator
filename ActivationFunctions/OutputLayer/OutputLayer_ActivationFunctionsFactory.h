#ifndef OUTPUT_LAYER_ACTIVATION_FUNCTION_FACTORY_H
#define OUTPUT_LAYER_ACTIVATION_FUNCTION_FACTORY_H

#include <functional>
#include <vector>


#include "OutputLayer_ActivationFunctions.h"

using std::function;
using std::vector;

//Takes vecotor<double> returns double
using FunctionType = function<double(vector<double>)>;

class OutputLayerActivation_FunctionFactory {
public:
	template<typename Func>
	static FunctionType create() {
		return Func()();
	}

};


#endif // !OUTPUT_LAYER_ACTIVATION_FUNCTION_FACTORY_H