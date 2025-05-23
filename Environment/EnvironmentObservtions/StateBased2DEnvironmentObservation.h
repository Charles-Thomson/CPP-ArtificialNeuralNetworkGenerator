#ifndef STATE_BASED_2D_OBSERVATION_H
#define STATE_BASED_2D_OBSERVATION_H

#include "../EnvironmentNodes/StateBased/StateBasedNode.h"
#include <string>
#include <vector>
#include <tuple>

using std::string;
using std::vector;
using std::tuple;

vector<double> PerformObservationFromLocation(tuple<int, int> observtionPoint, vector<vector<StateBasedNode>> Environment);




#endif // !STATE_BASED_2D_OBSERVATION_H