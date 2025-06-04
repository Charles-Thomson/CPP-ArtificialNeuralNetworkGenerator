#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "DirectionEnumeration/DirectionalEnum.h"

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
	
	
	tuple<int, double, bool> step(DirectionalEnum action);

	void removeGoal();

	double calcualteReward();

	bool terminationCheck(); 

	tuple<int, int> processAction();

	bool checkIfNodeInPath(StateBasedNode& node);

	
	StateBasedNode& getNodeAtEnvironmentLocation(int& coordX, int& coordY);

	//*
	// @brife Helper returns current X coordinate
	// */
	int getCurrentXCoordinate() {
		return get<0>(currentLocationInEnv);
	
	}

	//*
	// @brife Helper returns current Y coordinate
	// */
	int getCurrentYCoordinate() {
		return get<1>(currentLocationInEnv);

	}

	void setCurrentLocationInEnv(tuple<int, int> newLoc) { 
		currentLocationInEnv = newLoc; 
	}

	int getCurrentStep() const { 
		return currentStep;  
	}

	void setCurrentStep(int newValue) { 
		currentStep = newValue; 
	}

	void incrementStepCounter() {
		++currentStep;  
	}

	size_t getMaxActions() const {
		return maxActoins;
	}

	void setMaxActions(int newValue) {
		maxActoins = newValue;
	}

	vector<vector<StateBasedNode>> getEnvironmentMap() {
		return enviromentMap;
	}

	void setEnvironmentMap(vector<vector<StateBasedNode>> envMap) {
		enviromentMap = envMap;
	}


private:
	int currentStep = 0;
	vector<StateBasedNode> path = {};
	vector<vector<StateBasedNode>> enviromentMap = {};
	size_t maxActoins = 1;
	tuple<int, int> currentLocationInEnv;




};


#endif //! ENVIRONMENT_H