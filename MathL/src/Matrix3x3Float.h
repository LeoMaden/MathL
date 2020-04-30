#pragma once

#include "MatrixType.h"
#include "VectorType.h"

namespace MathL {

	template<>
	class Matrix<3, 3, float>
	{
	public:
		// ----- Data -----
		Vector<3, float> Rows[3];

		// ----- Basic Constructors -----
		Matrix();
		Matrix(float value);
		Matrix(const Vector<3, float>& row1, const Vector<3, float>& row2, const Vector<3, float>& row3);

	};

	//// ----- Binary Matrix Operators -----
	//Matrix<3, 3, float> operator+(const Matrix<3, 3, float>& left, const Matrix<3, 3, float>& right);
	//Matrix<3, 3, float> operator-(const Matrix<3, 3, float>& left, const Matrix<3, 3, float>& right);

	//Matrix<3, 3, float> operator*(const Matrix<3, 3, float>& left, const Matrix<3, 3, float>& right);
	//Vector<3, float> operator*(const Matrix<3, 3, float>& right, const Vector<3, float>& left);

}