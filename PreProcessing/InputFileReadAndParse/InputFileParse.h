#ifndef INPUT_FILE_PARSE
#define INPUT_FILE_PARSE



using JSON = shared_ptr<JSONValue>;

JSON parserInputToJSON(string& inputString);

#endif // INPUT_FILE_PARSE