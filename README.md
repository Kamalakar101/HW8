Matrix Operations Project

AUTHORING

- Author(s): Kamalakar Reddy  
- Affiliation: University of Maryland, Baltimore County (UMBC)  
- Course: CMSC 313, 1430, MW  
- Date: 4/19/25

PURPOSE OF SOFTWARE

This software implements matrix operations such as addition, scaling, multiplication, and transposition. It provides both an object-oriented (C++) and procedural (C) approach to matrix operations.

FILES

- Matrix.h: Header file for the C++ `Matrix` class, declaring all matrix operations.
- Matrix.cpp: Implementation of the C++ `Matrix` class and its methods.
- driver.cpp: Main driver file for the C++ implementation, demonstrating the use of the `Matrix` class.
- cmatrix.h: Header file for the procedural C implementation of matrix operations.
- cmatrix.c: Source file for the procedural C implementation of matrix operations.
- cdriver.c: Main driver file for the C implementation, demonstrating the use of C functions for matrix operations.
- Makefile: Build script for compiling and running the project. (C++)

BUILD INSTRUCTIONS

(C++):

1. To compile the C++ implementation:
    make

2. To run the C++ program:
    make run

(C):

1. To compile the C implementation:
   gcc cmatrix.c cdriver.c -o cdriver

2. To run the C program:
  ./cdriver.exe


TESTING METHODOLOGY

The testing methodology involved running various matrix operations on small matrices. These operations include:
- Printing matrices to verify correctness.



ADDITIONAL INFORMATION

- The driver files for both implementations have the given equation and runs them. I didn't add any operator overloading for the matrix operations because
  I wasn't sure if I needed to. 
