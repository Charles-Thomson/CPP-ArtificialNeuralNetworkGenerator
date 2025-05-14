#ifndef HYPER_PARAMETER_CONFIG_OBJECT_H
#define HYPER_PARAMETER_CONFIG_OBJECT_H

#include <string>
#include <vector>

using std::string;
using std::vector;


class HyperParameterConfigObject {

public:
	double maxNumberOfGenerations;
	double maxGenerationSize;
	double startingFitnessThreshold;
	double startNewGenerationThreshold;
	double generationFailureThreshold;

	// Default Constructor
	HyperParameterConfigObject() : maxNumberOfGenerations(0), 
								   maxGenerationSize(0), 
		                           startingFitnessThreshold(0), 
		                           startNewGenerationThreshold(0),
		                           generationFailureThreshold(0){}

	HyperParameterConfigObject(
		double _maxNumberOfGenerations,
		double _maxGenerationSize,
		double _startingFitnessThreshold,
		double _startNewGenerationThreshold,
		double _generationFailureThreshold
	);

	void PrintObjectAttributes();



	
};

#endif //HYPER_PARAMETER_CONFIG_OBJECT_H