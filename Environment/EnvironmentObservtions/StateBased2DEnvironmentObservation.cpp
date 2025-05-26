#include "StateBased2DEnvironmentObservation.h"
#include "../EnvironmentNodes/StateBased/StateBasedNode.h"
#include "EnvironmentObservationStructs/StateBasedObservationData.h"

#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <fmt/core.h>



using std::string;
using std::tuple;
using std::cout;
using std::endl;
using std::copy;
using std::back_inserter;
using std::minmax_element;
using fmt::format;
using std::tie;


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
// @brife Find max and min values in vector<int>
// 
// Find the max and min values in a vector of type int. 
// 
// @param vector<int> inputVector - Vector assesed for new min and max values
// @return tuple<int, int> - min and max values of vector
// */
tuple<double, double> DetermineMinAndMaxValues(vector<int>& inputVector) {

	// Need the return in the guard for the use case of the function
	if (inputVector.empty()) {
		return {};
	}

	auto [min_it, max_it] = minmax_element(inputVector.begin(), inputVector.end());

	double min = *min_it;
	double max = *max_it;

	return { min , max };
}

//*
// @ Brife Normalize values to between 0.0 and 1.0
// 
// @param inputValue Value to be normalized
// @return Normalized value
// */
vector<double> NormalizeDataSet(vector<int>& dataSet) {
	tuple<double, double> minMaxValues = DetermineMinAndMaxValues(dataSet);
	double min;
	double max;
	tie(min, max) = minMaxValues;

	vector<double> normalizedDataSet = {};

	cout << "Min Max values : " << min << " : " << max << endl;
	for (int& val : dataSet) {
		double nomrlizedValue = ((val - min) / (max - min));
		cout << "val : " << val << endl;
		cout << "Normolized val : " << nomrlizedValue << endl;
		normalizedDataSet.push_back(nomrlizedValue);

	}

	return normalizedDataSet;
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
// @Brife Calculate input data from sightlines data 
// 
// Calculate the input data along a sightline. Producing a value for each of the 
// types of object along a sightline. Higher value = shorter distance along sight line
// 
// @param observattionData Nodes along the sighline
// @param environmentDimension Dimension of the Environment
// @return Raw values relating to distance from from the observation point fo each node type 
// */
vector<int> CalculateAccumulativeInputDataAlongSightline(vector<StateBasedNode> observattionData, int environmentDimension) {

	// Accumulated values = environmentDimension - distance from observation point 
	int accumulativeOpenNodeInput = 0;
	int accumulativeObsticalNodeInput = 0;
	int accumulativeGoalNodeInput = 0;

	int offSet = observattionData.size();
	for (size_t i = 0; i < observattionData.size(); ++i) {

		switch (observattionData[i].state) {
		case StateBasedNode::State::OPEN:
			accumulativeOpenNodeInput += offSet - i;
			break;

		case StateBasedNode::State::OBSTICAL:
			accumulativeObsticalNodeInput += offSet - i;
			break;

		case StateBasedNode::State::GOAL:
			accumulativeGoalNodeInput += offSet - i;
			break;
		default: throw "Value not associated with a node state";
		}
	}

	return { accumulativeOpenNodeInput ,accumulativeObsticalNodeInput, accumulativeGoalNodeInput };

}

// ABOVE - VALUE COLLATION ISSUE ? 
// Check the made and work out whats going on 




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

	// Can all be stored in a single vector ?
	vector<int> upSightLineAccumulativeValues = CalculateAccumulativeInputDataAlongSightline(upSightLine, environmentDimension);
	vector<int> downSightLineAccumulativeValues = CalculateAccumulativeInputDataAlongSightline(downSightLine, environmentDimension);

	vector<int> leftSightLineAccumulativeValues = CalculateAccumulativeInputDataAlongSightline(leftSightLine, environmentDimension);
	vector<int> rightSightLineAccumulativeValues = CalculateAccumulativeInputDataAlongSightline(rightSightLine, environmentDimension);

	vector<int> upRightSightLineAccumulativeValues = CalculateAccumulativeInputDataAlongSightline(upRightSightLine, environmentDimension);
	vector<int> upLeftSightLineAccumulativeValues = CalculateAccumulativeInputDataAlongSightline(upLeftSightLine, environmentDimension);

	vector<int> downRightSightLineAccumulativeValues = CalculateAccumulativeInputDataAlongSightline(downRightSightLine, environmentDimension);
	vector<int> downLeftSightLineAccumulativeValues = CalculateAccumulativeInputDataAlongSightline(downLeftSightLine, environmentDimension);

	vector<int> unprocessedSightLineData = {};

	vector<vector<int>> sightLineVectors = {
		upSightLineAccumulativeValues,
		downSightLineAccumulativeValues,
		leftSightLineAccumulativeValues,
		rightSightLineAccumulativeValues,
		upRightSightLineAccumulativeValues,
		upLeftSightLineAccumulativeValues,
		downRightSightLineAccumulativeValues,
		downLeftSightLineAccumulativeValues
	};

	for (vector<int>& vec : sightLineVectors) {
		unprocessedSightLineData.insert(unprocessedSightLineData.end(), vec.begin(), vec.end());

	};

	// Take all the sight line data and normalize it.
	// Order no longer matters 

	vector<double> normolizedSightLineData = NormalizeDataSet(unprocessedSightLineData);

	/*for (double val : normolizedSightLineData) {
		cout << val << endl;
	
	}*/



	return {};
}









