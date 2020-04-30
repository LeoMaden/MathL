#pragma once

#include "Vector3Type.h"

namespace MathL {

	template<typename T, bool UseSimd>
	struct VectorAdd<3, T, UseSimd>
	{
		static Vector<3, T> Compute(const Vector<3, T>& left, const Vector<3, T>& right)
		{
			return Vector<3, T>(
				left.x + right.x,
				left.y + right.y,
				left.z + right.z
				);
		}

		static Vector<3, T> Compute(const Vector<3, T>& left, T value)
		{
			return Vector<3, T>(
				left.x + value,
				left.y + value,
				left.z + value
				);
		} 
	};

	template<typename T, bool UseSimd>
	struct VectorSub<3, T, UseSimd>
	{
		static Vector<3, T> Compute(const Vector<3, T>& left, const Vector<3, T>& right)
		{
			return Vector<3, T>(
				left.x - right.x,
				left.y - right.y,
				left.z - right.z
				);
		}

		static Vector<3, T> Compute(const Vector<3, T>& left, T value)
		{
			return Vector<3, T>(
				left.x - value,
				left.y - value,
				left.z - value
				);
		}
	};

	template<typename T, bool UseSimd>
	struct VectorMul<3, T, UseSimd>
	{
		static Vector<3, T> Compute(const Vector<3, T>& left, const Vector<3, T>& right)
		{
			return Vector<3, T>(
				left.x * right.x,
				left.y * right.y,
				left.z * right.z
				);
		}

		static Vector<3, T> Compute(const Vector<3, T>& left, T value)
		{
			return Vector<3, T>(
				left.x * value,
				left.y * value,
				left.z * value
				);
		}
	};

	template<typename T, bool UseSimd>
	struct VectorDiv<3, T, UseSimd>
	{
		static Vector<3, T> Compute(const Vector<3, T>& left, const Vector<3, T>& right)
		{
			return Vector<3, T>(
				left.x / right.x,
				left.y / right.y,
				left.z / right.z
				);
		}

		static Vector<3, T> Compute(const Vector<3, T>& left, T value)
		{
			return Vector<3, T>(
				left.x / value,
				left.y / value,
				left.z / value
				);
		}
	};

	template<typename T, bool UseSimd>
	struct VectorDot<3, T, UseSimd>
	{
		static T Compute(const Vector<3, T>& left, const Vector<3, T>& right)
		{
			return (left.x * right.x) + (left.y * right.y) + (left.z * right.z);
		}
	};

	template<typename T, bool UseSimd>
	struct VectorCross<3, T, UseSimd>
	{
		static Vector<3, T> Compute(const Vector<3, T>& left, const Vector<3, T>& right)
		{
			return Vector<3, T>(
				left.y * right.z - left.z * right.y,
				left.z * right.x - left.x * right.z,
				left.x * right.y - left.y * right.x
				);
		}
	};


	// ----- Basic Constructors -----
	template<typename T>
	inline Vector<3, T>::Vector()
		: x(0.0f), y(0.0f), z(0.0f)
	{
	}

	template<typename T>
	inline Vector<3, T>::Vector(T x, T y, T z)
		: x(x), y(y), z(z)
	{
	}


	// ----- Copy/Conversion Constructors -----
	template<typename T>
	inline Vector<3, T>::Vector(const Vector<3, T>& other)
		: x(other.x), y(other.y), z(other.z)
	{
	}


	// ----- Math Operations -----
	template<typename T>
	inline Vector<3, T> Vector<3, T>::Cross(const Vector<3, T>& other)
	{
		return VectorCross<3, T, ML_USE_SIMD>::Compute(*this, other);
	}

	template<typename T>
	inline T Vector<3, T>::Dot(const Vector<3, T>& other)
	{
		return VectorDot<3, T, ML_USE_SIMD>::Compute(*this, other);
	}


	// ----- Unary Vector Operators -----
	template<typename T>
	inline Vector<3, T>& Vector<3, T>::operator+=(const Vector<3, T>& other)
	{
		return *this = VectorAdd<3, T, ML_USE_SIMD>::Compute(*this, other);
	}

	template<typename T>
	inline Vector<3, T>& Vector<3, T>::operator-=(const Vector<3, T>& other)
	{
		return *this = VectorSub<3, T, ML_USE_SIMD>::Compute(*this, other);
	}

	template<typename T>
	inline Vector<3, T>& Vector<3, T>::operator*=(const Vector<3, T>& other)
	{
		return *this = VectorMul<3, T, ML_USE_SIMD>::Compute(*this, other);
	}

	template<typename T>
	inline Vector<3, T>& Vector<3, T>::operator/=(const Vector<3, T>& other)
	{
		return *this = VectorDiv<3, T, ML_USE_SIMD>::Compute(*this, other);
	}


	// ----- Unary Scalar Operators -----
	template<typename T>
	inline Vector<3, T>& Vector<3, T>::operator+=(T other)
	{
		return this* = VectorAdd<3, T, ML_USE_SIMD>::Compute(*this, other);
	}

	template<typename T>
	inline Vector<3, T>& Vector<3, T>::operator-=(T other)
	{
		return this* = VectorSub<3, T, ML_USE_SIMD>::Compute(*this, other);
	}

	template<typename T>
	inline Vector<3, T>& Vector<3, T>::operator*=(T other)
	{
		return this* = VectorMul<3, T, ML_USE_SIMD>::Compute(*this, other);
	}

	template<typename T>
	inline Vector<3, T>& Vector<3, T>::operator/=(T other)
	{
		return this* = VectorDiv<3, T, ML_USE_SIMD>::Compute(*this, other);
	}


	// ----- Binary Vector Operators -----
	template<typename T>
	Vector<3, T> operator+(const Vector<3, T>& left, const Vector<3, T>& right)
	{
		return VectorAdd<3, T, ML_USE_SIMD>::Compute(left, right);
	}

	template<typename T>
	Vector<3, T> operator-(const Vector<3, T>& left, const Vector<3, T>& right)
	{
		return VectorSub<3, T, ML_USE_SIMD>::Compute(left, right);
	}

	template<typename T>
	Vector<3, T> operator*(const Vector<3, T>& left, const Vector<3, T>& right)
	{
		return VectorMul<3, T, ML_USE_SIMD>::Compute(left, right);
	}

	template<typename T>
	Vector<3, T> operator/(const Vector<3, T>& left, const Vector<3, T>& right)
	{
		return VectorDiv<3, T, ML_USE_SIMD>::Compute(left, right);
	}


	// ----- Binary Scalar Operators -----
	template<typename T>
	Vector<3, T> operator+(const Vector<3, T>& left, T value)
	{
		return VectorAdd<3, T, ML_USE_SIMD>::Compute(left, value);
	}

	template<typename T>
	Vector<3, T> operator-(const Vector<3, T>& left, T value)
	{
		return VectorSub<3, T, ML_USE_SIMD>::Compute(left, value);
	}

	template<typename T>
	Vector<3, T> operator*(const Vector<3, T>& left, T value)
	{
		return VectorMul<3, T, ML_USE_SIMD>::Compute(left, value);
	}

	template<typename T>
	Vector<3, T> operator/(const Vector<3, T>& left, T value)
	{
		return VectorDiv<3, T, ML_USE_SIMD>::Compute(left, value);
	}



}