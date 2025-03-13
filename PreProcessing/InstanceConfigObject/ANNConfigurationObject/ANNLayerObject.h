#ifndef ANN_LAYER_OBJECT_H

#define ANN_LAYER_OBJECT_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class ANNLayer {
private:
	string weightInitFunction;
	string activationFunction;
	double layerInputs;
	double layerOutputs;

public:
	ANNLayer();
	ANNLayer(string _weightInitFunction, string _activationFunction, double _layerInputs, double _layerOutputs);

};
#endif // ANN_LAYER_OBJECT_H