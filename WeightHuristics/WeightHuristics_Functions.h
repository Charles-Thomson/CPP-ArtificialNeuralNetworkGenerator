#ifndef WEIGHT_HURISTICS_FUNCTIONS_H
#define WEIGHT_HURISTICS_FUNCTIONS_H
#include "WeightHuristics_GeneratorFactory.h"


#include <string>
#include <functional>
#include <format>
#include <iostream>

// Takes a vector<double> return double
using GeneratorType = function<Generator(vector<double>)>;

using std::string;
using std::cout;
using std::endl;
using std::function;


void testFunction();

class HeWeightHuristic {
public:
	GeneratorType operator()() const;
};





#endif // !WEIGHT_HURISTICS_FUNCTIONS_H