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

    PreProcessing/InputFileReadAndParse/InputFileRead.cpp 
    PreProcessing/InputFileReadAndParse/InputFileParse.h 
    PreProcessing/InputFileReadAndParse/InputFileRead.h
    PreProcessing/UnpackingToConfigurationObjects/UnpackToConfigObjects.cpp 
    PreProcessing/UnpackingToConfigurationObjects/UnpackToConfigObjects.h

    ConfigClasses/ANNConfigurationObject/ANNConfigObject.cpp
    ConfigClasses/ANNConfigurationObject/ANNConfigObject.h

    ConfigClasses/ANNConfigurationObject/ANNLayerObject.cpp
    ConfigClasses/ANNConfigurationObject/ANNLayerObject.h

    ConfigClasses/EnvironmentConfigurationObject/EnvironmentConfigObject.cpp 
    ConfigClasses/EnvironmentConfigurationObject/EnvironmentConfigObject.h 

    ConfigClasses/HyperParameterConfigurationObject/HyperParameterConfigObject.cpp
    ConfigClasses/HyperParameterConfigurationObject/HyperParameterConfigObject.h

    ConfigClasses/InstanceConfigurationObject/InstanceConfigObject.cpp
    ConfigClasses/InstanceConfigurationObject/InstanceConfigObject.h

    ActivationFunctions/HiddenLayer/HiddenLayer_ActivationFunctionsFactory.cpp
    ActivationFunctions/HiddenLayer/HiddenLayer_ActivationFunctions.h
    ActivationFunctions/HiddenLayer/HiddenLayer_ActivationFunctions.cpp
    ActivationFunctions/HiddenLayer/HiddenLayer_ActivationFunctionsFactory.h

    ActivationFunctions/OutputLayer/OutputLayer_ActivationFunctions.cpp 
    ActivationFunctions/OutputLayer/OutputLayer_ActivationFunctions.h
    ActivationFunctions/OutputLayer/OutputLayer_ActivationFunctionsFactory.h

    "WeightHuristics/WeightHuristics_GeneratorFactory.cpp"
    "WeightHuristics/WeightHuristics_GeneratorFactory.h" 
    WeightHuristics/WeightHuristics_Functions.h
    WeightHuristics/WeightHuristics_Functions.cpp
    GeneratorStruct/Generator.cpp 
    "Staging/WorkItemGeneration/WorkItem.h" "Environment/ANNEnvironemnt.cpp" "Environment/ANNEnvironment.h")

  

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CPP-ArtificialNeuralNetworkGenerator PROPERTY CXX_STANDARD 20)
endif()

include(FetchContent)

# Fetch content for CPP-JSONParser from GitHub
FetchContent_Declare(
    CPP-JSONParser
    GIT_REPOSITORY https://github.com/Charles-Thomson/CPP-JSONParser.git
)
set(CPP_JSONPARSER_BUILD_TESTS ON CACHE BOOL "" FORCE)  
FetchContent_MakeAvailable(CPP-JSONParser)


# Fetch content for CPP-Generator from GitHub
FetchContent_Declare(
    CPP-Generator
    GIT_REPOSITORY https://github.com/Charles-Thomson/CPP-Generator.git
)
FetchContent_MakeAvailable(CPP-Generator)


# Fetch Google Test
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

message(STATUS "GoogleTest source directory: ${googletest_SOURCE_DIR}")

target_link_libraries(CPP-ArtificialNeuralNetworkGenerator PRIVATE CPP-JSONParserStatic CPP_GENERATOR)

# Include the CPP-JSONParser headers in the project
target_include_directories(
    CPP-ArtificialNeuralNetworkGenerator PRIVATE 
    # Core project directories
    ${CMAKE_SOURCE_DIR}/PreProcessing
    ${CMAKE_SOURCE_DIR}/PreProcessing/InstanceConfigObject
    ${CMAKE_SOURCE_DIR}/PreProcessing/InstanceConfigObject/HyperParameterConfigurationObject
    #CPP-JSONParser directories 
    ${CPP-JSONParser_SOURCE_DIR}/ExposedFunctions  
    #CPP-Generator
    ${CPP-Generator_SOURCE_DIR}/ExposedFunctions
)




# Pass the string as a preprocessor macro definition
set(INPUT_FILE_PATH "C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/InputConfigFile.txt")
message(STATUS "INPUT_FILE_PATH is set to: ${INPUT_FILE_PATH}")
add_compile_definitions(INPUT_FILE_PATH="${INPUT_FILE_PATH}")
target_compile_definitions(CPP-ArtificialNeuralNetworkGenerator PRIVATE INPUT_FILE_PATH="${INPUT_FILE_PATH}")

# Enable testing
enable_testing()

# Test executable for read_and_parse_testing
add_executable(read_and_parse_testing Testing/InputParsingTests/ReadAndParseTesting.cpp "GeneratorStruct/Generator.cpp" "Staging/WorkItemGeneration/WorkItem.h" "Environment/ANNEnvironemnt.cpp" "Environment/ANNEnvironment.h")

add_executable(JSON_Unpacking_testing Testing/JSONUnpackingTests/JSONUnpackingTesting.cpp "GeneratorStruct/Generator.cpp" "Staging/WorkItemGeneration/WorkItem.h" "Environment/ANNEnvironemnt.cpp" "Environment/ANNEnvironment.h")

add_executable(hidden_layer_activation_function_testing Testing/ActivationFunctionTests/HiddenLayer_ActivationFunctionTests.cpp "GeneratorStruct/Generator.cpp" "Staging/WorkItemGeneration/WorkItem.h" "Environment/ANNEnvironemnt.cpp" "Environment/ANNEnvironment.h")

add_executable(output_layer_activation_function_testing Testing/ActivationFunctionTests/OutputLayer_ActivationFunctionTests.cpp "GeneratorStruct/Generator.cpp" "Staging/WorkItemGeneration/WorkItem.h" "Environment/ANNEnvironemnt.cpp" "Environment/ANNEnvironment.h")

add_executable(weight_huristics_function_testing Testing/WeightHuristicsTests/WeightHuristicsFunctionTests.cpp "GeneratorStruct/Generator.cpp" "Staging/WorkItemGeneration/WorkItem.h" "Environment/ANNEnvironemnt.cpp" "Environment/ANNEnvironment.h")

add_executable(generator_struct_functional_testing GeneratorStruct/Generator.cpp "Staging/WorkItemGeneration/WorkItem.h" "Environment/ANNEnvironemnt.cpp" "Environment/ANNEnvironment.h")

# List of Test targets
set(TEST_TARGETS
    JSON_Unpacking_testing
    read_and_parse_testing
    hidden_layer_activation_function_testing
    output_layer_activation_function_testing
    weight_huristics_function_testing
    generator_struct_functional_testing
)

#Target link libraries
foreach(target IN LISTS TEST_TARGETS)
    target_link_libraries(${target} PRIVATE gtest gtest_main CPP-ArtificialNeuralNetworkGenerator)
endforeach()

#Include directories for test targets
foreach(target IN LISTS TEST_TARGETS)
    target_include_directories(${target} PRIVATE
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/PreProcessing
        ${CMAKE_SOURCE_DIR}/Testing
        #CPP-JSONParser directories
        ${CPP-JSONParser_SOURCE_DIR}/ExposedFunctions 
        
         #CPP-Generator directories
        ${CPP-Generator_SOURCE_DIR}/ExposedFunctions

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

# Register the test
add_test(NAME WeightHuristicsFunctionTesting COMMAND weight_huristics_function_testing)
gtest_discover_tests(weight_huristics_function_testing)

# Register the test
add_test(NAME GeneratorStructFunctionalTesting COMMAND generator_struct_functional_testing)
gtest_discover_tests(generator_struct_functional_testing)



