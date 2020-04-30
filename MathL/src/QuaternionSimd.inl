#pragma once

#include <immintrin.h>

#include "QuaternionType.h"

namespace MathL {

	
	template<>
	struct QuaternionAdd<float, true>
	{
		inline static Quaternion<float> Compute(const Quaternion<float>& left, const Quaternion<float>& right)
		{
			__m128 ldata = _mm_load_ps(left.data);
			__m128 rdata = _mm_load_ps(right.data);

			__m128 result = _mm_add_ps(ldata, rdata);
			float* floats = result.m128_f32;

			return Quaternion<float>(floats[0], floats[1], floats[2], floats[3]);
		}

		inline static Quaternion<float> Compute(const Quaternion<float>& left, float value)
		{
			__m128 ldata = _mm_load_ps(left.data);
			__m128 constant = _mm_set_ps(value, value, value, value);

			__m128 result = _mm_add_ps(ldata, constant);
			float* floats = result.m128_f32;

			return Quaternion<float>(floats[0], floats[1], floats[2], floats[3]);
		}
	};

	template<>
	struct QuaternionSub<float, true>
	{
		inline static Quaternion<float> Compute(const Quaternion<float>& left, const Quaternion<float>& right)
		{
			__m128 ldata = _mm_load_ps(left.data);
			__m128 rdata = _mm_load_ps(right.data);

			__m128 result = _mm_sub_ps(ldata, rdata);
			float* floats = result.m128_f32;

			return Quaternion<float>(floats[0], floats[1], floats[2], floats[3]);
		}

		inline static Quaternion<float> Compute(const Quaternion<float>& left, float value)
		{
			__m128 ldata = _mm_load_ps(left.data);
			__m128 constant = _mm_set_ps(value, value, value, value);

			__m128 result = _mm_sub_ps(ldata, constant);
			float* floats = result.m128_f32;

			return Quaternion<float>(floats[0], floats[1], floats[2], floats[3]);
		}
	};

}