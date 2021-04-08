
#include "CppUnitTest.h"
#include <iostream>
#include "../Lab3/Polynominal.h"
#include <vector>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab3Test
{
	TEST_CLASS(Lab3Test)
	{
	public:

		TEST_METHOD(TestMethod1)
		{

		}

		TEST_METHOD(TestAddPolynominalByPlus)
		{
			vov elements = { {2,1},{1,2},{0,3} };
			vov elements2 = { {3,1},{1,2},{0,1} };
			Polynominal poly(elements);
			Polynominal poly2(elements2);
			Polynominal poly3 = poly + poly2;
			float value_factor0 = poly3.get_element(0);
			float value_factor1 = poly3.get_element(1);
			float value_factor2 = poly3.get_element(2);
			float value_factor3 = poly3.get_element(3);
			Assert::IsTrue(value_factor0 == 4);
			Assert::IsTrue(value_factor1 == 4);
			Assert::IsTrue(value_factor2 == 1);
			Assert::IsTrue(value_factor3 == 1);
		}
		TEST_METHOD(TestAddPolynominalByPlusEqual)
		{
			vov elements = { {2,1},{1,2},{0,3} };
			vov elements2 = { {3,1},{1,2},{0,1} };
			Polynominal poly(elements);
			Polynominal poly2(elements2);
			poly += poly2;
			float value_factor0 = poly.get_element(0);
			float value_factor1 = poly.get_element(1);
			float value_factor2 = poly.get_element(2);
			float value_factor3 = poly.get_element(3);
			Assert::IsTrue(value_factor0 == 4);
			Assert::IsTrue(value_factor1 == 4);
			Assert::IsTrue(value_factor2 == 1);
			Assert::IsTrue(value_factor3 == 1);
		}
		TEST_METHOD(TestSubtractPolynominalByMinus)
		{
			vov elements = { {2,1},{1,2},{0,3} };
			vov elements2 = { {3,1},{1,2},{0,1} };
			Polynominal poly(elements);
			Polynominal poly2(elements2);
			Polynominal poly3 = poly - poly2;
			float value_factor0 = poly3.get_element(0);
			float value_factor1 = poly3.get_element(1);
			float value_factor2 = poly3.get_element(2);
			float value_factor3 = poly3.get_element(3);
			Assert::IsTrue(value_factor0 == 2);
			Assert::IsTrue(value_factor1 == 0);
			Assert::IsTrue(value_factor2 == 1);
			Assert::IsTrue(value_factor3 == -1);
		}
		TEST_METHOD(TestSubtractPolynominalByMinusEqual)
		{
			vov elements = { {2,1},{1,2},{0,3} };
			vov elements2 = { {3,1},{1,2},{0,1} };
			Polynominal poly(elements);
			Polynominal poly2(elements2);
			poly -= poly2;
			float value_factor0 = poly.get_element(0);
			float value_factor1 = poly.get_element(1);
			float value_factor2 = poly.get_element(2);
			float value_factor3 = poly.get_element(3);
			Assert::IsTrue(value_factor0 == 2);
			Assert::IsTrue(value_factor1 == 0);
			Assert::IsTrue(value_factor2 == 1);
			Assert::IsTrue(value_factor3 == -1);
		}

		TEST_METHOD(TestMultiplyPolynominalByStar)
		{
			vov elements = { {1,1},{0,1} };
			vov elements2 = { {1,1},{0,-1} };
			Polynominal poly(elements);
			Polynominal poly2(elements2);
			Polynominal poly3 = poly * poly2;
			float value_factor0 = poly3.get_element(0);
			float value_factor1 = poly3.get_element(1);
			float value_factor2 = poly3.get_element(2);
			Assert::IsTrue(value_factor0 == -1);
			Assert::IsTrue(value_factor1 == 0);
			Assert::IsTrue(value_factor2 == 1);
		}

		TEST_METHOD(TestMultiplyPolynominalByStarEqual)
		{
			vov elements = { {1,1},{0,1} };
			vov elements2 = { {1,1},{0,-1} };
			Polynominal poly(elements);
			Polynominal poly2(elements2);
			poly *= poly2;
			float value_factor0 = poly.get_element(0);
			float value_factor1 = poly.get_element(1);
			float value_factor2 = poly.get_element(2);
			Assert::IsTrue(value_factor0 == -1);
			Assert::IsTrue(value_factor1 == 0);
			Assert::IsTrue(value_factor2 == 1);
		}
		TEST_METHOD(TestPolynominalValue)
		{
			vov elements = { {1,1},{0,1} };
			Polynominal poly(elements);
			float value = poly << 1;
			Assert::IsTrue(value == 2);
		}

		TEST_METHOD(TestAddNumberByPlus)
		{
			vov elements = { {2,1},{1,2},{0,3} };
			Polynominal poly(elements);
			Polynominal poly3 = poly + 3;
			float value_factor0 = poly3.get_element(0);
			float value_factor1 = poly3.get_element(1);
			float value_factor2 = poly3.get_element(2);
			Assert::IsTrue(value_factor0 == 6);
			Assert::IsTrue(value_factor1 == 2);
			Assert::IsTrue(value_factor2 == 1);
		}
		TEST_METHOD(TestAddNumberByPlusEqual)
		{
			vov elements = { {2,1},{1,2},{0,3} };
			Polynominal poly(elements);
			poly += 3;
			float value_factor0 = poly.get_element(0);
			float value_factor1 = poly.get_element(1);
			float value_factor2 = poly.get_element(2);
			Assert::IsTrue(value_factor0 == 6);
			Assert::IsTrue(value_factor1 == 2);
			Assert::IsTrue(value_factor2 == 1);
		}
		TEST_METHOD(TestSubtractNumberByMinus)
		{
			vov elements = { {2,1},{1,2},{0,3} };
			Polynominal poly(elements);
			Polynominal poly3 = poly - 3;
			float value_factor0 = poly3.get_element(0);
			float value_factor1 = poly3.get_element(1);
			float value_factor2 = poly3.get_element(2);
			Assert::IsTrue(value_factor0 == 0);
			Assert::IsTrue(value_factor1 == 2);
			Assert::IsTrue(value_factor2 == 1);
		}
		TEST_METHOD(TestSubtractNumberByMinusEqual)
		{
			vov elements = { {2,1},{1,2},{0,3} };
			Polynominal poly(elements);
			poly -= 3;
			float value_factor0 = poly.get_element(0);
			float value_factor1 = poly.get_element(1);
			float value_factor2 = poly.get_element(2);
			Assert::IsTrue(value_factor0 == 0);
			Assert::IsTrue(value_factor1 == 2);
			Assert::IsTrue(value_factor2 == 1);
		}
		TEST_METHOD(TestMultiplyNumberByStar)
		{
			vov elements = { {2,1},{1,2},{0,3} };
			Polynominal poly(elements);
			Polynominal poly3 = poly * 3;
			float value_factor0 = poly3.get_element(0);
			float value_factor1 = poly3.get_element(1);
			float value_factor2 = poly3.get_element(2);
			Assert::IsTrue(value_factor0 == 9);
			Assert::IsTrue(value_factor1 == 6);
			Assert::IsTrue(value_factor2 == 3);
		}
		TEST_METHOD(TestMultiplyNumberByStarEqual)
		{
			vov elements = { {2,1},{1,2},{0,3} };
			Polynominal poly(elements);
			poly *= 3;
			float value_factor0 = poly.get_element(0);
			float value_factor1 = poly.get_element(1);
			float value_factor2 = poly.get_element(2);
			Assert::IsTrue(value_factor0 == 9);
			Assert::IsTrue(value_factor1 == 6);
			Assert::IsTrue(value_factor2 == 3);
		}
		TEST_METHOD(TestDivideNumberBySlash)
		{
			vov elements = { {2,3},{1,6},{0,3} };
			Polynominal poly(elements);
			Polynominal poly3 = poly / 3;
			float value_factor0 = poly3.get_element(0);
			float value_factor1 = poly3.get_element(1);
			float value_factor2 = poly3.get_element(2);
			Assert::IsTrue(value_factor0 == 1);
			Assert::IsTrue(value_factor1 == 2);
			Assert::IsTrue(value_factor2 == 1);
		}
		TEST_METHOD(TestDivideNumberByStarSlashEqual)
		{
			vov elements = { {2,3},{1,6},{0,3} };
			Polynominal poly(elements);
			poly /= 3;
			float value_factor0 = poly.get_element(0);
			float value_factor1 = poly.get_element(1);
			float value_factor2 = poly.get_element(2);
			Assert::IsTrue(value_factor0 == 1);
			Assert::IsTrue(value_factor1 == 2);
			Assert::IsTrue(value_factor2 == 1);
		}
	};
}
