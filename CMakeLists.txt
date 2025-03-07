# CMakeLists.txt for CPP-ArtificialNeuralNetworkGenerator
cmake_minimum_required (VERSION 3.11)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (CPP-ArtificialNeuralNetworkGenerator)



 add_library(CPP-ArtificialNeuralNetworkGenerator SHARED
    CPP-ArtificialNeuralNetworkGenerator.cpp 
    CPP-ArtificialNeuralNetworkGenerator.h 
    PreProcessing/InstanceConfigObject/ANNConfigurationObject/ANNConfigObject.cpp
    PreProcessing/InstanceConfigObject/ANNConfigurationObject/ANNConfigObject.h
    PreProcessing/InstanceConfigObject/ANNConfigurationObject/ANNLayerObject.cpp
    PreProcessing/InstanceConfigObject/ANNConfigurationObject/ANNLayerObject.h
    PreProcessing/InstanceConfigObject/EnvironemntConfigurationObject/EnvironmentConfigObject.cpp 
    PreProcessing/InstanceConfigObject/EnvironemntConfigurationObject/EnvironmentConfigObject.h 
    PreProcessing/InstanceConfigObject/HyperParameterConfigurationObject/HyperParameterConfigObject.cpp
    PreProcessing/InstanceConfigObject/HyperParameterConfigurationObject/HyperParameterConfigObject.h
    PreProcessing/InstanceConfigObject/InstanceConfigurationObject/InstanceConfigObject.cpp
    PreProcessing/InstanceConfigObject/InstanceConfigurationObject/InstanceConfigObject.h
 
  )

 
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CPP-ArtificialNeuralNetworkGenerator PROPERTY CXX_STANDARD 20)
endif()

# Fetch content for CPP-JSONParser from GitHub
include(FetchContent)
FetchContent_Declare(
    CPP-JSONParser
    GIT_REPOSITORY https://github.com/Charles-Thomson/CPP-JSONParser.git
)
FetchContent_MakeAvailable(CPP-JSONParser)

# Include the CPP-JSONParser headers in the project
target_include_directories(
    CPP-ArtificialNeuralNetworkGenerator PRIVATE 
    ${CPP-JSONParser_SOURCE_DIR}
    ${CPP-JSONParser_SOURCE_DIR}/Structs
    ${CPP-JSONParser_SOURCE_DIR}/FileReader
    ${CPP-JSONParser_SOURCE_DIR}/ExposedFunctions


)

# Link the CPP-JSONParser library (shared/static depending on what was built)
# target_link_libraries(CPP-ArtificialNeuralNetworkGenerator PRIVATE CPP-JSONParser)

# Optional: If you want to explicitly link against the static library (if necessary):
target_link_libraries(CPP-ArtificialNeuralNetworkGenerator PRIVATE CPP-JSONParserStatic)

# TODO: Add tests and install targets if needed.