#pragma once

#include <string>

namespace MathL {

	template<int R, int C, typename T>
	class MatrixBase
	{
	protected:
		T m_Data[R][C]{};
		int m_Rows = R;
		int m_Cols = C;
	public:
		MatrixBase() {}//;
		MatrixBase(T diag);
		MatrixBase(T data[R][C]);

		virtual ~MatrixBase();


		virtual MatrixBase<C, R, T> Transpose();


		friend MatrixBase<C, R, T>;
	};

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

}