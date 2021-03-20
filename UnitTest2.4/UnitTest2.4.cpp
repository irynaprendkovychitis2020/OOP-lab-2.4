#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2.4/Matrix.h"
#include "../lab2.4/Matrix.cpp"
#include "../lab2.4/Line.h"
#include "../lab2.4/Line.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest24
{
	TEST_CLASS(UnitTest24)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Matrix A(2);
			A[0][0] = 1;
			A[0][1] = 2;
			A[1][0] = 3;
			A[1][1] = 4;
			double c = A.Norm();
			Assert::AreEqual(3., c);
		}
	};
}
