#ifndef WORK_ITEM_H
#define WORK_ITEM_H

#include <string>
#include "ConfigClasses/EnvironmentConfigurationObject/EnvironmentConfigObject.h "

using std::string;


struct WorkItem {
	string instanceID;
	string agent_generator;
	EnvironmentConfigObject envConfig;

	int maxNumberOfGenerations;
	int maxGenerationSize;
	int startingFitnessThreshold;
	int startNewGenerationThreshold;
	int generationFailureThreshold;

};




#endif // !WORK_ITEM_H