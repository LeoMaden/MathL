#pragma once

#define ML_USE_SIMD 0
#define ML_SUPPORTS_AVX 1
#define ML_USE_ALIGNED 1

// AVX Intrinsics
#include <immintrin.h>

namespace MathL {

	template<int L, typename T, bool IsAligned>
	struct Storage
	{
		typedef struct { T data[L]; } Type;
	};

#if (ML_USE_SIMD == 1) && (ML_SUPPORTS_AVX == 1)
	// Vector 3 or 4 Float
	template<>
	struct Storage<3, float, true>
	{
		typedef __m128 Type;
	};

	template<>
	struct Storage<4, float, true>
	{
		typedef __m128 Type;
	};

	// Vector 3 or 4 Double
	template<>
	struct Storage<3, double, true>
	{
		typedef __m256 Type;
	};

	template<>
	struct Storage<4, double, true>
	{
		typedef __m256 Type;
	};

	// Vector 3 or 4 Long Integer
	template<>
	struct Storage<3, long int, true>
	{
		typedef __m128i Type;
	};

	template<>
	struct Storage<4, long int, true>
	{
		typedef __m128i Type;
	};

	// Vector 3 or 4 Long Long Integer
	template<>
	struct Storage<3, long long int, true>
	{
		typedef __m256i Type;
	};

	template<>
	struct Storage<4, long long int, true>
	{
		typedef __m256i Type;
	};
#endif

}