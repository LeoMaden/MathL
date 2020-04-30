#pragma once

#include "VectorType.h"

namespace MathL {

	template<typename T>
	class Quaternion
	{
	public:
		// ----- Data -----
		union 
		{
			struct { T x, y, z, w; };
			struct { T a, b, c, d; };

			/*alignas(32)*/ T data[4];
		};

		// ----- Basic Constructors -----
		Quaternion();
		Quaternion(T x, T y, T z, T w);
		Quaternion(T value);

		// ----- Copy / conversion -----
		Quaternion(const Quaternion<T>& other);

		// ----- Access -----
		T ScalarPart();
		Vector<3, T> VectorPart();
		T& operator[](int i);

		// ----- Math operators -----
		T Norm() const;
		Quaternion<T> Conjugate() const;
		Quaternion<T> Reciprocal() const;

		// ----- Unary Quaternion Operators -----
		Quaternion<T>& operator+=(const Quaternion<T>& other);
		Quaternion<T>& operator-=(const Quaternion<T>& other);
		Quaternion<T>& operator*=(const Quaternion<T>& other);
		Quaternion<T>& operator/=(const Quaternion<T>& other);

		// ----- Unary Scalar Operators -----
		Quaternion<T>& operator+=(T other);
		Quaternion<T>& operator-=(T other);
		Quaternion<T>& operator*=(T other);
		Quaternion<T>& operator/=(T other);
	};

	// ----- Binary Quaternion Operators -----
	template<typename T>
	Quaternion<T> operator+(const Quaternion<T>& left, const Quaternion<T>& right);
	template<typename T>
	Quaternion<T> operator-(const Quaternion<T>& left, const Quaternion<T>& right);
	template<typename T>
	Quaternion<T> operator*(const Quaternion<T>& left, const Quaternion<T>& right);
	template<typename T>
	Quaternion<T> operator/(const Quaternion<T>& left, const Quaternion<T>& right);

	// ----- Binary Quaternion Operators -----
	template<typename T>
	Quaternion<T> operator+(const Quaternion<T>& left, T value);
	template<typename T>
	Quaternion<T> operator-(const Quaternion<T>& left, T value);
	template<typename T>
	Quaternion<T> operator*(const Quaternion<T>& left, T value);
	template<typename T>
	Quaternion<T> operator/(const Quaternion<T>& left, T value);

} // namespace MathL

#include "QuaternionType.inl"