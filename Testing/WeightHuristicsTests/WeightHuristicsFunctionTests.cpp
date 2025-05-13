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
// @brief Testing the HeWeightHuristic weight generator
// Expected Result: 
// - Returns the requiered numebr of weights (layerconnections[0]*layerconnections[1])
// */

TEST(WeightHuristicsFunctionTesting, HeWeightHuristic) {
	vector<double> layerConnections = { 10,20 };
	
	Generator testGen = WeightHuristics_GeneratorFactory::create<HeWeightHuristic>(layerConnections);

	double expectedNumebrOfValues = layerConnections[0] * layerConnections[1];
	cout << "Expected number of layers : " << expectedNumebrOfValues << endl;

	AssertCorrectNumberOfValuesProduced(testGen, expectedNumebrOfValues);

}

