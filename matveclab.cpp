#include<iostream>
#include<typeinfo>
#include "matveclab.h" // Matrix and Vector Class definition
using namespace std;

// Matrix class methods definition

void Matrix::SetMatrix()
// This method defines matrix
{
	cout << "----------X----------" << "\n" //
		<< "Define Matrix: " << endl;
	// Enter maximum number of rows and columns
	// Rows
	cout << "Enter total number of rows: " << endl;
	cin >> rows;
	// Check input type. If wrong, show error
	while (cin.fail())
	{
		cout << "Error: Invalid input type. Please try again" << "\n" << "Enter total number of rows: " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> rows;
	}
	// Column
	cout << "Enter total number of columns: " << endl;
	cin >> cols;
	// Check input type
	while (cin.fail())
	{
		cout << "Error: Invalid input type. Please try again" << "\n" << "Enter total number of columns: " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> cols;
	}
	// Assign matrix dimensions
	matrix = new double* [rows];
	for (int i = 0;i < rows;i++)
	{
		matrix[i] = new double[cols];
	}

	// Assign input elements of the matrix
	for (int i = 0;i < rows;i++)
	{
		for (int j = 0;j < cols;j++)
		{
			cout << "Enter the " << i << " row index and " << j << " column index element: " << endl;
			cin >> matrix[i][j];
			// Check input type
			while (cin.fail())
			{
				cout << "Error: Invalid input type. Please try again" << "\n" //
					<< "Enter the " << i << " row index and " << j << " column index element: " << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> matrix[i][j];
			}
		}
	}
	// Display matrix. Use predefined dispMatrix function
	for (int i = 0;i < rows;i++)
	{
		cout << "|";
		// For loop to iterate through matrix columns
		for (int j = 0;j < cols;j++)
		{
			cout << ":" << matrix[i][j] << ":";
		}
		cout << "|";
		cout << endl;
	}
}

void Matrix::AddMatrix(Matrix& m1, Matrix& m2)
// This method adds two matrices
{
	cout << "---------------------" << "\n" << //
		"Addition of matrices: " << endl;
	// If both inputs are vectors
	if (((m1.rows == 1 && m1.cols != 1) || (m1.rows != 1 && m1.cols == 1)) && ((m2.rows == 1 && m2.cols != 1) || (m2.rows != 1 && m2.cols == 1)))
	{
		cout << "Error: Both inputs are vectors" << "\n" <<//
			"For addition of two vectors, use function addVector" << endl;
	}
	if (((m1.rows == 1 && m1.cols != 1) || (m1.rows != 1 && m1.cols == 1)) || ((m2.rows == 1 && m2.cols != 1) || (m2.rows != 1 && m2.cols == 1)))
	{
		cout << "Error: One input is vector" << "\n" <<//
			"For addition of matrix and vector, use function addMatrixVector" << endl;
	}
	else if (m1.rows == m2.rows && m1.cols == m2.cols)
	{
		// Assign addition matrix
		double** matrix;
		matrix = new double* [m1.rows];
		for (int i = 0;i < m1.rows;i++)
		{
			matrix[i] = new double[m1.cols];
		}
		// Addition
		for (int i = 0; i < m1.rows; i++)
		{
			for (int j = 0; j < m1.cols; j++)
			{
				matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
			}
		}
		// Display matrix
		for (int i = 0;i < m1.rows;i++)
		{
			cout << "|";
			// For loop to iterate through matrix columns
			for (int j = 0;j < m1.cols;j++)
			{
				cout << ":" << matrix[i][j] << ":";
			}
			cout << "|";
			cout << endl;
		}
	}
	else
	{
		cout << "Error: Dimension mismatch. No addition possible" << endl;
	}
}

void Matrix::SubMatrix(Matrix& m1, Matrix& m2)
// This method subtracts two matrices
{
	cout << "---------------------" << "\n" << //
		"Subtraction of matrices: " << endl;
	// If both inputs are vectors
	if (((m1.rows == 1 && m1.cols != 1) || (m1.rows != 1 && m1.cols == 1)) && ((m2.rows == 1 && m2.cols != 1) || (m2.rows != 1 && m2.cols == 1)))
	{
		cout << "Error: Both inputs are vectors" << "\n" <<//
			"For subtraction of two vectors, use function subVector" << endl;
	}
	// First input vector and second matrix
	else if (((m1.rows == 1 && m1.cols != 1) || (m1.rows != 1 && m1.cols == 1)) && (m2.rows != 1 && m2.cols != 1))
	{
		cout << "Error: First input is vector" << "\n" <<//
			"For subtraction of vector and matrix, use function subVectorMatrix" << endl;
	}
	// First input matrix and second vector
	else if ((m1.rows != 1 && m1.cols != 1) && ((m2.rows == 1 && m2.cols != 1) || (m2.rows != 1 && m2.cols == 1)))
	{
		cout << "Error: Second input is vector" << "\n" <<//
			"For subtraction of matrix and vector, use function subMatrixVector" << endl;
	}
	else if (m1.rows == m2.rows && m1.cols == m2.cols)
	{
		// Assign subtraction matrix
		double** matrix;
		matrix = new double* [m1.rows];
		for (int i = 0;i < m1.rows;i++)
		{
			matrix[i] = new double[m1.cols];
		}
		// Subtraction
		for (int i = 0; i < m1.rows; i++)
		{
			for (int j = 0; j < m1.cols; j++)
			{
				matrix[i][j] = m1.matrix[i][j] - m2.matrix[i][j];
			}
		}
		// Display matrix
		for (int i = 0;i < m1.rows;i++)
		{
			cout << "|";
			// For loop to iterate through matrix columns
			for (int j = 0;j < m1.cols;j++)
			{
				cout << ":" << matrix[i][j] << ":";
			}
			cout << "|";
			cout << endl;
		}
	}
	else
	{
		cout << "Error: Dimension mismatch. No subtraction possible" << endl;
	}
}

void Matrix::MulMatrix(Matrix& m1, Matrix& m2)
// This method multiplies two matrices
{
	cout << "---------------------" << "\n" << //
		"Multiplication of matrices: " << endl;
	// Check multiplication conditions
	if (((m1.rows == 1 && m1.cols != 1) || (m1.rows != 1 && m1.cols == 1)) && (m2.rows != 1 && m2.cols != 1))
	{
		cout << "Error: First input is vector" << "\n" //
			<< "For multiplication of row vector and matrix, use function mulVectorMatrix" << "\n" <<//
			"For multiplication of matrix and column vector, use function mulMatrixVector" << endl;
	}
	else if ((m1.rows != 1 && m1.cols != 1) && ((m2.rows == 1 && m2.cols != 1) || (m2.rows != 1 && m2.cols == 1)))
	{
		cout << "Error: Second input is vector" << "\n" //
			<< "For multiplication of row vector and matrix, use function mulVectorMatrix" << "\n" <<//
			"For multiplication of matrix and column vector, use function mulMatrixVector" << endl;
	}
	else if (m1.cols != m2.rows)
	{
		cout << "Error: Dimension mismatch. Multiplication not possible" << "\n" //
			<< "Number of columns of first matrix must be equal to the number of rows of second matrix" << endl;
	}
	// Multiplication
	else if ((m1.rows == 1 && m1.cols == 1) || (m2.rows == 1 && m2.cols == 1))
	{
		cout << "Error: One of the input matrix has one row and one column, i.e., a scalar" << "\n"//
			<< "For scalar and matrix multiplication use scalarMulMatrix function" << endl;
	}
	else
	{
		// Assign multiplication matrix 
		double** matrix;
		matrix = new double* [m1.rows];
		for (int i = 0;i < m1.rows;i++)
		{
			matrix[i] = new double[m2.cols];
		}

		for (int i = 0;i < m1.rows;i++)
		{
			for (int j = 0;j < m2.cols;j++)
			{
				matrix[i][j] = 0;
				for (int k = 0;k < m1.rows;k++)
				{
					matrix[i][j] += (m1.matrix[i][k] * m2.matrix[k][j]);
					//rows = m1.rows;
					//cols = m2.cols;
				}
			}
		}
		// Display
		// For loop to iterate through matrix rows
		for (int i = 0;i < m1.rows;i++)
		{
			cout << "|";
			// For loop to iterate through matrix columns
			for (int j = 0;j < m2.cols;j++)
			{
				cout << ":" << matrix[i][j] << ":";
			}
			cout << "|";
			cout << endl;
		}
	}
}

void Matrix::EMulMatrix(Matrix& m1, Matrix& m2)
// This method performs elementwise multiplication of two matrices
{
	cout << "---------------------" << "\n" << //
		"Elementwise multiplication of matrices: " << endl;
	if (m1.rows == m2.rows && m1.cols == m2.cols)
	{
		// Assign elementwise multiplication matrix
		double** matrix;
		matrix = new double* [m1.rows];
		for (int i = 0;i < m1.rows;i++)
		{
			matrix[i] = new double[m1.cols];
		}
		// Elementwise multiplication
		for (int i = 0; i < m1.rows; i++)
		{
			for (int j = 0; j < m1.cols; j++)
			{
				matrix[i][j] = m1.matrix[i][j] * m2.matrix[i][j];
			}
		}
		// Display matrix
		for (int i = 0;i < m1.rows;i++)
		{
			cout << "|";
			// For loop to iterate through matrix columns
			for (int j = 0;j < m1.cols;j++)
			{
				cout << ":" << matrix[i][j] << ":";
			}
			cout << "|";
			cout << endl;
		}
	}
	else
	{
		cout << "Error: Dimension mismatch. No elementwise multiplication possible" << endl;
	}
}

void Matrix::ScalarMulMatrix(Matrix& m, double scalar)
// This method multiplies scalar and matrix
{
	cout << "---------------------" << "\n" << //
		"Scalar matrix multiplication: " << "\n" << //
		"Input scalar is: " << scalar << endl;
	// Assign scalar multiplication matrix
	if (typeid(scalar) != typeid(double))
	{
		cout << "Error: Invalid scalar input" << endl;
	}
	else if ((m.rows == 1 && m.cols != 1) || (m.rows != 1 && m.cols == 1))
	{
		cout << "Error: First input is vector" << "\n" //
			<< "For scalar vector multiplication, use function scalarMulVector" << endl;
	}
	else if (m.rows == 1 && m.cols == 1)
	{
		double element = 0;
		element = m.matrix[0][0] * scalar;
		cout << "|" << ":" << element << ":" << "|" << endl;
	}
	else
	{
		double** matrix;
		matrix = new double* [m.rows];
		for (int i = 0;i < m.rows;i++)
		{
			matrix[i] = new double[m.cols];
		}
		// Scalar matrix multiplication
		for (int i = 0;i < m.rows;i++)
		{
			for (int j = 0;j < m.cols;j++)
			{
				matrix[i][j] = m.matrix[i][j] * scalar;
			}
		}
		// Display
		for (int i = 0;i < m.rows;i++)
		{
			cout << "|";
			for (int j = 0;j < m.cols;j++)
			{
				cout << ":" << matrix[i][j] << ":";
			}
			cout << "|";
			cout << endl;
		}
	}
}

// End of the Matrix Class Methods
void Vector::SetVector(string s)
// This method defines vector
// This method requires one string input argument
// Possible string input arguments are 1. row, 2. column
// Row defines row vector. I.e. 1 row, multiple columns
// Column defines column vector. I.e. 1 column, multiple rows
// Calculations will be based on the input dimensions of row or column vector
{
	cout << "----------X----------" << "\n" //
		<< "Define Vector: " << endl;
	//bool flag{ true };
	if (s != "row" && s != "column")
	{
		//flag = false;
		cout << "Error: Invalid input argument" << "\n" << //
			"Valid input arguments: row / column" << endl;
		exit(0);
	}
	else if (typeid(s) != typeid(string))
	{
		cout << "Error: Invalid input argument" << "\n" << //
			"Valid input arguments: row / column" << endl;
		exit(0);
	}
	else if (s == "row")
	{
		rows_v = 1;
		cout << "Vector: Enter total number of elements" << endl;
		cin >> cols_v;
		while (cin.fail())
		{
			cout << "Error: Invalid input type. Please try again" << "\n" //
				<< "Vector: Enter total number of elements" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> cols_v;
		}
		vector = new double* [rows_v];
		for (int i = 0;i < rows_v;i++)
		{
			vector[i] = new double[cols_v];
		}
	}
	else if (s == "column")
	{
		cols_v = 1;
		cout << "Vector: Enter total number of elements " << endl;
		cin >> rows_v;
		while (cin.fail())
		{
			cout << "Error: Invalid input type. Please try again" << "\n" //
				<< "Vector: Enter total number of elements" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> rows_v;
		}
		vector = new double* [rows_v];
		for (int i = 0;i < rows_v;i++)
		{
			vector[i] = new double[cols_v];
		}
	}
	//if (flag = true)
	// Enter elements in vector
	for (int i = 0;i < rows_v;i++)
	{
		for (int j = 0;j < cols_v;j++)
		{
			cout << "Enter the " << i << " row index and " << j << " column index element: " << endl;
			cin >> vector[i][j];
			while (cin.fail())
			{
				cout << "Error: Invalid input type. Please try again" << "\n" //
					<< "Enter the " << i << " row index and " << j << " column index element: " << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> vector[i][j];
			}
			//flag = false;
		}
	}
	for (int i = 0;i < rows_v;i++)
	{
		cout << "|";
		for (int j = 0;j < cols_v;j++)
		{
			cout << ":" << vector[i][j] << ":";
		}
		cout << "|";
		cout << endl;
	}
}

void Vector::AddVector(Vector& v1, Vector& v2)
// This method performs addition of two vectors
{
	cout << "---------------------" << "\n" << //
		"Vector after addition: " << endl;
	if ((v1.rows_v != 1 && v1.cols_v != 1) && (v2.rows_v != 1 && v2.cols_v != 1))
	{
		cout << "Error: Both inputs are matrices" << "\n" //
			<< "For addition of two matrices, use function addMatrix" << endl;
	}
	else if ((v1.rows_v != 1 && v1.cols_v != 1) || (v2.rows_v != 1 && v2.cols_v != 1))
	{
		cout << "Error: One input is matrix" << "\n" //
			<< "For addition of matrix and vector, use function addMatrixVector" << endl;
	}
	else if (v1.rows_v == v2.rows_v && v1.cols_v == v2.cols_v)
	{
		//Final Vector Initialization
		vector = new double* [v1.rows_v];
		for (int i = 0;i < v1.rows_v;i++)
		{
			vector[i] = new double[v1.cols_v];
		}
		// Addition
		for (int i = 0; i < v1.rows_v; i++)
		{
			for (int j = 0; j < v1.cols_v; j++)
			{
				vector[i][j] = v1.vector[i][j] + v2.vector[i][j];
			}
		}
		// Display
		for (int i = 0;i < v1.rows_v;i++)
		{
			cout << "|";
			for (int j = 0;j < v1.cols_v;j++)
			{
				cout << ":" << vector[i][j] << ":";
			}
			cout << "|";
			cout << endl;
		}
	}
	else if (v1.rows_v != v2.rows_v && v1.cols_v != v2.cols_v)
	{
		//Final Vector Initialization
		if (v1.rows_v > v2.rows_v)
		{
			vector = new double* [v1.rows_v];
			for (int i = 0;i < v1.rows_v;i++)
			{
				vector[i] = new double[v2.cols_v];
			}
			// Addition
			for (int i = 0; i < v1.rows_v; i++)
			{
				for (int j = 0; j < v2.cols_v; j++)
				{
					vector[i][j] = v1.vector[i][0] + v2.vector[0][j];
				}
			}
			for (int i = 0;i < v1.rows_v;i++)
			{
				cout << "|";
				for (int j = 0;j < v2.cols_v;j++)
				{
					cout << ":" << vector[i][j] << ":";
				}
				cout << "|";
				cout << endl;
			}
		}
		else if (v1.rows_v < v2.rows_v)
		{
			vector = new double* [v2.rows_v];
			for (int i = 0;i < v2.rows_v;i++)
			{
				vector[i] = new double[v1.cols_v];
			}
			// Addition
			for (int i = 0; i < v2.rows_v; i++)
			{
				for (int j = 0; j < v1.cols_v; j++)
				{
					vector[i][j] = v2.vector[i][0] + v1.vector[0][j];
				}
			}
			for (int i = 0;i < v2.rows_v;i++)
			{
				cout << "|";
				for (int j = 0;j < v1.cols_v;j++)
				{
					cout << ":" << vector[i][j] << ":";
				}
				cout << "|";
				cout << endl;
			}
		}
	}
	else
	{
		cout << "Error: Dimension mismatch. No addition possible." << endl;
	}
}

void Vector::SubVector(Vector& v1, Vector& v2)
// This method performs subtraction of two vectors
{
	cout << "---------------------" << "\n";
	cout << "Vector after Subtraction: " << endl;
	if ((v1.rows_v != 1 && v1.cols_v != 1) && (v2.rows_v != 1 && v2.cols_v != 1))
	{
		cout << "Error: Both inputs are matrices" << "\n" //
			<< "For subtraction of two matrices, use function subMatrix" << endl;
	}
	else if ((v1.rows_v != 1 && v1.cols_v != 1) || (v2.rows_v != 1 && v2.cols_v != 1))
	{
		cout << "Error: One input is matrix" << "\n" //
			<< "For subtraction of matrix and vector, use function subMatrixVector" << "\n" << //
			"For subtraction of vector and matrix, use function subVectorMatrix" << endl;
	}

	else if (v1.rows_v == v2.rows_v && v1.cols_v == v2.cols_v)
	{
		//Final Vector Initialization
		vector = new double* [v1.rows_v];
		for (int i = 0;i < v1.rows_v;i++)
		{
			vector[i] = new double[v1.cols_v];
		}
		// Subtraction
		for (int i = 0; i < v1.rows_v; i++)
		{
			for (int j = 0; j < v1.cols_v; j++)
			{
				vector[i][j] = v1.vector[i][j] - v2.vector[i][j];
			}
		}
		// Display
		for (int i = 0;i < v1.rows_v;i++)
		{
			cout << "|";
			for (int j = 0;j < v1.cols_v;j++)
			{
				cout << ":" << vector[i][j] << ":";
			}
			cout << "|";
			cout << endl;
		}
	}
	else if (v1.rows_v != v2.rows_v && v1.cols_v != v2.cols_v)
	{
		//Final Vector Initialization
		if (v1.rows_v > v2.rows_v)
		{
			vector = new double* [v1.rows_v];
			for (int i = 0;i < v1.rows_v;i++)
			{
				vector[i] = new double[v2.cols_v];
			}
			// Subtraction
			for (int i = 0; i < v1.rows_v; i++)
			{
				for (int j = 0; j < v2.cols_v; j++)
				{
					vector[i][j] = v1.vector[i][0] - v2.vector[0][j];
				}
			}
			// Display
			for (int i = 0;i < v1.rows_v;i++)
			{
				cout << "|";
				for (int j = 0;j < v2.cols_v;j++)
				{
					cout << ":" << vector[i][j] << ":";
				}
				cout << "|";
				cout << endl;
			}
		}
		else if (v1.rows_v < v2.rows_v)
		{
			vector = new double* [v2.rows_v];
			for (int i = 0;i < v2.rows_v;i++)
			{
				vector[i] = new double[v1.cols_v];
			}
			// Subtraction
			for (int i = 0; i < v2.rows_v; i++)
			{
				for (int j = 0; j < v1.cols_v; j++)
				{
					vector[i][j] = v2.vector[i][0] - v1.vector[0][j];
				}
			}
			// Display
			for (int i = 0;i < v2.rows_v;i++)
			{
				cout << "|";
				for (int j = 0;j < v1.cols_v;j++)
				{
					cout << ":" << vector[i][j] << ":";
				}
				cout << "|";
				cout << endl;
			}
		}
	}
	else
	{
		cout << "Error: Dimension mismatch. No subtraction possible." << endl;
	}
}

void Vector::ScalarMulVector(Vector& v, double scalar)
// This method perfomrs scalar and vector multiplication
{
	cout << "---------------------" << "\n" << //
		"Scalar vector multiplication: " << "\n" << //
		"Input scalar is: " << scalar << endl;
	if (typeid(scalar) != typeid(double))
	{
		cout << "Error: Invalid scalar input" << endl;
		exit(0);
	}
	else if (v.rows_v != 1 && v.cols_v != 1)
	{
		cout << "Error: First input is matrix" << "\n" << //
			"For matrix and scalar multiplication, use function scalarMulMatrix" << endl;
	}
	else if (v.rows_v == 1 && v.cols_v == 1)
		// Exception: if vector has only one element
	{
		double element = 0;
		element = v.vector[0][0] * scalar;
		cout << "|" << ":" << element << ":" << "|" << endl;
	}
	else
	{
		vector = new double* [v.rows_v];
		for (int i = 0;i < v.rows_v;i++)
		{
			vector[i] = new double[v.cols_v];
		}
		// Scalar multiplication
		for (int i = 0;i < v.rows_v;i++)
		{
			for (int j = 0;j < v.cols_v;j++)
			{
				vector[i][j] = v.vector[i][j] * scalar;
			}
		}
		// Display
		for (int i = 0;i < v.rows_v;i++)
		{
			cout << "|";
			for (int j = 0;j < v.cols_v;j++)
			{
				cout << ":" << vector[i][j] << ":";
			}
			cout << "|";
			cout << endl;
		}
	}
}

// Friend Methods Definition
// Friend methods are common methods defined in two different classes
// With friend methods, properties of 2 different class objects can be used
// These methods are used to perform operations on 2 objects from different classes

void MulMatrixVector(Matrix& m, Vector& v)
// This method multiplies matrix and column vector
// To multiply column vector with a matrix, following conditions must be satisfied
// Matrix as first input argument
// Column vector as second input argument
// Number of columns of matrix must be equal to number of rows of column vector
{
	cout << "---------------------" << "\n" << //
		"Multiplication: Matrix * Column Vector = Column Vector" << endl;
	if (m.cols == v.rows_v)
	{
		double* solution = new double[m.cols];
		// Initilization
		for (int i = 0;i < m.cols;i++)
		{
			solution[i] = 0;
		}
		// Multiplication
		for (int i = 0;i < m.cols;i++)
		{
			for (int j = 0;j < v.rows_v;j++)
			{
				solution[i] += (m.matrix[i][j] * v.vector[j][0]);
			}
		}
		// Display
		for (int i = 0;i < v.rows_v;i++)
		{
			cout << "|" << solution[i] << "|" << endl;
		}
	}
	else
	{
		cout << "Error: Dimension mismatch. No multiplication possible." << endl;
	}
}

void MulVectorMatrix(Vector& v, Matrix& m)
// This method multiplies row vector and matrix
// To multiply row vector with a matrix, following conditions must be satisfied
// Row vector as first input argument
// Matrix as second input argument
// Number of columns of row vector must be equal to number of rows of matrix
{
	cout << "---------------------" << endl;
	cout << "Multiplication: Row Vector X Matrix = Row Vector" << endl;
	if (v.cols_v == m.rows)
	{
		double* solution = new double[v.cols_v];
		//initilization.
		for (int i = 0;i < v.cols_v;i++)
		{
			solution[i] = 0;
		}
		//multiplication.
		for (int i = 0;i < v.cols_v;i++)
		{
			for (int j = 0;j < m.rows;j++)
			{

				solution[i] += (m.matrix[j][i] * v.vector[0][j]);
			}
		}
		// Display
		for (int i = 0;i < v.cols_v;i++)
		{
			cout << "|" << solution[i] << "|";
		}
	}
	else
	{
		cout << "Error: Dimension mismatch. No multiplication possible." << endl;
	}
}

void AddMatrixVector(Matrix& m, Vector& v)
// This method adds matrix and vector
{
	cout << "---------------------" << "\n" //
		<< "Addition Matrix: Matrix + Vector" << endl;
	double** matrix;
	matrix = new double* [m.rows];
	for (int i = 0;i < m.rows;i++)
	{
		matrix[i] = new double[m.cols];
	}
	// Addition
	if (v.rows_v > v.cols_v && v.rows_v == m.rows)
	{
		for (int j = 0;j < m.cols;j++)
		{
			for (int i = 0;i < m.rows;i++)
			{
				matrix[i][j] = v.vector[i][0] + m.matrix[i][j];
			}
		}
		for (int i = 0;i < m.rows;i++)
		{
			cout << "|";
			for (int j = 0;j < m.cols;j++)
			{
				cout << ":" << matrix[i][j] << ":";
			}
			cout << "|";
			cout << endl;
		}
	}
	else if (v.cols_v > v.rows_v && v.cols_v == m.cols)
	{
		for (int i = 0;i < m.rows;i++)
		{
			for (int j = 0;j < v.cols_v;j++)
			{
				matrix[i][j] = v.vector[0][j] + m.matrix[i][j];
			}
		}
		// Display
		for (int i = 0;i < m.rows;i++)
		{
			cout << "|";
			for (int j = 0;j < m.cols;j++)
			{
				cout << ":" << matrix[i][j] << ":";
			}
			cout << "|";
			cout << endl;
		}
	}
	else
	{
		cout << "Error: Dimension mismatch. Addition not possible." << endl;
	}
}

void SubMatrixVector(Matrix& m, Vector& v)
// This method subtracts vector from a matrix
// subtraction of vector from matrix and subtraction of matrix from vector shows different results
{
	cout << "---------------------" << "\n" << //
		"Subtraction Matrix: Matrix - Vector" << endl;
	double** matrix;
	matrix = new double* [m.rows];
	for (int i = 0;i < m.rows;i++)
	{
		matrix[i] = new double[m.cols];
	}
	// Subtraction
	if (v.rows_v > v.cols_v && v.rows_v == m.rows)
	{
		for (int j = 0;j < m.cols;j++)
		{
			for (int i = 0;i < m.rows;i++)
			{
				matrix[i][j] = m.matrix[i][j] - v.vector[i][0];
			}
		}
		for (int i = 0;i < m.rows;i++)
		{
			cout << "|";
			for (int j = 0;j < m.cols;j++)
			{
				cout << ":" << matrix[i][j] << ":";
			}
			cout << "|";
			cout << endl;
		}
	}
	else if (v.cols_v > v.rows_v && v.cols_v == m.cols)
	{
		for (int j = 0;j < m.rows;j++)
		{
			for (int i = 0;i < v.cols_v;i++)
			{
				matrix[j][i] = m.matrix[j][i] - v.vector[0][i];
			}
		}
		// Display
		for (int i = 0;i < m.rows;i++)
		{
			cout << "|";
			for (int j = 0;j < m.cols;j++)
			{
				cout << ":" << matrix[i][j] << ":";
			}
			cout << "|";
			cout << endl;
		}
	}
	else
	{
		cout << "Error: dimension mismatch. Subtraction not possible." << endl;
	}
}

void SubVectorMatrix(Vector& v, Matrix& m)
// This method subtracts matrix from a vector
// subtraction of vector from matrix and subtraction of matrix from vector shows different results
{
	cout << "---------------------" << "\n" << //
		"Subtraction Matrix: Vector - Matrix" << endl;
	double** matrix;
	matrix = new double* [m.rows];
	for (int i = 0;i < m.rows;i++)
	{
		matrix[i] = new double[m.cols];
	}
	// Subtraction
	if (v.rows_v > v.cols_v && v.rows_v == m.rows)
	{
		for (int j = 0;j < m.rows;j++)
		{
			for (int i = 0;i < m.cols;i++)
			{
				matrix[j][i] = v.vector[i][0] - m.matrix[j][i];
			}
		}
		// Display
		for (int i = 0;i < m.rows;i++)
		{
			cout << "|";
			for (int j = 0;j < m.cols;j++)
			{
				cout << ":" << matrix[i][j] << ":";
			}
			cout << "|";
			cout << endl;
		}
	}
	else if (v.cols_v > v.rows_v && v.cols_v == m.cols)
	{
		// Subtraction
		for (int i = 0;i < m.rows;i++)
		{
			for (int j = 0;j < v.cols_v;j++)
			{
				matrix[i][j] = v.vector[0][j] - m.matrix[i][j];
			}
		}
		// Display
		for (int i = 0;i < m.rows;i++)
		{
			cout << "|";
			for (int j = 0;j < m.cols;j++)
			{
				cout << ":" << matrix[i][j] << ":";
			}
			cout << "|";
			cout << endl;
		}
	}
	else
	{
		cout << "Error: Dimension mismatch. Subtraction not possible." << endl;
	}
}
