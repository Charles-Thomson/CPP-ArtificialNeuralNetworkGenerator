#include "ANNLayerObject.h"
#include "ANNLayerObject.h"
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

string ANNLayer::getLayerID() const 
{
	return layerID;
}

void ANNLayer::setLayerID(string newLayerID)
{
	layerID = newLayerID;
}

string ANNLayer::getWeightInitFunction() const 
{
	return weightInitFunction;
}

void ANNLayer::setWeightInitFunction(string newWeightInitFunction) 
{
	weightInitFunction = newWeightInitFunction;

}

string ANNLayer::getActivationFunction() const
{
	return weightInitFunction;
}

void ANNLayer::setActivationFunction(string newActivationFunction)
{
	activationFunction = newActivationFunction;

}

double ANNLayer::getLayerInputs() const 
{
	return layerInputs;
}

void ANNLayer::setLayerInputs(double newLayerInputs) 
{
	layerInputs = newLayerInputs;
}

double ANNLayer::getLayerOutputs() const
{
	return layerOutputs;
}

void ANNLayer::setLayerOutputs(double newLayerOutputs) {
	layerOutputs = newLayerOutputs;


}




