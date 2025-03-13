#include "CPP-JSONParser.h"

using JSON = shared_ptr<JSONValue>;

//*
// @brief Parse string to json
// 
// Parse a given string to JSON format 
// 
// @param reference inputSting to be parsed
// @return JSON representation of inputString
// 
// */
JSON parserInputToJSON(string& inputString) {
	JSON test_pointer = ParseToJSON(inputString);
}