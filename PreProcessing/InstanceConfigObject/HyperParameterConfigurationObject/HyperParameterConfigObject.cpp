

#include "HyperParameterConfigObject.h"

#include <string>
#include <vector>
#include<tuple>

using std::string;
using std::vector;
using std::tuple;

HyperParameterConfigObject::HyperParameterConfigObject(
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
    generationFailureThreshold(_generationFailureThreshold) {
    // Any additional setup or validation can be added here if needed
}

