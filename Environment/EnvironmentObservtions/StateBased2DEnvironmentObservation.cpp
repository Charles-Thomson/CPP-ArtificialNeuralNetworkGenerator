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

//*
// @brife Print helper for vector<StateBasedNode>
// 
// Prints the conent of vector of type StateBasedNode
// Converts the stored data to int before printing
// 
// @param inputVector The vector to be printed
// */
void VectorPrintHelper(vector<StateBasedNode> inputVector) {
	for (StateBasedNode node : inputVector) {
		int nodeValue = StateBasedNode::state_to_int(node.state);
		cout << nodeValue << " , ";

	}
	cout << endl;
}


//*
// @Brife Collate data along a 2D vector axis
// 
// Collate data along an axis of a 2D vector, including diagonals
// 
// @param Environment The given 2D vector
// @param observationPointX X coods of observation/start point
// @param observationPointY Y coods of observation/start point
// @param gainX  provides direction of data collaction along x axis
// @param gainY  provides direction of data collaction along y axis
// @param environmentDimension  Dimension of the environment
// @param sightLine Storage of the collated data - By ref so directly updated
// */
void CollateSightLineData(
	const vector<vector<StateBasedNode>>& Environment,
	int observationPointX,
	int observationPointY, 
	int gainX,
	int gainY,
	int environmentDimension,
	vector<StateBasedNode>& sightLine
) {
	for (int i = 1; i < environmentDimension; ++i) {

		int newX = observationPointX + gainX * i;
		int newY = observationPointY + gainY * i;

		if (newX < environmentDimension && newX >= 0) {
			if (newY < environmentDimension && newY >= 0) {
				sightLine.push_back(Environment[newX][newY]);

			};

		};

	};
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

	vector<StateBasedNode> upSightLine;
	vector<StateBasedNode> downSightLine;

	vector<StateBasedNode> leftSightLine;
	vector<StateBasedNode> rightSightLine;

	vector<StateBasedNode> upRightSightLine;
	vector<StateBasedNode> upLeftSightLine;

	vector<StateBasedNode>	downRightSightLine;
	vector<StateBasedNode>  downLeftSightLine;

	
	CollateSightLineData(Environment, observationPointX, observationPointY, -1, 0, environmentDimension, upSightLine);
	CollateSightLineData(Environment, observationPointX, observationPointY, 1, 0, environmentDimension, downSightLine);
	
	CollateSightLineData(Environment, observationPointX, observationPointY, 0, 1, environmentDimension, rightSightLine);
	CollateSightLineData(Environment, observationPointX, observationPointY, 0, -1, environmentDimension, leftSightLine);

	CollateSightLineData(Environment, observationPointX, observationPointY, 1, -1, environmentDimension, upRightSightLine);
	CollateSightLineData(Environment, observationPointX, observationPointY, -1, -1, environmentDimension, upLeftSightLine);

	CollateSightLineData(Environment, observationPointX, observationPointY, 1, 1, environmentDimension, downRightSightLine);
	CollateSightLineData(Environment, observationPointX, observationPointY, -1, 1, environmentDimension, downLeftSightLine);

	

	return {};
}


\

