#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 3.3F/Point.h"
#include "../lab 3.3F/Point.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Laba33F
{
	TEST_CLASS(Laba33F)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Point p1;
			p1 = Point(0, 4);
			double actual = p1.distanceToOrigin();
			double expected = 4;
			Assert::AreEqual(expected, actual);

		}
	};
}
