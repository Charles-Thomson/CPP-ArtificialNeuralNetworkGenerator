#include <gtest/gtest.h>
#include <string>

#include "UnpackingToConfigurationObjects/UnpackToConfigObjects.cpp"
#include "../CPP-JSONParser.h"
#include "Preprocessing/InputFileReadAndParse/InputFileRead.h"
#include "Preprocessing/InputFileReadAndParse/InputFileParse.h"

using std::cout;
using std::string;
using std::endl;

using JSON = shared_ptr<JSONValue>;

TEST(JSONUnpackingTesting, UnpackToANNConfigObj) {
	cout << "Test running" << endl;
	string TestData = readInputFile();
	JSON TestJSON = ParseToJSON(TestData);
	UnpackJSONToConfigObjects(TestJSON);



	ASSERT_EQ(1, 2);



}