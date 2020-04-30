#pragma once

#include "Vector3Float.h"

namespace MathL {

	// ----- Basic Constructors -----
	inline Vector<3, float>::Vector()
		: x(0.0f), y(0.0f), z(0.0f)
	{
	}

	inline Vector<3, float>::Vector(float x, float y, float z)
		: x(x), y(y), z(z)
	{
	}


	// ----- Copy/Conversion Constructors -----
	inline Vector<3, float>::Vector(const Vector<3, float>& other)
		: x(other.x), y(other.y), z(other.z)
	{
	}



}