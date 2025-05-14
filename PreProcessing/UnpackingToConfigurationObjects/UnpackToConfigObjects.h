#include <string>
#include "../CPP-JSONParser.h"
#include "../../ConfigClasses/ANNConfigurationObject/ANNConfigObject.h"
#include "../../ConfigClasses/ANNConfigurationObject/ANNLayerObject.h"
#include "../../ConfigClasses/EnvironmentConfigurationObject/EnvironmentConfigObject.h "
#include "../../ConfigClasses/HyperParameterConfigurationObject/HyperParameterConfigObject.h"

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