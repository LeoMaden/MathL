#include <gtest/gtest.h>

#include <immintrin.h>

#include "QuaternionFloat.h"

namespace MathL {
namespace Tests {
	
	// ----- Constructors -----
	TEST(QuaternionFloatTest, ConstructsZeroQuat)
	{
		Quaternion<float> quat;

		EXPECT_FLOAT_EQ(quat.x, 0.0f);
		EXPECT_FLOAT_EQ(quat.y, 0.0f);
		EXPECT_FLOAT_EQ(quat.z, 0.0f);
		EXPECT_FLOAT_EQ(quat.w, 0.0f);
	}

	TEST(QuaternionFloatTest, ConstructsQuatWithValues)
	{
		Quaternion<float> a(1.0f, 2.0f, 3.0f, 4.0f);

		EXPECT_FLOAT_EQ(a.x, 1.0f);
		EXPECT_FLOAT_EQ(a.y, 2.0f);
		EXPECT_FLOAT_EQ(a.z, 3.0f);
		EXPECT_FLOAT_EQ(a.w, 4.0f);
	}


	// ----- Unary Quaternion Operators -----
	TEST(QuaternionFloatTest, OperatorPlusEqualsWorks)
	{
		Quaternion<float> a(1.0f, 2.0f, 3.0f, 4.0f);
		Quaternion<float> b(1.0f, 2.0f, 3.0f, 4.0f);

		a += b;

		EXPECT_FLOAT_EQ(a.x, 2.0f);
		EXPECT_FLOAT_EQ(a.y, 4.0f);
		EXPECT_FLOAT_EQ(a.z, 6.0f);
		EXPECT_FLOAT_EQ(a.w, 8.0f);
	}

	TEST(QuaternionFloatTest, OperatorMinusEqualsWorks)
	{
		Quaternion<float> a(1.0f, 2.0f, 3.0f, 4.0f);
		Quaternion<float> b(1.0f, 1.0f, 1.0f, 1.0f);

		a -= b;

		EXPECT_FLOAT_EQ(a.x, 0.0f);
		EXPECT_FLOAT_EQ(a.y, 1.0f);
		EXPECT_FLOAT_EQ(a.z, 2.0f);
		EXPECT_FLOAT_EQ(a.w, 3.0f);
	}

	TEST(QuaternionFloatTest, OperatorTimesEqualsWorks)
	{
		Quaternion<float> a(1.0f, 2.0f, 3.0f, 4.0f);
		Quaternion<float> b(2.0f, 3.0f, 2.0f, 1.0f);

		a *= b;

		EXPECT_FLOAT_EQ(a.x, -14.0f);
		EXPECT_FLOAT_EQ(a.y, 2.0f);
		EXPECT_FLOAT_EQ(a.z, 18.0f);
		EXPECT_FLOAT_EQ(a.w, 4.0f);
	}

	TEST(QuaternionFloatTest, OperatorDivideEqualsWorks)
	{
		Quaternion<float> a(1.0f, 2.0f, 3.0f, 4.0f);

		a /= a;

		EXPECT_FLOAT_EQ(a.x, 1.0f);
		EXPECT_FLOAT_EQ(a.y, 0.0f);
		EXPECT_FLOAT_EQ(a.z, 0.0f);
		EXPECT_FLOAT_EQ(a.w, 0.0f);
	}


	// ----- Binary Quaternion Operators -----
	TEST(QuaternionFloatTest, OperatorPlusWorks)
	{
		Quaternion<float> a(1.0f, 2.0f, 3.0f, 4.0f);
		Quaternion<float> b(1.0f, 1.0f, 1.0f, 1.0f);

		Quaternion<float> result = a + b;

		EXPECT_FLOAT_EQ(result.x, 2.0f);
		EXPECT_FLOAT_EQ(result.y, 3.0f);
		EXPECT_FLOAT_EQ(result.z, 4.0f);
		EXPECT_FLOAT_EQ(result.w, 5.0f);
	}

	TEST(QuaternionFloatTest, OperatorMinusWorks)
	{
		Quaternion<float> a(1.0f, 2.0f, 3.0f, 4.0f);
		Quaternion<float> b(1.0f, 1.0f, 1.0f, 1.0f);

		Quaternion<float> result = a - b;

		EXPECT_FLOAT_EQ(result.x, 0.0f);
		EXPECT_FLOAT_EQ(result.y, 1.0f);
		EXPECT_FLOAT_EQ(result.z, 2.0f);
		EXPECT_FLOAT_EQ(result.w, 3.0f);
	}

	TEST(QuaternionFloatTest, OperatorTimesWorks)
	{
		Quaternion<float> a(1.0f, 2.0f, 3.0f, 4.0f);
		Quaternion<float> b(2.0f, 3.0f, 2.0f, 1.0f);

		Quaternion<float> result = a * b;

		EXPECT_FLOAT_EQ(result.x, -14.0f);
		EXPECT_FLOAT_EQ(result.y, 2.0f);
		EXPECT_FLOAT_EQ(result.z, 18.0f);
		EXPECT_FLOAT_EQ(result.w, 4.0f);
	}

	TEST(QuaternionFloatTest, OperatorDivideWorks)
	{
		Quaternion<float> a(1.0f, 2.0f, 3.0f, 4.0f);

		Quaternion<float> result = a / a;

		EXPECT_FLOAT_EQ(result.x, 1.0f);
		EXPECT_FLOAT_EQ(result.y, 0.0f);
		EXPECT_FLOAT_EQ(result.z, 0.0f);
		EXPECT_FLOAT_EQ(result.w, 0.0f);
	}


	// ----- SIMD Operations -----
	TEST(QuaternionFloatTest, SimdAddWorks)
	{
		Quaternion<float> a(1.0f, 2.0f, 3.0f, 4.0f);
		Quaternion<float> b(1.0f, 1.0f, 1.0f, 1.0f);

		Quaternion<float> result = QuaternionAdd<float, true>::Compute(a, b);

		EXPECT_FLOAT_EQ(result.x, 2.0f);
		EXPECT_FLOAT_EQ(result.y, 3.0f);
		EXPECT_FLOAT_EQ(result.z, 4.0f);
		EXPECT_FLOAT_EQ(result.w, 5.0f); 
	}

	TEST(QuaternionFloatTest, SimdSubWorks)
	{
		Quaternion<float> a(5.0f, 6.0f, 7.0f, 8.0f);
		Quaternion<float> b(3.0f, 4.0f, 1.0f, 2.0f);

		Quaternion<float> result = QuaternionSub<float, true>::Compute(a, b);

		EXPECT_FLOAT_EQ(result.x, 2.0f);
		EXPECT_FLOAT_EQ(result.y, 2.0f);
		EXPECT_FLOAT_EQ(result.z, 6.0f);
		EXPECT_FLOAT_EQ(result.w, 6.0f);
	}

}
}