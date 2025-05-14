#include <gtest/gtest.h>
#include <string>

#include "UnpackingToConfigurationObjects/UnpackToConfigObjects.cpp"
#include "../CPP-JSONParser.h"
#include "Preprocessing/InputFileReadAndParse/InputFileRead.h"
#include "Preprocessing/InputFileReadAndParse/InputFileParse.h"


#include "../../ConfigClasses/ANNConfigurationObject/ANNConfigObject.h"
#include "../../ConfigClasses/ANNConfigurationObject/ANNLayerObject.h"
#include "../../ConfigClasses/EnvironmentConfigurationObject/EnvironmentConfigObject.h"
#include "../../ConfigClasses/HyperParameterConfigurationObject/HyperParameterConfigObject.h"

using std::cout;
using std::string;
using std::endl;

using JSON = shared_ptr<JSONValue>;

//*
// @ brief Helper to Read and Parse input data
// 
// */
JSON ReadAndParseTestDataHelper() {
	string TestData = readInputFile();
	JSON TestJSON = ParseToJSON(TestData);

	return TestJSON;
}

//*
// @ brief Helper to validate ANNLayers
// 
// */
void ValidateANNLayer(const ANNLayer& annLayer) {
	ASSERT_FALSE(annLayer.getLayerID().empty()) << "Layer Attribute can not be empty -> LayerID" << endl;
	ASSERT_FALSE(annLayer.getWeightInitFunction().empty()) << "Layer Attribute can not be empty -> weightInitFunction" << endl;
	ASSERT_FALSE(annLayer.getActivationFunction().empty()) << "Layer Attribute can not be empty -> activationFunction" << endl;
	ASSERT_GT(annLayer.getLayerInputs(), 0) << "Layer Attribute must be greater than zero -> layerInputs" << endl;
	ASSERT_GT(annLayer.getLayerOutputs(), 0) << "Layer Attribute must be greater than zero -> layerOutputs" << endl;
}

//*
// @ brief Testing unpacking of JSON to ANNConfigObj
// 
// */
TEST(JSONUnpackingTesting, UnpackToANNConfigObj) {
	
	JSON TestJSON = ReadAndParseTestDataHelper();

	JSON ANNConfigData = GetValueByKey(TestJSON, "ANNConfig");
	ANNConfigObject testConfigObject = UnpackToANNCongifObj(ANNConfigData);

	testConfigObject.PrintObjectAttributes();

	ASSERT_FALSE(testConfigObject.GenerationFunction.empty()) << "Attribute can not be null/empty -> GenerationFunction" << endl;

	ASSERT_GT(testConfigObject.numOfLayers, 0) << "Attribute must be greater than zero -> numOfLayers" << endl;
	ASSERT_GT(testConfigObject.ANNLayersConfigs.size(), 0) << "Attribute must be greater than zero -> ANNLayersConfigs" << endl;
	ASSERT_EQ(testConfigObject.ANNLayersConfigs.size(), testConfigObject.numOfLayers);

	for (ANNLayer annLayer : testConfigObject.ANNLayersConfigs) {
		ValidateANNLayer(annLayer);
	}
}

//*
// @ brief Testing unpacking of JSON to HyperParameterConfigObj
// 
// */
TEST(JSONUnpackingTesting, UnpackToHyperParameterConfigObj) {
	JSON TestJSON = ReadAndParseTestDataHelper();

	JSON HyperParameterConfigData = GetValueByKey(TestJSON, "HyperParameterConfig");

	HyperParameterConfigObject testConfigObject = UnpackToHyperParameterConfigObj(HyperParameterConfigData);

	ASSERT_GT(testConfigObject.maxNumberOfGenerations, 0) << "Attribute must be greater than zero -> maxNumberOfGenerations" << endl;
	ASSERT_GT(testConfigObject.maxGenerationSize, 0) << "Attribute must be greater than zero -> maxGenerationSize" << endl;
	ASSERT_GT(testConfigObject.startingFitnessThreshold, 0) << "Attribute must be greater than zero -> startingFitnessThreshold" << endl;
	ASSERT_GT(testConfigObject.startNewGenerationThreshold, 0) << "Attribute must be greater than zero -> startNewGenerationThreshold" << endl;
	ASSERT_GT(testConfigObject.generationFailureThreshold, 0) << "Attribute must be greater than zero -> generationFailureThreshold" << endl;

	testConfigObject.PrintObjectAttributes();
}

void TestEnvironmentMapLayers(vector<double> mapLayer, double expectedSize)  {
	
	ASSERT_EQ(mapLayer.size(), expectedSize) << " Map layer size is rgeater than declared Environment Dimension" << endl;
}

//*
// @ brief Testing unpacking of JSON to EnvironmentConfigObj
// 
// */
TEST(JSONUnpackingTesting, UnpackToEnvironmentConfigObj) {
	JSON TestJSON = ReadAndParseTestDataHelper();
	JSON EnvironmentJSONData = GetValueByKey(TestJSON, "environmentConfig");

	EnvironmentConfigObject testConfigObject = UnpackToEnvironmentConfigObj(EnvironmentJSONData);

	testConfigObject.PrintObjectAttributes();

	ASSERT_GT(testConfigObject.getMaxActionsInEnvironment(), 0) << "Attribute must be greater than zero -> MaxActionsInEnvironment" << endl;

	vector<double> envDimensions = testConfigObject.getEnvironmentMapDimensions();
	ASSERT_EQ(envDimensions.size(), 2) << "Atribute must be of size 2  -> environmentMapDimensions" << endl;
	ASSERT_GT(envDimensions[0], 0) << "Attribute must be greater than zero -> environmentMapDimensions(x)" << endl;
	ASSERT_GT(envDimensions[1], 0) << "Attribute must be greater than zero -> environmentMapDimensions(y)" << endl;

	vector<double> envStartLocation = testConfigObject.getEnvironmentMapStartLocation();
	ASSERT_EQ(envStartLocation.size(), 2) << "Atribute must be of size 2  -> environmentMapStartLocation" << endl;
	ASSERT_LE(envStartLocation[0], envDimensions[0]) << "Start Location(x) must be less than the max environment dimension(x) -> environmentMapStartLocation" << endl;
	ASSERT_LE(envStartLocation[1], envDimensions[1]) << "Start Location(y) must be less than the max environment dimension(y) -> environmentMapStartLocation" << endl;

	vector<vector<double>> envMap = testConfigObject.getEnvironmentMap();

	ASSERT_GT(envMap.size(), 0) << "Environment map must be gretaer than zero -> environmentMap" << endl;
	ASSERT_EQ(envMap.size(), envDimensions[0]) << "Envionment Map and delclared Environment Map size are not equal -> environmentMap" << endl;
	
	for (vector<double> mapLayer : envMap) {
		TestEnvironmentMapLayers(mapLayer, envDimensions[1]);
	}
}


