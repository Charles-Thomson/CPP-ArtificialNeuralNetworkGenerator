#ifndef ENVIRONEMNT_CONFIG_OBJECT_H
#define ENVIRONEMNT_CONFIG_OBJECT_H

#include <string>
#include <vector>
#include<tuple>

using std::string;
using std::vector;
using std::tuple;

class EnvironemntConfigObject {
private:
	vector<vector<double>> environmentMap;
	tuple<double, double> environmentMapDimensions;
	tuple<double, double> environmentMapStartLocation;
	double maxActionsInEnvironment;
		 
public:
	EnvironemntConfigObject(
		vector<vector<double>> environmentMap,
		tuple<double, double> environmentMapDimensions,
		tuple<double, double> environmentMapStartLocation,
		double maxActionsInEnvironment);


};







#endif ENVIRONEMNT_CONFIG_OBJECT_H