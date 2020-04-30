#pragma once

#include "Vector3Type.h"

namespace MathL {

	template<typename T, bool UseSimd>
	struct VectorAdd<3, T, UseSimd>
	{
		Vector<3, T> Compute(const Vector<3, T>& left, const Vector<3, T>& right)
		{
			return Vector<3, T>(
				left.x + right.x,
				left.y + right.y,
				left.z + right.z
				);
		}

		Vector<3, T> Compute(const Vector<3, T>& left, T value)
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
		Vector<3, T> Compute(const Vector<3, T>& left, const Vector<3, T>& right)
		{
			return Vector<3, T>(
				left.x - right.x,
				left.y - right.y,
				left.z - right.z
				);
		}

		Vector<3, T> Compute(const Vector<3, T>& left, T value)
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
		Vector<3, T> Compute(const Vector<3, T>& left, const Vector<3, T>& right)
		{
			return Vector<3, T>(
				left.x * right.x,
				left.y * right.y,
				left.z * right.z
				);
		}

		Vector<3, T> Compute(const Vector<3, T>& left, T value)
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
		Vector<3, T> Compute(const Vector<3, T>& left, const Vector<3, T>& right)
		{
			return Vector<3, T>(
				left.x / right.x,
				left.y / right.y,
				left.z / right.z
				);
		}

		Vector<3, T> Compute(const Vector<3, T>& left, T value)
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
		T Compute(const Vector<3, T>& left, const Vector<3, T>& right)
		{
			return (left.x * right.x) + (left.y * right.y) + (left.z * right.z);
		}
	};

	template<typename T, bool UseSimd>
	struct VectorCross<3, T, UseSimd>
	{
		Vector<3, T> Compute(const Vector<3, T>& left, const Vector<3, T>& right)
		{
			return Vector<3, T>(
				left.y * right.z - left.z * right.y,
				left.z * right.x - left.x * right.z,
				left.x * right.y - left.y - right.x
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



}