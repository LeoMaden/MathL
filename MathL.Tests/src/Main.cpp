#include <iostream>

#include "Matrix.h"
#include "Vector.h"

namespace MathL {

	typedef MathL::Matrix<2, 2, float> Mat2;
	typedef MathL::Matrix<3, 3, float> Mat3;
}

int main()
{
	/*MathL::Mat3 mat;
	auto mat2 = MathL::Mat3::Identity();

	MathL::Vector<3, float> vec(1.0f, 2.0f, 3.0f);

	std::cout << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")" << std::endl;*/

	int nums[3][2]{ 1, 2, 3, 4, 5, 6 };

	// TODO: Implement transpose for matrix subclass.
	MathL::Matrix<3, 2, int> mat(nums);
	//MathL::Matrix<2, 3, int> matT = mat.Transpose();


	std::cin.get();
	return 0;
}