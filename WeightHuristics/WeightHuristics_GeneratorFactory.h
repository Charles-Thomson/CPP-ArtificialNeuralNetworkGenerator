#ifndef WEIGHT_HURISTICS_FACTORY_H
#define WEIGHT_HURISTICS_FACTORY_H

#include "cppGenerator.h"

#include <string>
#include <iostream>
#include <format>
#include <functional>
#include <vector>


using std::function;
using std::string;
using std::vector;


// Takes a vector<double> return double
using GeneratorType = function<Generator(vector<double>)>;


// This needs to return a generator
// Build out to retiurn a generator instead of a function
// May need to change approach
class WeightHuristics_GeneratorFactory {
public:
	template<typename Func>
	static GeneratorType create() {
		return Func()();
	}
};



#endif // !WEIGHT_HURISTICS_FACTORY_H