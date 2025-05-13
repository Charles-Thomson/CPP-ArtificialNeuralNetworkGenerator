#ifndef WEIGHT_HURISTICS_FUNCTIONS_H
#define WEIGHT_HURISTICS_FUNCTIONS_H
#include "WeightHuristics_GeneratorFactory.h"


#include <string>
#include <functional>

#include <iostream>
#include <random>
#include <coroutine>

using std::string;
using std::cout;
using std::endl;
using std::function;
using std::vector;
using std::sqrt;
using std::random_device;
using std::make_shared;
using std::shared_ptr;
using std::uniform_real_distribution;
using std::normal_distribution;


//*
// @Brief HE weight distribution value generator
// 
// Produces a geenrator to generate values acoriding to the HE weight Huristic
// 
// @param layerConnections - The Numebr of Input and Output connections of the layer
// @return Generator - Generator to produce weights using the HE weight huristic
// */
class HeWeightHuristic {
public:
    // The operator() function creates a generator 
    Generator operator()(const vector<double>& layerConnections) {
        double inputLayerSize = layerConnections[0];
        double outputLayerSize = layerConnections[1];

        double requieredNumberOfWeights = inputLayerSize * outputLayerSize;
        double stdDev = sqrt(2.0 / inputLayerSize);
       
        auto gen = make_shared<mt19937>(random_device{}());
        auto dist = make_shared<normal_distribution<>>(0.0, stdDev);

        return ReturnGen(requieredNumberOfWeights, dist, gen);
    }

private:
    Generator ReturnGen(double requieredNumberOfWeights, shared_ptr<normal_distribution<>> dist, shared_ptr<mt19937> gen) {
        for (size_t i = 0; i < requieredNumberOfWeights; ++i) {
            double weight = (*dist)(*gen); // Generate a weight using the normal distribution
            co_yield weight; // Yield the generated weight
        }
    }
};

//*
// @Brief Xavier weight distribution value generator
// 
// Produces a generator to generate values acoriding to the Xavier weight Huristic
// 
// @param layerConnections - The Numeber of Input and Output connections of the layer
// @return Generator - Generator to produce weights using the Xavier weight huristic
// */
class XavierWeightHuristic {
public:
    Generator operator()(const vector<double>& layerConnections) {
        double inputLayerSize = layerConnections[0];
        double outputlayerSize = layerConnections[1];

        double requieredNumberOfWeights = inputLayerSize * outputlayerSize;

        double stdDev = sqrt(2.0 / (inputLayerSize + outputlayerSize));
        auto gen = make_shared<mt19937>(random_device{}());
        auto dist = make_shared<normal_distribution<>>(0.0, stdDev);

        return ReturnGen(requieredNumberOfWeights, dist, gen);
    }
private: 
    Generator ReturnGen(double requieredNumberOfWeights, shared_ptr<normal_distribution<>> dist, shared_ptr<mt19937> gen) {
        for (size_t i = 0; i < requieredNumberOfWeights; i++) {
            double weight = (*dist)(*gen);
            co_yield weight;

        };
    }

};


//*
// @ Brief Xavier Uniform WEight Hurisic generator
// 
// Proiduce a generator to return weight following the Xavier Unifor weight Huristic
// 
// @param layerConnections - The Numeber of Input and Output connections of the layer
// @return Generator - Generator to produce weights using the Xavier Uniform weight huristic
// */
class XavierUniformWeightHuristic {
public:
    Generator operator()(const vector<double>& layerConnections) {
        double inputLayerSize = layerConnections[0];
        double outputLayerSize = layerConnections[1];

        double requieredNumberOfWeights = inputLayerSize * outputLayerSize;
        double limit = sqrt(6.0) / sqrt(inputLayerSize + outputLayerSize);
        auto gen = make_shared<mt19937>(random_device{}());
        auto dist = make_shared<uniform_real_distribution<>>(-limit, limit);

        return ReturnGen(requieredNumberOfWeights, dist, gen);
    }

private:
    Generator  ReturnGen(double requieredNumberOfWeights, shared_ptr<uniform_real_distribution<>> dist, shared_ptr<mt19937> gen) {
        for (size_t i = 0; i < requieredNumberOfWeights; i++) {
            double weight = (*dist)(*gen);
            co_yield weight;
        };
    }
};





#endif // !WEIGHT_HURISTICS_FUNCTIONS_H