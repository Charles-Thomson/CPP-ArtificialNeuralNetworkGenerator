#include "EnvironmentConfigObject.h"

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using std::string;
using std::vector;
using std::tuple;
using std::endl;
using std::cout;


EnvironmentConfigObject::EnvironmentConfigObject(
	vector<vector<double>> _environmentMap,
	vector<double> _environmentMapDimensions,
	vector<double> _environmentMapStartLocation,
	double _maxActionsInEnvironment
) :
	environmentMap(_environmentMap),
	environmentMapDimensions(_environmentMapDimensions),
	environmentMapStartLocation(_environmentMapStartLocation),
	maxActionsInEnvironment(_maxActionsInEnvironment) {}



vector<vector<double>> EnvironmentConfigObject::getEnvironmentMap() const
{
	return environmentMap;
}

void EnvironmentConfigObject::setEnvironmentMap(vector<vector<double>> newEnvironmentMap)
{
	environmentMap = newEnvironmentMap;
}

vector<double> EnvironmentConfigObject::getEnvironmentMapDimensions() const
{
	return environmentMapDimensions;
}

void EnvironmentConfigObject::setEnvironmentMapDimensions(vector<double> newEnvironmentMapDimensions)
{
	environmentMapDimensions = newEnvironmentMapDimensions;
}

vector<double> EnvironmentConfigObject::getEnvironmentMapStartLocation() const
{
	return environmentMapStartLocation;
}

void EnvironmentConfigObject::setEnvironmentMapStartLocation(vector<double> newEnvironmentMapStartLocation)
{
	environmentMapStartLocation = newEnvironmentMapStartLocation;
}

double EnvironmentConfigObject::getMaxActionsInEnvironment() const
{
	return maxActionsInEnvironment;
}

void EnvironmentConfigObject::setMaxActionsInEnvironment(double newMaxActionsInEnvironment)
{
	maxActionsInEnvironment = newMaxActionsInEnvironment;

}







// Issue relating to the unpacking of the array 
// I expect the issue is due to the cector storing pointers
// May have to convert the vector<pointer> to vector<held type>
void EnvironmentConfigObject::PrintObjectAttributes() {
	cout << "EnvironmentConfigObject Attributes" << endl;
	cout << "maxActionsInEnvironment : " << maxActionsInEnvironment << endl;
	cout << "environmentMapDimensions : " << endl;

	for (auto& val : environmentMapDimensions) {
		cout << val << " ";
	};
	cout << " " << endl; // Formatting
	cout << "environmentMapStartLocation" << endl;
	for (auto& val : environmentMapStartLocation) {
		cout << val << " ";

	};
	cout << " " << endl; // Formatting
	cout << "environmentMap" << endl;
	cout << "Environment Map Rows : " << environmentMap.size() << endl;
	cout << " " << endl; // Formatting
	for (vector<double>& row : environmentMap) {
		for (auto& val : row) {
			cout << val << " ";

		};
		cout << " " << endl;
	};
}
