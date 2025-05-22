#include "StateBased2DEnvironmentObservation.h"
#include "../EnvironmentNodes/StateBased/StateBasedNode.h"
#include "EnvironmentObservationStructs/StateBasedObservationData.h"

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
void CollateDataAlongSightLine(
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
// @ Brife Generate StateBasedObservationData Object
// Generate a StateBasedObservationData object to store the collated sightline data
// and environment node type dependent input data
// 
// @param sightLineData Raw data along a sightline
// @param openNodeInputValue Value representing the quantity of OPEN nodes along the given sightline
// @param obsticalNodeInputValue Value representing the quantity of OBSTICAL nodes along the given sightline
// @param goalNodeInputValue Value representing the quantity of GOAL nodes along the given sightline
// 
// @return StateBasedObservationData New StateBasedObservationData object
// */
StateBasedObservationData GenerateStateBasedObservationDataObject(vector<int> sightLineData, double openNodeInputValue, double obsticalNodeInputValue , double goalNodeInputValue) {
	StateBasedObservationData newObj = { .SightLineData_2D = sightLineData,
										 .openNodeInput = openNodeInputValue,
										 .obsticalNodeInput = obsticalNodeInputValue,
										 .goalNodeInput = goalNodeInputValue };
	return newObj;
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

	
	CollateDataAlongSightLine(Environment, observationPointX, observationPointY, -1, 0, environmentDimension, upSightLine);
	CollateDataAlongSightLine(Environment, observationPointX, observationPointY, 1, 0, environmentDimension, downSightLine);
	
	CollateDataAlongSightLine(Environment, observationPointX, observationPointY, 0, 1, environmentDimension, rightSightLine);
	CollateDataAlongSightLine(Environment, observationPointX, observationPointY, 0, -1, environmentDimension, leftSightLine);

	CollateDataAlongSightLine(Environment, observationPointX, observationPointY, 1, -1, environmentDimension, upRightSightLine);
	CollateDataAlongSightLine(Environment, observationPointX, observationPointY, -1, -1, environmentDimension, upLeftSightLine);

	CollateDataAlongSightLine(Environment, observationPointX, observationPointY, 1, 1, environmentDimension, downRightSightLine);
	CollateDataAlongSightLine(Environment, observationPointX, observationPointY, -1, 1, environmentDimension, downLeftSightLine);

	return {};
}


//*
// @ Brife Normalize values to between 0.0 and 1.0
// 
// @param inputValue Value to be normalized
// @return Normalized value
// */
double NormalizeValue(int inputValue) {


	return 0.0;
}


//*
// @Brife Calculate input data from sightlines data 
// 
// Calculate the input data along a sightline. Producing a value for each of the 
// types of object along a sightline. Higher value = shorter distance along sight line
// 
// 
// */
vector<double> CalculateInputDataAlongSightline(vector<int> observattionData, int environmentDimension) {

	// Accumulated values = environmentDimension - distance from observation point 
	int accumulativeOpenNodeInput = 0;
	int accumulativeObsticalNodeInput = 0;
	int accumulativeGoalNodeInput = 0;

	int offSet = observattionData.size(); 
	for (size_t i = 0; i < observattionData.size(); ++i) {
		StateBasedNode nodeState(StateBasedNode::state_from_int(observattionData[i]));

		switch (nodeState.state) {
		case StateBasedNode::State::OPEN: 
			accumulativeOpenNodeInput += offSet - i; 
			return;

		case StateBasedNode::State::OBSTICAL: 
			accumulativeObsticalNodeInput += offSet - i;
			return;

		case StateBasedNode::State::GOAL: 
			accumulativeGoalNodeInput += offSet - i;
			return;
		default: throw "Value not associated with a node state";
		}
	}


	double openNodeInput = NormalizeValue(accumulativeOpenNodeInput);
	double obsticalNodeInput = NormalizeValue(accumulativeObsticalNodeInput);
	double goalNodeInput = NormalizeValue(accumulativeGoalNodeInput);


	
	// Need to adjust the values to between 0.0 < n < 1.0 
	




}




