#include "ANNConfigObject.h"

#include <string>
#include <vector>

using std::string;
using std::vector;



ANNConfigObject::ANNConfigObject(vector<ANNLayer> _ANNLayersConfigs,
								 double _numOfLayers,
								 string _GenerationFunction ) :
	ANNLayersConfigs(_ANNLayersConfigs),
	numOfLayers(_numOfLayers),
	GenerationFunction(_GenerationFunction) {}

