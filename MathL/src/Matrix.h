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
		Matrix() {}
		Matrix(T diag) : MatrixBase<R, C, T>(diag) {}
		Matrix(T data[R][C]) : MatrixBase<R, C, T>(data) {}

		~Matrix() {}


		friend MatrixBase<R, C, T>;
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
		Matrix() {}
		Matrix(float diag) : MatrixBase<R, C, float>(diag) {}
		Matrix(float data[R][C]) : MatrixBase<R, C, float>(data) {}

		~Matrix() {}


		MatrixBase<C, R, float> Transpose() { return MatrixBase<R, C, float>.Transpose(); }
	};

	template<int R, int C>
	Matrix<R, C, float> Matrix<R, C, float>::Identity()
	{
		return { 1.0f };
	}
}