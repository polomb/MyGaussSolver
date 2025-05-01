#include "GaussSolver.h"

#define CONST_N 3

void main() 
{
	Matrix a(CONST_N, CONST_N);
	Vector b(CONST_N);
	a(0, 0) = 2; a(0, 1) = 4; a(0, 2) = 1;
	a(1, 0) = 5; a(1, 1) = 2; a(1, 2) = 1;
	a(2, 0) = 2; a(2, 1) = 3; a(2, 2) = 4;
	b[0] = 36; b[1] = 47; b[2] = 37;
	//a(0, 0) = 2; a(0, 1) = 4; a(0, 2) = 1;
	//a(1, 0) = 5; a(1, 1) = 2; a(1, 2) = 1;
	//a(2, 0) = 2; a(2, 1) = 3; a(2, 2) = 4;
	//b[0] = 36; b[1] = 47; b[2] = 37;
	GaussSolver sol;
	sol.solve(a, b);
}