#ifndef _GAUSS_SOLVER_
#define _GAUSS_SOLVER_

#include <vector>

#include "Matrix.h"

#define EPS 1e-15

class GaussSolver
{
public:
	GaussSolver() {}
	std::vector<Vector> solve(const Matrix& m, const Vector& v)
	{
		Matrix matrix = m;
		int y = matrix.getY();
		int x = matrix.getX();
		Vector vector = v;
		Vector KMeshaniu(x);
		std::vector<Vector> otvet;
		for (int i = 0; i < x; i++)
		{
			KMeshaniu[i] = i;
		}
		int h = 0;
		int index;
		double maxLine;
		for (h = 0; h < y; h++)
		{
			index = h;
			int maxColumn = 0;
			for (int i = h; i < x; i++)
			{
				if ((matrix.IsPartColumnEqualsZero(h, h)))
				{
					if (h != i)
					{
						matrix.swapColumn(h, i);
						double lll = KMeshaniu[h];
						KMeshaniu[h] = KMeshaniu[i];
						KMeshaniu[i] = lll;
					}
					maxColumn += 1;
				}
			}
			if (maxColumn == x - h)
				break;
			if (h != index)
			{
				matrix.swapLine(h, index, h);
				maxLine = vector[h];
				vector[h] = vector[index];
				vector[index] = maxLine;
			}
			//
			index = h;
			maxLine = abs(matrix(h, h));
			for (int i = h; i < y; i++)
			{
				if (maxLine < abs(matrix(i, h)))
				{
					index = i;
					maxLine = abs(matrix(i, h));
				}
			}
			//
			if (h != index)
			{
				matrix.swapLine(h, index, h);
				maxLine = vector[h];
				vector[h] = vector[index];
				vector[index] = maxLine;
			}
			//
			for (int i = h; i < std::min(x,y); i++)
			{
				double temp = matrix(i, h);
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
		int NullCollums = 0;
		for (int j = 0; j < x; j++)
		{
			if (matrix.IsColumnEqualsZero(j - NullCollums))
			{
				matrix.DestroyColumn(j - NullCollums);
				//
				double lll = 0;
				for (int l = j - NullCollums; l < KMeshaniu.getSize()-1; l++)
				{
					lll = KMeshaniu[l];
					KMeshaniu[l] = KMeshaniu[l+1];
					KMeshaniu[l+1] = lll;
				}
				//
				NullCollums += 1;
			}
		}
		x -= NullCollums;
		int XMinusY = 0;
		int YMinusX = 0;
		if (x > y)
		{
			XMinusY = x - y;
			x = y;
		}
		else if (y > x)
		{
			YMinusX = y - x;
			y = x;
		}
		int NullLines = 0;
		for (int i = 0; i < y; i++)
		{
			if (matrix.IsLineEqualsZero(i))
			{
				NullLines += 1;
			}
		}
		Vector KOtvetu(x + NullCollums + XMinusY);
		//Обратный ход
		for (h = std::min((x - 1), (y - 1)); h >= 0; h--)
		{
			KOtvetu[KMeshaniu[h]] = vector[KMeshaniu[h]];
			for (int i = 0; i < h; i++)
				vector[KMeshaniu[i]] = vector[KMeshaniu[i]] - matrix(i, h) * vector[KMeshaniu[h]];
		}
		while (YMinusX > -NullLines)
		{
			double res = 0;
			for (int i = 0; i < x; i++)
			{
				res += matrix(y + YMinusX - NullLines - 1, i) * KOtvetu[i];
			}
			if ((res - vector[y + YMinusX - NullLines - 1]) > EPS)
			{
				return otvet;
			}
			YMinusX -= 1;
		}
		KOtvetu.print();
		otvet.push_back(KOtvetu);
		for (int k = XMinusY; k > 0; k--)
		{
			Vector DopVect(x + NullCollums + XMinusY);
			//Обратный ход
			for (int l = std::min((x - 1), (y - 1)); l >= 0; l--)
			{
				DopVect[KMeshaniu[l]] = matrix(KMeshaniu[l], x + XMinusY - k);
				for (int i = 0; i < l; i++)
					matrix(KMeshaniu[i], x + XMinusY - k) = matrix(KMeshaniu[i], x + XMinusY - k) - matrix(i, l) * matrix(KMeshaniu[l], x + XMinusY - k);
			}
			DopVect[KMeshaniu[x + XMinusY - k]] = 1;
			DopVect.print();
			otvet.push_back(DopVect);
		}
		return otvet;
	}
};

#endif