cmake_minimum_required (VERSION 3.12)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (CPP-ArtificialNeuralNetworkGenerator)

# Main library
add_library(CPP-ArtificialNeuralNetworkGenerator 
    CPP-ArtificialNeuralNetworkGenerator.cpp 
    CPP-ArtificialNeuralNetworkGenerator.h 
    PreProcessing/InstanceConfigObject/ANNConfigurationObject/ANNConfigObject.cpp
    PreProcessing/InstanceConfigObject/ANNConfigurationObject/ANNConfigObject.h
    PreProcessing/InstanceConfigObject/ANNConfigurationObject/ANNLayerObject.cpp
    PreProcessing/InstanceConfigObject/ANNConfigurationObject/ANNLayerObject.h
    PreProcessing/InstanceConfigObject/EnvironmentConfigurationObject/EnvironmentConfigObject.cpp 
    PreProcessing/InstanceConfigObject/EnvironmentConfigurationObject/EnvironmentConfigObject.h 
    PreProcessing/InstanceConfigObject/HyperParameterConfigurationObject/HyperParameterConfigObject.cpp
    PreProcessing/InstanceConfigObject/HyperParameterConfigurationObject/HyperParameterConfigObject.h
    PreProcessing/InstanceConfigObject/InstanceConfigurationObject/InstanceConfigObject.cpp
    PreProcessing/InstanceConfigObject/InstanceConfigurationObject/InstanceConfigObject.h
    PreProcessing/InputFileReadAndParse/InputFileRead.cpp 
    PreProcessing/InputFileReadAndParse/InputFileParse.h 
    PreProcessing/InputFileReadAndParse/InputFileRead.h
    PreProcessing/UnpackingToConfigurationObjects/UnpackToConfigObjects.cpp 
    PreProcessing/UnpackingToConfigurationObjects/UnpackToConfigObjects.h
    
    ActivationFunctions/HiddenLayer/HiddenLayer_ActivationFunctionsFactory.cpp
    ActivationFunctions/HiddenLayer/HiddenLayer_ActivationFunctions.h
    ActivationFunctions/HiddenLayer/HiddenLayer_ActivationFunctions.cpp
    ActivationFunctions/HiddenLayer/HiddenLayer_ActivationFunctionsFactory.h

    ActivationFunctions/OutputLayer/OutputLayer_ActivationFunctions.cpp 
    ActivationFunctions/OutputLayer/OutputLayer_ActivationFunctions.h
    ActivationFunctions/OutputLayer/OutputLayer_ActivationFunctionsFactory.h)

  

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CPP-ArtificialNeuralNetworkGenerator PROPERTY CXX_STANDARD 20)
endif()

# Fetch content for CPP-JSONParser from GitHub
include(FetchContent)
FetchContent_Declare(
    CPP-JSONParser
    GIT_REPOSITORY https://github.com/Charles-Thomson/CPP-JSONParser.git
)
set(CPP_JSONPARSER_BUILD_TESTS ON CACHE BOOL "" FORCE)  
FetchContent_MakeAvailable(CPP-JSONParser)

# Fetch Google Test
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

message(STATUS "GoogleTest source directory: ${googletest_SOURCE_DIR}")



target_link_libraries(CPP-ArtificialNeuralNetworkGenerator PRIVATE CPP-JSONParserStatic)

# Include the CPP-JSONParser headers in the project
target_include_directories(
    CPP-ArtificialNeuralNetworkGenerator PRIVATE 
    # Core project directories
    ${CMAKE_SOURCE_DIR}/PreProcessing
    ${CMAKE_SOURCE_DIR}/PreProcessing/InstanceConfigObject
    ${CMAKE_SOURCE_DIR}/PreProcessing/InstanceConfigObject/HyperParameterConfigurationObject
    #CPP-JSONParser directories 
    ${CPP-JSONParser_SOURCE_DIR}/ExposedFunctions  
)

#${CPP-JSONParser_SOURCE_DIR}
    #${CPP-JSONParser_SOURCE_DIR}/Structs
    #${CPP-JSONParser_SOURCE_DIR}/FileReader
    #${CPP-JSONParser_SOURCE_DIR}/ExposedFunctions


# Pass the string as a preprocessor macro definition
set(INPUT_FILE_PATH "C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/InputConfigFile.txt")
message(STATUS "INPUT_FILE_PATH is set to: ${INPUT_FILE_PATH}")
add_compile_definitions(INPUT_FILE_PATH="${INPUT_FILE_PATH}")
target_compile_definitions(CPP-ArtificialNeuralNetworkGenerator PRIVATE INPUT_FILE_PATH="${INPUT_FILE_PATH}")

# Enable testing
enable_testing()

# Test executable for read_and_parse_testing
add_executable(read_and_parse_testing Testing/InputParsingTests/ReadAndParseTesting.cpp)

add_executable(JSON_Unpacking_testing Testing/JSONUnpackingTests/JSONUnpackingTesting.cpp)

add_executable(hidden_layer_activation_function_testing Testing/ActivationFunctionTests/HiddenLayer_ActivationFunctionTests.cpp)

add_executable(output_layer_activation_function_testing Testing/ActivationFunctionTests/OutputLayer_ActivationFunctionTests.cpp)

# Target Libs 
target_link_libraries(JSON_Unpacking_testing PRIVATE gtest gtest_main CPP-ArtificialNeuralNetworkGenerator)
target_link_libraries(read_and_parse_testing PRIVATE gtest gtest_main CPP-ArtificialNeuralNetworkGenerator)
target_link_libraries(hidden_layer_activation_function_testing PRIVATE gtest gtest_main CPP-ArtificialNeuralNetworkGenerator)
target_link_libraries(output_layer_activation_function_testing PRIVATE gtest gtest_main CPP-ArtificialNeuralNetworkGenerator)


# List of Test targets
set(TEST_TARGETS
    JSON_Unpacking_testing
    read_and_parse_testing
    hidden_layer_activation_function_testing
    output_layer_activation_function_testing
)

#Include directories for test targets
foreach(target IN LISTS TEST_TARGETS)
    target_include_directories(${target} PRIVATE
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/PreProcessing
        ${CMAKE_SOURCE_DIR}/Testing
        ${CPP-JSONParser_SOURCE_DIR}/ExposedFunctions  
        ${googletest_SOURCE_DIR}/googletest/include  
        "${gtest_SOURCE_DIR}/include"
    )
endforeach()

#Set compile option to  Multithreaded DLL runtime library (MSVCRTD) as memory leaks are likely
foreach(target IN LISTS TEST_TARGETS)
    target_compile_options(${target} PRIVATE /MDd)

endforeach()




# Register the test
add_test(NAME InputFileReadAndParse COMMAND read_and_parse_testing)
gtest_discover_tests(read_and_parse_testing)

# Register the test
add_test(NAME JSONUnpacking COMMAND JSON_Unpacking_testing)
gtest_discover_tests(JSON_Unpacking_testing)

# Register the test
add_test(NAME HiddenLayerActivationFunctionTesting COMMAND hidden_layer_activation_function_testing)
gtest_discover_tests(hidden_layer_activation_function_testing)

# Register the test
add_test(NAME OutputLayerActivationFunctionTesting COMMAND output_layer_activation_function_testing)
gtest_discover_tests(output_layer_activation_function_testing)




