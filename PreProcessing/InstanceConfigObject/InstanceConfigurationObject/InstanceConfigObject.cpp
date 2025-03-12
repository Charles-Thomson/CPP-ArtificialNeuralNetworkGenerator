#include <string>
#include <vector>

#include "InstanceConfigObject.h"
#include "../ANNConfigurationObject/ANNConfigObject.h"
#include "../EnvironemntConfigurationObject/EnvironmentConfigObject.h "
#include "../HyperParameterConfigurationObject/HyperParameterConfigObject.h "

using std::string;
using std::vector;

InstanceConfigObject::InstanceConfigObject() {}

void InstanceConfigObject::setANNConfig(ANNConfigObject obj) {
	ANNConfig = obj;
};

void InstanceConfigObject::setEnvConfig(EnvironemntConfigObject obj) {
	EnvConfig = obj;
};

void InstanceConfigObject::setHyperParameterConfig(HyperParamterConfigObject obj) {
	HyperParameterConfig = obj;
};

ANNConfigObject InstanceConfigObject::getANNConfig() {
	return ANNConfig;
};

EnvironemntConfigObject InstanceConfigObject::getEnvConfig() {
	return EnvConfig;
};

HyperParamterConfigObject InstanceConfigObject::getHyperParameterConfig() {
	return HyperParameterConfig;
};