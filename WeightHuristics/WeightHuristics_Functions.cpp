#include "WeightHuristics_Functions.h"
#include "cppGenerator.h"

#include <iostream>
#include <string>
#include <format>
#include <optional>
#include <coroutine>
#include <generator>
#include <vector>
#include <cmath>
#include <random>

using std::vector;
using std::sqrt;
using std::random_device;


//// Form here
//GeneratorType HeWeightHuristic::operator()() const {
//	return[](vector<double> layerConnections) -> Generator {
//
//		vector<double> weights;
//
//		size_t inputLayerSize = layerConnections[0];
//		size_t outputLayerSize = layerConnections[1];
//
//		size_t requieredWeights = inputLayerSize * outputLayerSize;
//
//		double stdDev = sqrt(2.0 / inputLayerSize);
//
//		random_device rd;
//		mt19937 gen(rd());
//		normal_distribution<>dist(0.0, stdDev);
//
//		for (size_t i = 0; i < requieredWeights; i++) {
//			co_yield dist(gen);
//		}
//	};
//}



void testFunction() { 
	cout << "Test function " << endl;
	Generator gen = count_to_test_func(5);
	size_t upperLimit = 5;
	while (gen.next()) {
		cout << "Generator Value : " << gen.value() << endl; 
	}
	cout << "Test function " << endl;
}

