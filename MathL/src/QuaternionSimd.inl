#pragma once

#include "QuaternionType.h"
#include "Storage.h"

namespace MathL {

#if ML_SUPPORTS_AVX == 1
	template<>
	struct QuaternionAdd<float, true>
	{
		inline static Quaternion<float> Compute(const Quaternion<float>& left, const Quaternion<float>& right)
		{
			__m128 result = _mm_add_ps(left.data, right.data);
			float* floats = result.m128_f32;

			return Quaternion<float>(floats[0], floats[1], floats[2], floats[3]);
		}

		inline static Quaternion<float> Compute(const Quaternion<float>& left, float value)
		{
			__m128 result = _mm_add_ps(left.data, _mm_set1_ps(value));
			float* floats = result.m128_f32;

			return Quaternion<float>(floats[0], floats[1], floats[2], floats[3]);
		}
	};

	template<>
	struct QuaternionSub<float, true>
	{
		inline static Quaternion<float> Compute(const Quaternion<float>& left, const Quaternion<float>& right)
		{
			__m128 result = _mm_sub_ps(left.data, right.data);
			float* floats = result.m128_f32;

			return Quaternion<float>(floats[0], floats[1], floats[2], floats[3]);
		}

		inline static Quaternion<float> Compute(const Quaternion<float>& left, float value)
		{
			__m128 result = _mm_sub_ps(left.data, _mm_set1_ps(value));
			float* floats = result.m128_f32;

			return Quaternion<float>(floats[0], floats[1], floats[2], floats[3]);
		}
	};
#endif

}