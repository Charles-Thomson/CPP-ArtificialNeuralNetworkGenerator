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


	tuple<int, int> getCurrentLocationInEnv() { 
		return currentLocationInEnv; 
	}

	void setCurrentLocationInEnv(tuple<int, int> newLoc) { 
		currentLocationInEnv = newLoc; 
	}

	int getCurrentStep() { 
		return currentStep;  
	}

	void setCurrentStep(int newValue) { 
		currentStep = newValue; 
	}

	void incrementStepCounter() {
		++currentStep;  
	}

	size_t getMaxActions() {
		return maxActoins;
	}

	void setMaxActions(int newValue) {
		maxActoins = newValue;
	}

private:
	int currentStep = 0;
	vector<tuple<int, int>> path = {};
	vector<vector<int>> enviromentMap = {};
	size_t maxActoins = 1;
	tuple<int, int> currentLocationInEnv;




};


#endif //! ENVIRONMENT_H