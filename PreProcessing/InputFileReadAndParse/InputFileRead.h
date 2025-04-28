#ifndef INPUT_FILE_READ
#define INPUT_FILE_READ

#include "cppJSONParser.h"
#include <string>

using JSON = shared_ptr<JSONValue>;
using std::string;

string readInputFile();


#endif // INPUT_FILE_READ