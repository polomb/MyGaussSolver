#ifndef _MY_MATRIX_
#define _MY_MATRIX_

#include "Vector.h"

#define EPS 1e-13

class Matrix
{
private:
	int y = 0; int x = 0;
	Vector matrix;
public:
	Matrix() {}
	Matrix(int n, int m)
	{
		y = n; x = m;
		matrix.obnulenie(n * m);
	}
	double& operator()(int i, int j)
	{
		//ПОТОМ УДАЛИТЬ
		if (i >= y || j >= x)
			std::cout << "Error: MatrixOperator()";
		//ПОТОМ УДАЛИТЬ
		//Вернуть A[i,j]
		return matrix[i * x + j];
	}
	double operator()(int i, int j) const
	{
		//ПОТОМ УДАЛИТЬ
		if (i >= y || j >= x)
			std::cout << "Error: MatrixOperator()";
		//ПОТОМ УДАЛИТЬ
		//Вернуть A[i,j]
		return matrix[i * x + j];
	}
	int getX() { return x; }
	int getY() { return y; }
	void swapLine(int y1, int y2, int h = 0)
	{
		int x = this->getX();
		Vector temp(x);
		for (int j = 0; j < x; j++)
		{
			temp[j] = matrix[y1 * x + j];
		}
		for (int j = 0; j < x; j++)
		{
			matrix[y1 * x + j] = matrix[y2 * x + j];
		}
		for (int j = 0; j < x; j++)
		{
			matrix[y2 * x + j] = temp[j];
		}
	}
	void swapRow(int x1, int x2, int h = 0)
	{
		int y = this->getY();
		Vector temp(x);
		for (int i = 0; i < y; i++)
		{
			temp[i] = matrix[i * x + x1];
		}
		for (int i = 0; i < y; i++)
		{
			matrix[i * x + x1] = matrix[i * x + x2];
		}
		for (int i = 0; i < y; i++)
		{
			matrix[i * x + x2] = temp[i];
		}
	}
	bool IsLineEqualsZero(int i)
	{
		int x = this->getX();
		for (int j = 0; j < x; j++)
		{
			if (matrix[i * x + j] > EPS)
				return false;
		}
		return true;
	}
	bool IsRowEqualsZero(int j)
	{
		int x = this->getX();
		for (int i = 0; i < x; i++)
		{
			if (matrix[i * x + j] > EPS)
				return false;
		}
		return true;
	}
	Matrix(const Matrix& copy)
	{
		this->y = copy.y; this->x = copy.x;
		this->matrix = copy.matrix;
	}
	void print() const
	{
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
				std::cout << matrix[x * i + j] << " ";
			std::cout << std::endl;
		}
	}
	void resize(int i, int j)
	{
		y = i;
		x = j;
		matrix.resize(x*y);
	}
	void resizeXY(int i, int j)
	{
		Vector dop(i*j);
		for (int yy = 0; yy < i; yy++)
		{
			for (int xx = 0; xx < j; xx++)
			{
				dop[yy*j+xx] = matrix[yy * x + xx];
			}
		}
		matrix.resize(x * y);
		for (int yy = 0; yy < i; yy++)
		{
			for (int xx = 0; xx < j; xx++)
			{
				matrix[yy * j + xx] = dop[yy * j + xx];
			}
		}
		y = i;
		x = j;
	}
};

#endif