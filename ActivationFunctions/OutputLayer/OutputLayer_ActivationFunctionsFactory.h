#ifndef OUTPUT_LAYER_ACTIVATION_FUNCTION_FACTORY_H
#define OUTPUT_LAYER_ACTIVATION_FUNCTION_FACTORY_H

#include <functional>
#include <vector>


#include "OutputLayer_ActivationFunctions.h"

using std::function;
using std::vector;

using FunctionType = function<vector<double>(double)>;

class OutputLayerActivation_FunctionFactory {
public:
	template<typename T>
	static FunctionType create() {
		return Func()();
	}




};


#endif // !OUTPUT_LAYER_ACTIVATION_FUNCTION_FACTORY_H