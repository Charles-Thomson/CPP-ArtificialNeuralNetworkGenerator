#include "WeightHuristics_Functions.h"
#include "cppGenerator.h"

#include <iostream>
#include <string>
#include <format>
#include <optional>
#include <coroutine>
#include <generator>
#include <vector>
#include <cmath>
#include <random>

using std::vector;
using std::sqrt;
using std::random_device;


void testFunction() { 
	cout << "Test function " << endl;
	Generator gen = count_to_test_func(5);
	size_t upperLimit = 5;
	while (gen.next()) {
		cout << "Generator Value : " << gen.value() << endl; 
	}
	cout << "Test function " << endl;
}

