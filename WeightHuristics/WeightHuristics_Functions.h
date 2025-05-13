#ifndef WEIGHT_HURISTICS_FUNCTIONS_H
#define WEIGHT_HURISTICS_FUNCTIONS_H
#include "WeightHuristics_GeneratorFactory.h"


#include <string>
#include <functional>
#include <format>
#include <iostream>
#include <random>
#include <coroutine>

// Takes a vector<double> return double
using GeneratorType = Generator;

using std::string;
using std::cout;
using std::endl;
using std::function;
using std::vector;
using std::sqrt;
using std::random_device;
using std::make_shared;
using std::shared_ptr;

using Generator = Generator;

class HeWeightHuristic {
public:
    // The operator() function creates a generator 
    Generator operator()(const vector<double>& layerConnections) {
        double inputLayerSize = layerConnections[0];
        double outputLayerSize = layerConnections[1];

        size_t requiredWeights = inputLayerSize * outputLayerSize;
        double stdDev = sqrt(2.0 / inputLayerSize);
        random_device rd;
        auto gen = make_shared<mt19937>(random_device{}());
        auto dist = make_shared<normal_distribution<>>(0.0, stdDev);

        return ReturnGen(requiredWeights, dist, gen); 
    }

private:
    Generator ReturnGen(size_t requiredWeights, shared_ptr<normal_distribution<>> dist, shared_ptr<mt19937> gen) {
        for (size_t i = 0; i < requiredWeights; ++i) {
            double weight = (*dist)(*gen); // Generate a weight using the normal distribution
            co_yield weight; // Yield the generated weight
        }
    }
};





#endif // !WEIGHT_HURISTICS_FUNCTIONS_H