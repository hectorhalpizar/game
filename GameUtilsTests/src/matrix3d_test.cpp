#include "stdafx.h"

#include <cmath>

#include "TestTools/AssertExtention.hpp"
#include "matrix3d.hpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace GameUtills::UnitTesting;

namespace GameUtilsTests
{
	[TestClass]
	public ref class Matrix3DTest
	{
	private:
		TestContext^ testContextInstance;
		#define ASSERT_ERROR_MESSAGE "Result is {0} and expected is {1}"

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
		void test_Matrix3D_Default_constructor_and_const_parenthesis_operator()
		{
			// Arrange & Act
			const Matrix3D testInstance;
			
			// Assert
			Assert::AreEqual(0.f, testInstance(0,0));
			Assert::AreEqual(0.f, testInstance(0,1));
			Assert::AreEqual(0.f, testInstance(0,2));
			Assert::AreEqual(0.f, testInstance(1,0));
			Assert::AreEqual(0.f, testInstance(1,1));
			Assert::AreEqual(0.f, testInstance(1,2));
			Assert::AreEqual(0.f, testInstance(2,0));
			Assert::AreEqual(0.f, testInstance(2,1));
			Assert::AreEqual(0.f, testInstance(2,2));
		};

		[TestMethod]
		void test_Matrix3D_float_values_constructor_and_parenthesis_operator()
		{
			// Arrange & Act
			Matrix3D testInstance = Matrix3D(1.f, 2.f, 3.f,
											 4.f, 5.f, 6.f,
											 7.f, 8.f, 9.f);
			
			// Assert
			Assert::AreEqual(1.f, testInstance(0,0));
			Assert::AreEqual(2.f, testInstance(0,1));
			Assert::AreEqual(3.f, testInstance(0,2));
			Assert::AreEqual(4.f, testInstance(1,0));
			Assert::AreEqual(5.f, testInstance(1,1));
			Assert::AreEqual(6.f, testInstance(1,2));
			Assert::AreEqual(7.f, testInstance(2,0));
			Assert::AreEqual(8.f, testInstance(2,1));
			Assert::AreEqual(9.f, testInstance(2,2));
		};

		[TestMethod]
		void test_Matrix3D_Vector3D_values_constructor_const_bracket_operator_and_parentesis_results()
		{
			// Arrange & Act
			const Matrix3D testInstance = Matrix3D(Vector3D(1.f, 2.f, 3.f),
												   Vector3D(4.f, 5.f, 6.f),
												   Vector3D(7.f, 8.f, 9.f));
			
			// Assert
			Vector3D result = testInstance[0];
			
			Assert::AreEqual(1.f, result.x);
			Assert::AreEqual(2.f, result.y);
			Assert::AreEqual(3.f, result.z);

			result = testInstance[1];

			Assert::AreEqual(4.f, result.x);
			Assert::AreEqual(5.f, result.y);
			Assert::AreEqual(6.f, result.z);

			result = testInstance[2];

			Assert::AreEqual(7.f, result.x);
			Assert::AreEqual(8.f, result.y);
			Assert::AreEqual(9.f, result.z);

			Assert::AreEqual(1.f, testInstance(0,0));
			Assert::AreEqual(2.f, testInstance(1,0));
			Assert::AreEqual(3.f, testInstance(2,0));
			Assert::AreEqual(4.f, testInstance(0,1));
			Assert::AreEqual(5.f, testInstance(1,1));
			Assert::AreEqual(6.f, testInstance(2,1));
			Assert::AreEqual(7.f, testInstance(0,2));
			Assert::AreEqual(8.f, testInstance(1,2));
			Assert::AreEqual(9.f, testInstance(2,2));
		};

		[TestMethod]
		void test_Matrix3D_Vector3D_values_constructor_and_bracket_operator()
		{
			// Arrange & Act
			Matrix3D testInstance = Matrix3D(Vector3D(1.f, 2.f, 3.f),
											 Vector3D(4.f, 5.f, 6.f),
											 Vector3D(7.f, 8.f, 9.f));
			
			// Assert
			Assert::AreEqual(1.f, testInstance[0][0]);
			Assert::AreEqual(2.f, testInstance[0][1]);
			Assert::AreEqual(3.f, testInstance[0][2]);
			Assert::AreEqual(4.f, testInstance[1][0]);
			Assert::AreEqual(5.f, testInstance[1][1]);
			Assert::AreEqual(6.f, testInstance[1][2]);
			Assert::AreEqual(7.f, testInstance[2][0]);
			Assert::AreEqual(8.f, testInstance[2][1]);
			Assert::AreEqual(9.f, testInstance[2][2]);
		};
	};	
}
