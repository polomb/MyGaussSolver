#ifndef _GAUSS_SOLVER_
#define _GAUSS_SOLVER_

#include <vector>

#include "Matrix.h"

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
		int YMinusX = 0;
		int ColumnsDeleted = 0;
		std::vector<int> pizza;
		for (int i = 0; i < x; i++)
		{
			if (matrix.IsColumnEqualsZero(i))
			{
				x -= 1;
				ColumnsDeleted += 1;
				matrix.DestroyColumn(i);
				pizza.push_back(i);
			}
		}
		if (x > y)
		{
			y = x;
			matrix.resize(y, x);
			vector.resize(y);
		}
		else if (y > x)
		{
			YMinusX = y - x;
			y = x;
		}
		Vector KOtvetu(y);
		std::vector<Vector> otvet;

		int h = 0;
		int index;
		double maxColumn;
		for (h = 0; h < y; h++)
		{
			//Находим наибольшую строку
			index = h;
			maxColumn = abs(matrix(h,h));
			for (int i = h; i < y; i++)
			{
				if (maxColumn < abs(matrix(i, h)))
				{
					index = i;
					maxColumn = abs(matrix(i, h));
				}
			}
			//Берём наибольшую строку
			if (h != index)
			{
				matrix.swapLine(h, index, h);
				maxColumn = vector[h];
				vector[h] = vector[index];
				vector[index] = maxColumn;
			}
			//Приводим к треугольному виду
			for (int i = h; i < y; i++)
			{
				double temp = matrix(i,h);
				if (abs(temp) < EPS) continue;
				for (int j = h; j < x; j++)
				{
					matrix(i, j) = matrix(i, j) / temp;
				}
				vector[i] = vector[i] / temp;
				if (i == h)  continue;
				for (int j = 0; j < x; j++)
				{
					matrix(i, j) = matrix(i, j) - matrix(h, j);
				}
				vector[i] = vector[i] - vector[h];
			}
		}
		//Адэкватирование ответа
		int count = 0;
		for (h = y - 1; h >= 0; h--)
		{
			if (matrix.IsLineEqualsZero(h))
			{
				if (vector[h] >= EPS)
				{
					otvet.push_back(KOtvetu);
					return otvet;
				}
				count += 1;
			}
			else
			{
				break;
			}
		}
		while (y > x && count > 0)
		{
			y -= 1;
			count -= 1;
		}
		//Обратный ход
		for (h = y - 1; h > y - 1 - count; h--)
		{
			KOtvetu[h] = vector[h];
		}
		for (h = y - 1 - count; h >= 0; h--)
		{
			KOtvetu[h] = vector[h];
			for (int i = 0; i < h; i++)
				vector[i] = vector[i] - matrix(i, h) * vector[h];
		}
		//
		while (YMinusX > 0)
		{
			double res = 0;
			for (int i = 0; i < x; i++)
			{
				res += matrix(y + YMinusX - 1, i) * KOtvetu[i];
			}
			if ((res - vector[y + YMinusX - 1]) > EPS)
			{
				return otvet;
			}
			YMinusX -= 1;
		}
		for (int P = ColumnsDeleted; P > 0; P--)
		{
			KOtvetu.insert(pizza[P-1], 0.0);
		}
		//
		KOtvetu.print();
		otvet.push_back(KOtvetu);
		//Доп Вектора
		for (h = count; h > 0; h--)
		{
			Vector DopVect(y);
			Vector dopOtvet(y);
			for (int i = 0; i < y; i++)
			{
				dopOtvet[i] = matrix(i, x - h);
			}
			for (int g = y - 1; g > y - 1 - count; g--)
			{
				DopVect[g] = dopOtvet[g];
			}
			for (int g = y - 1 - count; g >= 0; g--)
			{
				DopVect[g] = dopOtvet[g];
				for (int i = 0; i < g; i++)
					dopOtvet[i] = dopOtvet[i] - matrix(i, g) * dopOtvet[g];
			}
			for (int P = ColumnsDeleted; P > 0; P--)
			{
				DopVect.insert(pizza[P-1], 0.0);
			}
			DopVect[y - h] = 1;
			//DopVect.print();
			otvet.push_back(DopVect);
		}
		return otvet;
	}
};

#endif

