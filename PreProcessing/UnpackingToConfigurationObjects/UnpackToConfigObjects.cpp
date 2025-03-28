#include <string>
#include "../CPP-JSONParser.h"
#include "../../PreProcessing/InstanceConfigObject/ANNConfigurationObject/ANNConfigObject.h"
#include "../../PreProcessing/InstanceConfigObject/ANNConfigurationObject/ANNLayerObject.h"
#include "../../PreProcessing/InstanceConfigObject/EnvironmentConfigurationObject/EnvironmentConfigObject.h"
#include "../../PreProcessing/InstanceConfigObject/HyperParameterConfigurationObject/HyperParameterConfigObject.h"

using JSON = shared_ptr<JSONValue>;

using std::string;
using std::cout;
using std::endl;



void UnpackJSONToConfigObjects(JSON& JSONData) {

	ANNConfigObject ANNConfig; 
	EnvironmentConfigObject EnvironmentConfig;
	HyperParameterConfigObject HyperParameterConfig;

	cout << "UnpackJSONToConfigObjects - > In the function" << endl;





	



}

//ANNConfigObject UnpackJSONToANNConfigObject() {
//
//
//
//
//
//
//}