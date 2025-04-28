
#include "cppJSONParser.h"

//#include "FileReader.h"
//#include "JSONValueStruct.h"
#include <string>

using std::string;

//*
// @ brief Read the INPUT_FILE_PATH 
// 
// Read the input file path defined globally
// 
// @return string File Contents of INPUT_FILE_PATH 
// */
string readInputFile() {
	FileReader fileReader;
	string filePath = string(INPUT_FILE_PATH);
	string result = fileReader.GetFileContents(filePath);
	return result;
}