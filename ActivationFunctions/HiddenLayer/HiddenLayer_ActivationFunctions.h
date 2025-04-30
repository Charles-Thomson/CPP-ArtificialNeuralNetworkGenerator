#ifndef HIDDEN_LAYER_ACTIVATION_FUNCTION_H
#define HIDDEN_LAYER_ACTIVATION_FUNCTION_H

#include "HiddenLayer_ActivationFunctionsFactory.h"

#include <functional>

using std::function;

using FunctionType = function<double(double)>;

class LinearActivation {
public:
    FunctionType operator()() const;
};

class RectifiedLinearActivation {
public:
    FunctionType operator()() const;
};

class LeakyRectifiedLinearActivation {
public :
    FunctionType operator()() const;
};

class SigmoidActivation {
public:
    FunctionType operator()() const;
};

class HyperbolicTangentActivation {
public:
    FunctionType operator()() const;

};




#endif // !HIDDEN_LAYER_ACTIVATION_FUNCTION_H
