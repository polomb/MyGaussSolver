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
		//������������ std::vector<Vector> 1,0,{V0, V1, ... , Vk}, V0 - ������ ������

	}
};

#endif