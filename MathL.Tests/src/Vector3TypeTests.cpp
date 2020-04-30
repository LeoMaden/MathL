#include <gtest/gtest.h>

#include "Vector3Type.h"

#include "Storage.h"

namespace MathL {
namespace Tests {

	// ----- Basic Constructors -----
	TEST(Vector3TypeTest, ConstructsZeroVector)
	{
		Vector<3, float> v;

		EXPECT_FLOAT_EQ(v.x, 0.0f);
		EXPECT_FLOAT_EQ(v.y, 0.0f);
		EXPECT_FLOAT_EQ(v.z, 0.0f);
	}

	TEST(Vector3TypeTest, ConstructsVectorWithValues)
	{
		Vector<3, float> v(1.0f, 2.0f, 3.0f);

		EXPECT_FLOAT_EQ(v.x, 1.0f);
		EXPECT_FLOAT_EQ(v.y, 2.0f);
		EXPECT_FLOAT_EQ(v.z, 3.0f);
	}


	// ----- Copy/Conversion Constructors -----
	TEST(Vector3TypeTest, ConstructsFromVector3)
	{
		Vector<3, float> a(1.0f, 2.0f, 3.0f);
		Vector<3, float> b(a);

		EXPECT_FLOAT_EQ(b.x, 1.0f);
		EXPECT_FLOAT_EQ(b.y, 2.0f);
		EXPECT_FLOAT_EQ(b.z, 3.0f);
	}


	// ----- Math Operators -----
	TEST(Vector3TypeTest, DotProductWorks)
	{
		Vector<3, float> a(1.0f, 2.0f, 3.0f);
		Vector<3, float> b(4.0f, 5.0f, 6.0f);

		auto result = a.Dot(b);

		EXPECT_FLOAT_EQ(result, 32.0f);
	}

	TEST(Vector3TypeTest, CrossProductWorks)
	{
		Vector<3, float> a(1.0f, 4.0f, 2.0f);
		Vector<3, float> b(3.0f, 1.0f, 1.0f);

		auto result = a.Cross(b);

		EXPECT_FLOAT_EQ(result.x, 2.0f);
		EXPECT_FLOAT_EQ(result.y, 5.0f);
		EXPECT_FLOAT_EQ(result.z, -11.0f);
	}


	// ----- Unary Vector Operators -----
	TEST(Vector3TypeTest, OperatorPlusEqualsWorks)
	{
		Vector<3, float> a(1.0f, 4.0f, 2.0f);
		Vector<3, float> b(3.0f, 1.0f, 1.0f);

		a += b;

		EXPECT_FLOAT_EQ(a.x, 4.0f);
		EXPECT_FLOAT_EQ(a.y, 5.0f);
		EXPECT_FLOAT_EQ(a.z, 3.0f);
	}

	TEST(Vector3TypeTest, OperatorMinusEqualsWorks)
	{
		Vector<3, float> a(1.0f, 4.0f, 2.0f);
		Vector<3, float> b(3.0f, 1.0f, 1.0f);

		a -= b;

		EXPECT_FLOAT_EQ(a.x, -2.0f);
		EXPECT_FLOAT_EQ(a.y, 3.0f);
		EXPECT_FLOAT_EQ(a.z, 1.0f);
	}

	TEST(Vector3TypeTest, OperatorTimesEqualsWorks)
	{
		Vector<3, float> a(1.0f, 4.0f, 2.0f);
		Vector<3, float> b(3.0f, 1.0f, 1.0f);

		a *= b;

		EXPECT_FLOAT_EQ(a.x, 3.0f);
		EXPECT_FLOAT_EQ(a.y, 4.0f);
		EXPECT_FLOAT_EQ(a.z, 2.0f);
	}

	TEST(Vector3TypeTest, OperatorDivideEqualsWorks)
	{
		Vector<3, float> a(4.0f, 1.0f, 6.0f);
		Vector<3, float> b(2.0f, 4.0f, 3.0f);

		a /= b;

		EXPECT_FLOAT_EQ(a.x, 2.0f);
		EXPECT_FLOAT_EQ(a.y, 0.25f);
		EXPECT_FLOAT_EQ(a.z, 2.0f);
	}



	// ----- Unary Scalar Operators -----
}
}