#pragma once

#include "VectorBase.h"

namespace MathL {

	template<int D, typename T>
	class Vector : public VectorBase<D, T>
	{
	public:
		Vector() {}
		~Vector() {}
	};


	// ------------------------------------
	// ---- Template Specialisations ------
	// ------------------------------------
	template<>
	class Vector<3, float> : public VectorBase<3, float>
	{
	public:
		float& x = m_Data[0];
		float& y = m_Data[1];
		float& z = m_Data[2];

		Vector() {}
		Vector(float x, float y, float z);

		~Vector() {}
	};

	inline Vector<3, float>::Vector(float x, float y, float z)
	{
		m_Data[0] = x;
		m_Data[1] = y;
		m_Data[2] = z;
	}
}
