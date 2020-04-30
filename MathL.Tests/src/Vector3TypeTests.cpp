#include <gtest/gtest.h>

#include "Vector3Type.h"

#include "Storage.h"

namespace MathL {
namespace Tests {

	// ----- Constructors -----
	TEST(Vector3TypeTest, ConstructsZeroVector)
	{
		Vector<3, float> v;

		EXPECT_FLOAT_EQ(v.x, 0.0f);
		EXPECT_FLOAT_EQ(v.y, 0.0f);
		EXPECT_FLOAT_EQ(v.z, 0.0f);
	}

	TEST(TestTest, Test)
	{
		Storage<3, float, false>::Type x{};

		x.data;
	}
}
}