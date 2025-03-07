#include "EnvironmentConfigObject.h"

#include <string>
#include <vector>
#include<tuple>

using std::string;
using std::vector;
using std::tuple;



EnvironemntConfigObject::EnvironemntConfigObject(
	vector<vector<double>> _environmentMap,
	tuple<double, double> _environmentMapDimensions,
	tuple<double, double> _environmentMapStartLocation,
	double _maxActionsInEnvironment
) :
	environmentMap(_environmentMap),
	environmentMapDimensions(_environmentMapDimensions),
	environmentMapStartLocation(_environmentMapStartLocation),
	maxActionsInEnvironment(_maxActionsInEnvironment) {}