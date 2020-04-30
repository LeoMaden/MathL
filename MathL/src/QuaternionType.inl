#pragma once

#include "QuaternionType.h"
#include "Vector3Float.h"

#define ML_USE_SIMD false

namespace MathL {

	template<typename T, bool UseSimd>
	struct QuaternionAdd
	{
		inline static Quaternion<T> Compute(const Quaternion<T>& left, const Quaternion<T>& right)
		{
			return Quaternion<T>(
				left.x + right.x,
				left.y + right.y,
				left.z + right.z,
				left.w + right.w
				);
		}

		inline static Quaternion<T> Compute(const Quaternion<T>& left, T value)
		{
			return Quaternion<T>(
				left.x + value,
				left.y,
				left.z,
				left.w
				);
		}
	};

	template<typename T, bool UseSimd>
	struct QuaternionSub
	{
		inline static Quaternion<T> Compute(const Quaternion<T>& left, const Quaternion<T>& right)
		{
			return Quaternion<T>(
				left.x - right.x,
				left.y - right.y,
				left.z - right.z,
				left.w - right.w
				);
		}

		inline static Quaternion<T> Compute(const Quaternion<T>& left, T value)
		{
			return Quaternion<T>(
				left.x - value,
				left.y,
				left.z,
				left.w
				);
		}
	};

	template<typename T, bool UseSimd>
	struct QuaternionMul
	{
		inline static Quaternion<T> Compute(const Quaternion<T>& left, const Quaternion<T>& right)
		{
			T x1 = left.x;
			T y1 = left.y;
			T z1 = left.z;
			T w1 = left.w;

			T x2 = right.x;
			T y2 = right.y;
			T z2 = right.z;
			T w2 = right.w;

			return Quaternion<T>(
				x1 * x2 - y1 * y2 - z1 * z2 - w1 * w2,
				x1 * y2 + y1 * x2 + z1 * w2 - w1 * z2,
				x1 * z2 - y1 * w2 + z1 * x2 + w1 * y2,
				x1 * w2 + y1 * z2 - z1 * y2 + w1 * x2
				);
		}

		inline static Quaternion<T> Compute(const Quaternion<T>& left, T value)
		{
			return Quaternion<T>(
				left.x * value,
				left.y * value,
				left.z * value,
				left.w * value
				);
		}
	};

	/*template<>
	struct QuaternionMul<T, true>
	{
		inline static Quaternion<T> Compute(const Quaternion<T>& left, const Quaternion<T>& right)
		{
			T x1 = left.x;
			T y1 = left.y;
			T z1 = left.z;
			T w1 = left.w;

			T x2 = right.x;
			T y2 = right.y;
			T z2 = right.z;
			T w2 = right.w;

			__m256 xyMul1 = _mm256_set_ps(x1, x1, y1, y1, z1, z1, w1, w1);
			__m256 xyMul2 = _mm256_set_ps(x2, y2, y2, x2, z2, w2, w2, z2);

			__m256 zwMul1 = _mm256_set_ps(x1, x1, y1, y1, z1, z1, w1, w1);
			__m256 zwMul2 = _mm256_set_ps(x2, w2, w2, z2, x2, y2, y2, x2);

			__m256 xyMuls = _mm256_mul_ps(xyMul1, xyMul2);
			__m256 zwMuls = _mm256_mul_ps(zwMul1, zwMul2);

			return Quaternion<T>();
			

		}

		inline static Quaternion<T> Compute(const Quaternion<T>& left, T value)
		{
			__m128 ldata = _mm_load_ps(left.data);
			__m128 constant = _mm_set_ps(value, value, value, value);

			__m128 result = _mm_add_ps(ldata, constant);
			T* floats = result.m128_f32;

			return Quaternion<T>(floats[0], floats[1], floats[2], floats[3]);
		}
	};*/


	template<typename T, bool UseSimd>
	struct QuaternionDiv
	{
		inline static Quaternion<T> Compute(const Quaternion<T>& left, const Quaternion<T>& right)
		{
			auto rightInv = QuaternionReciprocal<T, ML_USE_SIMD>::Compute(right);
			return QuaternionMul<T, ML_USE_SIMD>::Compute(left, rightInv);
		}

		inline static Quaternion<T> Compute(const Quaternion<T>& left, T value)
		{
			return Quaternion<T>(
				left.x / value,
				left.y / value,
				left.z / value,
				left.w / value
				);
		}
	};

	template<typename T, bool UseSimd>
	struct QuaternionNorm
	{
		inline static T Compute(const Quaternion<T>& quat)
		{
			return std::sqrt(std::powf(quat.x, 2) + std::powf(quat.y, 2) + std::powf(quat.z, 2) + std::powf(quat.w, 2));
		}
	};

	template<typename T, bool UseSimd>
	struct QuaternionReciprocal
	{
		inline static Quaternion<T> Compute(const Quaternion<T>& quat)
		{
			T normSquared = std::powf(QuaternionNorm<T, ML_USE_SIMD>::Compute(quat), 2);
			return QuaternionDiv<T, ML_USE_SIMD>::Compute(quat.Conjugate(), normSquared);
		}
	};


	// ----- Basic Constructors -----
	template<typename T>
	inline MathL::Quaternion<T>::Quaternion()
		: x(0.0f), y(0.0f), z(0.0f), w(0.0f)
	{
	}

	template<typename T>
	inline Quaternion<T>::Quaternion(T x, T y, T z, T w)
		: x(x), y(y), z(z), w(w)
	{
	}

	template<typename T>
	inline Quaternion<T>::Quaternion(T value)
		: x(value), y(value), z(value), w(value)
	{
	}


	// ----- Copy / conversion -----
	template<typename T>
	inline Quaternion<T>::Quaternion(const Quaternion<T>& other)
		: x(other.x), y(other.y), z(other.z), w(other.w)
	{
	}


	// ----- Access -----
	template<typename T>
	inline T Quaternion<T>::ScalarPart()
	{
		return x;
	}

	template<typename T>
	inline Vector<3, T> Quaternion<T>::VectorPart()
	{
		return Vector<3, T>(y, z, w);
	}

	template<typename T>
	inline T& Quaternion<T>::operator[](int i)
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
	template<typename T>
	inline T Quaternion<T>::Norm() const
	{
		return QuaternionNorm<T, ML_USE_SIMD>::Compute(*this);
	}

	template<typename T>
	inline Quaternion<T> Quaternion<T>::Conjugate() const
	{
		return Quaternion<T>(x, -y, -z, -w);
	}

	template<typename T>
	inline Quaternion<T> Quaternion<T>::Reciprocal() const
	{
		return QuaternionReciprocal<T, ML_USE_SIMD>::Compute(*this);
	}


	// ----- Unary Quaternion Operators -----
	template<typename T>
	inline Quaternion<T>& Quaternion<T>::operator+=(const Quaternion<T>& other)
	{
		return *this = QuaternionAdd<T, ML_USE_SIMD>::Compute(*this, other);
	}

	template<typename T>
	inline Quaternion<T>& Quaternion<T>::operator-=(const Quaternion<T>& other)
	{
		return *this = QuaternionSub<T, ML_USE_SIMD>::Compute(*this, other);
	}

	template<typename T>
	inline Quaternion<T>& Quaternion<T>::operator*=(const Quaternion<T>& other)
	{
		return *this = QuaternionMul<T, ML_USE_SIMD>::Compute(*this, other);
	}

	template<typename T>
	inline Quaternion<T>& Quaternion<T>::operator/=(const Quaternion<T>& other)
	{
		return *this = QuaternionDiv<T, ML_USE_SIMD>::Compute(*this, other);
	}


	// ----- Unary Scalar Operators -----
	template<typename T>
	inline Quaternion<T>& Quaternion<T>::operator+=(T other)
	{
		return QuaternionAdd<T, ML_USE_SIMD>::Compute(*this, other);
	}

	template<typename T>
	inline Quaternion<T>& Quaternion<T>::operator-=(T other)
	{
		return QuaternionSub<T, ML_USE_SIMD>::Compute(*this, other);
	}

	template<typename T>
	inline Quaternion<T>& Quaternion<T>::operator*=(T other)
	{
		return QuaternionMul<T, ML_USE_SIMD>::Compute(*this, other);
	}

	template<typename T>
	inline Quaternion<T>& Quaternion<T>::operator/=(T other)
	{
		return QuaternionDiv<T, ML_USE_SIMD>::Compute(*this, other);
	}


	// ----- Binary Quaternion Operators -----
	template<typename T>
	Quaternion<T> operator+(const Quaternion<T>& left, const Quaternion<T>& right)
	{
		return QuaternionAdd<T, ML_USE_SIMD>::Compute(left, right);
	}

	template<typename T>
	Quaternion<T> operator-(const Quaternion<T>& left, const Quaternion<T>& right)
	{
		return QuaternionSub<T, ML_USE_SIMD>::Compute(left, right);
	}

	template<typename T>
	Quaternion<T> operator*(const Quaternion<T>& left, const Quaternion<T>& right)
	{
		return QuaternionMul<T, ML_USE_SIMD>::Compute(left, right);
	}

	template<typename T>
	Quaternion<T> operator/(const Quaternion<T>& left, const Quaternion<T>& right)
	{
		return QuaternionDiv<T, ML_USE_SIMD>::Compute(left, right);
	}


	// ----- Binary Quaternion Operators -----
	template<typename T>
	Quaternion<T> operator+(const Quaternion<T>& left, T value)
	{
		return QuaternionAdd<T, ML_USE_SIMD>::Compute(left, value);
	}

	template<typename T>
	Quaternion<T> operator-(const Quaternion<T>& left, T value)
	{
		return QuaternionSub<T, ML_USE_SIMD>::Compute(left, value);
	}

	template<typename T>
	Quaternion<T> operator*(const Quaternion<T>& left, T value)
	{
		return QuaternionMul<T, ML_USE_SIMD>::Compute(left, value);
	}

	template<typename T>
	Quaternion<T> operator/(const Quaternion<T>& left, T value)
	{
		return QuaternionDiv<T, ML_USE_SIMD>::Compute(left, value);
	}

}

#include "QuaternionSimd.inl"