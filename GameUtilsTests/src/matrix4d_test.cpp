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
	public ref class Matrix4DTest
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
		void test_Matrix4D_Default_constructor_and_const_parenthesis_operator()
		{
			// Arrange & Act
			const Matrix4D testInstance;
			
			// Assert
			Assert::AreEqual(0.f, testInstance(0,0));
			Assert::AreEqual(0.f, testInstance(0,1));
			Assert::AreEqual(0.f, testInstance(0,2));
			Assert::AreEqual(0.f, testInstance(0,3));
			Assert::AreEqual(0.f, testInstance(1,0));
			Assert::AreEqual(0.f, testInstance(1,1));
			Assert::AreEqual(0.f, testInstance(1,2));
			Assert::AreEqual(0.f, testInstance(1,3));
			Assert::AreEqual(0.f, testInstance(2,0));
			Assert::AreEqual(0.f, testInstance(2,1));
			Assert::AreEqual(0.f, testInstance(2,2));
			Assert::AreEqual(0.f, testInstance(2,3));
			Assert::AreEqual(0.f, testInstance(3,0));
			Assert::AreEqual(0.f, testInstance(3,1));
			Assert::AreEqual(0.f, testInstance(3,2));
			Assert::AreEqual(0.f, testInstance(3,3));
		};

		[TestMethod]
		void test_Matrix4D_float_values_constructor_and_parenthesis_operator()
		{
			// Arrange & Act
			Matrix4D testInstance = Matrix4D( 1.f,  2.f,  3.f,  4.f, 
											  5.f,  6.f,  7.f,  8.f, 
											  9.f, 10.f, 11.f, 12.f,
											 13.f, 14.f, 15.f, 16.f);
			
			// Assert
			Assert::AreEqual( 1.f, testInstance(0,0));
			Assert::AreEqual( 2.f, testInstance(0,1));
			Assert::AreEqual( 3.f, testInstance(0,2));
			Assert::AreEqual( 4.f, testInstance(0,3));
			Assert::AreEqual( 5.f, testInstance(1,0));
			Assert::AreEqual( 6.f, testInstance(1,1));
			Assert::AreEqual( 7.f, testInstance(1,2));
			Assert::AreEqual( 8.f, testInstance(1,3));
			Assert::AreEqual( 9.f, testInstance(2,0));
			Assert::AreEqual(10.f, testInstance(2,1));
			Assert::AreEqual(11.f, testInstance(2,2));
			Assert::AreEqual(12.f, testInstance(2,3));
			Assert::AreEqual(13.f, testInstance(3,0));
			Assert::AreEqual(14.f, testInstance(3,1));
			Assert::AreEqual(15.f, testInstance(3,2));
			Assert::AreEqual(16.f, testInstance(3,3));
		};

		[TestMethod]
		void test_Matrix4D_Vector4D_values_constructor_const_bracket_operator_and_parentesis_results()
		{
			// Arrange & Act
			const Matrix4D testInstance = Matrix4D(Vector4D( 1.f,  2.f,  3.f,  4.f),
												   Vector4D( 5.f,  6.f,  7.f,  8.f),
												   Vector4D( 9.f, 10.f, 11.f, 12.f),
												   Vector4D(13.f, 14.f, 15.f, 16.f));
			
			// Assert
			Vector4D result = testInstance[0];
			
			Assert::AreEqual( 1.f, result.x);
			Assert::AreEqual( 2.f, result.y);
			Assert::AreEqual( 3.f, result.z);
			Assert::AreEqual( 4.f, result.w);

			result = testInstance[1];

			Assert::AreEqual( 5.f, result.x);
			Assert::AreEqual( 6.f, result.y);
			Assert::AreEqual( 7.f, result.z);
			Assert::AreEqual( 8.f, result.w);

			result = testInstance[2];

			Assert::AreEqual( 9.f, result.x);
			Assert::AreEqual(10.f, result.y);
			Assert::AreEqual(11.f, result.z);
			Assert::AreEqual(12.f, result.w);

			result = testInstance[3];

			Assert::AreEqual(13.f, result.x);
			Assert::AreEqual(14.f, result.y);
			Assert::AreEqual(15.f, result.z);
			Assert::AreEqual(16.f, result.w);

			Assert::AreEqual( 1.f, testInstance(0,0));
			Assert::AreEqual( 2.f, testInstance(1,0));
			Assert::AreEqual( 3.f, testInstance(2,0));
			Assert::AreEqual( 4.f, testInstance(3,0));
			Assert::AreEqual( 5.f, testInstance(0,1));
			Assert::AreEqual( 6.f, testInstance(1,1));
			Assert::AreEqual( 7.f, testInstance(2,1));
			Assert::AreEqual( 8.f, testInstance(3,1));
			Assert::AreEqual( 9.f, testInstance(0,2));
			Assert::AreEqual(10.f, testInstance(1,2));
			Assert::AreEqual(11.f, testInstance(2,2));
			Assert::AreEqual(12.f, testInstance(3,2));
			Assert::AreEqual(13.f, testInstance(0,3));
			Assert::AreEqual(14.f, testInstance(1,3));
			Assert::AreEqual(15.f, testInstance(2,3));
			Assert::AreEqual(16.f, testInstance(3,3));
		};

		[TestMethod]
		void test_Matrix4D_Vector4D_values_constructor_and_bracket_operator()
		{
			// Arrange & Act
			Matrix4D testInstance = Matrix4D(Vector4D( 1.f,  2.f,  3.f,  4.f),
											 Vector4D( 5.f,  6.f,  7.f,  8.f),
											 Vector4D( 9.f, 10.f, 11.f, 12.f),
											 Vector4D(13.f, 14.f, 15.f, 16.f));
			
			// Assert
			Assert::AreEqual( 1.f, testInstance[0][0]);
			Assert::AreEqual( 2.f, testInstance[0][1]);
			Assert::AreEqual( 3.f, testInstance[0][2]);
			Assert::AreEqual( 4.f, testInstance[0][3]);
			Assert::AreEqual( 5.f, testInstance[1][0]);
			Assert::AreEqual( 6.f, testInstance[1][1]);
			Assert::AreEqual( 7.f, testInstance[1][2]);
			Assert::AreEqual( 8.f, testInstance[1][3]);
			Assert::AreEqual( 9.f, testInstance[2][0]);
			Assert::AreEqual(10.f, testInstance[2][1]);
			Assert::AreEqual(11.f, testInstance[2][2]);
			Assert::AreEqual(12.f, testInstance[2][3]);
			Assert::AreEqual(13.f, testInstance[3][0]);
			Assert::AreEqual(14.f, testInstance[3][1]);
			Assert::AreEqual(15.f, testInstance[3][2]);
			Assert::AreEqual(16.f, testInstance[3][3]);
		};

		[TestMethod]
		void test_Matrix4D_Inverse()
		{
			// Arrange
			Matrix4D testInstance = Matrix4D(Vector4D( .10f, -.155f,  .100f, -.085f),
											 Vector4D(-.15f,  .125f, -.095f,  .095f),
											 Vector4D( .15f, -.100f,  .110f,  .120f),
											 Vector4D( .20f,  .150f,  .150f, -.160f));

			// Act
			Matrix4D result = Inverse(testInstance);

			// Assert
			AssertExtension::AreEqual(-16.890262f, result(0,0));
			AssertExtension::AreEqual(- 1.831208f, result(0,1));
			AssertExtension::AreEqual( 22.876266f, result(0,2));
			AssertExtension::AreEqual(- 1.383086f, result(0,3));
			AssertExtension::AreEqual(-18.578735f, result(1,0));
			AssertExtension::AreEqual(  2.649995f, result(1,1));
			AssertExtension::AreEqual( 24.901105f, result(1,2));
			AssertExtension::AreEqual(  2.605737f, result(1,3));
			AssertExtension::AreEqual(  1.046167f, result(2,0));
			AssertExtension::AreEqual(  0.237890f, result(2,1));
			AssertExtension::AreEqual(  3.070454f, result(2,2));
			AssertExtension::AreEqual(  4.409283f, result(2,3));
			AssertExtension::AreEqual(- 1.273546f, result(3,0));
			AssertExtension::AreEqual(  2.724682f, result(3,1));
			AssertExtension::AreEqual(  4.934855f, result(3,2));
			AssertExtension::AreEqual(- 0.661115f, result(3,3));
		}
	};	
}
