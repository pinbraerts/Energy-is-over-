#include "CppUnitTest.h"
#include "../include/Math.hpp"
#include "../include/includes.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTester
{		
	TEST_CLASS(MathTest)
	{
	public:
		
		TEST_METHOD(SqrFunction)
		{
            Assert::AreEqual(square(3), 9);
            Assert::AreEqual(square(0), 0);
            Assert::AreEqual(square(-2.1f), 4.41f, 1.e-5f);
		}
	};

    TEST_CLASS(STOWSTest) {
public:
    TEST_METHOD(Stows) {
        Assert::AreEqual(stows("hello").c_str(), L"hello");
    }
    };
}
