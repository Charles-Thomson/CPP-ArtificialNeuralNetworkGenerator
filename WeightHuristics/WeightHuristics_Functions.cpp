#include "WeightHuristics_Functions.h"

#include <iostream>
#include <string>
#include <format>
#include <optional>
#include <coroutine>
#include <generator>


std::generator<int> count_to(int max) {
	for (int i = 0; i < max; ++i)
		co_yield i;
}



void testFunction() { 
	cout << "Test function " << endl;

	double valueA = 20;

	



}

