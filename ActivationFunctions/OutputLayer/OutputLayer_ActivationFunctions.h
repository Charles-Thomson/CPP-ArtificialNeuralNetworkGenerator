#ifndef OUTPUT_LAYER_ACTIVATION_FUNCTIONS
#define OUTPUT_LAYER_ACTIVATION_FUNCTIONS

#include "OutputLayer_ActivationFunctionsFactory.h"

#include <functional>

using std::function;
using std::vector;

using FunctionType = function<double(vector<double>)>;

class ArgMax {
public:
	FunctionType operator()() const;
};

class SoftArgMax {
public:
	FunctionType operator()() const;
};



#endif // !OUTPUT_LAYER_ACTIVATION_FUNCTIONS