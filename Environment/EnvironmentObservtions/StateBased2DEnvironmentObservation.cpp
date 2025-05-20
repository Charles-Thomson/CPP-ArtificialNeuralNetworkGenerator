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
	

	cout << "Observation location : " << get<0>(observtionPoint) << get<1>(observtionPoint) << endl;

	int observationPointX = get<0>(observtionPoint);

	int environmentDimension = Environment.size();


	vector<tuple<int, int>> sightLineDown = {};

	
	vector<StateBasedNode> horizontalSlice = Environment[observationPointX];
	int leftSightLineOffSet = (environmentDimension - observationPointX);

	vector<StateBasedNode> leftSightLine(horizontalSlice.begin(), horizontalSlice.end() - leftSightLineOffSet);

	VectorPrintHelper(horizontalSlice);
	VectorPrintHelper(leftSightLine);


	return {};
}


string testFunctionCall() {
	return "Test Call Return";


}

