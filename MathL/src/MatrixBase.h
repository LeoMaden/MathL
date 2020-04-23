#pragma once

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

		virtual ~MatrixBase();

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
	MatrixBase<R, C, T>::~MatrixBase()
	{
	}

}