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




void AssertValueWithinBounds(double upperbounds, double lowerbounds, double value) {
	SCOPED_TRACE("Given value falls outside the lower bounds");
	ASSERT_GT(value, -1.0);
	SCOPED_TRACE("Given value falls outside the upper bounds");
	ASSERT_LT(value, 1.0);
}


//*
// @brief Check if a generator produces the expected number of values
// 
// 
// @param gen - The given generator 
// @param expectedNumebrOfValues - the epxected number of values to be produced
// */
void AssertCorrectNumberOfValuesProduced(Generator& gen, double expectedNumebrOfValues) {
	
	double i = 0;
	while (gen.next()) {
		gen.value();
		cout << i << endl;
		i++;

	};

	SCOPED_TRACE("The numebr of expected values does not equal the numebr of produced values");
	ASSERT_DOUBLE_EQ(i, expectedNumebrOfValues);
}

//*
// @ Brief Helper function to create generator of type T 
// 
// Created a generator for weights following the given huristic of type T
// 
// @template T - The huristics type
// @param layerConnections - Number of connections fot eh ANN layer (input & output)
// @return Generator - Genrator to produce weigths of huristic T 
// */
template<typename T>
Generator RetrieveGeneratorOfHuristicsType(vector<double> layerConnections ) {
	return WeightHuristics_GeneratorFactory::create<T>(layerConnections);
}


//*
// @brief Testing the HeWeightHuristic weight generator
// Expected Result: 
// - Returns the requiered numebr of weights (layerconnections[0]*layerconnections[1])
// */

TEST(WeightHuristicsFunctionTesting, HeWeightHuristic) {
	vector<double> layerConnections = { 10,20 };
	double expectedNumebrOfValues = layerConnections[0] * layerConnections[1];
	
	Generator testGen = RetrieveGeneratorOfHuristicsType<HeWeightHuristic>(layerConnections);
	AssertCorrectNumberOfValuesProduced(testGen, expectedNumebrOfValues);
}

//*
// @ Brief Testing the Xavier Weight Huristic
// Expected Result: 
// - The Returned Generator produces the requiere number of weights
// */

TEST(WeightHuristicsFunctionTesting, XavierHuristic) {
	vector<double> layerConnections = { 10,20 };
	double expectedNumberOfConnections = layerConnections[0] * layerConnections[1];

	Generator testGen = RetrieveGeneratorOfHuristicsType<XavierWeightHuristic>(layerConnections);
	AssertCorrectNumberOfValuesProduced(testGen, expectedNumberOfConnections);
}

//*
// @ Brief Testing the Xavier Uniform Weight Huristic
// Expected Result: 
// - The Returned Generator produces the requiere number of weights
// */

TEST(WeightHuristicsFunctionTesting, XavierUniformHuristic) {
	vector<double> layerConnections = { 10,20 };
	double expectedNumberOfConnections = layerConnections[0] * layerConnections[1];

	Generator testGen = RetrieveGeneratorOfHuristicsType<XavierUniformWeightHuristic>(layerConnections);
	AssertCorrectNumberOfValuesProduced(testGen, expectedNumberOfConnections);
}

