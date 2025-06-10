#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "DirectionEnumeration/DirectionalEnum.h"
#include "EnvironmentNodes/StateBased/StateBasedNode.h"

#include <string>
#include <vector>
#include <tuple>

using std::string;
using std::vector;
using std::tuple;


class Environment {
public:
	vector<StateBasedNode> path = {};
	int pathLength = 0;
	

	Environment() {};
	~Environment() {};

	double calculateOpenNodeReward(double& baseOpenNodeReward);

	vector<double> getObservationDataFromEnvironment(StateBasedNode& obeservationPoint);
	
	
	tuple<int, double, bool> step(DirectionalEnum action);

	void removeGoal();

	double calcualteReward(StateBasedNode& newNodeLocation);

	bool terminationCheck(); 

	tuple<int, int> processAction();

	bool checkIfNodeInPath(StateBasedNode& node);

	void addNodeToPath(StateBasedNode& node);

	
	StateBasedNode& getNodeAtEnvironmentLocation(int& coordX, int& coordY);


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
		return maxActions;
	}

	void setMaxActions(int newValue) {
		maxActions = newValue;
	}

	vector<vector<StateBasedNode>> getEnvironmentMap() {
		return enviromentMap;
	}

	void setEnvironmentMap(vector<vector<StateBasedNode>> envMap) {
		enviromentMap = envMap;
	}

	StateBasedNode getCurrentNode() {
		return currentNode;
	}

	void setCurrentNode(StateBasedNode newNode) {
		currentNode = newNode;
	}

	void incrementActionCount() {
		++acctionCount;
	}


private:
	int currentStep = 0;
	
	vector<vector<StateBasedNode>> enviromentMap = {};
	int maxActions = 1;
	int acctionCount = 0;
	StateBasedNode currentNode;


};


#endif //! ENVIRONMENT_H