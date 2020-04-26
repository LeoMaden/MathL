#pragma once

#include <string>

#define ML_MATRIX_COMMON(NAME, R, C, T) \
NAME() {} \
NAME(T diag) : MatrixBase<R, C, T>(diag) {} \
NAME(T data[R][C]) : MatrixBase<R, C, T>(data) {} \
~NAME() {}

namespace MathL {

	template<int R, int C, typename T>
	class MatrixBase
	{
	protected:
		T m_Data[R][C]{};
		int m_Rows = R;
		int m_Cols = C;
	public:
		// ML_MATRIX_COMMON Constructors
		MatrixBase() {} 
		MatrixBase(T diag); 
		MatrixBase(T data[R][C]); 
		virtual ~MatrixBase(); 
		// -------------------------

		virtual void SetElement(int row, int col, T value);
		virtual T GetElement(int row, int col) const;
		virtual MatrixBase<C, R, T> Transpose();

		template<int R2, int C2>
		MatrixBase<R, C2, T> operator*(MatrixBase<R2, C2, T> other);


		friend MatrixBase<C, R, T>;
	};

	// ----- Constructors -----

	template<int R, int C, typename T>
	MatrixBase<R, C, T>::MatrixBase(T diag) : MatrixBase()
	{
		int minDim = R > C ? C : R;

		for (int i = 0; i < minDim; i++)
		{
			//m_Data[i + R * i] = diag;
			m_Data[i][i] = diag;
		}
	}

	template<int R, int C, typename T>
	MatrixBase<R, C, T>::MatrixBase(T data[R][C])
	{
		memcpy(m_Data, data, R * C * sizeof(T));
	}

	template<int R, int C, typename T>
	MatrixBase<R, C, T>::~MatrixBase()
	{
	}

	// ----- Member functions -----

	template<int R, int C, typename T>
	inline void MatrixBase<R, C, T>::SetElement(int row, int col, T value)
	{
		m_Data[row][col] = value;
	}

	template<int R, int C, typename T>
	inline T MatrixBase<R, C, T>::GetElement(int row, int col) const
	{
		return m_Data[row][col];
	}

	template<int R, int C, typename T>
	MatrixBase<C, R, T> MatrixBase<R, C, T>::Transpose()
	{
		MatrixBase<C, R, T> copy;

		for (int i = 0; i < m_Rows; i++)
		{
			for (int j = 0; j < m_Cols; j++)
			{
				T value = m_Data[i][j];
				copy.m_Data[j][i] = value;
			}
		}

		return copy;
	}

	// ----- Operators -----

	template<int R, int C, typename T>
	template<int R2, int C2>
	inline MatrixBase<R, C2, T> MatrixBase<R, C, T>::operator*(MatrixBase<R2, C2, T> other)
	{
		Matrix<R, C2, T> mat;

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C2; j++)
			{
				T sum = 0;
				for (int k = 0; k < C; k++)
				{
					sum += m_Data[i][k] * other.m_Data[k][j];
				}
				mat.m_Data[i][j] = sum;
			}
		}

		return mat;
	}

}