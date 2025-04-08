#include "ANNConfigObject.h"

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;



ANNConfigObject::ANNConfigObject(vector<ANNLayer> _ANNLayersConfigs,
								 double _numOfLayers,
								 string _GenerationFunction ) :
	ANNLayersConfigs(_ANNLayersConfigs),
	numOfLayers(_numOfLayers),
	GenerationFunction(_GenerationFunction) {
}

void ANNConfigObject::PrintObjectAttributes() {
	cout << "ANNConfigObject Attributes" << endl;
	cout << "Generation Function : " << GenerationFunction << endl;
	cout << "Number of ANN Layers : " << numOfLayers << endl;
	cout << "Layer Configs : " << endl;

	for (ANNLayer layer : ANNLayersConfigs) {
		cout << "" << endl; // Formatting 
		layer.PrintLayerData();
	}

};

