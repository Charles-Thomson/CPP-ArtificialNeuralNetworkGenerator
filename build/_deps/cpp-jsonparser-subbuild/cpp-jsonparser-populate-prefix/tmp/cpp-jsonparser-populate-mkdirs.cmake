# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-jsonparser-src")
  file(MAKE_DIRECTORY "C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-jsonparser-src")
endif()
file(MAKE_DIRECTORY
  "C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-jsonparser-build"
  "C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-jsonparser-subbuild/cpp-jsonparser-populate-prefix"
  "C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-jsonparser-subbuild/cpp-jsonparser-populate-prefix/tmp"
  "C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-jsonparser-subbuild/cpp-jsonparser-populate-prefix/src/cpp-jsonparser-populate-stamp"
  "C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-jsonparser-subbuild/cpp-jsonparser-populate-prefix/src"
  "C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-jsonparser-subbuild/cpp-jsonparser-populate-prefix/src/cpp-jsonparser-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-jsonparser-subbuild/cpp-jsonparser-populate-prefix/src/cpp-jsonparser-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/Charl/source/repos/C++/CPP-ArtificialNeuralNetworkGenerator/build/_deps/cpp-jsonparser-subbuild/cpp-jsonparser-populate-prefix/src/cpp-jsonparser-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
