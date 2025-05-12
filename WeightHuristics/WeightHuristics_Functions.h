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

using Generator = Generator;

// The HeWeightHuristic class (does not invoke the lambda immediately)
class HeWeightHuristic {
public:
    // The operator() function creates a generator (does not invoke it immediately)
    Generator operator()(const vector<double>& layerConnections) {
        double inputLayerSize = layerConnections[0];
        double outputLayerSize = layerConnections[1];

        size_t requiredWeights = inputLayerSize * outputLayerSize;
        double stdDev = sqrt(2.0 / inputLayerSize);
        random_device rd;
        mt19937 gen(rd());
        normal_distribution<> dist(0.0, stdDev);

        // Return a generator function (lambda) that is invoked separately
        return ReturnGen(requiredWeights, dist, gen); // Call ReturnGen here
    }

private:
    Generator ReturnGen(size_t requiredWeights, normal_distribution<> dist, mt19937 gen) {
        for (size_t i = 0; i < requiredWeights; ++i) {
            double weight = dist(gen); // Generate a weight using the normal distribution
            cout << "Generated weight: " << weight << endl; // Debug line
            co_yield weight; // Yield the generated weight
        }
    }
};





#endif // !WEIGHT_HURISTICS_FUNCTIONS_H