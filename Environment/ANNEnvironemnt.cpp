#include "ANNEnvironment.h"
#include "EnvironmentObservtions/StateBased2DEnvironmentObservation.h"
#include "EnvironmentNodes/StateBased/StateBasedNode.h"
#include "DirectionEnumeration/DirectionalEnum.h"

#include <string>
#include <vector>
#include <tuple>

using std::string;
using std::vector;
using std::tuple;






//*
// @ Brief Collect observation data from Environment
// 
// Collected observation data from the environment based on the location of the agnet
// @return vector<double> - Observation daat as numeric values
// */
vector<double> Environment::getObservationDataFromEnvironment() {
	return PerformObservationFromLocation(getValueAtEnvironmentLocation(), getEnvironmentMap());

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


}

//*
// @ Brief Calculate reward based on location in environment
// 
// */
double Environment::calcualteReward() {
	int coordX = getCurrentXCoordinate();
	int coordY = getCurrentYCoordinate();

	StateBasedNode stateValue = getNodeAtEnvironmentLocation(coordX, coordY);




	return 0.0;
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

//*
// @ Brief Get the value at the curent location in the environment
// Includes a termination condition ?
// 
// */
StateBasedNode& Environment::getNodeAtEnvironmentLocation(int& coordX, int& coordY){

	vector<vector<StateBasedNode>> env = getEnvironmentMap();
	return env[coordX][coordY];
}

