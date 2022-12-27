#include <iostream>
#include <math.h>
#include <complex>
#include <iomanip>
#include <vector>
using namespace std;

template <class T>

class Matrix {
private:
	int rows, columns;
	vector<vector<T>> matrix;
public:
	double epsilon;
	Matrix(const Matrix<T>& src) = default;
	Matrix<T>& operator= (const Matrix<T>& src) = default;
	~Matrix() = default;
	Matrix();
	Matrix(int rows, int columns);
	void EnterMatrix();
	T& operator () (int i, int j);
	T operator () (int i, int j) const;
	Matrix operator + (const Matrix& rhs);
	Matrix operator - (const Matrix& rhs);
	Matrix operator * (const Matrix& rhs);
	Matrix operator * (const T& h);
	Matrix operator / (const T& h);
	bool operator == (const Matrix& rhs);

	auto begin() {
		return matrix.begin();
	}

	auto end() {
		return matrix.end();
	}

	friend Matrix operator * (const T& h, Matrix& matrix)
	{
		Matrix result(matrix.GetRows(), matrix.GetCols());
		result = matrix * h;
		return result;
	}
	friend std::ostream& operator << (std::ostream& s, const Matrix<T>& matrix)
	{
		for (int i = 0; i < matrix.rows; i++) {
			for (int j = 0; j < matrix.columns; j++)
				s << matrix.matrix[i][j] << " ";
			s << "\n";
		}
		return s;
	}
	int GetRows() const;
	int GetCols() const;
	T tr();
	Matrix<T> Solution_of_the_equation(const Matrix& Mat);
};
