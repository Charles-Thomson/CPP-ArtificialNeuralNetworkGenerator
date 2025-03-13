#ifndef INSTANCE_OBJECT_H
#define INSTANCE_OBJECT_H

#include <string>
#include <vector>

#include "../ANNConfigurationObject/ANNConfigObject.h"
#include "../EnvironmentConfigurationObject/EnvironmentConfigObject.h"  // Fixed typo: no extra space
#include "../HyperParameterConfigurationObject/HyperParameterConfigObject.h"  // Fixed typo: no extra space

using std::string;
using std::vector;





class InstanceConfigObject {
private:
	ANNConfigObject ANNConfig;
	EnvironmentConfigObject EnvConfig;
	HyperParameterConfigObject HyperParameterConfig;

public:
	InstanceConfigObject();

	void setANNConfig(ANNConfigObject obj);

	ANNConfigObject getANNConfig();

	void setEnvConfig(EnvironmentConfigObject obj);

	EnvironmentConfigObject getEnvConfig();

	void setHyperParameterConfig(HyperParameterConfigObject obj);

	HyperParameterConfigObject getHyperParameterConfig();

};







#endif // INSTANCE_OBJECT_H



