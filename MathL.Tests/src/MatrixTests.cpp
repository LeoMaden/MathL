//#include <gtest/gtest.h>
//
//#include "Matrix.h"
//
//namespace MathL {
//namespace Tests {
//
//	// ----- MatrixBase -----
//	TEST(MatrixBaseTest, ConstructsEmptyMatrix)
//	{
//		MathL::MatrixBase<2, 2, int> mat;
//
//		EXPECT_EQ(mat.GetElement(0, 0), 0);
//		EXPECT_EQ(mat.GetElement(0, 1), 0);
//		EXPECT_EQ(mat.GetElement(1, 0), 0);
//		EXPECT_EQ(mat.GetElement(1, 1), 0);
//	}
//
//	TEST(MatrixBaseTest, ConstructsDiagMatrix)
//	{
//		MathL::MatrixBase<2, 2, float> mat(1.0f);
//
//		EXPECT_EQ(mat.GetElement(0, 0), 1.0f);
//		EXPECT_EQ(mat.GetElement(0, 1), 0.0f);
//		EXPECT_EQ(mat.GetElement(1, 0), 0.0f);
//		EXPECT_EQ(mat.GetElement(1, 1), 1.0f);
//	}
//
//	TEST(MatrixBaseTest, ConstructsFromArray)
//	{
//		double values[4]{ 1, 2, 3, 4 };
//		MathL::MatrixBase<2, 2, double> mat((double*)values);
//
//		EXPECT_EQ(mat.GetElement(0, 0), 1.0);
//		EXPECT_EQ(mat.GetElement(0, 1), 2.0);
//		EXPECT_EQ(mat.GetElement(1, 0), 3.0);
//		EXPECT_EQ(mat.GetElement(1, 1), 4.0);
//	}
//
//	/*TEST(MatrixBaseTest, ConstructsFrom2DArray)
//	{
//		MathL::MatrixBase<2, 2, float> mat(1.0f);
//
//		EXPECT_EQ(mat.GetElement(0, 0), 1.0f);
//		EXPECT_EQ(mat.GetElement(0, 1), 0.0f);
//		EXPECT_EQ(mat.GetElement(1, 0), 0.0f);
//		EXPECT_EQ(mat.GetElement(1, 1), 1.0f);
//	}*/
//
//	TEST(MatrixBaseTest, TransposeWorks)
//	{
//		MathL::MatrixBase<1, 3, float> mat;
//		mat.SetElement(0, 0, 1.0f);
//		mat.SetElement(0, 1, 2.0f);
//		mat.SetElement(0, 2, 3.0f);
//
//		MathL::MatrixBase<3, 1, float> mat2 = mat.Transpose();
//
//		EXPECT_EQ(mat2.GetElement(0, 0), 1.0f);
//		EXPECT_EQ(mat2.GetElement(1, 0), 2.0f);
//		EXPECT_EQ(mat2.GetElement(2, 0), 3.0f);
//	}
//
//}
//}