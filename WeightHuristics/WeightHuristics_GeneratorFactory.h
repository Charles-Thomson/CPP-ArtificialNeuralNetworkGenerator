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


class WeightHuristics_GeneratorFactory {
public:
	template<typename Func>
	static Generator create(vector<double>& layerConnections) {
		return Func()(layerConnections);
	}
};



#endif // !WEIGHT_HURISTICS_FACTORY_H