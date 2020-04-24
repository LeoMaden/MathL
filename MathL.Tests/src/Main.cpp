#include <iostream>

#include "Matrix.h"
#include "Vector.h"

namespace MathL {

	typedef MathL::Matrix<2, 2, float> Mat2;
	typedef MathL::Matrix<3, 3, float> Mat3;
	typedef MathL::Matrix<4, 4, float> Mat4;
}

int main()
{
	/*MathL::Mat3 mat;
	auto mat2 = MathL::Mat3::Identity();

	MathL::Vector<3, float> vec(1.0f, 2.0f, 3.0f);

	std::cout << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")" << std::endl;*/

	// TODO: Implement transpose for matrix subclass.
	//MathL::Matrix<3, 2, int> mat(nums);
	//MathL::Matrix<2, 3, int> matT = mat.Transpose();

	int nums[3][2]{ 1, 2, 3, 4, 5, 6 };
	MathL::Matrix<3, 2, int> mat(nums);
	MathL::MatrixBase<2, 3, int> matT = mat.Transpose();

	MathL::Mat4 translation = MathL::Mat4::Translation({ 1.0f, 2.0f, 3.0f });
	//MathL::Mat4 identity = MathL::Mat4::Identity();
	//MathL::MatrixBase<4, 4, float> x = identity * translation;

	//float a[2][2]{ 2, 3, 1, 1 };
	//float b[2][2]{ 4, 1, 0, 1 };
	//MathL::Mat2 mat1(a);
	//MathL::Mat2 mat2(b);
	//auto result = mat1 * mat2;

	//MathL::Mat2 aMat(a);

	std::cin.get();
	return 0;
}