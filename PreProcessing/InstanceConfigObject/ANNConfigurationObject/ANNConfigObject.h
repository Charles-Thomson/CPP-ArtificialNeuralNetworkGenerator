#ifndef ANN_CONFIG_OBJECT_H
#define ANN_CONFIG_OBJECT_H

#include <string>
#include <vector>

#include "ANNLayerObject.h"


//#include "../EnvironemntConfigurationObject/EnvironmentConfigObject.h"

using std::string;
using std::vector;


class ANNConfigObject {
	private:
		vector<ANNLayer> ANNLayersConfigs;
		double numOfLayers;
		string GenerationFunction;

	public:

		ANNConfigObject()
			: numOfLayers(0), GenerationFunction("default") {
		}

		//Constructor
		ANNConfigObject(
			vector<ANNLayer> _ANNLayersConfigs,
			double _numOfLayers,
			string _GenerationFunction
		);

		// Destructor (if needed)
		~ANNConfigObject() = default;
};

#endif //ANN_CONFIG_OBJECT_H