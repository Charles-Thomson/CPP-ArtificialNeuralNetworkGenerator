#include <string>
#include <vector>

#include "InstanceConfigObject.h"
#include "../ANNConfigurationObject/ANNConfigObject.h"
#include "../EnvironmentConfigurationObject/EnvironmentConfigObject.h"
#include "../HyperParameterConfigurationObject/HyperParameterConfigObject.h"

using std::string;
using std::vector;

InstanceConfigObject::InstanceConfigObject() {}

void InstanceConfigObject::setANNConfig(ANNConfigObject obj) {
	ANNConfig = obj;
};


void InstanceConfigObject::setHyperParameterConfig(HyperParameterConfigObject obj)
{
	HyperParameterConfig = obj;
};

ANNConfigObject InstanceConfigObject::getANNConfig() {
	return ANNConfig;
}

void InstanceConfigObject::setEnvConfig(EnvironmentConfigObject obj)
{
	EnvConfig = obj;
}
;

EnvironmentConfigObject InstanceConfigObject::getEnvConfig() {
	return EnvConfig;
};


HyperParameterConfigObject InstanceConfigObject::getHyperParameterConfig() {
	return HyperParameterConfig;
};