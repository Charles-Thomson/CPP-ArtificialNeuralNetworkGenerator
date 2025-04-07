#ifndef ANN_LAYER_OBJECT_H

#define ANN_LAYER_OBJECT_H

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;
class ANNLayer {
private:
	string layerID;
	string weightInitFunction;
	string activationFunction;
	double layerInputs;
	double layerOutputs;

public:
	ANNLayer();
	ANNLayer(string _layerID, string _weightInitFunction, string _activationFunction, double _layerInputs, double _layerOutputs);


	void PrintLayerData() {
		cout << "Layer ID : " << layerID << endl;
		cout << "Weight Init Function : " << weightInitFunction << endl;
		cout << "Activation Function Function : " << activationFunction << endl;
		cout << "Number of Layer inputs : " << layerInputs << endl;
		cout << "Number of Layer Outputs : " << layerOutputs << endl;
	}

};
#endif // ANN_LAYER_OBJECT_H