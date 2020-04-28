#include <gtest/gtest.h>

#include "QuaternionFloat.h"

namespace MathL {
namespace Tests {
	
	TEST(QuaternionFloatTest, ConstructsZeroQuat)
	{
		Quaternion<float> quat;

		EXPECT_EQ(quat.x, 0.0f);
		EXPECT_EQ(quat.y, 0.0f);
		EXPECT_EQ(quat.z, 0.0f);
		EXPECT_EQ(quat.w, 0.0f);
	}

	TEST(QuaternionFloatTest, DivideByItselfEqualsOne)
	{
		Quaternion<float> quat(1.0f, 2.0f, 3.0f, 4.0f);

		Quaternion<float> result = quat / quat;
	}

}
}