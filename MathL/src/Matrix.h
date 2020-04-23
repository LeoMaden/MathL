#pragma once

#include "MatrixBase.h"

namespace MathL {

	template<int R, int C, typename T>
	class Matrix : public MatrixBase<R, C, T>
	{
	public:
		Matrix() {}
		Matrix(T diag) : MatrixBase<R, C, T>(diag) {}

		~Matrix() {}
	};


	// ------------------------------------
	// ---- Template Specialisations ------
	// ------------------------------------
	template<int R, int C>
	class Matrix<R, C, float> : public MatrixBase<R, C, float>
	{
	public:
		Matrix() {}
		Matrix(float diag) : MatrixBase<R, C, float>(diag) {}

		virtual ~Matrix() {}

		static Matrix<R, C, float> Identity();
	};

	template<int R, int C>
	Matrix<R, C, float> Matrix<R, C, float>::Identity()
	{
		return { 1.0f };
	}
}