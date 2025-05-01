#ifndef _MY_MATRIX_
#define _MY_MATRIX_

#include "Vector.h"

class Matrix
{
private:
	int y = 0; int x = 0;
	Vector* matrix;
	Vector atrix;
public:
	Matrix(){}
	Matrix(int n, int m)
	{
		y = n; x = m;
		matrix = new Vector [n];
		for (int i = 0; i < n; i++)
			matrix[i].obnulenie(m);
	}
	double& operator()(int i, int j)
	{
		//ÏÎÒÎÌ ÓÁÐÀÒÜ
		if (i >= y || j >= x)
			std::cout << "Error: MatrixOperator()";
		//ÏÎÒÎÌ ÓÁÐÀÒÜ
		//Âåðíóòü A[i,j]
		return matrix[i][j];
	}
	double operator()(int i, int j) const
	{
		//ÏÎÒÎÌ ÓÁÐÀÒÜ
		if (i >= y || j >= x)
			std::cout << "Error: MatrixOperator()";
		//ÏÎÒÎÌ ÓÁÐÀÒÜ
		//Âåðíóòü A[i,j]
		return matrix[i][j];
	}
	double MaxRow(int j)
	{
		//ÏÎÒÎÌ ÓÁÐÀÒÜ
		if (j >= x)
			std::cout << "Error: MatrixMaxRow";
		//ÏÎÒÎÌ ÓÁÐÀÒÜ
		double MaxRow = matrix[0][j];
		for (int i = 0; i < y; i++)
		{
			MaxRow = std::max(MaxRow, matrix[i][j]);
		}
		return MaxRow;
	}
	double MaxLine(int i)
	{
		//ÏÎÒÎÌ ÓÁÐÀÒÜ
		if (i >= y)
			std::cout << "Error: MatrixMaxLine";
		//ÏÎÒÎÌ ÓÁÐÀÒÜ
		double MaxLine = matrix[i][0];
		for (int j = 0; j < x; j++)
		{
			MaxLine = std::max(MaxLine, matrix[i][j]);
		}
		return MaxLine;
	}
	void swapLine(int y1, int y2, int x)
	{
		for (int j = 0; j < x; j++)
		{
			double temp = matrix[y1][j];;
			matrix[y1][j] = matrix[y2][j];
			matrix[y2][j] = temp;
		}
	}
	void print() const 
	{
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
				std::cout << matrix[i][j] << " ";
			std::cout << std::endl;
		}
    }
};

#endif