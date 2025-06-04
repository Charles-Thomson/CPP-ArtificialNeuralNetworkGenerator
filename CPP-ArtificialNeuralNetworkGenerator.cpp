// CPP-ArtificialNeuralNetworkGenerator.cpp : Defines the entry point for the application.
//

#include "CPP-ArtificialNeuralNetworkGenerator.h"

#include "PreProcessing/InputFileReadAndParse/InputFileRead.h"
#include "PreProcessing/InputFileReadAndParse/InputFileParse.h"
#include "ConfigClasses/InstanceConfigurationObject/InstanceConfigObject.h"



#include "cppJSONParser.h"
#include "CheckIfContainsKey.h"

#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <list>
#include <variant>
#include <sstream>

#include <UnpackingToConfigurationObjects/UnpackToConfigObjects.cpp>

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




//*
// @ Brief PreProcess input data
// 
// Apply pre processing and to input config file
// 
// *//
bool static PreProcessing() {
	string InputFileString = readInputFile();
	JSON JSONConfigData = parserInputToJSON(InputFileString);


	InstanceConfigObject newInstanceConfig = UnpackJSONToConfigObjects(JSONConfigData);

	// Convert into a 

	return false;
}







