#include "Matrices.h"

namespace Matrices
{

	Matrix::Matrix(int _rows, int _cols)
	{
		if (_rows < 0 || _cols < 0)
		{
			throw runtime_error("Error: invalid matrix size");
		}
		rows = _rows;
		cols = _cols;
		a.resize(rows, vector<double>(cols, 0));
	}

	Matrix operator+(const Matrix& a, const Matrix& b)
	{
		if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
		{
			throw runtime_error("Error: dimensions must agree");
		}
		Matrix c(a.getRows(), a.getCols());
		for (int row = 0; row < c.getRows(); row++)
		{
			for (int col = 0; col < c.getCols(); col++)
			{
				c(row, col) = a(row, col) + b(row, col);
			}
		}
		return c;
	}

	Matrix operator-(const Matrix& a)
	{
		Matrix matrix = a;
		for (int row = 0; row < a.getRows(); row++)
		{
			for (int col = 0; col < a.getCols(); col++)
			{
				matrix(row, col) = matrix(row, col) * -1;
			}
		}
		return matrix;
	}

	Matrix operator-(const Matrix& a, const Matrix& b)
	{
		Matrix c = a + -b;
		return c;
	}

	Matrix operator*(const Matrix& a, const Matrix& b)
	{
		if (a.getCols() != b.getRows())
		{
			throw runtime_error("Error: dimensions must agree");
		}
		Matrix c(a.getRows(), b.getCols());
		for (int row = 0; row < c.getRows(); row++)
		{
			for (int col = 0; col < c.getCols(); col++)
			{
				for (int i = 0; i < b.getRows(); i++)
				{
					c(row, col) += a(row, i) * b(i, col);
				}
			}
		}
		return c;
	}

	bool operator==(const Matrix& a, const Matrix& b)
	{
		if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
		{
			return false;
		}
		for (int row = 0; row < a.getRows(); row++)
		{
			for (int col = 0; col < a.getCols(); col++)
			{
				if (abs(a(row, col) - b(row, col)) > 0.001)
				{
					return false;
				}
			}
		}
		return true;
	}

	bool operator!=(const Matrix& a, const Matrix& b)
	{
		return !(a == b);
	}

	ostream& operator<<(ostream& os, const Matrix& a)
	{
		for (int i = 0; i < a.getRows(); i++)
		{
			for (int k = 0; k < a.getCols(); k++)
			{
				os << setw(11) << a(i, k);
			}
			os << '\n';
		}
		return os;
	}
}