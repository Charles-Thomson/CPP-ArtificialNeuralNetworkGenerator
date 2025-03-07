

#include "HyperParameterConfigObject.h"

#include <string>
#include <vector>
#include<tuple>

using std::string;
using std::vector;
using std::tuple;

HyperParamterConfigObject::HyperParamterConfigObject(
	double _maxNumberOfGenerations,
	double _maxGenerationSize,
	double _startingFitnessThreshold,
	double _startNewGenerationThreshold,
	double _generationFailureThreshold
) :
	maxNumberOfGenerations(_maxNumberOfGenerations),
	maxGenerationSize(_maxGenerationSize),
	startingFitnessThreshold(_startingFitnessThreshold),
	startNewGenerationThreshold(_startNewGenerationThreshold),
	generationFailureThreshold(_generationFailureThreshold){
}

