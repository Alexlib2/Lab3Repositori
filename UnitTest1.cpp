#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\User\source\repos\SECodeLab\SECodeLab\SECodeLab.cpp"
#include "vector";
#include <cassert>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1) //formula
		{
			vector<point> points;
			int n = 3;
			double x = -10, p = 1, y = 0;
			points = calculate(points, n, x, p, y);
			assert(points[0].x == -10);
			assert(points[0].y == 221);
		}
		TEST_METHOD(TestMethod2)
		{
			vector<point> points;
			int n = 3;
			double x = -10, p = 1, y = 0;
			points = calculate(points, n, x, p, y);
			assert(points[1].x == -10);
			assert(points[1].y == 354786);
		}
		TEST_METHOD(TestMethod3) //range
		{
			double a = 4, b = 8;
			try {
				if (a < b) {
					Assert::IsTrue(true);
				}
			}
			catch (...) {
				Assert::Fail();
			}
		}
		TEST_METHOD(TestMethod4)
		{
			double a = 99, b = 6;
			try {
				if (a > b) {
					 Assert::Fail();
				}
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}
		TEST_METHOD(TestMethod5) //step
		{
			double k = -4;
			try {
				if (k < 0) {
					Assert::Fail();
				}
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}
		TEST_METHOD(TestMethod6) //step_range
		{
			double a = 4, b = 10, k = 8;
			try
			{
				double range = abs(a - b);
				Assert::IsTrue(k < range);
			}
			catch (...) {
				Assert::Fail();
			}
		}
	};
}