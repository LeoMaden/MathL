#pragma once

#include "QuaternionFloat.h"

namespace MathL {

	template<bool UseSimd>
	struct QuaternionAdd<float, UseSimd>
	{
		inline static Quaternion<float> Compute(const Quaternion<float>& left, const Quaternion<float>& right)
		{
			return Quaternion<float>(
				left.x + right.x,
				left.y + right.y,
				left.z + right.z,
				left.w + right.w
				);
		}

		inline static Quaternion<float> Compute(const Quaternion<float>& left, float value)
		{
			return Quaternion<float>(
				left.x + value,
				left.y,
				left.z,
				left.w
				);
		}
	};

	template<bool UseSimd>
	struct QuaternionSub<float, UseSimd>
	{
		inline static Quaternion<float> Compute(const Quaternion<float>& left, const Quaternion<float>& right)
		{
			return Quaternion<float>(
				left.x - right.x,
				left.y - right.y,
				left.z - right.z,
				left.w - right.w
				);
		}

		inline static Quaternion<float> Compute(const Quaternion<float>& left, float value)
		{
			return Quaternion<float>(
				left.x - value,
				left.y,
				left.z,
				left.w
				);
		}
	};

	template<bool UseSimd>
	struct QuaternionMul<float, UseSimd>
	{
		inline static Quaternion<float> Compute(const Quaternion<float>& left, const Quaternion<float>& right)
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

		inline static Quaternion<float> Compute(const Quaternion<float>& left, float value)
		{
			return Quaternion<float>(
				left.x * value,
				left.y * value,
				left.z * value,
				left.w * value
				);
		}
	};

	template<bool UseSimd>
	struct QuaternionDiv<float, UseSimd>
	{
		inline static Quaternion<float> Compute(const Quaternion<float>& left, const Quaternion<float>& right)
		{
			auto rightInv = QuaternionReciprocal<float, ML_USE_SIMD>::Compute(right);
			return QuaternionMul<float, ML_USE_SIMD>::Compute(left, rightInv);
		}

		inline static Quaternion<float> Compute(const Quaternion<float>& left, float value)
		{
			return Quaternion<float>(
				left.x / value,
				left.y / value,
				left.z / value,
				left.w / value
				);
		}
	};

	template<bool UseSimd>
	struct QuaternionNorm<float, UseSimd>
	{
		inline static float Compute(const Quaternion<float>& quat)
		{
			return std::sqrt(std::powf(quat.x, 2) + std::powf(quat.y, 2) + std::powf(quat.z, 2) + std::powf(quat.w, 2));
		}
	};

	template<bool UseSimd>
	struct QuaternionReciprocal<float, UseSimd>
	{
		inline static Quaternion<float> Compute(const Quaternion<float>& quat)
		{
			float normSquared = std::powf(QuaternionNorm<float, ML_USE_SIMD>::Compute(quat), 2);
			return QuaternionDiv<float, ML_USE_SIMD>::Compute(quat.Conjugate(), normSquared);
		}
	};


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

	inline float& Quaternion<float>::operator[](int i)
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
		return QuaternionNorm<float, ML_USE_SIMD>::Compute(*this);
	}

	inline Quaternion<float> Quaternion<float>::Conjugate() const
	{
		return Quaternion<float>(x, -y, -z, -w);
	}

	inline Quaternion<float> Quaternion<float>::Reciprocal() const
	{
		return QuaternionReciprocal<float, ML_USE_SIMD>::Compute(*this);
	}


	// ----- Unary Quaternion Operators -----
	inline Quaternion<float>& Quaternion<float>::operator+=(const Quaternion<float>& other)
	{
		return *this = QuaternionAdd<float, ML_USE_SIMD>::Compute(*this, other);
	}

	inline Quaternion<float>& Quaternion<float>::operator-=(const Quaternion<float>& other)
	{
		return *this = QuaternionSub<float, ML_USE_SIMD>::Compute(*this, other);
	}

	inline Quaternion<float>& Quaternion<float>::operator*=(const Quaternion<float>& other)
	{
		return *this = QuaternionMul<float, ML_USE_SIMD>::Compute(*this, other);
	}

	inline Quaternion<float>& Quaternion<float>::operator/=(const Quaternion<float>& other)
	{
		return *this = QuaternionDiv<float, ML_USE_SIMD>::Compute(*this, other);
	}


	// ----- Unary Scalar Operators -----
	inline Quaternion<float>& Quaternion<float>::operator+=(float other)
	{
		return QuaternionAdd<float, ML_USE_SIMD>::Compute(*this, other);
	}

	inline Quaternion<float>& Quaternion<float>::operator-=(float other)
	{
		return QuaternionSub<float, ML_USE_SIMD>::Compute(*this, other);
	}

	inline Quaternion<float>& Quaternion<float>::operator*=(float other)
	{
		return QuaternionMul<float, ML_USE_SIMD>::Compute(*this, other);
	}

	inline Quaternion<float>& Quaternion<float>::operator/=(float other)
	{
		return QuaternionDiv<float, ML_USE_SIMD>::Compute(*this, other);
	}


	// ----- Binary Quaternion Operators -----
	Quaternion<float> operator+(const Quaternion<float>& left, const Quaternion<float>& right)
	{
		return QuaternionAdd<float, ML_USE_SIMD>::Compute(left, right);
	}

	Quaternion<float> operator-(const Quaternion<float>& left, const Quaternion<float>& right)
	{
		return QuaternionSub<float, ML_USE_SIMD>::Compute(left, right);
	}

	Quaternion<float> operator*(const Quaternion<float>& left, const Quaternion<float>& right)
	{
		return QuaternionMul<float, ML_USE_SIMD>::Compute(left, right);
	}

	Quaternion<float> operator/(const Quaternion<float>& left, const Quaternion<float>& right)
	{
		return QuaternionDiv<float, ML_USE_SIMD>::Compute(left, right);
	}


	// ----- Binary Quaternion Operators -----
	Quaternion<float> operator+(const Quaternion<float>& left, float value)
	{
		return QuaternionAdd<float, ML_USE_SIMD>::Compute(left, value);
	}

	Quaternion<float> operator-(const Quaternion<float>& left, float value)
	{
		return QuaternionSub<float, ML_USE_SIMD>::Compute(left, value);
	}

	Quaternion<float> operator*(const Quaternion<float>& left, float value)
	{
		return QuaternionMul<float, ML_USE_SIMD>::Compute(left, value);
	}

	Quaternion<float> operator/(const Quaternion<float>& left, float value)
	{
		return QuaternionDiv<float, ML_USE_SIMD>::Compute(left, value);
	}

}