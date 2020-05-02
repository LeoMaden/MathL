#include <gtest/gtest.h>

#include "Matrix3x3Type.h"

namespace MathL {
namespace Tests {

	// ----- Basic Constructors -----
	TEST(Matrix3x3TypeTest, ConstructsZeroMatrix)
	{
		Matrix<3, 3, float> mat;

		EXPECT_FLOAT_EQ(mat[0][0], 0.0f);
		EXPECT_FLOAT_EQ(mat[0][1], 0.0f);
		EXPECT_FLOAT_EQ(mat[0][2], 0.0f);

		EXPECT_FLOAT_EQ(mat[1][0], 0.0f);
		EXPECT_FLOAT_EQ(mat[1][1], 0.0f);
		EXPECT_FLOAT_EQ(mat[1][2], 0.0f);

		EXPECT_FLOAT_EQ(mat[2][0], 0.0f);
		EXPECT_FLOAT_EQ(mat[2][1], 0.0f);
		EXPECT_FLOAT_EQ(mat[2][2], 0.0f);
	}

	TEST(Matrix3x3TypeTest, ConstructsDiagonalMatrix)
	{
		Matrix<3, 3, float> mat(2.0f);

		EXPECT_FLOAT_EQ(mat[0][0], 2.0f);
		EXPECT_FLOAT_EQ(mat[0][1], 0.0f);
		EXPECT_FLOAT_EQ(mat[0][2], 0.0f);

		EXPECT_FLOAT_EQ(mat[1][0], 0.0f);
		EXPECT_FLOAT_EQ(mat[1][1], 2.0f);
		EXPECT_FLOAT_EQ(mat[1][2], 0.0f);

		EXPECT_FLOAT_EQ(mat[2][0], 0.0f);
		EXPECT_FLOAT_EQ(mat[2][1], 0.0f);
		EXPECT_FLOAT_EQ(mat[2][2], 2.0f);
	}

	// ----- Binary Operators -----
	TEST(Matrix3x3TypeTest, OperatorPlusWorks)
	{
		Matrix<3, 3, float> a({ 1, 2, 3 }, { 4, 2, 1 }, { 5, 2, 2 });
		Matrix<3, 3, float> b({ 2, 3, 5 }, { 2, 1, 1 }, { 4, 2, 3 });
		
		Matrix<3, 3, float> result = a + b;

		EXPECT_FLOAT_EQ(result[0][0], 3.0f);
		EXPECT_FLOAT_EQ(result[0][1], 5.0f);
		EXPECT_FLOAT_EQ(result[0][2], 8.0f);

		EXPECT_FLOAT_EQ(result[1][0], 6.0f);
		EXPECT_FLOAT_EQ(result[1][1], 3.0f);
		EXPECT_FLOAT_EQ(result[1][2], 2.0f);

		EXPECT_FLOAT_EQ(result[2][0], 9.0f);
		EXPECT_FLOAT_EQ(result[2][1], 4.0f);
		EXPECT_FLOAT_EQ(result[2][2], 5.0f);
	}

	TEST(Matrix3x3TypeTest, OperatorMinusWorks)
	{
		Matrix<3, 3, float> a({ 1, 2, 3 }, { 4, 2, 1 }, { 5, 2, 2 });
		Matrix<3, 3, float> b({ 2, 3, 5 }, { 2, 1, 1 }, { 4, 2, 3 });

		Matrix<3, 3, float> result = a - b;

		EXPECT_FLOAT_EQ(result[0][0], -1.0f);
		EXPECT_FLOAT_EQ(result[0][1], -1.0f);
		EXPECT_FLOAT_EQ(result[0][2], -2.0f);

		EXPECT_FLOAT_EQ(result[1][0], 2.0f);
		EXPECT_FLOAT_EQ(result[1][1], 1.0f);
		EXPECT_FLOAT_EQ(result[1][2], 0.0f);

		EXPECT_FLOAT_EQ(result[2][0], 1.0f);
		EXPECT_FLOAT_EQ(result[2][1], 0.0f);
		EXPECT_FLOAT_EQ(result[2][2], -1.0f);
	}

	TEST(Matrix3x3TypeTest, OperatorTimesWorks)
	{
		Matrix<3, 3, float> a({ 1, 2, 3 }, { 4, 2, 1 }, { 5, 2, 2 });
		Matrix<3, 3, float> b({ 2, 3, 5 }, { 2, 1, 1 }, { 4, 2, 3 });

		Matrix<3, 3, float> result = a * b;

		EXPECT_FLOAT_EQ(result[0][0], 18.0f);
		EXPECT_FLOAT_EQ(result[0][1], 11.0f);
		EXPECT_FLOAT_EQ(result[0][2], 16.0f);

		EXPECT_FLOAT_EQ(result[1][0], 16.0f);
		EXPECT_FLOAT_EQ(result[1][1], 16.0f);
		EXPECT_FLOAT_EQ(result[1][2], 25.0f);

		EXPECT_FLOAT_EQ(result[2][0], 22.0f);
		EXPECT_FLOAT_EQ(result[2][1], 21.0f);
		EXPECT_FLOAT_EQ(result[2][2], 33.0f);
	}

	TEST(Matrix3x3TypeTest, OperatorVectorTimesWorks)
	{
		Matrix<3, 3, float> a({ 1, 2, 3 }, { 4, 2, 1 }, { 5, 2, 2 });
		Vector<3, float> b(2, 3, 5);

		Vector<3, float> result = a * b;

		EXPECT_FLOAT_EQ(result.x, 23.0f);
		EXPECT_FLOAT_EQ(result.y, 19.0f);
		EXPECT_FLOAT_EQ(result.z, 26.0f);
	}

}
}