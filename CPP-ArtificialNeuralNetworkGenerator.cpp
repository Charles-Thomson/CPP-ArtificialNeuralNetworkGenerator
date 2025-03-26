// CPP-ArtificialNeuralNetworkGenerator.cpp : Defines the entry point for the application.
//

#include "CPP-ArtificialNeuralNetworkGenerator.h"

#include "PreProcessing/InputFileReadAndParse/InputFileRead.h"
#include "PreProcessing/InputFileReadAndParse/InputFileParse.h"


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




//*
// @ Brief PreProcess input data
// 
// Apply pre processing and to input config file
// 
// *//
bool PreProcessing() {
	string InputFileString = readInputFile();
	JSON InputFileJSON = parserInputToJSON(InputFileString);


	// parse out to objects


	return false;
}







