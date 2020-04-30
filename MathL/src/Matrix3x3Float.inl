#pragma once

#include "Matrix3x3Float.h"
#include "Vector3Float.h"

namespace MathL {

	// ----- Basic Constructors -----
	inline Matrix<3, 3, float>::Matrix()
	{
		Rows[0] = Vector<3, float>();
		Rows[1] = Vector<3, float>();
		Rows[2] = Vector<3, float>();
	}

	inline Matrix<3, 3, float>::Matrix(float value)
	{
		Rows[0] = Vector<3, float>(value, 0.0f, 0.0f);
		Rows[1] = Vector<3, float>(0.0f, value, 0.0f);
		Rows[2] = Vector<3, float>(0.0f, 0.0f, value);
	}

	inline Matrix<3, 3, float>::Matrix(const Vector<3, float>& row1, const Vector<3, float>& row2, const Vector<3, float>& row3)
	{
		Rows[0] = row1;
		Rows[1] = row2;
		Rows[2] = row3;
	}

}