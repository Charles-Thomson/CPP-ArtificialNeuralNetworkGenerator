#ifndef INSTANCE_OBJECT_H
#define INSTANCE_OBJECT_H

#include <string>
#include <vector>

#include "../ANNConfigurationObject/ANNConfigObject.h"
#include "../EnvironemntConfigurationObject/EnvironmentConfigObject.h "
#include "../HyperParameterConfigurationObject/HyperParameterConfigObject.h "

using std::string;
using std::vector;





class InstanceConfigObject{
private:
	ANNConfigObject ANNConfig;
	EnvironemntConfigObject EnvConfig;
	HyperParamterConfigObject HyperParameterConfig;

public:
	InstanceConfigObject();

	
	void setANNConfig(ANNConfigObject obj);

	ANNConfigObject getANNConfig();

	void setEnvConfig(EnvironemntConfigObject obj);

	EnvironemntConfigObject getEnvConfig();

	void setHyperParameterConfig(HyperParamterConfigObject obj);

	HyperParamterConfigObject getHyperParameterConfig();





}







#endif INSTANCE_OBJECT_H



