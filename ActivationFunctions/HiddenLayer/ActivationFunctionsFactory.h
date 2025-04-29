#ifndef ACTIVATION_FUNCTION_FACTORY_H
#define ACTIVATION_FUNCTION_FACTORY_H

#include <functional>

#include "ActivationFunctions.h"

using std::function;


using FunctionType = function<double(double)>;


class FunctionFactory {
public:
	template<typename Func>
	static FunctionType create() {
		return Func()();
	
	
	}
};



#endif // !ACTIVATION_FUNCTION_FACTORY_H
