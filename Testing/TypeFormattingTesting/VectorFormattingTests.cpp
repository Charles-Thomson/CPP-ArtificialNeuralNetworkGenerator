#include <gtest/gtest.h>

#include <vector>
#include<string>

#include "../CPP-JSONParser.h"
#include "TypeFormatting/VectorFormatting.cpp"


using std::string;

using JSON = shared_ptr<JSONValue>;

TEST(TypeFormattingTesting, UnpackingVector) {
	VectorTestFunction();
	ASSERT_EQ(1, 2);
	// Need to work from here
	// detmermin if vectors/arrays are being parsed ocrrectly
	// They will likley need to be converted from vector<shared_ptr> to the correcttype


}