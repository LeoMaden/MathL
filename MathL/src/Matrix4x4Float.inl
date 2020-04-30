#pragma once

#include "Matrix4x4Float.h"
#include "Vector4Float.h"

namespace MathL {

	// ----- Basic Constructors -----
	inline Matrix<4, 4, float>::Matrix()
	{
		Rows[0] = Vector<4, float>();
		Rows[1] = Vector<4, float>();
		Rows[2] = Vector<4, float>();
		Rows[3] = Vector<4, float>();
	}

	inline Matrix<4, 4, float>::Matrix(float value)
	{
		Rows[0] = Vector<4, float>(value, 0.0f, 0.0f, 0.0f);
		Rows[1] = Vector<4, float>(0.0f, value, 0.0f, 0.0f);
		Rows[2] = Vector<4, float>(0.0f, 0.0f, value, 0.0f);
		Rows[3] = Vector<4, float>(0.0f, 0.0f, 0.0f, value);
	}

	inline Matrix<4, 4, float>::Matrix(const Vector<4, float>& row1, const Vector<4, float>& row2, const Vector<4, float>& row3, const Vector<4, float>& row4)
	{
		Rows[0] = row1;
		Rows[1] = row2;
		Rows[2] = row3;
		Rows[3] = row4;
	}

}