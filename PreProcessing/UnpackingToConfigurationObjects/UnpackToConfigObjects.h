#include <string>
#include "../CPP-JSONParser.h"
#include "../../PreProcessing/InstanceConfigObject/ANNConfigurationObject/ANNConfigObject.h"
#include "../../PreProcessing/InstanceConfigObject/ANNConfigurationObject/ANNLayerObject.h"
#include "../../PreProcessing/InstanceConfigObject/EnvironmentConfigurationObject/EnvironmentConfigObject.h"
#include "../../PreProcessing/InstanceConfigObject/HyperParameterConfigurationObject/HyperParameterConfigObject.h"

#include <format>

using JSON = shared_ptr<JSONValue>;

using std::string;
using std::cout;
using std::endl;
using std::format;




vector<ANNLayer> unpackANNLayerConfigs(JSON& ANNLayerDataJSON, double& numberOfANNLayers); 

ANNConfigObject UnpackToANNCongifObj(JSON& ANNConfigJSONData); 

HyperParameterConfigObject UnpackToHyperParameterConfigObj(JSON& HyperParameterJSONData);

EnvironmentConfigObject UnpackToEnvironmentConfigObj(JSON& JSONEnvironmentConfigData);