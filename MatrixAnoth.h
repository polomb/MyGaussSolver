#ifndef _MY_MATRIX_
#define _MY_MATRIX_

#include "Vector.h"

class Matrix
{
private:
	int y = 0; int x = 0;
	Vector matrix;
public:
	Matrix(){}
	Matrix(int n, int m)
	{
		y = n; x = m;
		matrix.obnulenie(n * m);
	}
	double& operator()(int i, int j)
	{
		//ÏÎÒÎÌ ÓÁĞÀÒÜ
		if (i >= y || j >= x)
			std::cout << "Error: MatrixOperator()";
		//ÏÎÒÎÌ ÓÁĞÀÒÜ
		//Âåğíóòü A[i,j]
		return matrix[i * y + j];
	}
	double operator()(int i, int j) const
	{
		//ÏÎÒÎÌ ÓÁĞÀÒÜ
		if (i >= y || j >= x)
			std::cout << "Error: MatrixOperator()";
		//ÏÎÒÎÌ ÓÁĞÀÒÜ
		//Âåğíóòü A[i,j]
		return matrix[i * y + j];
	}
	double MaxRow(int j)
	{
		//ÏÎÒÎÌ ÓÁĞÀÒÜ
		if (j >= x)
			std::cout << "Error: MatrixMaxRow";
		//ÏÎÒÎÌ ÓÁĞÀÒÜ
		double MaxRow = matrix[j];
		for (int i = 0; i < y; i++)
		{
			MaxRow = std::max(MaxRow, matrix[i * y + j]);
		}
		return MaxRow;
	}
	double MaxLine(int i)
	{
		//ÏÎÒÎÌ ÓÁĞÀÒÜ
		if (i >= y)
			std::cout << "Error: MatrixMaxLine";
		//ÏÎÒÎÌ ÓÁĞÀÒÜ
		double MaxLine = matrix[i * y];
		for (int j = 0; j < x; j++)
		{
			MaxLine = std::max(MaxLine, matrix[i * y + j]);
		}
		return MaxLine;
	}
	void swapLine(int y1, int y2, int x)
	{
		for (int j = 0; j < x; j++)
		{
			double temp = matrix[y1 * x + j];
			matrix[y1 * x + j] = matrix[y2 * x + j];
			matrix[y2 * x + j] = temp;
		}
	}
	void print() const 
	{
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
				std::cout << matrix[y*i + j] << " ";
			std::cout << std::endl;
		}
    }
};

#endif