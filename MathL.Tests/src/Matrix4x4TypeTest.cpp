#include <gtest/gtest.h>

#include "Matrix4x4Type.h"

namespace MathL {
	namespace Tests {

		// ----- Basic Constructors -----
		TEST(Matrix4x4TypeTest, ConstructsZeroMatrix)
		{
			Matrix<4, 4, float> mat;

			EXPECT_FLOAT_EQ(mat[0][0], 0.0f);
			EXPECT_FLOAT_EQ(mat[0][1], 0.0f);
			EXPECT_FLOAT_EQ(mat[0][2], 0.0f);
			EXPECT_FLOAT_EQ(mat[0][3], 0.0f);

			EXPECT_FLOAT_EQ(mat[1][0], 0.0f);
			EXPECT_FLOAT_EQ(mat[1][1], 0.0f);
			EXPECT_FLOAT_EQ(mat[1][2], 0.0f);
			EXPECT_FLOAT_EQ(mat[1][3], 0.0f);

			EXPECT_FLOAT_EQ(mat[2][0], 0.0f);
			EXPECT_FLOAT_EQ(mat[2][1], 0.0f);
			EXPECT_FLOAT_EQ(mat[2][2], 0.0f);
			EXPECT_FLOAT_EQ(mat[2][3], 0.0f);

			EXPECT_FLOAT_EQ(mat[3][0], 0.0f);
			EXPECT_FLOAT_EQ(mat[3][1], 0.0f);
			EXPECT_FLOAT_EQ(mat[3][2], 0.0f);
			EXPECT_FLOAT_EQ(mat[3][3], 0.0f);
		}

		TEST(Matrix4x4TypeTest, ConstructsDiagonalMatrix)
		{
			Matrix<4, 4, float> mat(2.0f);

			EXPECT_FLOAT_EQ(mat[0][0], 2.0f);
			EXPECT_FLOAT_EQ(mat[0][1], 0.0f);
			EXPECT_FLOAT_EQ(mat[0][2], 0.0f);
			EXPECT_FLOAT_EQ(mat[0][3], 0.0f);

			EXPECT_FLOAT_EQ(mat[1][0], 0.0f);
			EXPECT_FLOAT_EQ(mat[1][1], 2.0f);
			EXPECT_FLOAT_EQ(mat[1][2], 0.0f);
			EXPECT_FLOAT_EQ(mat[1][3], 0.0f);

			EXPECT_FLOAT_EQ(mat[2][0], 0.0f);
			EXPECT_FLOAT_EQ(mat[2][1], 0.0f);
			EXPECT_FLOAT_EQ(mat[2][2], 2.0f);
			EXPECT_FLOAT_EQ(mat[2][3], 0.0f);

			EXPECT_FLOAT_EQ(mat[3][0], 0.0f);
			EXPECT_FLOAT_EQ(mat[3][1], 0.0f);
			EXPECT_FLOAT_EQ(mat[3][2], 0.0f);
			EXPECT_FLOAT_EQ(mat[3][3], 2.0f);
		}

		// ----- Binary Operators -----
		TEST(Matrix4x4TypeTest, OperatorPlusWorks)
		{
			Matrix<4, 4, float> a({ 1, 2, 1, 3 }, { 4, 2, 1, 5 }, { 5, 2, 2, 6 }, { 3, 6, 1, 3 });
			Matrix<4, 4, float> b({ 2, 4, 5, 2 }, { 2, 1, 1, 3 }, { 4, 2, 4, 1 }, { 2, 4, 1, 1 });

			Matrix<4, 4, float> result = a + b;

			EXPECT_FLOAT_EQ(result[0][0], 3.0f);
			EXPECT_FLOAT_EQ(result[0][1], 6.0f);
			EXPECT_FLOAT_EQ(result[0][2], 6.0f);
			EXPECT_FLOAT_EQ(result[0][3], 5.0f);

			EXPECT_FLOAT_EQ(result[1][0], 6.0f);
			EXPECT_FLOAT_EQ(result[1][1], 3.0f);
			EXPECT_FLOAT_EQ(result[1][2], 2.0f);
			EXPECT_FLOAT_EQ(result[1][3], 8.0f);

			EXPECT_FLOAT_EQ(result[2][0], 9.0f);
			EXPECT_FLOAT_EQ(result[2][1], 4.0f);
			EXPECT_FLOAT_EQ(result[2][2], 6.0f);
			EXPECT_FLOAT_EQ(result[2][3], 7.0f);

			EXPECT_FLOAT_EQ(result[3][0], 5.0f);
			EXPECT_FLOAT_EQ(result[3][1], 10.0f);
			EXPECT_FLOAT_EQ(result[3][2], 2.0f);
			EXPECT_FLOAT_EQ(result[3][3], 4.0f);
		}

		TEST(Matrix4x4TypeTest, OperatorMinusWorks)
		{
			Matrix<4, 4, float> a({ 1, 2, 1, 3 }, { 4, 2, 1, 5 }, { 5, 2, 2, 6 }, { 3, 6, 1, 3 });
			Matrix<4, 4, float> b({ 2, 4, 5, 2 }, { 2, 1, 1, 3 }, { 4, 2, 4, 1 }, { 2, 4, 1, 1 });

			Matrix<4, 4, float> result = a - b;

			EXPECT_FLOAT_EQ(result[0][0], -1.0f);
			EXPECT_FLOAT_EQ(result[0][1], -2.0f);
			EXPECT_FLOAT_EQ(result[0][2], -4.0f);
			EXPECT_FLOAT_EQ(result[0][3], 1.0f);

			EXPECT_FLOAT_EQ(result[1][0], 2.0f);
			EXPECT_FLOAT_EQ(result[1][1], 1.0f);
			EXPECT_FLOAT_EQ(result[1][2], 0.0f);
			EXPECT_FLOAT_EQ(result[1][3], 2.0f);

			EXPECT_FLOAT_EQ(result[2][0], 1.0f);
			EXPECT_FLOAT_EQ(result[2][1], 0.0f);
			EXPECT_FLOAT_EQ(result[2][2], -2.0f);
			EXPECT_FLOAT_EQ(result[2][3], 5.0f);

			EXPECT_FLOAT_EQ(result[3][0], 1.0f);
			EXPECT_FLOAT_EQ(result[3][1], 2.0f);
			EXPECT_FLOAT_EQ(result[3][2], 0.0f);
			EXPECT_FLOAT_EQ(result[3][3], 2.0f);
		}

		TEST(Matrix4x4TypeTest, OperatorTimesWorks)
		{
			Matrix<4, 4, float> a({ 1, 2, 1, 3 }, { 4, 2, 1, 5 }, { 5, 2, 2, 6 }, { 3, 6, 1, 3 });
			Matrix<4, 4, float> b({ 2, 4, 5, 2 }, { 2, 1, 1, 3 }, { 4, 2, 4, 1 }, { 2, 4, 1, 1 });

			Matrix<4, 4, float> result = a * b;

			EXPECT_FLOAT_EQ(result[0][0], 16.0f);
			EXPECT_FLOAT_EQ(result[0][1], 20.0f);
			EXPECT_FLOAT_EQ(result[0][2], 14.0f);
			EXPECT_FLOAT_EQ(result[0][3], 12.0f);

			EXPECT_FLOAT_EQ(result[1][0], 26.0f);
			EXPECT_FLOAT_EQ(result[1][1], 40.0f);
			EXPECT_FLOAT_EQ(result[1][2], 31.0f);
			EXPECT_FLOAT_EQ(result[1][3], 20.0f);

			EXPECT_FLOAT_EQ(result[2][0], 34.0f);
			EXPECT_FLOAT_EQ(result[2][1], 50.0f);
			EXPECT_FLOAT_EQ(result[2][2], 41.0f);
			EXPECT_FLOAT_EQ(result[2][3], 24.0f);

			EXPECT_FLOAT_EQ(result[3][0], 28.0f);
			EXPECT_FLOAT_EQ(result[3][1], 32.0f);
			EXPECT_FLOAT_EQ(result[3][2], 28.0f);
			EXPECT_FLOAT_EQ(result[3][3], 28.0f);
		}

		TEST(Matrix4x4TypeTest, OperatorVectorTimesWorks)
		{
			Matrix<4, 4, float> a({ 1, 2, 1, 3 }, { 4, 2, 1, 5 }, { 5, 2, 2, 6 }, { 3, 6, 1, 3 });
			Vector<4, float> b(2, 4, 5, 5);

			Vector<4, float> result = a * b;

			EXPECT_FLOAT_EQ(result.x, 30.0f);
			EXPECT_FLOAT_EQ(result.y, 46.0f);
			EXPECT_FLOAT_EQ(result.z, 58.0f);
			EXPECT_FLOAT_EQ(result.w, 50.0f);
		}

	}
}