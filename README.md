Neural Network Training Pipeline

Overview

This project is a C++ implementation of a pipeline for creating and training artificial neural networks. Built using CMake, the project aims to provide a structured workflow for defining, generating, and training neural networks efficiently.

Features

JSON Parser: Parses configuration files for defining neural network architectures and training parameters.

Generation Pipeline: Handles the structured creation of neural networks based on user-defined configurations.

Training Pipeline: Implements the training mechanism for optimizing neural network performance.

Prerequisites

To build and run the project, ensure you have the following dependencies installed:

C++ Compiler (C++17 or later recommended)

CMake (version 3.10 or later)

Roadmap

Future improvements and features include:

Implementing different activation functions

Support for saving/loading trained models

Current Bugs:

- Parser Type passing
  The passing of vector<> types to the parser does not correctly return.

- Import of Parser - FIXED
  Importing the single exposed .h file results in some file path related issues 

Currently implementing:

Pre processing / staging of work items

Next To be implemented:

Work item Processing 

