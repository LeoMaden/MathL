#pragma once

namespace MathL {

	template<int R, int C, typename T>
	class Matrix
	{
	protected:
		T m_Data[R][C]{};
		int m_Rows;
		int m_Cols;
	public:
		Matrix();
		Matrix(T diag);

		virtual ~Matrix();
	};


	template<int R, int C, typename T>
	Matrix<R, C, T>::Matrix() : m_Rows(R), m_Cols(C)
	{
		//m_Data = new T[R * C];
	}

	template<int R, int C, typename T>
	Matrix<R, C, T>::Matrix(T diag) : Matrix()
	{
		int minDim = R > C ? C : R;

		for (int i = 0; i < minDim; i++)
		{
			//m_Data[i + R * i] = diag;
			m_Data[i][i] = diag;
		}
	}

	template<int R, int C, typename T>
	Matrix<R, C, T>::~Matrix()
	{

	}

	template<int R, int C>
	class MatrixF : public Matrix<R, C, float>
	{
	public:
		MatrixF() : Matrix<R, C, float>() {}
		MatrixF(float diag) : Matrix<R, C, float>(diag) {}

		virtual ~MatrixF() {}


		static MatrixF<R, C> Identity();
	};

	template<int R, int C>
	MatrixF<R, C> MatrixF<R, C>::Identity()
	{
		return { 1.0f };
	}
}