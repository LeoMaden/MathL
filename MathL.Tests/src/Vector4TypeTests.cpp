#include <gtest/gtest.h>

#include "Vector4Type.h"

#include "Storage.h"

namespace MathL {
namespace Tests {

	// ----- Basic Constructors -----
	TEST(Vector4TypeTest, ConstructsZeroVector)
	{
		Vector<4, float> v;

		EXPECT_FLOAT_EQ(v.x, 0.0f);
		EXPECT_FLOAT_EQ(v.y, 0.0f);
		EXPECT_FLOAT_EQ(v.z, 0.0f);
		EXPECT_FLOAT_EQ(v.w, 0.0f);
	}

	TEST(Vector4TypeTest, ConstructsVectorWithValues)
	{
		Vector<4, float> v(1.0f, 2.0f, 4.0f, 3.0f);

		EXPECT_FLOAT_EQ(v.x, 1.0f);
		EXPECT_FLOAT_EQ(v.y, 2.0f);
		EXPECT_FLOAT_EQ(v.z, 4.0f);
		EXPECT_FLOAT_EQ(v.w, 3.0f);
	}


	// ----- Copy/Conversion Constructors -----
	TEST(Vector4TypeTest, ConstructsFromVector4)
	{
		Vector<4, float> a(1.0f, 2.0f, 4.0f, 3.0f);
		Vector<4, float> b(a);

		EXPECT_FLOAT_EQ(b.x, 1.0f);
		EXPECT_FLOAT_EQ(b.y, 2.0f);
		EXPECT_FLOAT_EQ(b.z, 4.0f);
		EXPECT_FLOAT_EQ(b.w, 3.0f);
	}


	// ----- Math Operators -----
	TEST(Vector4TypeTest, DotProductWorks)
	{
		Vector<4, float> a(1.0f, 2.0f, 4.0f, 3.0f);
		Vector<4, float> b(4.0f, 5.0f, 6.0f, 2.0f);

		auto result = a.Dot(b);

		EXPECT_FLOAT_EQ(result, 44.0f);
	}


	// ----- Unary Vector Operators -----
	TEST(Vector4TypeTest, OperatorPlusEqualsWorks)
	{
		Vector<4, float> a(1.0f, 4.0f, 2.0f, 3.0f);
		Vector<4, float> b(4.0f, 1.0f, 1.0f, 2.0f);

		a += b;

		EXPECT_FLOAT_EQ(a.x, 5.0f);
		EXPECT_FLOAT_EQ(a.y, 5.0f);
		EXPECT_FLOAT_EQ(a.z, 3.0f);
		EXPECT_FLOAT_EQ(a.w, 5.0f);
	}

	TEST(Vector4TypeTest, OperatorMinusEqualsWorks)
	{
		Vector<4, float> a(1.0f, 4.0f, 2.0f, 3.0f);
		Vector<4, float> b(4.0f, 1.0f, 1.0f, 2.0f);

		a -= b;

		EXPECT_FLOAT_EQ(a.x, -3.0f);
		EXPECT_FLOAT_EQ(a.y, 3.0f);
		EXPECT_FLOAT_EQ(a.z, 1.0f);
		EXPECT_FLOAT_EQ(a.w, 1.0f);
	}

	TEST(Vector4TypeTest, OperatorTimesEqualsWorks)
	{
		Vector<4, float> a(1.0f, 4.0f, 2.0f, 3.0f);
		Vector<4, float> b(4.0f, 1.0f, 1.0f, 2.0f);

		a *= b;

		EXPECT_FLOAT_EQ(a.x, 4.0f);
		EXPECT_FLOAT_EQ(a.y, 4.0f);
		EXPECT_FLOAT_EQ(a.z, 2.0f);
		EXPECT_FLOAT_EQ(a.w, 6.0f);
	}

	TEST(Vector4TypeTest, OperatorDivideEqualsWorks)
	{
		Vector<4, float> a(1.0f, 4.0f, 2.0f, 3.0f);
		Vector<4, float> b(4.0f, 1.0f, 1.0f, 2.0f);

		a /= b;

		EXPECT_FLOAT_EQ(a.x, 0.25f);
		EXPECT_FLOAT_EQ(a.y, 4.0f);
		EXPECT_FLOAT_EQ(a.z, 2.0f);
		EXPECT_FLOAT_EQ(a.w, 1.5f);
	}


	// ----- Unary Scalar Operators -----
	TEST(Vector4TypeTest, OperatorScalarPlusEqualsWorks)
	{
		Vector<4, float> a(1.0f, 4.0f, 2.0f, 3.0f);

		a += 2.0f;

		EXPECT_FLOAT_EQ(a.x, 3.0f);
		EXPECT_FLOAT_EQ(a.y, 6.0f);
		EXPECT_FLOAT_EQ(a.z, 4.0f);
		EXPECT_FLOAT_EQ(a.w, 5.0f);
	}

	TEST(Vector4TypeTest, OperatorScalarMinusEqualsWorks)
	{
		Vector<4, float> a(1.0f, 4.0f, 2.0f, 3.0f);

		a -= 2.0f;

		EXPECT_FLOAT_EQ(a.x, -1.0f);
		EXPECT_FLOAT_EQ(a.y, 2.0f);
		EXPECT_FLOAT_EQ(a.z, 0.0f);
		EXPECT_FLOAT_EQ(a.w, 1.0f);
	}

	TEST(Vector4TypeTest, OperatorScalarTimesEqualsWorks)
	{
		Vector<4, float> a(1.0f, 4.0f, 2.0f, 3.0f);

		a *= 2.0f;

		EXPECT_FLOAT_EQ(a.x, 2.0f);
		EXPECT_FLOAT_EQ(a.y, 8.0f);
		EXPECT_FLOAT_EQ(a.z, 4.0f);
		EXPECT_FLOAT_EQ(a.w, 6.0f);
	}

	TEST(Vector4TypeTest, OperatorScalarDivideEqualsWorks)
	{
		Vector<4, float> a(1.0f, 4.0f, 2.0f, 3.0f);

		a /= 2.0f;

		EXPECT_FLOAT_EQ(a.x, 0.5f);
		EXPECT_FLOAT_EQ(a.y, 2.0f);
		EXPECT_FLOAT_EQ(a.z, 1.0f);
		EXPECT_FLOAT_EQ(a.w, 1.5f);
	}


	// ----- Binary Vector Operators -----
	TEST(Vector4TypeTest, OperatorPlusWorks)
	{
		Vector<4, float> a(1.0f, 4.0f, 2.0f, 3.0f);
		Vector<4, float> b(4.0f, 1.0f, 1.0f, 2.0f);

		Vector<4, float> result = a + b;

		EXPECT_FLOAT_EQ(result.x, 5.0f);
		EXPECT_FLOAT_EQ(result.y, 5.0f);
		EXPECT_FLOAT_EQ(result.z, 3.0f);
		EXPECT_FLOAT_EQ(result.w, 5.0f);
	}

	TEST(Vector4TypeTest, OperatorMinusWorks)
	{
		Vector<4, float> a(1.0f, 4.0f, 2.0f, 3.0f);
		Vector<4, float> b(4.0f, 1.0f, 1.0f, 2.0f);

		Vector<4, float> result = a - b;

		EXPECT_FLOAT_EQ(result.x, -3.0f);
		EXPECT_FLOAT_EQ(result.y, 3.0f);
		EXPECT_FLOAT_EQ(result.z, 1.0f);
		EXPECT_FLOAT_EQ(result.w, 1.0f);
	}

	TEST(Vector4TypeTest, OperatorTimesWorks)
	{
		Vector<4, float> a(1.0f, 4.0f, 2.0f, 3.0f);
		Vector<4, float> b(4.0f, 1.0f, 1.0f, 2.0f);

		Vector<4, float> result = a * b;

		EXPECT_FLOAT_EQ(result.x, 4.0f);
		EXPECT_FLOAT_EQ(result.y, 4.0f);
		EXPECT_FLOAT_EQ(result.z, 2.0f);
		EXPECT_FLOAT_EQ(result.w, 6.0f);
	}

	TEST(Vector4TypeTest, OperatorDivideWorks)
	{
		Vector<4, float> a(1.0f, 4.0f, 2.0f, 3.0f);
		Vector<4, float> b(4.0f, 1.0f, 1.0f, 2.0f);

		Vector<4, float> result = a / b;

		EXPECT_FLOAT_EQ(result.x, 0.25f);
		EXPECT_FLOAT_EQ(result.y, 4.0f);
		EXPECT_FLOAT_EQ(result.z, 2.0f);
		EXPECT_FLOAT_EQ(result.w, 1.5f);
	}


	// ----- Unary Scalar Operators -----
	TEST(Vector4TypeTest, OperatorScalarPlusWorks)
	{
		Vector<4, float> a(1.0f, 4.0f, 2.0f, 3.0f);

		Vector<4, float> result = a + 2.0f;

		EXPECT_FLOAT_EQ(result.x, 3.0f);
		EXPECT_FLOAT_EQ(result.y, 6.0f);
		EXPECT_FLOAT_EQ(result.z, 4.0f);
		EXPECT_FLOAT_EQ(result.w, 5.0f);
	}

	TEST(Vector4TypeTest, OperatorScalarMinusWorks)
	{
		Vector<4, float> a(1.0f, 4.0f, 2.0f, 3.0f);

		Vector<4, float> result = a - 2.0f;

		EXPECT_FLOAT_EQ(result.x, -1.0f);
		EXPECT_FLOAT_EQ(result.y, 2.0f);
		EXPECT_FLOAT_EQ(result.z, 0.0f);
		EXPECT_FLOAT_EQ(result.w, 1.0f);
	}

	TEST(Vector4TypeTest, OperatorScalarTimesWorks)
	{
		Vector<4, float> a(1.0f, 4.0f, 2.0f, 3.0f);

		Vector<4, float> result = a * 2.0f;

		EXPECT_FLOAT_EQ(result.x, 2.0f);
		EXPECT_FLOAT_EQ(result.y, 8.0f);
		EXPECT_FLOAT_EQ(result.z, 4.0f);
		EXPECT_FLOAT_EQ(result.w, 6.0f);
	}

	TEST(Vector4TypeTest, OperatorScalarDivideWorks)
	{
		Vector<4, float> a(1.0f, 4.0f, 2.0f, 3.0f);

		Vector<4, float> result = a / 2.0f;

		EXPECT_FLOAT_EQ(result.x, 0.5f);
		EXPECT_FLOAT_EQ(result.y, 2.0f);
		EXPECT_FLOAT_EQ(result.z, 1.0f);
		EXPECT_FLOAT_EQ(result.w, 1.5f);
	}
}
}