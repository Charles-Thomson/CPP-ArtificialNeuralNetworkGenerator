#include <gtest/gtest.h>

#include <iostream>
#include <format>
#include <vector>

#include "cppGenerator.h"
#include "../WeightHuristics/WeightHuristics_Functions.h"

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



//// This is the Generator constructor function
//Generator GeneratorReturn(vector<double> (*TestAlg)(vector<double>), vector<double> layerConnections) {
//	
//	vector<double> returnVector = TestAlg(layerConnections);
//
//	for(double val : returnVector) {
//		co_yield val;
//	}
//
//}

TEST(WeightHuristicsFunctionTesting, WeightHuristicsFunctions_Testing) {
	cout << "in the working test call" << endl;


	vector<double> layerConnections = { 4,6 };
	Generator gen = TestGenerator(layerConnections);
	

	while (gen.next()) {
		cout << "Gen value : " << gen.value() << endl;
	
	}


	ASSERT_EQ(1, 2);
	

}