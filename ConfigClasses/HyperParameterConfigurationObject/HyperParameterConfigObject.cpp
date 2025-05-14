

#include "HyperParameterConfigObject.h"

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using std::string;
using std::vector;
using std::tuple;
using std::cout;
using std::endl;


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

void HyperParameterConfigObject::PrintObjectAttributes() {
    cout << "HyperParameterConfigObject Atributes " << endl;
    cout << "maxNumberOfGenerations : " << maxNumberOfGenerations << endl;
    cout << "maxGenerationSize : " << maxGenerationSize << endl;
    cout << "startingFitnessThreshold : " << startingFitnessThreshold << endl;
    cout << "startNewGenerationThreshold : " << startNewGenerationThreshold << endl;
    cout << "generationFailureThreshold : " << generationFailureThreshold << endl;
}