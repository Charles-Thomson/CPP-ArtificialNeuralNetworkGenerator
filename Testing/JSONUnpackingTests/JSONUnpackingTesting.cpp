#include <gtest/gtest.h>
#include <string>

#include "UnpackingToConfigurationObjects/UnpackToConfigObjects.cpp"
#include "../CPP-JSONParser.h"
#include "Preprocessing/InputFileReadAndParse/InputFileRead.h"
#include "Preprocessing/InputFileReadAndParse/InputFileParse.h"


#include "../../PreProcessing/InstanceConfigObject/ANNConfigurationObject/ANNConfigObject.h"
#include "../../PreProcessing/InstanceConfigObject/ANNConfigurationObject/ANNLayerObject.h"
#include "../../PreProcessing/InstanceConfigObject/EnvironmentConfigurationObject/EnvironmentConfigObject.h"
#include "../../PreProcessing/InstanceConfigObject/HyperParameterConfigurationObject/HyperParameterConfigObject.h"

using std::cout;
using std::string;
using std::endl;

using JSON = shared_ptr<JSONValue>;

JSON ReadAndParseTestDataHelper() {
	string TestData = readInputFile();
	JSON TestJSON = ParseToJSON(TestData);

	return TestJSON;
}

void ValidateANNLayer(const ANNLayer& annLayer) {
	ASSERT_FALSE(annLayer.getLayerID().empty()) << "Layer Attribute can not be empty -> LayerID" << endl;
	ASSERT_FALSE(annLayer.getWeightInitFunction().empty()) << "Layer Attribute can not be empty -> weightInitFunction" << endl;
	ASSERT_FALSE(annLayer.getActivationFunction().empty()) << "Layer Attribute can not be empty -> activationFunction" << endl;
	ASSERT_GT(annLayer.getLayerInputs(), 0) << "Layer Attribute must be greater than zero -> layerInputs" << endl;
	ASSERT_GT(annLayer.getLayerOutputs(), 0) << "Layer Attribute must be greater than zero -> layerOutputs" << endl;
}

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


TEST(JSONUnpackingTesting, UnpackToEnvironmentConfigObj) {
	JSON TestJSON = ReadAndParseTestDataHelper();
	JSON EnvironmentJSONData = GetValueByKey(TestJSON, "environmentConfig");

	EnvironmentConfigObject testConfigObject = UnpackToEnvironmentConfigObj(EnvironmentJSONData);

	testConfigObject.PrintObjectAttributes();

	//Test point 
	ASSERT_TRUE(false);

}


