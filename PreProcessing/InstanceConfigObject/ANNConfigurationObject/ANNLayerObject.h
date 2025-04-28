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

	string getLayerID() const;
	void setLayerID(string newLayerID);

	string getWeightInitFunction() const;
	void setWeightInitFunction(string newWeightInitFunction) ;

	string getActivationFunction() const;
	void setActivationFunction(string newActivationFunction);

	double getLayerInputs() const;
	void setLayerInputs(double newLayerInputs);

	double getLayerOutputs() const;
	void setLayerOutputs(double newLayerOutputs);








	void PrintLayerData() {
		cout << "Layer ID : " << layerID << endl;
		cout << "Weight Init Function : " << weightInitFunction << endl;
		cout << "Activation Function Function : " << activationFunction << endl;
		cout << "Number of Layer inputs : " << layerInputs << endl;
		cout << "Number of Layer Outputs : " << layerOutputs << endl;
	}

};
#endif // ANN_LAYER_OBJECT_H