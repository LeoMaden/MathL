#pragma once

#include "Matrix3x3Type.h"
#include "Vector3Type.h"

namespace MathL {

	template<typename T, bool UseSimd>
	struct MatrixAdd<3, 3, T, UseSimd>
	{
		static Matrix<3, 3, T> Compute(const Matrix<3, 3, T>& left, const Matrix<3, 3, T>& right)
		{
			return Matrix<3, 3, T>(left[0] + right[0], left[1] + right[1], left[2] + right[2]);
		}
	};

	template<typename T, bool UseSimd>
	struct MatrixSub<3, 3, T, UseSimd>
	{
		static Matrix<3, 3, T> Compute(const Matrix<3, 3, T>& left, const Matrix<3, 3, T>& right)
		{
			return Matrix<3, 3, T>(left[0] - right[0], left[1] - right[1], left[2] - right[2]);
		}
	};

	template<typename T, bool UseSimd>
	struct MatrixMul<3, 3, T, UseSimd>
	{
		static Matrix<3, 3, T> Compute(const Matrix<3, 3, T>& left, const Matrix<3, 3, T>& right)
		{
			auto& a = left;
			auto& b = right;

			Vector<3, T> row1(
				a[0][0] * b[0][0] + a[0][1] * b[1][0] + a[0][2] * b[2][0],
				a[0][0] * b[0][1] + a[0][1] * b[1][1] + a[0][2] * b[2][1],
				a[0][0] * b[0][2] + a[0][1] * b[1][2] + a[0][2] * b[2][2]
			);

			Vector<3, T> row2(
				a[1][0] * b[0][0] + a[1][1] * b[1][0] + a[1][2] * b[2][0],
				a[1][0] * b[0][1] + a[1][1] * b[1][1] + a[1][2] * b[2][1],
				a[1][0] * b[0][2] + a[1][1] * b[1][2] + a[1][2] * b[2][2]
			);

			Vector<3, T> row3(
				a[2][0] * b[0][0] + a[2][1] * b[1][0] + a[2][2] * b[2][0],
				a[2][0] * b[0][1] + a[2][1] * b[1][1] + a[2][2] * b[2][1],
				a[2][0] * b[0][2] + a[2][1] * b[1][2] + a[2][2] * b[2][2]
			);

			return Matrix<3, 3, T>(row1, row2, row3);
		}

		static Vector<3, T> Compute(const Matrix<3, 3, T>& left, const Vector<3, T>& right)
		{
			auto& a = left;
			auto& b = right;

			return Vector<3, T>(
				a[0][0] * b[0] + a[0][1] * b[1] + a[0][2] * b[2],
				a[1][0] * b[0] + a[1][1] * b[1] + a[1][2] * b[2],
				a[2][0] * b[0] + a[2][1] * b[1] + a[2][2] * b[2]
				);
		}
	};

	template<typename T, bool UseSimd>
	struct MatrixDet<3, 3, T, UseSimd>
	{

	};

	template<typename T, bool UseSimd>
	struct MatrixInv<3, 3, T, UseSimd>
	{

	};

	template<typename T, bool UseSimd>
	struct MatrixMinor<3, 3, T, UseSimd>
	{

	};

	template<typename T, bool UseSimd>
	struct MatrixCofactor<3, 3, T, UseSimd>
	{

	};


	// ----- Basic Constructors -----
	template<typename T>
	inline Matrix<3, 3, T>::Matrix()
	{
		Rows[0] = Vector<3, T>();
		Rows[1] = Vector<3, T>();
		Rows[2] = Vector<3, T>();
	}

	template<typename T>
	inline Matrix<3, 3, T>::Matrix(T value)
	{
		Rows[0] = Vector<3, T>(value, 0.0f, 0.0f);
		Rows[1] = Vector<3, T>(0.0f, value, 0.0f);
		Rows[2] = Vector<3, T>(0.0f, 0.0f, value);
	}

	template<typename T>
	inline Matrix<3, 3, T>::Matrix(const Vector<3, T>& row1, const Vector<3, T>& row2, const Vector<3, T>& row3)
	{
		Rows[0] = row1;
		Rows[1] = row2;
		Rows[2] = row3;
	}


	// ----- Access -----
	template<typename T>
	inline Vector<3, T>& Matrix<3, 3, T>::operator[](int i)
	{
		return Rows[i];
	}

	template<typename T>
	inline const Vector<3, T>& Matrix<3, 3, T>::operator[](int i) const
	{
		return Rows[i];
	}


	// ----- Binary Operators -----
	template<typename T>
	Matrix<3, 3, T> operator+(const Matrix<3, 3, T>& left, const Matrix<3, 3, T>& right)
	{
		return MatrixAdd<3, 3, T, ML_USE_SIMD>::Compute(left, right);
	}

	template<typename T>
	Matrix<3, 3, T> operator-(const Matrix<3, 3, T>& left, const Matrix<3, 3, T>& right)
	{
		return MatrixSub<3, 3, T, ML_USE_SIMD>::Compute(left, right);
	}

	template<typename T>
	Matrix<3, 3, T> operator*(const Matrix<3, 3, T>& left, const Matrix<3, 3, T>& right)
	{
		return MatrixMul<3, 3, T, ML_USE_SIMD>::Compute(left, right);
	}

	template<typename T>
	Vector<3, T> operator*(const Matrix<3, 3, T>& left, const Vector<3, T>& right)
	{
		return MatrixMul<3, 3, T, ML_USE_SIMD>::Compute(left, right);
	}

}