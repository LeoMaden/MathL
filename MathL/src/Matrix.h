#pragma once

#include "MatrixBase.h"

namespace MathL {

	template<int R, int C, typename T>
	class Matrix : public MatrixBase<R, C, T>
	{
	private:
		//T m_Data[R][C]{} override;
		//int m_Rows = R override;
		//int m_Cols = C override;
	public:
		ML_MATRIX_COMMON(Matrix, R, C, T)
	};

	//template<int R, int C, typename T>
	//Matrix<R, C, T>::Matrix(const MatrixBase<R, C, T>& parent)
	


	// ------------------------------------
	// ---- Template Specialisations ------
	// ------------------------------------
	template<int R, int C>
	class Matrix<R, C, float> : public MatrixBase<R, C, float>
	{
	public:
		static Matrix<R, C, float> Identity();

	public:
		ML_MATRIX_COMMON(Matrix, R, C, float)
	};

	template<int R, int C>
	Matrix<R, C, float> Matrix<R, C, float>::Identity()
	{
		return { 1.0f };
	}
}