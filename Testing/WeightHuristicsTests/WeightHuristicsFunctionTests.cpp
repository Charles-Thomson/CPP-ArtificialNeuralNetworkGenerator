#include <gtest/gtest.h>

#include <iostream>
#include <format>

#include "../WeightHuristics/WeightHuristics_Functions.h"

using std::cout;
using std::endl;
using std::string;
using std::format;


TEST(WeightHuristicsFunctionTesting, WeightHuristicsFunctions_Testing) {
	cout << "in the working test call" << endl;
	testFunction();
	ASSERT_EQ(1, 2);
	

}