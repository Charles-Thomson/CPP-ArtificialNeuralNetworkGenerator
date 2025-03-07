#include <string>
#include <vector>

using std::string;
using std::vector;


class HyperParamterConfigObject {
public:
	double maxNumberOfGenerations;
	double maxGenerationSize;
	double startingFitnessThreshold;
	double startNewGenerationThreshold;
	double generationFailureThreshold;

private:

	HyperParamterConfigObject(
	double _maxNumberOfGenerations,
	double _maxGenerationSize,
	double _startingFitnessThreshold,
	double _startNewGenerationThreshold,
	double _generationFailureThreshold
	)
	

	

};