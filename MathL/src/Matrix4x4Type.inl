#pragma once

#include "Matrix4x4Type.h"
#include "Vector4Type.h"

namespace MathL {

	template<typename T, bool UseSimd>
	struct MatrixAdd<4, 4, T, UseSimd>
	{
		static Matrix<4, 4, T> Compute(const Matrix<4, 4, T>& left, const Matrix<4, 4, T>& right)
		{
			return Matrix<4, 4, T>(left[0] + right[0], left[1] + right[1], left[2] + right[2], left[3] + right[3]);
		}
	};

	template<typename T, bool UseSimd>
	struct MatrixSub<4, 4, T, UseSimd>
	{
		static Matrix<4, 4, T> Compute(const Matrix<4, 4, T>& left, const Matrix<4, 4, T>& right)
		{
			return Matrix<4, 4, T>(left[0] - right[0], left[1] - right[1], left[2] - right[2], left[3] - right[3]);
		}
	};

	template<typename T, bool UseSimd>
	struct MatrixMul<4, 4, T, UseSimd>
	{
		static Matrix<4, 4, T> Compute(const Matrix<4, 4, T>& left, const Matrix<4, 4, T>& right)
		{
			auto& a = left;
			auto& b = right;

			Vector<4, T> row1(
				a[0][0] * b[0][0] + a[0][1] * b[1][0] + a[0][2] * b[2][0] + a[0][3] * b[3][0],
				a[0][0] * b[0][1] + a[0][1] * b[1][1] + a[0][2] * b[2][1] + a[0][3] * b[3][1],
				a[0][0] * b[0][2] + a[0][1] * b[1][2] + a[0][2] * b[2][2] + a[0][3] * b[3][2],
				a[0][0] * b[0][3] + a[0][1] * b[1][3] + a[0][2] * b[2][3] + a[0][3] * b[3][3]
			);

			Vector<4, T> row2(
				a[1][0] * b[0][0] + a[1][1] * b[1][0] + a[1][2] * b[2][0] + a[1][3] * b[3][0],
				a[1][0] * b[0][1] + a[1][1] * b[1][1] + a[1][2] * b[2][1] + a[1][3] * b[3][1],
				a[1][0] * b[0][2] + a[1][1] * b[1][2] + a[1][2] * b[2][2] + a[1][3] * b[3][2],
				a[1][0] * b[0][3] + a[1][1] * b[1][3] + a[1][2] * b[2][3] + a[1][3] * b[3][3]
			);

			Vector<4, T> row3(
				a[2][0] * b[0][0] + a[2][1] * b[1][0] + a[2][2] * b[2][0] + a[2][3] * b[3][0],
				a[2][0] * b[0][1] + a[2][1] * b[1][1] + a[2][2] * b[2][1] + a[2][3] * b[3][1],
				a[2][0] * b[0][2] + a[2][1] * b[1][2] + a[2][2] * b[2][2] + a[2][3] * b[3][2],
				a[2][0] * b[0][3] + a[2][1] * b[1][3] + a[2][2] * b[2][3] + a[2][3] * b[3][3]
			);

			Vector<4, T> row4(
				a[3][0] * b[0][0] + a[3][1] * b[1][0] + a[3][2] * b[2][0] + a[3][3] * b[3][0],
				a[3][0] * b[0][1] + a[3][1] * b[1][1] + a[3][2] * b[2][1] + a[3][3] * b[3][1],
				a[3][0] * b[0][2] + a[3][1] * b[1][2] + a[3][2] * b[2][2] + a[3][3] * b[3][2],
				a[3][0] * b[0][3] + a[3][1] * b[1][3] + a[3][2] * b[2][3] + a[3][3] * b[3][3]
			);

			return Matrix<4, 4, T>(row1, row2, row3, row4);
		}

		static Vector<4, T> Compute(const Matrix<4, 4, T>& left, const Vector<4, T>& right)
		{
			auto& a = left;
			auto& b = right;

			return Vector<4, T>(
				a[0][0] * b[0] + a[0][1] * b[1] + a[0][2] * b[2] + a[0][3] * b[3],
				a[1][0] * b[0] + a[1][1] * b[1] + a[1][2] * b[2] + a[1][3] * b[3],
				a[2][0] * b[0] + a[2][1] * b[1] + a[2][2] * b[2] + a[2][3] * b[3],
				a[3][0] * b[0] + a[3][1] * b[1] + a[3][2] * b[2] + a[3][3] * b[3]
				);
		}
	};

	template<typename T, bool UseSimd>
	struct MatrixDet<4, 4, T, UseSimd>
	{

	};

	template<typename T, bool UseSimd>
	struct MatrixInv<4, 4, T, UseSimd>
	{

	};

	template<typename T, bool UseSimd>
	struct MatrixMinor<4, 4, T, UseSimd>
	{

	};

	template<typename T, bool UseSimd>
	struct MatrixCofactor<4, 4, T, UseSimd>
	{

	};


	// ----- Basic Constructors -----
	template<typename T>
	inline Matrix<4, 4, T>::Matrix()
	{
		Rows[0] = Vector<4, T>();
		Rows[1] = Vector<4, T>();
		Rows[2] = Vector<4, T>();
		Rows[3] = Vector<4, T>();
	}

	template<typename T>
	inline Matrix<4, 4, T>::Matrix(T value)
	{
		Rows[0] = Vector<4, T>(value, 0.0f, 0.0f, 0.0f);
		Rows[1] = Vector<4, T>(0.0f, value, 0.0f, 0.0f);
		Rows[2] = Vector<4, T>(0.0f, 0.0f, value, 0.0f);
		Rows[3] = Vector<4, T>(0.0f, 0.0f, 0.0f, value);
	}

	template<typename T>
	inline Matrix<4, 4, T>::Matrix(const Vector<4, T>& row1, const Vector<4, T>& row2, const Vector<4, T>& row3, const Vector<4, T>& row4)
	{
		Rows[0] = row1;
		Rows[1] = row2;
		Rows[2] = row3;
		Rows[3] = row4;
	}


	// ----- Access -----
	template<typename T>
	inline Vector<4, T>& Matrix<4, 4, T>::operator[](int i)
	{
		return Rows[i];
	}

	template<typename T>
	inline const Vector<4, T>& Matrix<4, 4, T>::operator[](int i) const
	{
		return Rows[i];
	}

	// ----- Binary Operators -----
	template<typename T>
	inline Matrix<4, 4, T> operator+(const Matrix<4, 4, T>& left, const Matrix<4, 4, T>& right)
	{
		return MatrixAdd<4, 4, T, ML_USE_SIMD>::Compute(left, right);
	}

	template<typename T>
	inline Matrix<4, 4, T> operator-(const Matrix<4, 4, T>& left, const Matrix<4, 4, T>& right)
	{
		return MatrixSub<4, 4, T, ML_USE_SIMD>::Compute(left, right);
	}

	template<typename T>
	inline Matrix<4, 4, T> operator*(const Matrix<4, 4, T>& left, const Matrix<4, 4, T>& right)
	{
		return MatrixMul<4, 4, T, ML_USE_SIMD>::Compute(left, right);
	}

	template<typename T>
	inline Vector<4, T> operator*(const Matrix<4, 4, T>& left, const Vector<4, T>& right)
	{
		return MatrixMul<4, 4, T, ML_USE_SIMD>::Compute(left, right);
	}
}