#ifndef _GAUSS_SOLVER_
#define _GAUSS_SOLVER_

#include <vector>

#include "Matrix.h"

#define EPS 1e-15

class GaussSolver
{
public:
	GaussSolver(){}
	std::vector<Vector> solve(const Matrix& m, const Vector& v)
	{
		//Возвращается std::vector<Vector> 1,0,{V0, V1, ... , Vk}, V0 - вектор сдвига
		Matrix matrix = m;
		int y = matrix.getY();
		int x = matrix.getX();
		Vector vector = v;
		Vector KOtvetu(y);
		std::vector<Vector> otvet;

		int h = 0;
		int index;
		double maxRow;
		for (h = 0; h < y; h++)
		{
			//Находим наибольшую строку
			index = h;
			maxRow = abs(matrix(h,h));
			for (int i = h; i < y; i++)
			{
				if (maxRow < abs(matrix(i, h)))
				{
					index = i;
					maxRow = abs(matrix(i, h));
				}
			}
			//Берём наибольшую строку
			if (h != index)
			{
				matrix.swapLine(h, index, h);
				maxRow = vector[h];
				vector[h] = vector[index];
				vector[index] = maxRow;
			}
			//Приводим к треугольному виду
			for (int i = h; i < y; i++)
			{
				double temp = matrix(i,h);
				if (abs(temp) < EPS) continue;
				for (int j = h; j < x; j++)
					matrix(i, j) = matrix(i, j) / temp;
				vector[i] = vector[i] / temp;
				if (i == h)  continue;
				for (int j = 0; j < x; j++)
					matrix(i, j) = matrix(i, j) - matrix(h, j);
				vector[i] = vector[i] - vector[h];
			}
		}
		//Обратный ход
		for (h = y - 1; h >= 0; h--)
		{
			KOtvetu[h] = vector[h];
			for (int i = 0; i < h; i++)
				vector[i] = vector[i] - matrix(i,h) * vector[h];
		}
		otvet.push_back(KOtvetu);
		return otvet;
	}
};

#endif