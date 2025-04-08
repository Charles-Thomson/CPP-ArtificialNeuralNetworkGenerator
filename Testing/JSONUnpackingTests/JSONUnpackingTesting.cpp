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


//*
// @ brief Compare two given string for equality
// 
// Compare two string representations of types. If the comparison fails, 
// provide given SCOPED_TRACE message
// 
// @param scopedTraceMesasge message provided to SCOPED_TRACE, displayed of comparison failure
// @param expected expected type - string representation
// @param actual actual type - string representation
// */
//void typeComparisonHelper(const string& scopedTraceMesasge, const string& expected, const string& actual) {
//	SCOPED_TRACE(scopedTraceMesasge);
//	EXPECT_EQ(expected, actual);
//}


JSON ReadAndParseTestDataHelper() {
	string TestData = readInputFile();
	JSON TestJSON = ParseToJSON(TestData);

	return TestJSON;
}



TEST(JSONUnpackingTesting, UnpackToANNConfigObj) {
	
	JSON TestJSON = ReadAndParseTestDataHelper();

	JSON ANNConfigData = GetValueByKey(TestJSON, "ANNConfig");
	ANNConfigObject testConfigObject = UnpackToANNCongifObj(ANNConfigData);

	testConfigObject.PrintObjectAttributes();

	// Test point 
	ASSERT_TRUE(false);
}

TEST(JSONUnpackingTesting, UnpackToHyperParameterConfigObj) {
	JSON TestJSON = ReadAndParseTestDataHelper();
	JSON HyperParameterConfigData = GetValueByKey(TestJSON, "HyperParameterConfig");

	HyperParameterConfigObject testConfigObject = UnpackToHyperParameterConfigObj(HyperParameterConfigData);

	testConfigObject.PrintObjectAttributes();

	//Test point 
	ASSERT_TRUE(false);

}


TEST(JSONUnpackingTesting, UnpackToEnvironmentConfigObj) {
	JSON TestJSON = ReadAndParseTestDataHelper();
	JSON EnvironmentJSONData = GetValueByKey(TestJSON, "environmentConfig");

	EnvironmentConfigObject testConfigObject = UnpackToEnvironmentConfigObj(EnvironmentJSONData);

	testConfigObject.PrintObjectAttributes();

	//Test point 
	ASSERT_TRUE(false);

}


