#pragma once

#include "VectorType.h"

namespace MathL {

	template<>
	class Vector<4, float>
	{
	public:
		// ----- Data -----
		union
		{
			struct { float x, y, z, w; };
			struct { float a, b, c, d; };

			/*alignas(32)*/ float data[4];
		};

		// ----- Basic Constructors -----
		Vector();
		Vector(float x, float y, float z, float w);

		// ----- Copy/Conversion Constructor -----
		Vector(const Vector<4, float>& other);

		//// ----- Math Operations -----
		//Vector<4, float> Cross(const Vector<4, float>& other);
		//float Dot(const Vector<4, float>& other);

		//// ----- Unary Vector Operators -----
		//Vector<4, float>& operator+=(const Vector<4, float>& other);
		//Vector<4, float>& operator-=(const Vector<4, float>& other);
		//Vector<4, float>& operator*=(const Vector<4, float>& other);
		//Vector<4, float>& operator/=(const Vector<4, float>& other);

		//// ----- Unary Scalar Operators -----
		//Vector<4, float>& operator+=(float other);
		//Vector<4, float>& operator-=(float other);
		//Vector<4, float>& operator*=(float other);
		//Vector<4, float>& operator/=(float other);
	};

	//// ----- Binary Vector Operators -----
	//Vector<4, float> operator+(const Vector<4, float>& left, const Vector<4, float>& right);
	//Vector<4, float> operator-(const Vector<4, float>& left, const Vector<4, float>& right);
	//Vector<4, float> operator*(const Vector<4, float>& left, const Vector<4, float>& right);
	//Vector<4, float> operator/(const Vector<4, float>& left, const Vector<4, float>& right);

	//// ----- Binary Scalar Operators -----
	//Vector<4, float> operator+(const Vector<4, float>& left, float value);
	//Vector<4, float> operator-(const Vector<4, float>& left, float value);
	//Vector<4, float> operator*(const Vector<4, float>& left, float value);
	//Vector<4, float> operator/(const Vector<4, float>& left, float value);

}

#include "Vector4Float.h"
