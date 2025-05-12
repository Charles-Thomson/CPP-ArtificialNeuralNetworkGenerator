#include <gtest/gtest.h>

#include <iostream>
#include <format>
#include <vector>

#include "cppGenerator.h"
#include "../WeightHuristics/WeightHuristics_Functions.h"
#include "WeightHuristics/WeightHuristics_GeneratorFactory.h"

using std::cout;
using std::endl;
using std::string;
using std::format;
using std::vector;

// A test algorithm
Generator TestGenerator(vector<double> layerConnections) {

	vector<double> resultVector;
	for (double val : layerConnections) {
		double res = val * val;
		resultVector.push_back(val);
	};
	for (double val : resultVector) {
		co_yield val;
	}
}
using GeneratorA = std::function<void()>;


TEST(WeightHuristicsFunctionTesting, GetFunctionFromFactory) {
	vector<double> layerConnections = { 10,20 };
	Generator testGen = WeightHuristics_GeneratorFactory::create<HeWeightHuristic>(layerConnections);
	
	while (testGen.next()) {
		cout << "GeneratedValue : " << testGen.value() << endl; 
	
	}
	ASSERT_EQ(1, 2);

}

TEST(WeightHuristicsFunctionTesting, WeightHuristicsFunctions_Testing) {
	cout << "in the working test call" << endl;


	vector<double> layerConnections = { 4,6 };
	Generator gen = TestGenerator(layerConnections);
	

	while (gen.next()) {
		cout << "Gen value : " << gen.value() << endl;
	
	}


	ASSERT_EQ(1, 2);
	

}