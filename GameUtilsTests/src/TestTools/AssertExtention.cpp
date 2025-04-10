#include "stdafx.h"

#include <cmath>

#include "TestTools/AssertExtention.hpp"

#define ASSERT_ERROR_MESSAGE "Result is {0} and expected is {1}"

using namespace	Microsoft::VisualStudio;
using namespace GameUtills::UnitTesting;

bool floatsAreEqual(double a, double b, double epsilon)
{
	return std::fabs(a - b) < epsilon;
};

void AssertExtension::AreEqual(double expected, double result, double epsilon)
{
	TestTools::UnitTesting::Assert::IsTrue(floatsAreEqual(result, expected, epsilon), ASSERT_ERROR_MESSAGE, expected, result);
}

void AssertExtension::AreEqual(double expected, double result)
{
	AssertExtension::AreEqual(result, expected, 1e-6);
}