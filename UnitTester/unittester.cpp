#include "CppUnitTest.h"
#include "../include/Math.hpp"
#include "../include/includes.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

std::wstring ToString(const D2D1_VECTOR_2F& a) {
    return ((std::wstringstream&)(std::wstringstream{} << L"Vector { x: " << a.x << ", y: " << a.y << " }")).str();
}

namespace UnitTester
{		
	TEST_CLASS(MathTest)
	{
	public:
        D2D1_VECTOR_2F a{ 1, 2 }, b{ 3, -5 }, d{ 4, -3 };
        float c = -7;
		
		TEST_METHOD(SqrFunction)
		{
            Assert::AreEqual(square(3), 9);
            Assert::AreEqual(square(0), 0);
            Assert::AreEqual(square(-2.1f), 4.41f, 1.e-5f);
            Assert::AreEqual(square(a), abs(a) * abs(a), 1.e-5f);
            Assert::AreEqual(square(b), abs(b) * abs(b), 1.e-5f);
		}

        TEST_METHOD(VecMul) {
            Assert::AreEqual(a * b, c, 1.e-5f);
        }
        TEST_METHOD(VecAdd) {
            Assert::AreEqual(a + b, d);
        }
	};
}
