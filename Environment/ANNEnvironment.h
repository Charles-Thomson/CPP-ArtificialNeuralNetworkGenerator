#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "DirectionEnumeration/DirectionalEnum.h"
#include "EnvironmentNodes/StateBased/StateBasedNode.h"
#include "DirectionEnumeration/DirectionalEnum.h"

#include <string>
#include <vector>
#include <tuple>

using std::string;
using std::vector;
using std::tuple;

using Direction = DirectionalEnum::Direction;

class Environment {
public:
	vector<StateBasedNode> path = {};
	
	Environment() {};
	~Environment() {};

	double calculateOpenNodeReward(double& baseOpenNodeReward);

	vector<double> getObservationDataFromEnvironment(StateBasedNode& obeservationPoint);
	
	
	tuple<StateBasedNode, double, bool> step(Direction& action);

	void removeGoal(StateBasedNode& node);

	double calculateReward(StateBasedNode& newNodeLocation);

	bool nodeTerminationCheck(StateBasedNode& ndode); 

	bool boundryTerminationCheck(pair<int,int>& coords);

	bool checkIfNodeInPath(StateBasedNode& node);

	void addNodeToPath(StateBasedNode& node);

	pair<int, int> determineNewCoordinates(Direction& dir);

	
	StateBasedNode& getNodeAtEnvironmentLocation(int& coordX, int& coordY);

	size_t getMaxActions() const {
		return maxActions;
	}

	void setMaxActions(int newValue) {
		maxActions = newValue;
	}

	void incrementActionCount() {
		++actionCount;
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

	

	int getActionCount() {
		return actionCount;
	};

	pair<int, int> getEnviromentMapDimensions() {
		return enviromentMapDimensions;
	
	}

	void setEnviromentMapDimensions(pair<int, int> dim) {
		enviromentMapDimensions = dim;
	}


private:
	pair<int, int> enviromentMapDimensions;
	vector<vector<StateBasedNode>> enviromentMap = {};
	int maxActions = 1;
	int actionCount = 0;
	StateBasedNode currentNode;


};


#endif //! ENVIRONMENT_H