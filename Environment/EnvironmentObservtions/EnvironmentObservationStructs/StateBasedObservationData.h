#ifndef STATE_BASED_OBSERVATION_DATA_H
#define STATE_BASED_OBSERVATION_DATA_H

#include <string>
#include <vector>

using std::vector;

struct StateBasedObservationData {
	vector<int> SightLineData_2D;
	vector<vector<int>> SightLineData_3D;

	double openNodeInput;
	double obsticalNodeInput;
	double goalNodeInput;

	int openNodeAccumulativeData;
	int obsticalNodeAccumulativeData;
	int goalNodeAccumulativeData;

};

#endif // !STATE_BASED_OBSERVATION_DATA_H