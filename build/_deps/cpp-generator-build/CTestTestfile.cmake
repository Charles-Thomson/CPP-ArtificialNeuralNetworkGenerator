# CMake generated Testfile for 
# Source directory: C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-generator-src
# Build directory: C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-generator-build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
include("C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-generator-build/generator_testing[1]_include.cmake")
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(Generator_Testing "C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-generator-build/Debug/generator_testing.exe")
  set_tests_properties(Generator_Testing PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-generator-src/CMakeLists.txt;69;add_test;C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-generator-src/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(Generator_Testing "C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-generator-build/Release/generator_testing.exe")
  set_tests_properties(Generator_Testing PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-generator-src/CMakeLists.txt;69;add_test;C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-generator-src/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(Generator_Testing "C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-generator-build/MinSizeRel/generator_testing.exe")
  set_tests_properties(Generator_Testing PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-generator-src/CMakeLists.txt;69;add_test;C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-generator-src/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(Generator_Testing "C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-generator-build/RelWithDebInfo/generator_testing.exe")
  set_tests_properties(Generator_Testing PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-generator-src/CMakeLists.txt;69;add_test;C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-generator-src/CMakeLists.txt;0;")
else()
  add_test(Generator_Testing NOT_AVAILABLE)
endif()
