#pragma once

#include "MatrixType.h"
#include "VectorType.h"

namespace MathL {

	template<>
	class Matrix<4, 4, float>
	{
	public:
		// ----- Data -----
		Vector<4, float> Rows[4];

		// ----- Basic Constructors -----
		Matrix();
		Matrix(float value);
		Matrix(const Vector<4, float>& row1, const Vector<4, float>& row2, const Vector<4, float>& row3, const Vector<4, float>& row4);

	};

	//// ----- Binary Matrix Operators -----
	//Matrix<4, 4, float> operator+(const Matrix<4, 4, float>& left, const Matrix<4, 4, float>& right);
	//Matrix<4, 4, float> operator-(const Matrix<4, 4, float>& left, const Matrix<4, 4, float>& right);

	//Matrix<4, 4, float> operator*(const Matrix<4, 4, float>& left, const Matrix<4, 4, float>& right);
	//Vector<4, float> operator*(const Matrix<4, 4, float>& right, const Vector<4, float>& left);

}