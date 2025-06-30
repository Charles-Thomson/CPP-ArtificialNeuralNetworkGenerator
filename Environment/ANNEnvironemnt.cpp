#include "ANNEnvironment.h"
#include "EnvironmentObservtions/StateBased2DEnvironmentObservation.h"
#include "EnvironmentNodes/StateBased/StateBasedNode.h"
#include "DirectionEnumeration/DirectionalEnum.h"

#include <string>
#include <vector>
#include <tuple>
#include <cassert>
#include <fmt/format.h>


using std::string;
using std::vector;
using std::tuple;
using std::out_of_range;
using fmt::format;
using std::endl;
using std::cout;


// C++20 - compatibility issue potential
using enum DirectionalEnum::Direction;

using Direction = DirectionalEnum::Direction;

//*
// @ Brife Get the value at the curent location in the environment
// @ param int coordX - x coordinate 
// @ param int coordY - y coordinate 
// @ return StateBasedNode - node at location coordY,coordX (inverted)  
// */
StateBasedNode Environment::getNodeAtEnvironmentLocation(int coordX, int coordY) {

	vector<vector<StateBasedNode>> env = getEnvironmentMap();

	// Inverted on return as the maze is generated from top left 
	return env[coordX][coordY];
}




//*
// @ Brief Determine if action taken results in termination
// 
// */
bool Environment::nodeTerminationCheck(StateBasedNode& node) {

	if (node.state == StateBasedNode::State::OBSTICAL) {
		return true;
	}

	return false;
}

//*
// @brife Check if given coords fall outside of acceptable range
// Check if the given x,y coords fall within the environment, else set termination
// flag to be true
// 
// @param coords - coords to be checked
// @return true if terminating 
// */
bool Environment::boundryTerminationCheck(pair<int, int>& coords) {

	if (coords.first > enviromentMapDimensions.first || coords.first < 0) {
		cout << "boundryTerminationCheck -> Terminting " << endl;
		return true;
	}

	if (coords.second > enviromentMapDimensions.second || coords.second < 0) {
		cout << "boundryTerminationCheck -> Terminting " << endl;
		return true;
	}
	
	return false;
}

//*
// @brife Apply a given offset to a set of cooridnates
// 
// 
// @param currentCoords - Coordinates to be offset
// @param offSet - the offset to be applied
// @ return pair<int,int> - Coordinates with offset applied
// */
pair<int, int> applyOffsetToCoords(pair<int, int>& currentCoords, pair<int, int>& offSet) {
	int newX = currentCoords.first + offSet.first;
	int newY = currentCoords.second + offSet.second;

	return { newX, newY };
}

//*
// @Breife calculate new coordinates based on direction
// */
pair<int, int> Environment::determineNewCoordinates(Direction& dir) {
	pair<int, int> offSet = DirectionalEnum::getDirectionOffsef(dir);

	pair<int, int> currentCoords = { currentNode.nodeCoordX,currentNode.nodeCoordY };

	pair<int, int> newCoordinates = applyOffsetToCoords(currentCoords, offSet);

	return newCoordinates; 

}


//*
// @ Brief Collect observation data from Environment
// 
// Collected observation data from the environment based on the location of the agnet
// @return vector<double> - Observation daat as numeric values
// */
vector<double> Environment::getObservationDataFromEnvironment(StateBasedNode& obeservationPoint) {
	return PerformObservationFromLocation(obeservationPoint, getEnvironmentMap());

}

//* 
// @ Brief Agent taks an action/step in the environment
// 
// @return tuple - New State Node, terminationFlag, reward for action
// */
tuple<StateBasedNode, double, bool> Environment::step(Direction action) {
	incrementActionCount();

	StateBasedNode newNode = currentNode;

	bool terminationFlag = false;

	pair<int, int> potantialNewNodeCoords = determineNewCoordinates(action);

	cout << "Potential node coords : " << potantialNewNodeCoords.first << "-" << potantialNewNodeCoords.second << endl;

	terminationFlag = boundryTerminationCheck(potantialNewNodeCoords);

	if (!terminationFlag) {
		newNode = getNodeAtEnvironmentLocation(potantialNewNodeCoords.first, potantialNewNodeCoords.second);
	}

	terminationFlag = nodeTerminationCheck(newNode);

	currentNode = newNode; // Update the current node in the env

	addNodeToPath(newNode);

	double reward = calculateReward(newNode);

	return { newNode, reward, terminationFlag };

}

//*
// @ brief Remove goal in environment
// 
// REmove a goal from the evironment once it has been reached by an agent
// */
void Environment::removeGoal(StateBasedNode& node) {
	node.updateNodeState(StateBasedNode::State::OPEN);
}

//*
// @ Brife Check if a given node is in the traversed path
// 
// @param node - Node to be checked
// */
bool Environment::checkIfNodeInPath(StateBasedNode& node) {

	if (find(path.begin(), path.end(), node) != path.end()) {
		return true;
	}

	return false;
}


//*
// @brife Add node to traversed path
// 
// @parma node - node to be added to path
// */
void Environment::addNodeToPath(StateBasedNode& node){
	path.push_back(node);
}

//*
// @brife Calculate OpenNodeReward 
// 
// Calculate the reward bassed on the length of the path * openNodeReward
// 
// Higher reward given for more open nodes traversed *
// 
// @param baseOpenNodeReward - base reward given for open nodes
// */
double Environment::calculateOpenNodeReward(double& baseOpenNodeReward) {
	double reward = actionCount * baseOpenNodeReward;
	
	return reward;
}

//*
// @ Brief Calculate reward based on location in environment
// 
// @param newNodeLocation - Node reward is to be calculated based on
// */
double Environment::calculateReward(StateBasedNode& newNodeLocation) {
	double goalNodeReward = 2.5;
	double baseOpenNodeReward = 0.1;
	double reward = 0.0;

	setCurrentNode(newNodeLocation);

	switch (newNodeLocation.state) {
		cout << "New node state : " << newNodeLocation.state_to_string() << endl;
		case StateBasedNode::State::OPEN:

			if (!checkIfNodeInPath(newNodeLocation)) {
				reward = calculateOpenNodeReward(baseOpenNodeReward);
			}
			else {
				reward = baseOpenNodeReward;
			}
			break;


		case StateBasedNode::State::GOAL:
			removeGoal(newNodeLocation); // Set State as OPEN			
			reward = goalNodeReward;
			break;

		default:
			break;
		}

	addNodeToPath(newNodeLocation);
	
	return reward;
}








