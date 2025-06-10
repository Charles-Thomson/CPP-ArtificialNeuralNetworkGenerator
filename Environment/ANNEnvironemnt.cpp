#include "ANNEnvironment.h"
#include "EnvironmentObservtions/StateBased2DEnvironmentObservation.h"
#include "EnvironmentNodes/StateBased/StateBasedNode.h"
#include "DirectionEnumeration/DirectionalEnum.h"

#include <string>
#include <vector>
#include <tuple>
#include <cassert>

using std::string;
using std::vector;
using std::tuple;



//*
// @ Brief Get the value at the curent location in the environment
// Includes a termination condition ?
// 
// */
StateBasedNode& Environment::getNodeAtEnvironmentLocation(int& coordX, int& coordY) {

	vector<vector<StateBasedNode>> env = getEnvironmentMap();
	return env[coordX][coordY];
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
// @return tuple - currentCoords, terminationFlag, reward for action
// */
tuple<int, double, bool> Environment::step(DirectionalEnum action) {

	double reward = calcualteReward();


	return {};

}

//*
// @ brief Remove goal in environment
// 
// REmove a goal from the evironment once it has been reached by an agent
// */
void Environment::removeGoal() {
	
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
	int pathLength = path.size();
	
	

	return pathLength * baseOpenNodeReward;
}
//*
// @ Brief Calculate reward based on location in environment
// 
// @param newNodeLocation - Node reward is to be calculated based on
// */
double Environment::calcualteReward(StateBasedNode& newNodeLocation) {

	double goalNodeReward = 2.5;
	double baseOpenNodeReward = 0.1;
	double reward = 0.0;

	setCurrentNode(newNodeLocation);
	
	switch (newNodeLocation.state) {

		case StateBasedNode::State::OPEN:

			if (!checkIfNodeInPath(newNodeLocation)) {
				reward = calculateOpenNodeReward(baseOpenNodeReward);
			}
			else {
				reward = baseOpenNodeReward;
			}
			return;


		case StateBasedNode::State::GOAL:
			newNodeLocation.updateNodeState(StateBasedNode::State::OPEN); // Remove the goal 
			reward = goalNodeReward;
			return;

		default:
			return;
		}

	addNodeToPath(newNodeLocation);

	

	return reward;
}


//*
// @ Brief Determine if action taken results in termination
// 
// */
bool Environment::terminationCheck() {
	return false;

}

//*
// @ Brief  Calculate new location based of given action
// 
// */
tuple<int, int> Environment::processAction() {
	return {};


}


