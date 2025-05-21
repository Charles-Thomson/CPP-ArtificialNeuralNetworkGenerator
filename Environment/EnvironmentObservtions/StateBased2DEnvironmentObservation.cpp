#include "StateBased2DEnvironmentObservation.h"
#include "../EnvironmentNodes/StateBased/StateBasedNode.h"
#include <string>
#include <vector>
#include <tuple>

using std::string;
using std::tuple;
using std::cout;
using std::endl;
using std::copy;
using std::back_inserter;


void VectorPrintHelper(vector<StateBasedNode> inputVector) {
	for (StateBasedNode node : inputVector) {
		int nodeValue = StateBasedNode::state_to_int(node.state);
		cout << nodeValue << " , ";

	}
	cout << endl;
}



//*
// @ Brief Perform observation of environment from given location
// 
// Observes the surrounding points along defined "sight lines" from a 
// given location 
// 
// @param observtionPoint Location the environemnt is to be observerd from
// @return vector<double> Values relating to objects found along sightlines
// */
vector<double> PerformObservationFromLocation(tuple<int, int> observtionPoint, vector<vector<StateBasedNode>> Environment) {
	
	int observationPointX = get<0>(observtionPoint);
	int observationPointY = get<1>(observtionPoint);

	int environmentDimension = Environment.size();



	vector<StateBasedNode> horizontalSlice = Environment[observationPointX];
	int leftSightLineOffSet = (environmentDimension - observationPointX);


	vector<StateBasedNode> leftSightLine(horizontalSlice.begin(), horizontalSlice.end() - leftSightLineOffSet);
	vector<StateBasedNode> rightSightLine(horizontalSlice.begin() + observationPointX, horizontalSlice.end());

	vector<StateBasedNode> upSightLine;
	vector<StateBasedNode> downSightLine;

	vector<StateBasedNode> upRightSightLine;
	vector<StateBasedNode> upLeftSightLine;

	vector<StateBasedNode>	downRightSightLine;
	vector<StateBasedNode>  downLeftSightLine;


	// Collate values "upRight" diagonal from observation point
	for (int i = 1; i < environmentDimension; ++i) {

		if (observationPointX + i < environmentDimension && observationPointY - i > -1) {
			StateBasedNode value = Environment[observationPointX + i][observationPointY - i];
			upRightSightLine.push_back(value);
		}
		else {
			break;
		}
	}

	// Collate values "upLeft" diagonal from observation point
	for (int i = 1; i < environmentDimension; ++i) {

		if (observationPointX - i > -1 && observationPointY - i > -1) {
			StateBasedNode value = Environment[observationPointX - i][observationPointY - i];
			upLeftSightLine.push_back(value);
		}
		else {
			break;
		}
	}

	// Collate values "downRightSightLine" diagonal from observation point
	for (int i = 1; i < environmentDimension; ++i) {

		if (observationPointX + i < environmentDimension && observationPointY + i < environmentDimension) {
			StateBasedNode value = Environment[observationPointX + i][observationPointY + i];
			downRightSightLine.push_back(value);
		}
		else {
			break;
		}
	}

	// Collate values "downLeftSightLine" diagonal from observation point
	for (int i = 1; i < environmentDimension; ++i) {

		if (observationPointX - i > -1 && observationPointY + i < environmentDimension) {
			StateBasedNode value = Environment[observationPointX - i][observationPointY + i];
			downLeftSightLine.push_back(value);
		}
		else {
			break;
		}
	}



	// Collate values "down" from observation point
	for (int i = observationPointY; i < environmentDimension; ++i) {
		StateBasedNode value = Environment[i][observationPointY];
		downSightLine.push_back(value);
	}
	// Collate values "up" from observation point
	for (int i = observationPointY - 1; i > -1; --i) {
		StateBasedNode value = Environment[i][observationPointY];
		upSightLine.push_back(value);
	}

	VectorPrintHelper(downRightSightLine);
	VectorPrintHelper(downLeftSightLine);


	return {};
}


string testFunctionCall() {
	return "Test Call Return";


}

