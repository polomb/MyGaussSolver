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
		//Вернуть A[i,j]
		return matrix[i * x + j];
	}
	double operator()(int i, int j) const
	{
		//Вернуть A[i,j]
		return matrix[i * x + j];
	}
	int getX() { return x; }
	int getY() { return y; }
	void setX(int xx){ this->x = xx; }
	void setY(int yy) { this->y = yy; }
	void swapLine(int y1, int y2, int h = 0)
	{
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
	void swapColumn(int x1, int x2, int h = 0)
	{
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
	void DestroyColumn(int xx)
	{
		this->x -= 1;
		Vector dop = matrix;
		matrix.resize(y * x);
		for (int j = 0; j < x; j++)
		{
			for (int i = 0; i < y; i++)
			{
				if (j < xx)
				{
					matrix[i * x + j] = dop[i * (x+1) + j];
				}
				else
				{
					matrix[i * x + j] = dop[i * (x+1) + j + 1];
				}
			}
		}
	}
	bool IsLineEqualsZero(int i)
	{
		for (int j = 0; j < x; j++)
		{
			if (matrix[i * x + j] > EPS)
				return false;
		}
		return true;
	}
	bool IsColumnEqualsZero(int j)
	{
		for (int i = 0; i < y; i++)
		{
			if (matrix[i * x + j] > EPS)
				return false;
		}
		return true;
	}
	bool IsPartColumnEqualsZero(int j, int nachalo)
	{
		for (int i = nachalo; i < y; i++)
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
};

#endif