#include<iostream>
#include<typeinfo>
using namespace std;

// Step1. Define classes (Vector Class and Matrix Class)

class Vector; //class Vector, Definition of vector class and its methods after the definition of Matrix Class

class Matrix  // Define Matrix Class
{
public:
	int rows, cols; // Variables: Dynamic number of rows and columns
	double** matrix; // Array: Dynamic matrix                           
	void SetMatrix(); // Method: Define matrix		
	void AddMatrix(Matrix&, Matrix&); // Method: Addition of two Matrices
	void SubMatrix(Matrix&, Matrix&); // Method: Subtraction of two Matrices
	void MulMatrix(Matrix&, Matrix&); // Method: Multiplication of two Matrices
	void EMulMatrix(Matrix&, Matrix&); // Method: Elementwise Multiplication of two Matrices	
	void ScalarMulMatrix(Matrix&, double scalar); // Method: Scalar and matrix multiplication
	friend void MulMatrixVector(Matrix&, Vector&); // Method: Matrix and column vector multiplication
	friend void MulVectorMatrix(Vector&, Matrix&); // Method: Row vector and matrix multiplication
	friend void AddMatrixVector(Matrix&, Vector&); // Method: Matrix and vector addition
	friend void SubMatrixVector(Matrix&, Vector&); // Method: Matrix and vector subtraction
	friend void SubVectorMatrix(Vector&, Matrix&); // Method: Vector and matrix subtraction
};

class Vector // Define Vector Class
{
public:
	int rows_v, cols_v; // Variables
	double** vector; // Array: Dynamc vector array 
	void SetVector(string s); // Method: Define Vector	
	void AddVector(Vector&, Vector&); // Method: Addition of two Vectors
	void SubVector(Vector&, Vector&); // Method: Subtraction of two Vectors
	void ScalarMulVector(Vector&, double scalar);  // Method: Scalar and Vector Multiplication
	friend void MulMatrixVector(Matrix&, Vector&);
	friend void MulVectorMatrix(Vector&, Matrix&);
	friend void SubMatrixVector(Matrix&, Vector&);
	friend void SubVectorMatrix(Vector&, Matrix&);
};
