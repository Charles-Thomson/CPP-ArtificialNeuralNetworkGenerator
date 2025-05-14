#include "ANNEnvironment.h"


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
	return {};

}

//* 
// @ Brief Agent taks an action/step in the environment
// 
// @return tuple - currentCoords, terminationFlag, reward for action
// */
tuple<int, double, bool> Environment::step() {
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
// @ Brief Calculate reward based on location in environment
// 
// */
double Environment::calcualteReward() {
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
tuple<double, bool> getLocationValue() {
	return {};


}