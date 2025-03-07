#include "ANNLayerObject.h"


#include <string>
#include <vector>

using std::string;
using std::vector;

ANNLayer::ANNLayer(
	string _weightInitFunction, 
	string _activationFunction, 
	double _layerInputs, 
	double _layerOutputs) 
	: weightInitFunction(_weightInitFunction), 
	  activationFunction(_activationFunction), 
	  layerInputs(_layerInputs), 
	  layerOutputs(_layerOutputs) {}