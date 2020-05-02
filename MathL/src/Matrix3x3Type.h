#pragma once

#include "MatrixType.h"
#include "VectorType.h"
#include "Storage.h"

namespace MathL {

	template<typename T>
	class Matrix<3, 3, T>
	{
	public:
		// ----- Data -----
		Vector<3, T> Rows[3];

		// ----- Basic Constructors -----
		Matrix();
		Matrix(T value);
		Matrix(const Vector<3, T>& row1, const Vector<3, T>& row2, const Vector<3, T>& row3);

		// ----- Access -----
		Vector<3, T>& operator[](int i);
		const Vector<3, T>& operator[](int i) const;
	};

	// ----- Binary Operators -----
	template<typename T>
	Matrix<3, 3, T> operator+(const Matrix<3, 3, T>& left, const Matrix<3, 3, T>& right);
	template<typename T>
	Matrix<3, 3, T> operator-(const Matrix<3, 3, T>& left, const Matrix<3, 3, T>& right);

	template<typename T>
	Matrix<3, 3, T> operator*(const Matrix<3, 3, T>& left, const Matrix<3, 3, T>& right);
	template<typename T>
	Vector<3, T> operator*(const Matrix<3, 3, T>& left, const Vector<3, T>& right);

}

#include "Matrix3x3Type.inl"