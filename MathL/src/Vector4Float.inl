#pragma once

#include "Vector4Float.h"

namespace MathL {

	// ----- Basic Constructors -----
	inline Vector<4, float>::Vector()
		: x(0.0f), y(0.0f), z(0.0f), w(0.0f)
	{
	}

	inline Vector<4, float>::Vector(float x, float y, float z, float w)
		: x(x), y(y), z(z), w(w)
	{
	}


	// ----- Copy/Conversion Constructors -----
	inline Vector<4, float>::Vector(const Vector<4, float>& other)
		: x(other.x), y(other.y), z(other.z), w(other.w)
	{
	}



}