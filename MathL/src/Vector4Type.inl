#pragma once

#include "Vector4Type.h"

namespace MathL {

	template<typename T, bool UseSimd>
	struct VectorAdd<4, T, UseSimd>
	{
		static Vector<4, T> Compute(const Vector<4, T>& left, const Vector<4, T>& right)
		{
			return Vector<4, T>(
				left.x + right.x,
				left.y + right.y,
				left.z + right.z,
				left.w + right.w
				);
		}

		static Vector<4, T> Compute(const Vector<4, T>& left, T value)
		{
			return Vector<4, T>(
				left.x + value,
				left.y + value,
				left.z + value,
				left.w + value
				);
		}
	};

	template<typename T, bool UseSimd>
	struct VectorSub<4, T, UseSimd>
	{
		static Vector<4, T> Compute(const Vector<4, T>& left, const Vector<4, T>& right)
		{
			return Vector<4, T>(
				left.x - right.x,
				left.y - right.y,
				left.z - right.z,
				left.w - right.w
				);
		}

		static Vector<4, T> Compute(const Vector<4, T>& left, T value)
		{
			return Vector<4, T>(
				left.x - value,
				left.y - value,
				left.z - value,
				left.w - value
				);
		}
	};

	template<typename T, bool UseSimd>
	struct VectorMul<4, T, UseSimd>
	{
		static Vector<4, T> Compute(const Vector<4, T>& left, const Vector<4, T>& right)
		{
			return Vector<4, T>(
				left.x * right.x,
				left.y * right.y,
				left.z * right.z,
				left.w * right.w
				);
		}

		static Vector<4, T> Compute(const Vector<4, T>& left, T value)
		{
			return Vector<4, T>(
				left.x * value,
				left.y * value,
				left.z * value,
				left.w * value
				);
		}
	};

	template<typename T, bool UseSimd>
	struct VectorDiv<4, T, UseSimd>
	{
		static Vector<4, T> Compute(const Vector<4, T>& left, const Vector<4, T>& right)
		{
			return Vector<4, T>(
				left.x / right.x,
				left.y / right.y,
				left.z / right.z,
				left.w / right.w
				);
		}

		static Vector<4, T> Compute(const Vector<4, T>& left, T value)
		{
			return Vector<4, T>(
				left.x / value,
				left.y / value,
				left.z / value,
				left.w / value
				);
		}
	};

	template<typename T, bool UseSimd>
	struct VectorDot<4, T, UseSimd>
	{
		static T Compute(const Vector<4, T>& left, const Vector<4, T>& right)
		{
			return (left.x * right.x) + (left.y * right.y) + (left.z * right.z) + (left.w * right.w);
		}
	};


	// ----- Basic Constructors -----
	template<typename T>
	inline Vector<4, T>::Vector()
		: x(0.0f), y(0.0f), z(0.0f), w(0.0f)
	{
	}

	template<typename T>
	inline Vector<4, T>::Vector(T x, T y, T z, T w)
		: x(x), y(y), z(z), w(w)
	{
	}


	// ----- Copy/Conversion Constructors -----
	template<typename T>
	inline Vector<4, T>::Vector(const Vector<4, T>& other)
		: x(other.x), y(other.y), z(other.z), w(other.w)
	{
	}


	// ----- Math Operations -----
	template<typename T>
	inline T Vector<4, T>::Dot(const Vector<4, T>& other)
	{
		return VectorDot<4, T, ML_USE_SIMD>::Compute(*this, other);
	}


	// ----- Access -----
	template<typename T>
	inline T Vector<4, T>::operator[](int i)
	{
		switch (i)
		{
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


	// ----- Unary Vector Operators -----
	template<typename T>
	inline Vector<4, T>& Vector<4, T>::operator+=(const Vector<4, T>& other)
	{
		return *this = VectorAdd<4, T, ML_USE_SIMD>::Compute(*this, other);
	}

	template<typename T>
	inline Vector<4, T>& Vector<4, T>::operator-=(const Vector<4, T>& other)
	{
		return *this = VectorSub<4, T, ML_USE_SIMD>::Compute(*this, other);
	}

	template<typename T>
	inline Vector<4, T>& Vector<4, T>::operator*=(const Vector<4, T>& other)
	{
		return *this = VectorMul<4, T, ML_USE_SIMD>::Compute(*this, other);
	}

	template<typename T>
	inline Vector<4, T>& Vector<4, T>::operator/=(const Vector<4, T>& other)
	{
		return *this = VectorDiv<4, T, ML_USE_SIMD>::Compute(*this, other);
	}


	// ----- Unary Scalar Operators -----
	template<typename T>
	inline Vector<4, T>& Vector<4, T>::operator+=(T other)
	{
		return *this = VectorAdd<4, T, ML_USE_SIMD>::Compute(*this, other);
	}

	template<typename T>
	inline Vector<4, T>& Vector<4, T>::operator-=(T other)
	{
		return *this = VectorSub<4, T, ML_USE_SIMD>::Compute(*this, other);
	}

	template<typename T>
	inline Vector<4, T>& Vector<4, T>::operator*=(T other)
	{
		return *this = VectorMul<4, T, ML_USE_SIMD>::Compute(*this, other);
	}

	template<typename T>
	inline Vector<4, T>& Vector<4, T>::operator/=(T other)
	{
		return *this = VectorDiv<4, T, ML_USE_SIMD>::Compute(*this, other);
	}


	// ----- Binary Vector Operators -----
	template<typename T>
	Vector<4, T> operator+(const Vector<4, T>& left, const Vector<4, T>& right)
	{
		return VectorAdd<4, T, ML_USE_SIMD>::Compute(left, right);
	}

	template<typename T>
	Vector<4, T> operator-(const Vector<4, T>& left, const Vector<4, T>& right)
	{
		return VectorSub<4, T, ML_USE_SIMD>::Compute(left, right);
	}

	template<typename T>
	Vector<4, T> operator*(const Vector<4, T>& left, const Vector<4, T>& right)
	{
		return VectorMul<4, T, ML_USE_SIMD>::Compute(left, right);
	}

	template<typename T>
	Vector<4, T> operator/(const Vector<4, T>& left, const Vector<4, T>& right)
	{
		return VectorDiv<4, T, ML_USE_SIMD>::Compute(left, right);
	}


	// ----- Binary Scalar Operators -----
	template<typename T>
	Vector<4, T> operator+(const Vector<4, T>& left, T value)
	{
		return VectorAdd<4, T, ML_USE_SIMD>::Compute(left, value);
	}

	template<typename T>
	Vector<4, T> operator-(const Vector<4, T>& left, T value)
	{
		return VectorSub<4, T, ML_USE_SIMD>::Compute(left, value);
	}

	template<typename T>
	Vector<4, T> operator*(const Vector<4, T>& left, T value)
	{
		return VectorMul<4, T, ML_USE_SIMD>::Compute(left, value);
	}

	template<typename T>
	Vector<4, T> operator/(const Vector<4, T>& left, T value)
	{
		return VectorDiv<4, T, ML_USE_SIMD>::Compute(left, value);
	}



}