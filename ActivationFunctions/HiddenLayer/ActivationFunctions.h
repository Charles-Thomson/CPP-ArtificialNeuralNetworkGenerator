#ifndef ACTIVATION_FUNCTION_H
#define ACTIVATION_FUNCTION_H

#include "ActivationFunctionsFactory.h"

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




#endif // !ACTIVATION_FUNCTION_H
