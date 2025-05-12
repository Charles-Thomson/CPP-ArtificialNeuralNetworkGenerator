#ifndef HIDDEN_LAYER_ACTIVATION_FUNCTION_FACTORY_H
#define HIDDEN_LAYER_ACTIVATION_FUNCTION_FACTORY_H

#include <functional>

#include "HiddenLayer_ActivationFunctions.h"

using std::function;

// Takes a double return double
using FunctionType = function<double(double)>;


class HiddenLayerActivation_FunctionFactory {
public:
	template<typename Func>
	static FunctionType create() {
		return Func()();
	
	
	}
};



#endif // !HIDDEN_LAYER_ACTIVATION_FUNCTION_FACTORY_H
