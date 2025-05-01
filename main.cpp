#include "GaussSolver.h"

#define CONST_N 5

void main() 
{
	Matrix a(CONST_N, CONST_N);
	for (int i = 0; i < CONST_N; i++)
	{
		for (int j = 0; j < CONST_N; j++)
		{
			a(i, j) = i * CONST_N + j;
		}
	}
	a.print();
	std::cout << "MaxRow: " << a.MaxRow(0) << ", MaxLine: " << a.MaxLine(0) << "\n";
	a.swapLine(0, 1, CONST_N);
	a.print();
}