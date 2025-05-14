#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H


#include <string>
#include <vector>
#include <tuple>

using std::string;
using std::vector;
using std::tuple;


class Environment {
public:

	Environment() {};
	~Environment() {};

	vector<double> getObservationDataFromEnvironment();
	
	
	tuple<int, double, bool> step();

	void removeGoal();

	double calcualteReward();

	bool terminationCheck(); 


};


#endif //! ENVIRONMENT_H