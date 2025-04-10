#include <string>
#include "../CPP-JSONParser.h"
#include "../../PreProcessing/InstanceConfigObject/ANNConfigurationObject/ANNConfigObject.h"
#include "../../PreProcessing/InstanceConfigObject/ANNConfigurationObject/ANNLayerObject.h"
#include "../../PreProcessing/InstanceConfigObject/EnvironmentConfigurationObject/EnvironmentConfigObject.h"
#include "../../PreProcessing/InstanceConfigObject/HyperParameterConfigurationObject/HyperParameterConfigObject.h"
#include "UnpackToConfigObjects.h"
#include <format>

using JSON = shared_ptr<JSONValue>;

using std::string;
using std::cout;
using std::endl;
using std::format;






//*
// @ brief Unpack JSON ANNLayer Configs to ANNLayer objects
// 
// Unpack the ANNLayerConfigs for the Given JSON to ANNLayer config objects, and 
// store in vector for return
// 
// @ param ANNLayerDataJSON The JSON data
// @ param numberOfANNLayers Number of Layer Configs to expect
//
// @ return ANNLayerConfigs Vector of ANNLayer objects
// 
// */
// Need to write tests for this function
vector<ANNLayer> unpackANNLayerConfigs(JSON& ANNLayerDataJSON, double& numberOfANNLayers) {
	vector<ANNLayer> ANNLayerConfigs; 

	for (double i = 0; numberOfANNLayers > i; i++) {
		string layerKey = format("layer{}", i);
		
		JSON layerJSON = GetValueByKey(ANNLayerDataJSON, layerKey);

		string layerID = GetValueByKeyWithType<string>(layerJSON, "layerID");

		string weightInitHeuristic = GetValueByKeyWithType<string>(layerJSON, "weightInitHeuristic");
		string activationFunction = GetValueByKeyWithType<string>(layerJSON, "activationFunction");

		double layerInputs = GetValueByKeyWithType<double>(layerJSON, "layerInputs");
		double layerOutputs = GetValueByKeyWithType<double>(layerJSON, "layerOutputs");

		ANNLayer newLayer = ANNLayer(layerID, weightInitHeuristic, activationFunction, layerInputs, layerOutputs);

		ANNLayerConfigs.push_back(newLayer);
	}
	return ANNLayerConfigs;
}


//*
// @ Brief Unpack ANNCongif from JSON to ANNCongifObj
// 
// Unpack the JSON for the ANNConfig to an ANNConfigObj 
// 
// @param JSONANNConfigData The ANNConfigData as JSON
// @return ANNConfigObject of the troed JSON
// 
// */
ANNConfigObject UnpackToANNCongifObj(JSON& ANNConfigJSONData) {

	double numberOfANNLayers = GetValueByKeyWithType<double>(ANNConfigJSONData, "numberOfLayers");

	JSON layerData = GetValueByKey(ANNConfigJSONData, "ANNLayers");

	vector<ANNLayer> ANNLLayersConfigs = unpackANNLayerConfigs(layerData, numberOfANNLayers);

	string GenerationFunction = GetValueByKeyWithType<string>(ANNConfigJSONData, "newGenerationCreationFunction");
	
	ANNConfigObject newANNConfigObj = ANNConfigObject(ANNLLayersConfigs, numberOfANNLayers, GenerationFunction);

	return newANNConfigObj;
}


HyperParameterConfigObject UnpackToHyperParameterConfigObj(JSON& HyperParameterJSONData) {
	double maxNumberOfGenerations = GetValueByKeyWithType<double>(HyperParameterJSONData, "maxNumberOfGenerations");
	double maxGenerationSize = GetValueByKeyWithType<double>(HyperParameterJSONData, "maxGenerationSize");
	double startingFitnessThreshold = GetValueByKeyWithType<double>(HyperParameterJSONData, "startingFitnessThreshold");
	double startNewGenerationThreshold = GetValueByKeyWithType<double>(HyperParameterJSONData, "startNewGenerationThreshold");
	double generationFailureThreshold = GetValueByKeyWithType<double>(HyperParameterJSONData, "generationFailureThreshold");

	HyperParameterConfigObject newHyperParameterConfigObj = HyperParameterConfigObject(
		maxNumberOfGenerations,
		maxGenerationSize,
		startingFitnessThreshold,
		startNewGenerationThreshold,
		generationFailureThreshold
	);

	return newHyperParameterConfigObj;
}

EnvironmentConfigObject UnpackToEnvironmentConfigObj(JSON& JSONEnvironmentConfigData) {

	vector<vector<double>> environmentMap = GetValueByKeyWithType<vector<vector<double>>>(JSONEnvironmentConfigData, "environmentMap");

	vector<double> environmentDimensions = GetValueByKeyWithType<vector<double>>(JSONEnvironmentConfigData, "environmentDimensions");


	vector<double> environmentStartCoordinates = GetValueByKeyWithType<vector<double>>(JSONEnvironmentConfigData, "environmentStartCoordinates");

	double environmentMaxActionCount = GetValueByKeyWithType<double>(JSONEnvironmentConfigData, "environmentMaxActionCount");


	EnvironmentConfigObject mewEnvironmentConfigObj = EnvironmentConfigObject(
		environmentMap,
		environmentDimensions,
		environmentStartCoordinates,
		environmentMaxActionCount
	);

	return mewEnvironmentConfigObj; 

}





//*
// @ brief Unpack JSON to Config Objects
// 
// Unpack the JSON of the input file into the repective Config Objects
// 
// @param JSONData The JSON representation of the InputFile
// 
// @return TODO: Will return the unpacked ConfigObjects
// */
void UnpackJSONToConfigObjects(JSON& JSONData) {

	ANNConfigObject ANNConfig;
	EnvironmentConfigObject EnvironmentConfig;
	HyperParameterConfigObject HyperParameterConfig;

	string searchKey = "instanceID";

	string InstanceID = GetValueByKeyWithType<string>(JSONData, searchKey);

	JSON ANNConfigJSONData = GetValueByKey(JSONData, "ANNConfig");
	JSON HyperParameterJSONData = GetValueByKey(JSONData, "HyperParameterConfig");
	JSON EnvironmentJSONData = GetValueByKey(JSONData, "environmentConfig");

	ANNConfig = UnpackToANNCongifObj(ANNConfigJSONData);
	HyperParameterConfig = UnpackToHyperParameterConfigObj(HyperParameterJSONData);
	EnvironmentConfig = UnpackToEnvironmentConfigObj(EnvironmentJSONData);

}







