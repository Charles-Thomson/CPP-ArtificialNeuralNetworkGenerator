#include <gtest/gtest.h>

#include <string>

#include "../../PreProcessing/InputFileReadAndParse/InputFileRead.h"
#include "../../PreProcessing/InputFileReadAndParse/InputFileParse.h"
#include "cppJSONParser.h"


using std::cout;
using std::endl;
using std::string;

using JSON = shared_ptr<JSONValue>;

TEST(InputFileReadAndParse, ReadFile) {
	string fileContent = readInputFile();
	cout << "ReadFile Test -> " << fileContent << endl;

	ASSERT_FALSE(fileContent.empty());

}

TEST(InputFileReadAndParse, ParseInputString) {
	string fileContent = readInputFile();
	cout << "ParseInputString Test -> " << fileContent << endl;

	JSON TestPointer = ParseToJSON(fileContent);

	if (TestPointer == nullptr) {
		cerr << "ParseInputString - > " << "Returned a null pointer" << endl;
	}
	ASSERT_FALSE(TestPointer == nullptr);
}