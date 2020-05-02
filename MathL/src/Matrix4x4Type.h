#pragma once

#include "MatrixType.h"
#include "VectorType.h"

namespace MathL {

	template<typename T>
	class Matrix<4, 4, T>
	{
	public:
		// ----- Data -----
		Vector<4, T> Rows[4];

		// ----- Basic Constructors -----
		Matrix();
		Matrix(T value);
		Matrix(const Vector<4, T>& row1, const Vector<4, T>& row2, const Vector<4, T>& row3, const Vector<4, T>& row4);

		// ----- Access -----
		Vector<4, T>& operator[](int i);
		const Vector<4, T>& operator[](int i) const;
	};

	// ----- Binary Operators -----
	template<typename T>
	Matrix<4, 4, T> operator+(const Matrix<4, 4, T>& left, const Matrix<4, 4, T>& right);
	template<typename T>
	Matrix<4, 4, T> operator-(const Matrix<4, 4, T>& left, const Matrix<4, 4, T>& right);

	template<typename T>
	Matrix<4, 4, T> operator*(const Matrix<4, 4, T>& left, const Matrix<4, 4, T>& right);
	template<typename T>
	Vector<4, T> operator*(const Matrix<4, 4, T>& left, const Vector<4, T>& right);

}

#include "Matrix4x4Type.inl"