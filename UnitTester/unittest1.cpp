#include "stdafx.h"
#include "CppUnitTest.h"
#include "../include/Math.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTester
{		
	TEST_CLASS(MathTest)
	{
	public:
		
		TEST_METHOD(SqrFunction)
		{
            Assert::AreEqual(sqr(3), 9);
            Assert::AreEqual(sqr(0), 0);
            Assert::AreEqual(sqr(-2.1f), 4.41f, 1.e-5f);
		}

	};
}