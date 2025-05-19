#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H


#include <string>
#include <vector>
#include <tuple>

using std::string;
using std::vector;
using std::tuple;


class Environment {
public:

	Environment() {};
	~Environment() {};

	vector<double> getObservationDataFromEnvironment();
	
	
	tuple<int, double, bool> step();

	void removeGoal();

	double calcualteReward();

	bool terminationCheck(); 

	tuple<int, int> processAction();

	tuple<double, bool> getLocationValue();

private:
	int currentStep = 0;
	vector<tuple<int, int>> path = {};
	vector<vector<int>> enviromentMap = {};
	size_t maxActoins = 1;
	tuple<int, int> currentLocationInEnv;




};


#endif //! ENVIRONMENT_H