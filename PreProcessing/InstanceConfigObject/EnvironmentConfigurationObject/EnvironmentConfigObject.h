#ifndef ENVIRONEMNT_CONFIG_OBJECT_H
#define ENVIRONEMNT_CONFIG_OBJECT_H

#include <string>
#include <vector>
#include<tuple>

using std::string;
using std::vector;
using std::tuple;

class EnvironmentConfigObject {
private:
	vector<vector<double>> environmentMap;
	vector<double> environmentMapDimensions;
	vector<double> environmentMapStartLocation;
	double maxActionsInEnvironment;
		 
public:
	// Default Constructor 
	EnvironmentConfigObject()
		: environmentMap({ {} }), environmentMapDimensions({ 0,0 }), environmentMapStartLocation{0,0}, maxActionsInEnvironment(0){
	}


	EnvironmentConfigObject(
		vector<vector<double>> environmentMap,
		vector<double> environmentMapDimensions,
		vector<double> environmentMapStartLocation,
		double maxActionsInEnvironment);

	void PrintObjectAttributes();



	vector<vector<double>> getEnvironmentMap() const;
	void setEnvironmentMap(vector<vector<double>> newEnvironmentMap);

	vector<double> getEnvironmentMapDimensions() const;
	void setEnvironmentMapDimensions(vector<double> newEnvironmentMapDimensions);

	vector<double> getEnvironmentMapStartLocation() const;
	void setEnvironmentMapStartLocation(vector<double> newEnvironmentMapStartLocation);

	double getMaxActionsInEnvironment() const;
	void setMaxActionsInEnvironment(double newMaxActionsInEnvironment);



};







#endif ENVIRONEMNT_CONFIG_OBJECT_H