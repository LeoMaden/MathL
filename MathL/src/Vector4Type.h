#pragma once

#include "VectorType.h"
#include "Storage.h"

namespace MathL {

	template<typename T>
	class Vector<4, T>
	{
	public:
		// ----- Data -----
		union
		{
			struct { T x, y, z, w; };
			struct { T a, b, c, d; };

			typename Storage<4, T, ML_USE_ALIGNED>::Type data;
		};

		// ----- Basic Constructors -----
		Vector();
		Vector(T x, T y, T z, T w);

		// ----- Copy/Conversion Constructor -----
		Vector(const Vector<4, T>& other);

		// ----- Math Operations -----
		T Dot(const Vector<4, T>& other);

		// ----- Access -----
		T& operator[](int i);
		const T& operator[](int i) const;

		// ----- Unary Vector Operators -----
		Vector<4, T>& operator+=(const Vector<4, T>& other);
		Vector<4, T>& operator-=(const Vector<4, T>& other);
		Vector<4, T>& operator*=(const Vector<4, T>& other);
		Vector<4, T>& operator/=(const Vector<4, T>& other);

		// ----- Unary Scalar Operators -----
		Vector<4, T>& operator+=(T other);
		Vector<4, T>& operator-=(T other);
		Vector<4, T>& operator*=(T other);
		Vector<4, T>& operator/=(T other);
	};

	// ----- Binary Vector Operators -----
	template<typename T>
	Vector<4, T> operator+(const Vector<4, T>& left, const Vector<4, T>& right);
	template<typename T>
	Vector<4, T> operator-(const Vector<4, T>& left, const Vector<4, T>& right);
	template<typename T>
	Vector<4, T> operator*(const Vector<4, T>& left, const Vector<4, T>& right);
	template<typename T>
	Vector<4, T> operator/(const Vector<4, T>& left, const Vector<4, T>& right);

	// ----- Binary Scalar Operators -----
	template<typename T>
	Vector<4, T> operator+(const Vector<4, T>& left, T value);
	template<typename T>
	Vector<4, T> operator-(const Vector<4, T>& left, T value);
	template<typename T>
	Vector<4, T> operator*(const Vector<4, T>& left, T value);
	template<typename T>
	Vector<4, T> operator/(const Vector<4, T>& left, T value);

}

#include "Vector4Type.inl"
