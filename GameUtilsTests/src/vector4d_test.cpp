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
	public ref class Vector4DTest
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
		void test_Vector4D_Default_constructor()
		{
			// Arrange & Act
			const Vector4D testInstance;
			
			// Assert
			Assert::AreEqual(0.f, testInstance[0]);
			Assert::AreEqual(0.f, testInstance[1]);
			Assert::AreEqual(0.f, testInstance[2]);
			Assert::AreEqual(0.f, testInstance[3]);
		};

		[TestMethod]
		void test_Vector4D_brackets_operator()
		{
			// Arrange & Act
			Vector4D testInstance = Vector4D(1, 2, 3, 4);

			// Assert
			Assert::AreEqual(1.f, testInstance[0]);
			Assert::AreEqual(2.f, testInstance[1]);
			Assert::AreEqual(3.f, testInstance[2]);
			Assert::AreEqual(4.f, testInstance[3]);
		};

		[TestMethod]
		void test_Vector4D_const_brackets_operator()
		{
			// Arrange & Act
			const Vector4D testInstance = Vector4D(1, 2, 3, 4);

			const float x = testInstance[0];
			const float y = testInstance[1];
			const float z = testInstance[2];
			const float w = testInstance[3];
			
			// Assert
			Assert::AreEqual(1.f, x);
			Assert::AreEqual(2.f, y);
			Assert::AreEqual(3.f, z);
			Assert::AreEqual(4.f, w);
		};

		[TestMethod]
		void test_Vector4D_multiply_composed_asignation_operator_with_a_common_float()
		{
			// Arrange
			Vector4D testInstance = Vector4D(1, 2, 3, 4);
			float commonFloat = 2.f;
			
			// Act
			testInstance *= 2.f;
			
			// Assert
			Assert::AreEqual(2.f, testInstance.x);
			Assert::AreEqual(4.f, testInstance.y);
			Assert::AreEqual(6.f, testInstance.z);
			Assert::AreEqual(8.f, testInstance.w);
		};

		[TestMethod]
		void test_Vector4D_division_composed_asignation_operator_with_a_common_float()
		{
			// Arrange
			Vector4D testInstance = Vector4D(2, 4, 6, 8);
			float commonFloat = 2.f;
			
			// Act
			testInstance /= 2.f;
			
			// Assert
			Assert::AreEqual(1.f, testInstance.x);
			Assert::AreEqual(2.f, testInstance.y);
			Assert::AreEqual(3.f, testInstance.z);
			Assert::AreEqual(4.f, testInstance.w);
		};

		[TestMethod]
		void test_Vector4D_addition_composed_asignation_operator_with_other_Vector4D()
		{
			// Arrange
			Vector4D testInstance = Vector4D(1, 2, 3, 4);
			Vector4D otherVector4D = Vector4D(1, 2, 3, 4);
			
			// Act
			testInstance += otherVector4D;
			
			// Assert
			Assert::AreEqual(2.f, testInstance.x);
			Assert::AreEqual(4.f, testInstance.y);
			Assert::AreEqual(6.f, testInstance.z);
			Assert::AreEqual(8.f, testInstance.w);
		};

		[TestMethod]
		void test_Vector4D_substraction_composed_asignation_operator_with_other_Vector4D()
		{
			// Arrange
			Vector4D testInstance = Vector4D(1, 2, 3, 4);
			Vector4D otherVector4D = Vector4D(1, 2, 3, 4);
			
			// Act
			testInstance -= otherVector4D;
			
			// Assert
			Assert::AreEqual(0.f, testInstance.x);
			Assert::AreEqual(0.f, testInstance.y);
			Assert::AreEqual(0.f, testInstance.z);
			Assert::AreEqual(0.f, testInstance.w);
		};
	};
}


