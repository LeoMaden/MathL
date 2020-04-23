#include <iostream>

#include "Matrix.h"

namespace MathL {

	typedef MathL::Matrix<2, 2, float> Mat2;
	typedef MathL::Matrix<3, 3, float> Mat3;
}

int main()
{
	MathL::Mat3 mat;
	auto mat2 = MathL::Mat3::Identity();

	return 0;
}