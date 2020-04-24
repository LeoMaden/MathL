#pragma once

#include "MatrixBase.h"
#include "Vector.h"

namespace MathL {

	template<int R, int C, typename T>
	class Matrix : public MatrixBase<R, C, T>
	{
	public:
		ML_MATRIX_COMMON(Matrix, R, C, T)
	};	


	// ------------------------------------
	// ---- Template Specialisations ------
	// ------------------------------------
	template<int R, int C>
	class Matrix<R, C, float> : public MatrixBase<R, C, float>
	{
	public:
		ML_MATRIX_COMMON(Matrix, R, C, float)

	public:
		static Matrix<R, C, float> Identity() { return { 1.0f }; }
	};

	// ------------------------------------

	template<>
	class Matrix<4, 4, float> : public MatrixBase<4, 4, float>
	{
	public:
		ML_MATRIX_COMMON(Matrix, 4, 4, float)

	public:
		static Matrix<4, 4, float> Identity() { return { 1.0f }; }
		static Matrix<4, 4, float> Translation(const Vector<3, float>& vector);
	};

	inline Matrix<4, 4, float> Matrix<4, 4, float>::Translation(const Vector<3, float>& vector)
	{
		Matrix<4, 4, float> mat(1.0f);

		mat.m_Data[0][3] = vector.x;
		mat.m_Data[1][3] = vector.y;
		mat.m_Data[2][3] = vector.z;

		return mat;
	}
}
