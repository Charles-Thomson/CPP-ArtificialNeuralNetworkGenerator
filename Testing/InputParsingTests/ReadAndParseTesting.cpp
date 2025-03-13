#include <gtest/gtest.h>

#include <string>

#include "../../PreProcessing/InputFileReadAndParse/InputFileRead.h"
#include "../../PreProcessing/InputFileReadAndParse/InputFileParse.h"

using std::cout;
using std::endl;
using std::string;

TEST(InputFileReadAndParse, ReadFile) {
	string fileContent = readInputFile();
	cout << fileContent << endl;

	ASSERT_EQ(1, 2);

}