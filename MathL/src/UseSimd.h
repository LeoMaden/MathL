#pragma once

#define ML_USE_SIMD 0

namespace MathL {

	struct UseSimd
	{
		#if ML_USE_SIMD == 1
			static const bool Value = true;
		#else
			static const bool Value = false;
		#endif
	};

}