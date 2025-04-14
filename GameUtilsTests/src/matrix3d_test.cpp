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

		[TestMethod]
		void test_Matrix3D_Inverse()
		{
			// Arrange
			Matrix3D testInstance = Matrix3D(Vector3D( .10f, -.155f,  .100f),
											 Vector3D(-.15f,  .125f, -.095f),
											 Vector3D( .15f, -.100f,  .110f));

			// Act
			Matrix3D result = Inverse(testInstance);

			// Assert
			AssertExtension::AreEqual(-14.225936f, result(0,0));
			AssertExtension::AreEqual(- 7.531379f, result(0,1));
			AssertExtension::AreEqual( 12.552297f, result(0,2));
			AssertExtension::AreEqual(-23.598320f, result(1,0));
			AssertExtension::AreEqual( 13.389120f, result(1,1));
			AssertExtension::AreEqual( 44.351455f, result(1,2));
			AssertExtension::AreEqual(- 7.447696f, result(2,0));
			AssertExtension::AreEqual( 18.410039f, result(2,1));
			AssertExtension::AreEqual( 35.983261f, result(2,2));
		}

		[TestMethod]
		void test_Matrix3D_Multiplication_Operator_with_other_Matrix3D()
		{
			// Arrange
			Matrix3D aMatrix3D = Matrix3D(Vector3D( .10f, -.155f,  .100f),
										  Vector3D(-.15f,  .125f, -.095f),
										  Vector3D( .15f, -.100f,  .110f));

			Matrix3D otherMatrix3D = Matrix3D(Vector3D( .30f,  .655f,  .650f),
											  Vector3D(-.45f, -.125f,  .475f),
											  Vector3D(-.10f, -.870f, -.310f));

			// Act
			Matrix3D result = aMatrix3D * otherMatrix3D;

			// Assert
			AssertExtension::AreEqual( 0.0292500f, result(0,0));
			AssertExtension::AreEqual( 0.0450000f, result(0,1));
			AssertExtension::AreEqual( 0.0740000f, result(0,2));
			AssertExtension::AreEqual(-0.0296250f, result(1,0));
			AssertExtension::AreEqual( 0.0066249f, result(1,1));
			AssertExtension::AreEqual(-0.0622499f, result(1,2));
			AssertExtension::AreEqual( 0.0392750f, result(2,0));
			AssertExtension::AreEqual( 0.0191249f, result(2,1));
			AssertExtension::AreEqual( 0.0385500f, result(2,2));
		}

		[TestMethod]
		void test_Matrix3D_Multiplication_Operator_with_a_Vector3D()
		{
			// Arrange
			Matrix3D aMatrix3D = Matrix3D(Vector3D( .10f, -.155f,  .100f),
										  Vector3D(-.15f,  .125f, -.095f),
										  Vector3D( .15f, -.100f,  .110f));

			Vector3D aVector3D = Vector3D(.30f, .655f, .650f);

			// Act
			Vector3D result = aMatrix3D * aVector3D;

			// Assert
			AssertExtension::AreEqual( 0.0292500f, result.x);
			AssertExtension::AreEqual(-0.0296250f, result.y);
			AssertExtension::AreEqual( 0.0392750f, result.z);
		}

		[TestMethod]
		void test_Matrix3D_Determinant()
		{
			// Arrange
			Matrix3D aMatrix3D = Matrix3D(Vector3D( .10f, -.155f,  .100f),
										  Vector3D(-.15f,  .125f, -.095f),
										  Vector3D( .15f, -.100f,  .110f));

			// Act
			float result = Determinant(aMatrix3D);

			// Assert
			AssertExtension::AreEqual(-0.0002987f, result);
		}

		[TestMethod]
		void test_Matrix3D_MakeRotationX()
		{
			// Arrange
			Matrix3D aMatrix3D = Matrix3D(Vector3D( .10f, -.155f,  .100f),
										  Vector3D(-.15f,  .125f, -.095f),
										  Vector3D( .15f, -.100f,  .110f));

			float rotationOnX = 90.f;

			// Act
			Matrix3D result = MakeRotationX(rotationOnX);

			// Assert
			AssertExtension::AreEqual( 1.f, result(0,0));
			AssertExtension::AreEqual( 0.f, result(0,1));
			AssertExtension::AreEqual( 0.f, result(0,2));
			AssertExtension::AreEqual( 0.f, result(1,0));
			AssertExtension::AreEqual(-0.4480736f, result(1,1));
			AssertExtension::AreEqual(-0.8939966f, result(1,2));
			AssertExtension::AreEqual( 0.f, result(2,0));
			AssertExtension::AreEqual( 0.8939966f, result(2,1));
			AssertExtension::AreEqual(-0.4480736f, result(2,2));
		}

		[TestMethod]
		void test_Matrix3D_MakeRotationY()
		{
			// Arrange
			Matrix3D aMatrix3D = Matrix3D(Vector3D( .10f, -.155f,  .100f),
										  Vector3D(-.15f,  .125f, -.095f),
										  Vector3D( .15f, -.100f,  .110f));

			float rotationOnY = 90.f;

			// Act
			Matrix3D result = MakeRotationY(rotationOnY);

			// Assert
			AssertExtension::AreEqual(-0.4480736f, result(0,0));
			AssertExtension::AreEqual( 0.f, result(0,1));
			AssertExtension::AreEqual( 0.8939966f, result(0,2));
			AssertExtension::AreEqual( 0.f, result(1,0));
			AssertExtension::AreEqual( 1.f, result(1,1));
			AssertExtension::AreEqual( 0.f, result(1,2));
			AssertExtension::AreEqual(-0.8939966f, result(2,0));
			AssertExtension::AreEqual( 0.f, result(2,1));
			AssertExtension::AreEqual(-0.4480736f, result(2,2));
		}

		[TestMethod]
		void test_Matrix3D_MakeRotationZ()
		{
			// Arrange
			Matrix3D aMatrix3D = Matrix3D(Vector3D( .10f, -.155f,  .100f),
										  Vector3D(-.15f,  .125f, -.095f),
										  Vector3D( .15f, -.100f,  .110f));

			float rotationOnZ = 90.f;

			// Act
			Matrix3D result = MakeRotationZ(rotationOnZ);

			// Assert
			AssertExtension::AreEqual(-0.4480736f, result(0,0));
			AssertExtension::AreEqual(-0.8939966f, result(0,1));
			AssertExtension::AreEqual( 0.f, result(0,2));
			AssertExtension::AreEqual( 0.8939966f, result(1,0));
			AssertExtension::AreEqual(-0.4480736f, result(1,1));
			AssertExtension::AreEqual( 0.f, result(1,2));
			AssertExtension::AreEqual( 0.f, result(2,0));
			AssertExtension::AreEqual( 0.f, result(2,1));
			AssertExtension::AreEqual( 1.f, result(2,2));
		}

		[TestMethod]
		void test_Matrix3D_MakeRotation()
		{
			// Arrange
			Matrix3D aMatrix3D = Matrix3D(Vector3D( .10f, -.155f,  .100f),
										  Vector3D(-.15f,  .125f, -.095f),
										  Vector3D( .15f, -.100f,  .110f));

			Vector3D aVector = Vector3D(1.f, 1.f, 1.f);
			float rotation = 90.f;

			// Act
			Matrix3D result = MakeRotation(rotation, aVector);

			// Assert
			AssertExtension::AreEqual(1.f,		  result(0,0));
			AssertExtension::AreEqual(0.5540769f, result(0,1));
			AssertExtension::AreEqual(2.3420703f, result(0,2));
			AssertExtension::AreEqual(2.3420703f, result(1,0));
			AssertExtension::AreEqual(1.f,		  result(1,1));
			AssertExtension::AreEqual(0.5540769f, result(1,2));
			AssertExtension::AreEqual(0.5540769f, result(2,0));
			AssertExtension::AreEqual(2.3420703f, result(2,1));
			AssertExtension::AreEqual(1.f,		  result(2,2));
		}

		[TestMethod]
		void test_Matrix3D_MakeReflection()
		{
			// Arrange
			Vector3D aVector = Vector3D(-1.f, -1.f, -1.f);

			// Act
			Matrix3D result = MakeReflection(aVector);

			// Assert
			AssertExtension::AreEqual(-1.f,	result(0,0));
			AssertExtension::AreEqual(-2.f, result(0,1));
			AssertExtension::AreEqual(-2.f, result(0,2));
			AssertExtension::AreEqual(-2.f, result(1,0));
			AssertExtension::AreEqual(-1.f,	result(1,1));
			AssertExtension::AreEqual(-2.f, result(1,2));
			AssertExtension::AreEqual(-2.f, result(2,0));
			AssertExtension::AreEqual(-2.f, result(2,1));
			AssertExtension::AreEqual(-1.f,	result(2,2));
		}
	};	
}
