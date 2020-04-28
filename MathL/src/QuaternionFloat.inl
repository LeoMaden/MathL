#pragma once

#include "QuaternionFloat.h"

namespace MathL {

	// ----- Basic Constructors -----
	inline MathL::Quaternion<float>::Quaternion()
		: x(0.0f), y(0.0f), z(0.0f), w(0.0f)
	{
	}

	inline Quaternion<float>::Quaternion(float x, float y, float z, float w)
		: x(x), y(y), z(z), w(w)
	{
	}

	inline Quaternion<float>::Quaternion(float value)
		: x(value), y(value), z(value), w(value)
	{
	}

	// ----- Copy / conversion -----
	inline Quaternion<float>::Quaternion(const Quaternion<float>& other)
		: x(other.x), y(other.y), z(other.z), w(other.w)
	{
	}

	// ----- Access -----
	inline float Quaternion<float>::ScalarPart()
	{
		return x;
	}

	inline Vector<3, float> Quaternion<float>::VectorPart()
	{
		return Vector<3, float>(y, z, w);
	}

	inline float Quaternion<float>::operator[](int i)
	{
		switch (i) {
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		case 3:
			return w;
		}
	}


	// ----- Math operators -----
	inline float Quaternion<float>::Norm() const
	{
		return std::sqrt(std::powf(x, 2) + std::powf(y, 2) + std::powf(z, 2) + std::powf(w, 2));
	}

	inline Quaternion<float> Quaternion<float>::Conjugate() const
	{
		return Quaternion<float>(x, -y, -z, -w);
	}

	inline Quaternion<float> Quaternion<float>::Reciprocal() const
	{
		return this->Conjugate() / std::powf(this->Norm(), 2);
	}


	// ----- Unary Quaternion Operators -----
	inline Quaternion<float>& Quaternion<float>::operator+=(const Quaternion<float>& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;

		return *this;
	}

	inline Quaternion<float>& Quaternion<float>::operator-=(const Quaternion<float>& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;

		return *this;
	}

	inline Quaternion<float>& Quaternion<float>::operator*=(const Quaternion<float>& other)
	{
		float x2 = other.x;
		float y2 = other.y;
		float z2 = other.z;
		float w2 = other.w;

		x = x* x2 - y * y2 - z * z2 - w * w2;
		y = x* y2 + y * x2 + z * w2 - w * z2;
		z = x* z2 - y * w2 + z * x2 + w * y2;
		w = x* w2 + y * z2 - z * y2 + w * x2;

		return *this;
	}

	inline Quaternion<float>& Quaternion<float>::operator/=(const Quaternion<float>& other)
	{
		return (*this *= other.Reciprocal());
	}


	// ----- Binary Quaternion Operators -----
	Quaternion<float> operator+(const Quaternion<float>& left, const Quaternion<float>& right)
	{
		return Quaternion<float>(
			left.x + right.x,
			left.y + right.y,
			left.z + right.z,
			left.w + right.w
		);
	}

	Quaternion<float> operator-(const Quaternion<float>& left, const Quaternion<float>& right)
	{
		return Quaternion<float>(
			left.x - right.x,
			left.y - right.y,
			left.z - right.z,
			left.w - right.w
			);
	}

	Quaternion<float> operator*(const Quaternion<float>& left, const Quaternion<float>& right)
	{
		float x1 = left.x;
		float y1 = left.y;
		float z1 = left.z;
		float w1 = left.w;

		float x2 = right.x;
		float y2 = right.y;
		float z2 = right.z;
		float w2 = right.w;

		return Quaternion<float>(
			x1 * x2 - y1 * y2 - z1 * z2 - w1 * w2,
			x1 * y2 + y1 * x2 + z1 * w2 - w1 * z2,
			x1 * z2 - y1 * w2 + z1 * x2 + w1 * y2,
			x1 * w2 + y1 * z2 - z1 * y2 + w1 * x2
		);
	}

	Quaternion<float> operator/(const Quaternion<float>& left, const Quaternion<float>& right)
	{
		return left * right.Reciprocal();
	}

}