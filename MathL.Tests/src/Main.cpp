#include <iostream>

#include "Matrix.h"

namespace MathL {

	typedef MathL::MatrixF<2, 2> Mat2;
}

int main()
{
	auto mat = MathL::Mat2::Identity();

	MathL::Matrix<2, 2, int> mat2;

	return 0;
}