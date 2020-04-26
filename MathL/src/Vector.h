#pragma once

#include "VectorBase.h"

#include <cmath>

namespace MathL {

	template<int D, typename T>
	class Vector : public VectorBase<D, T>
	{
	public:
		ML_VECTOR_COMMON(Vector, D, T)

	};


	// ------------------------------------
	// ---- Template Specialisations ------
	// ------------------------------------

	// ----- D FLOAT -----
	template<int D>
	class Vector<D, float> : public VectorBase<D, float>
	{
	public:
		ML_VECTOR_COMMON(Vector, D, float)

		float Magnitude();
		Vector<D, float> UnitVector();
	};
	
	template<int D>
	float Vector<D, float>::Magnitude()
	{
		float mag = 0;

		for (int i = 0; i < D; i++)
		{
			mag += std::pow(m_Data[i], 2);
		}

		return std::sqrt(mag);
		// TODO: Specialised func for Vec<3, float>
	}

	template<int D>
	inline Vector<D, float> Vector<D, float>::UnitVector()
	{
		return Vector<D, float>();
	}

	// ----- 3 FLOAT -----
	template<>
	class Vector<3, float> : public VectorBase<3, float>
	{
	public:
		float& x = m_Data[0];
		float& y = m_Data[1];
		float& z = m_Data[2];

		ML_VECTOR_COMMON(Vector, 3, float)

		Vector(float x, float y, float z);
		float Magnitude();
	};

	inline Vector<3, float>::Vector(float x, float y, float z)
	{
		m_Data[0] = x;
		m_Data[1] = y;
		m_Data[2] = z;
	}

	inline float Vector<3, float>::Magnitude()
	{
		return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));
	}
	
}
