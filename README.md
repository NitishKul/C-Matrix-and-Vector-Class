# C-Matrix-and-Vector-Class

Matrix-Vector Class definition and methods declaration in C++.

In matveclab.h, both Matrix and Vector Classes have been defined.

In matveclab.cpp, all the methods (functions) that belong to both
Matrix and Vector Classes have been defined.

Key point(s): 
Dynamic array allocation. E.g., dynamic matrix or vector.
Function exception handling methods.

List of all Matrix Class functions:
SetMatrix(); // Method: Define matrix		
AddMatrix(Matrix&, Matrix&); // Method: Addition of two Matrices
SubMatrix(Matrix&, Matrix&); // Method: Subtraction of two Matrices
MulMatrix(Matrix&, Matrix&); // Method: Multiplication of two Matrices
EMulMatrix(Matrix&, Matrix&); // Method: Elementwise Multiplication of two Matrices	
ScalarMulMatrix(Matrix&, double scalar); // Method: Scalar and matrix multiplication

List of all Vector Class functions:
SetVector(string s); // Method: Define Vector	
AddVector(Vector&, Vector&); // Method: Addition of two Vectors
SubVector(Vector&, Vector&); // Method: Subtraction of two Vectors
ScalarMulVector(Vector&, double scalar);  // Method: Scalar and Vector Multiplication

List of common functions:
MulMatrixVector(Matrix&, Vector&); 
MulVectorMatrix(Vector&, Matrix&);
SubMatrixVector(Matrix&, Vector&);
SubVectorMatrix(Vector&, Matrix&);
