#pragma once

#include "VectorType.h"
#include "Storage.h"

namespace MathL {

	template<typename T>
	class Vector<3, T>
	{
	public:
		// ----- Data -----
		union
		{
			struct { T x, y, z; };
			struct { T a, b, c; };

			typename Storage<3, T, ML_USE_ALIGNED>::Type data;
		};

		// ----- Basic Constructors -----
		Vector();
		Vector(T x, T y, T z);

		// ----- Copy/Conversion Constructor -----
		Vector(const Vector<3, T>& other);

		// ----- Math Operations -----
		Vector<3, T> Cross(const Vector<3, T>& other);
		T Dot(const Vector<3, T>& other);

		// ----- Unary Vector Operators -----
		Vector<3, T>& operator+=(const Vector<3, T>& other);
		Vector<3, T>& operator-=(const Vector<3, T>& other);
		Vector<3, T>& operator*=(const Vector<3, T>& other);
		Vector<3, T>& operator/=(const Vector<3, T>& other);

		// ----- Unary Scalar Operators -----
		Vector<3, T>& operator+=(T other);
		Vector<3, T>& operator-=(T other);
		Vector<3, T>& operator*=(T other);
		Vector<3, T>& operator/=(T other);
	};

	// ----- Binary Vector Operators -----
	template<typename T>
	Vector<3, T> operator+(const Vector<3, T>& left, const Vector<3, T>& right);
	template<typename T>
	Vector<3, T> operator-(const Vector<3, T>& left, const Vector<3, T>& right);
	template<typename T>
	Vector<3, T> operator*(const Vector<3, T>& left, const Vector<3, T>& right);
	template<typename T>
	Vector<3, T> operator/(const Vector<3, T>& left, const Vector<3, T>& right);

	// ----- Binary Scalar Operators -----
	template<typename T>
	Vector<3, T> operator+(const Vector<3, T>& left, T value);
	template<typename T>
	Vector<3, T> operator-(const Vector<3, T>& left, T value);
	template<typename T>
	Vector<3, T> operator*(const Vector<3, T>& left, T value);
	template<typename T>
	Vector<3, T> operator/(const Vector<3, T>& left, T value);

}

#include "Vector3Type.inl"
