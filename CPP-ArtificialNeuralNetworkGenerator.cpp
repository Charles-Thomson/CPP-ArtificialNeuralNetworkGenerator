// CPP-ArtificialNeuralNetworkGenerator.cpp : Defines the entry point for the application.
//

#include "CPP-ArtificialNeuralNetworkGenerator.h"

#include "CPP-JSONParser.h"
#include "JSONValueStruct.h"
#include "FileReader.h"
#include "CheckIfContainsKey.h"

#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <list>
#include <variant>
#include <sstream>

using std::tuple;
using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::cerr;
using std::getline;
using std::stringstream;
using std::pair;
using std::list;
using std::variant;


using JSON = shared_ptr<JSONValue>;

bool readAndParseCheck() {

	string inputConfigFilePath = "C:\\Users\\Charl\\source\\repos\\C++\\CPP-ArtificialNeuralNetworkGenerator\\InputConfigFile.txt";
	ifstream inputConfigFile(inputConfigFilePath);

	string contentLine;
	string line;

	if (getline(inputConfigFile, line)) {
		contentLine = line;
		cout << "File content : " << contentLine << endl;
	};

	JSON TestPointer = ParseToJSON(contentLine);

	if (TestPointer == nullptr) {
		cout << "Returned a null pointer" << endl;
	}

	// Contains key check
	string testKey = "age";

	bool keyTest = checkIfContainsKeyExposed(TestPointer, testKey);

	cout << "CheckIfContainsKey  Result :  " << keyTest << endl;

	// Get value check
	auto holder = GetValueByKey(TestPointer, testKey);

	if (auto val = holder->get<string>()) {
		cout << "GetValueByKey -> Result " << *val << endl;
	}

	string typeHolder = holder->getType();


	cout << "The return type is : " << typeHolder << endl;

	return true;
}

//*
// @ brief Read Input file
// */
string readInputFile() {

	string inputConfigFilePath = "C:\\Users\\Charl\\source\\repos\\C++\\CPP-ArtificialNeuralNetworkGenerator\\InputConfigFile.txt";
	ifstream inputConfigFile(inputConfigFilePath);

	string contentLine;
	string line;

	if (getline(inputConfigFile, line)) {
		contentLine = line;
		cout << "File content : " << contentLine << endl;
	};
	
	return contentLine;
}

//*
// @ brife parse a input string to JSON 
// */
JSON pareseToJSON(string& inputConfigString) {
	JSON parsedData = ParseToJSON(inputConfigString);

	if (parsedData == nullptr) {
		cout << "Returned a null pointer while parsing" << endl;
	}
	return parsedData;
}

int main() {
	string inputConfig = readInputFile();

	JSON parsedJSON = pareseToJSON(inputConfig);

	cout << "Parse Succeded" << endl;

	// NEXT: Unpack the jsonInto a struct/object that can then be pre processed
}

