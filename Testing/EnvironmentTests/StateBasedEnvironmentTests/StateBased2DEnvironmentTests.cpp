#include <gtest/gtest.h>
#include <iostream>

using std::cout;
using std::endl;




TEST(TestHolder, runTest) {
	cout << "Test Runnging" << endl;
	ASSERT_EQ(1, 2);

}