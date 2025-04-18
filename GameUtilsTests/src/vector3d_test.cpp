#include "stdafx.h"

#include <cmath>

#include "TestTools/AssertExtention.hpp"
#include "game_math.hpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace GameUtills::UnitTesting;
using namespace gameutils::math;

namespace GameUtilsTests
{
	[TestClass]
	public ref class Vector3DTest
	{
	private:
		TestContext^ testContextInstance;

	public: 
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		#pragma region Additional test attributes
		//
		//You can use the following additional attributes as you write your tests:
		//
		//Use ClassInitialize to run code before running the first test in the class
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//Use ClassCleanup to run code after all tests in a class have run
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//Use TestInitialize to run code before running each test
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//Use TestCleanup to run code after each test has run
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
		#pragma endregion 

		[TestMethod]
		void test_Vector3D_Default_constructor()
		{
			// Arrange & Act
			const Vector3D testInstance;
			
			// Assert
			Assert::AreEqual(0.f, testInstance[0]);
			Assert::AreEqual(0.f, testInstance[1]);
			Assert::AreEqual(0.f, testInstance[2]);
		};

		[TestMethod]
		void test_Vector3D_brackets_operator()
		{
			// Arrange & Act
			Vector3D testInstance = Vector3D(1, 2, 3);
			
			// Assert
			Assert::AreEqual(1.f, testInstance[0]);
			Assert::AreEqual(2.f, testInstance[1]);
			Assert::AreEqual(3.f, testInstance[2]);
		};

		[TestMethod]
		void test_Vector3D_const_brackets_operator()
		{
			// Arrange & Act
			const Vector3D testInstance = Vector3D(1, 2, 3);
			
			// Assert
			Assert::AreEqual(1.f, testInstance[0]);
			Assert::AreEqual(2.f, testInstance[1]);
			Assert::AreEqual(3.f, testInstance[2]);
		};

		[TestMethod]
		void test_Vector3D_multiply_composed_asignation_operator_with_a_common_float()
		{
			// Arrange
			Vector3D testInstance = Vector3D(1, 2, 3);
			float commonFloat = 2.f;
			
			// Act
			testInstance *= 2.f;
			
			// Assert
			Assert::AreEqual(2.f, testInstance.x);
			Assert::AreEqual(4.f, testInstance.y);
			Assert::AreEqual(6.f, testInstance.z);
		};

		[TestMethod]
		void test_Vector3D_division_composed_asignation_operator_with_a_common_float()
		{
			// Arrange
			Vector3D testInstance = Vector3D(2, 4, 6);
			float commonFloat = 2.f;
			
			// Act
			testInstance /= 2.f;
			
			// Assert
			Assert::AreEqual(1.f, testInstance.x);
			Assert::AreEqual(2.f, testInstance.y);
			Assert::AreEqual(3.f, testInstance.z);
		};

		[TestMethod]
		void test_Vector3D_addition_composed_asignation_operator_with_other_Vector3D()
		{
			// Arrange
			Vector3D testInstance = Vector3D(1, 2, 3);
			Vector3D otherVector3D = Vector3D(1, 2, 3);
			
			// Act
			testInstance += otherVector3D;
			
			// Assert
			Assert::AreEqual(2.f, testInstance.x);
			Assert::AreEqual(4.f, testInstance.y);
			Assert::AreEqual(6.f, testInstance.z);
		};

		[TestMethod]
		void test_Vector3D_substraction_composed_asignation_operator_with_other_Vector3D()
		{
			// Arrange
			Vector3D testInstance = Vector3D(1, 2, 3);
			Vector3D otherVector3D = Vector3D(1, 2, 3);
			
			// Act
			testInstance -= otherVector3D;
			
			// Assert
			Assert::AreEqual(0.f, testInstance.x);
			Assert::AreEqual(0.f, testInstance.y);
			Assert::AreEqual(0.f, testInstance.z);
		};

		[TestMethod]
		void test_Vector3D_division_operator_with_other_Vector3D()
		{
			// Arrange
			const Vector3D aVector3D = Vector3D(2, 4, 6);
			float aFloatValue = 2.f;
			
			// Act
			Vector3D result = aVector3D / aFloatValue;
			
			// Assert
			Assert::AreEqual(1.f, result.x);
			Assert::AreEqual(2.f, result.y);
			Assert::AreEqual(3.f, result.z);
		};

		[TestMethod]
		void test_Vector3D_multiplication_operator_with_other_Vector3D()
		{
			// Arrange
			const Vector3D aVector3D = Vector3D(2, 4, 6);
			float aFloatValue = 2.f;
			
			// Act
			Vector3D result = aVector3D * aFloatValue;
			
			// Assert
			Assert::AreEqual(4.f, result.x);
			Assert::AreEqual(8.f, result.y);
			Assert::AreEqual(12.f, result.z);
		};

		[TestMethod]
		void test_Vector3D_magnitud_with_other_Vector3D()
		{
			// Arrange
			const Vector3D aVector3D = Vector3D(2, 4, 6);
			
			// Act
			float result = Magnitude(aVector3D);
			
			// Assert
			Assert::AreEqual(7.483315f, result);
		};

		[TestMethod]
		void test_Vector3D_normalize_with_other_Vector3D()
		{
			// Arrange
			const Vector3D aVector3D = Vector3D(2, 4, 6);
			
			// Act
			Vector3D result = Normalize(aVector3D);
			Vector3D expected(0.2672612f, 0.5345225f, 0.8017837f);
			
			// Assert
			AssertExtension::AreEqual(expected.x, result.x);
			AssertExtension::AreEqual(expected.y, result.y);
			AssertExtension::AreEqual(expected.z, result.z);
		};

		[TestMethod]
		void test_Vector3D_addition_with_other_Vector3D()
		{
			// Arrange
			Vector3D aVector3D = Vector3D(2, 4, 6);
			const Vector3D otherVector3D = Vector3D(1, 2, 3);
			
			// Act
			Vector3D result = aVector3D + otherVector3D;
			
			// Assert
			Assert::AreEqual(3.f, result.x);
			Assert::AreEqual(6.f, result.y);
			Assert::AreEqual(9.f, result.z);
		};

		[TestMethod]
		void test_Vector3D_substraction_with_other_Vector3D()
		{
			// Arrange
			Vector3D aVector3D = Vector3D(2, 4, 6);
			const Vector3D otherVector3D = Vector3D(1, 2, 3);
			
			// Act
			Vector3D result = aVector3D - otherVector3D;
			
			// Assert
			Assert::AreEqual(1.f, result.x);
			Assert::AreEqual(2.f, result.y);
			Assert::AreEqual(3.f, result.z);
		};

		[TestMethod]
		void test_Vector3D_Dot_with_other_Vector3D()
		{
			// Arrange
			const Vector3D aVector3D = Vector3D(2.5f, 4.5f, 6.5f);
			const Vector3D otherVector3D = Vector3D(1.5f, 2.5f, 3.5f);
			
			// Act
			float result = Dot(aVector3D, otherVector3D);
			
			// Assert
			Assert::AreEqual(37.75f, result);
		};

		[TestMethod]
		void test_Vector3D_Cross_with_other_Vector3D()
		{
			// Arrange
			const Vector3D aVector3D = Vector3D(2.5f, 4.5f, 6.5f);
			const Vector3D otherVector3D = Vector3D(1.5f, 2.5f, 3.5f);
			
			// Act
			Vector3D result = Cross(aVector3D, otherVector3D);
			
			// Assert
			Assert::AreEqual(-0.5f, result.x);
			Assert::AreEqual(1.f, result.y);
			Assert::AreEqual(-0.5f, result.z);
		};

		[TestMethod]
		void test_Vector3D_Project_with_other_Vector3D()
		{
			// Arrange
			const Vector3D aVector3D = Vector3D(2.5f, 4.5f, 6.5f);
			const Vector3D otherVector3D = Vector3D(1.5f, 2.5f, 3.5f);
			
			// Act
			Vector3D result = Project(aVector3D, otherVector3D);
			const Vector3D expected = Vector3D(2.728916f, 4.548193f, 6.36747f);
			
			// Assert
			AssertExtension::AreEqual(expected.x, result.x);
			AssertExtension::AreEqual(expected.y, result.y);
			AssertExtension::AreEqual(expected.z, result.z);
		};

		[TestMethod]
		void test_Vector3D_Reject_with_other_Vector3D()
		{
			// Arrange
			const Vector3D aVector3D = Vector3D(2.5f, 4.5f, 6.5f);
			const Vector3D otherVector3D = Vector3D(1.5f, 2.5f, 3.5f);
			
			// Act
			Vector3D result = Reject(aVector3D, otherVector3D);
			const Vector3D expected = Vector3D(-0.2289157f, -0.04819298f, 0.1325297f);
			
			// Assert
			AssertExtension::AreEqual(expected.x, result.x);
			AssertExtension::AreEqual(expected.y, result.y);
			AssertExtension::AreEqual(expected.z, result.z);
		};
	};
}
