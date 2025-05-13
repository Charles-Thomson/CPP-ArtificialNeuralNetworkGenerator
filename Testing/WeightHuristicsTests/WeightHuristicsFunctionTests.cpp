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
void AssertCorrectNumberOfValuesProduced(vector<double> collatedGeneratorValues, double expectedNumebrOfValues) {
	
	SCOPED_TRACE("The numebr of expected values does not equal the numebr of produced values");
	ASSERT_DOUBLE_EQ(collatedGeneratorValues.size(), expectedNumebrOfValues);
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
// @ Brief Collate all values from a generator
// 
// Collate all values from generator into a vector
// 
// @param gen - Generator
// @return vector<double> - Collated Generator values
// */
vector<double> CollateGeneratorValuesToVector(Generator& gen) {
	vector<double> collatedValues;
	while (gen.next()) {
		collatedValues.push_back(gen.value());
	}
	return collatedValues;
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

	vector<double> collatedGeneratorValues = CollateGeneratorValuesToVector(testGen);
	AssertCorrectNumberOfValuesProduced(collatedGeneratorValues, expectedNumebrOfValues);
}

// Next, test the mean of Xavier weights is close / within a range of 0.0 
// sum weights / total weights == 0.0 +- 0.05

//*
// @ Brief Assert collated values are within a range of the expected mean
// 
// Assert that the collated values of a generator are within a tollerable variance of the expected mean
// 
// @parma collatedValues - The collated values of a Generator
// @prama expectedMean - The expected mean
// @param acceptableVariance - Limit of acceptable variance from the mean
// */
void AssertMeanIsWithinRange(vector<double> collatedValues, double expectedMean, double acceptableVariance) {
	double actualMean; 
	double valuesTotal = 0;
	double elementsTotal = 0;

	for (double value : collatedValues) {
		cout << value << endl;
		valuesTotal += value;
		elementsTotal += 1;
	}
	if (valuesTotal > 0 && elementsTotal > 0) {
		actualMean = valuesTotal / elementsTotal;
	}
	
	double meanUpperBounds = expectedMean + acceptableVariance;
	double meanLowerBounds = expectedMean - acceptableVariance;
	
	SCOPED_TRACE("Mean subceeds accptable variance");
	ASSERT_GT(actualMean, meanLowerBounds);
	SCOPED_TRACE("Mean exceeds accptable variance");
	ASSERT_LT(actualMean, meanUpperBounds);
}


//*
// @ Brief Testing the Xavier Weight Huristic
// Expected Result: 
// - The Returned Generator produces the requiere number of weights
// */

TEST(WeightHuristicsFunctionTesting, XavierHuristic) {
	vector<double> layerConnections = { 10,20 };
	double expectedNumebrOfValues = layerConnections[0] * layerConnections[1];

	Generator testGen = RetrieveGeneratorOfHuristicsType<XavierWeightHuristic>(layerConnections);
	vector<double> collatedGeneratorValues = CollateGeneratorValuesToVector(testGen);
	AssertCorrectNumberOfValuesProduced(collatedGeneratorValues, expectedNumebrOfValues);
	AssertMeanIsWithinRange(collatedGeneratorValues, 0.0, 0.25);
}

//*
// @ Brief Test if producecd generator values of Xavier Uniform Huristic are valid
// 
// Test if produced weights fall within the upper and lower bounds
// 
// @param collatedWeights - The collated weights form the generator
// @param inputLayerConnections - number of inputs into the layer
// @param outputLayerConnections - number of outputs from the layer
// */
void textXavierUniformWeights(vector<double> collatedWeights, double inputLayerConnections, double outputLayerConnections) {

	double limit = sqrt(6.0) / sqrt(inputLayerConnections + outputLayerConnections);

	for (double weight : collatedWeights) {
		SCOPED_TRACE("Weight exceeds upper limit");
		ASSERT_GT(limit, weight);
		SCOPED_TRACE("Weight falls subceeds lower limit");
		ASSERT_LT(-limit, weight);
	};
	
}

//*
// @ Brief Testing the Xavier Uniform Weight Huristic
// Expected Result: 
// - The Returned Generator produces the requiere number of weights
// */

TEST(WeightHuristicsFunctionTesting, XavierUniformHuristic) {
	vector<double> layerConnections = { 10,20 };
	double expectedNumebrOfValues = layerConnections[0] * layerConnections[1];

	Generator testGen = RetrieveGeneratorOfHuristicsType<XavierUniformWeightHuristic>(layerConnections);
	vector<double> collatedGeneratorValues = CollateGeneratorValuesToVector(testGen);
	AssertCorrectNumberOfValuesProduced(collatedGeneratorValues, expectedNumebrOfValues);
	textXavierUniformWeights(collatedGeneratorValues, layerConnections[0], layerConnections[1]);
	

}

