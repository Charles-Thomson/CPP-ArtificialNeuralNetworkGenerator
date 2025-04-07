#include "ANNLayerObject.h"


#include <string>
#include <vector>

using std::string;
using std::vector;

ANNLayer::ANNLayer() {}

ANNLayer::ANNLayer(
	string _layerID,
	string _weightInitFunction, 
	string _activationFunction, 
	double _layerInputs, 
	double _layerOutputs) 
	: 
		layerID(_layerID),
		weightInitFunction(_weightInitFunction), 
		activationFunction(_activationFunction), 
		layerInputs(_layerInputs), 
		layerOutputs(_layerOutputs) {


	void PrintLayerData();

}


