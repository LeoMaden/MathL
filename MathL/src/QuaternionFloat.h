#pragma once

#include "QuaternionType.h"
#include "Vector.h"

namespace MathL {

	template<>
	class Quaternion<float>
	{
	public:
		// ----- Data -----
		union 
		{
			struct { float x, y, z, w; };
			alignas(32) float data[4];
		};
		//float x, y, z, w;

		// ----- Basic Constructors -----
		Quaternion();
		Quaternion(float x, float y, float z, float w);
		Quaternion(float value);

		// ----- Copy / conversion -----
		Quaternion(const Quaternion<float>& other);

		// ----- Access -----
		float ScalarPart();
		Vector<3, float> VectorPart();
		float operator[](int i);

		// ----- Math operators -----
		float Norm() const;
		Quaternion<float> Conjugate() const;
		Quaternion<float> Reciprocal() const;

		// ----- Unary Scalar Operators -----
		//Quaternion<float>& operator+=(float other);
		//Quaternion<float>& operator-=(float other);
		//Quaternion<float>& operator*=(float other);
		//Quaternion<float>& operator/=(float other);

		// ----- Unary Quaternion Operators -----
		Quaternion<float>& operator+=(const Quaternion<float>& other);
		Quaternion<float>& operator-=(const Quaternion<float>& other);
		Quaternion<float>& operator*=(const Quaternion<float>& other);
		Quaternion<float>& operator/=(const Quaternion<float>& other);
	};

	// ----- Binary Quaternion Operators -----
	Quaternion<float> operator+(const Quaternion<float>& left, const Quaternion<float>& right);
	Quaternion<float> operator-(const Quaternion<float>& left, const Quaternion<float>& right);
	Quaternion<float> operator*(const Quaternion<float>& left, const Quaternion<float>& right);
	Quaternion<float> operator/(const Quaternion<float>& left, const Quaternion<float>& right);

} // namespace MathL

#include "QuaternionFloat.inl"