#pragma once
#include "VectorType.h"

namespace MathL {

	template<>
	class Vector<3, float>
	{
	public:
		// ----- Data -----
		union
		{
			struct { float x, y, z; };
			struct { float a, b, c; };

			/*alignas(32)*/ float data[3] ;
		};

		// ----- Basic Constructors -----
		Vector();
		Vector(float x, float y, float z);

		// ----- Copy/Conversion Constructor -----
		Vector(const Vector<3, float>& other);

		//// ----- Math Operations -----
		//Vector<3, float> Cross(const Vector<3, float>& other);
		//float Dot(const Vector<3, float>& other);

		//// ----- Unary Vector Operators -----
		//Vector<3, float>& operator+=(const Vector<3, float>& other);
		//Vector<3, float>& operator-=(const Vector<3, float>& other);
		//Vector<3, float>& operator*=(const Vector<3, float>& other);
		//Vector<3, float>& operator/=(const Vector<3, float>& other);

		//// ----- Unary Scalar Operators -----
		//Vector<3, float>& operator+=(float other);
		//Vector<3, float>& operator-=(float other);
		//Vector<3, float>& operator*=(float other);
		//Vector<3, float>& operator/=(float other);
	};

	//// ----- Binary Vector Operators -----
	//Vector<3, float> operator+(const Vector<3, float>& left, const Vector<3, float>& right);
	//Vector<3, float> operator-(const Vector<3, float>& left, const Vector<3, float>& right);
	//Vector<3, float> operator*(const Vector<3, float>& left, const Vector<3, float>& right);
	//Vector<3, float> operator/(const Vector<3, float>& left, const Vector<3, float>& right);

	//// ----- Binary Scalar Operators -----
	//Vector<3, float> operator+(const Vector<3, float>& left, float value);
	//Vector<3, float> operator-(const Vector<3, float>& left, float value);
	//Vector<3, float> operator*(const Vector<3, float>& left, float value);
	//Vector<3, float> operator/(const Vector<3, float>& left, float value);

}
