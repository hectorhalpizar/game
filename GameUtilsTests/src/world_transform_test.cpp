#include "stdafx.h"

#include <cmath>

#include "TestTools/AssertExtention.hpp"
#include "game_math.hpp"
#include "world_transform.hpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace GameUtills::UnitTesting;
using namespace gameutils;
using namespace gameutils::math;

namespace GameUtilsTests
{
	[TestClass]
	public ref class WorldTransformTest
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
		void test_WorldTransformation_Scale_GetMatrix_Only_Scale()
		{
			// Arrange
			WorldTransform testInstance;
			testInstance.SetScale(2.f);
			testInstance.SetRotation(0.f, 0.f, 0.f);
			testInstance.SetPosition(0.f, 0.f, 0.f);

			// Act
			Matrix4D result = testInstance.GetMatrix();

			// Assert
			Assert::AreEqual(2.f, result(0,0));
			Assert::AreEqual(0.f, result(0,1));
			Assert::AreEqual(0.f, result(0,2));
			Assert::AreEqual(0.f, result(0,3));

			Assert::AreEqual(0.f, result(1,0));
			Assert::AreEqual(2.f, result(1,1));
			Assert::AreEqual(0.f, result(1,2));
			Assert::AreEqual(0.f, result(1,3));

			Assert::AreEqual(0.f, result(2,0));
			Assert::AreEqual(0.f, result(2,1));
			Assert::AreEqual(2.f, result(2,2));
			Assert::AreEqual(0.f, result(2,3));

			Assert::AreEqual(0.f, result(3,0));
			Assert::AreEqual(0.f, result(3,1));
			Assert::AreEqual(0.f, result(3,2));
			Assert::AreEqual(1.f, result(3,3));
		};

		[TestMethod]
		void test_WorldTransformation_Scale_GetMatrix_Only_Scale_And_Rotation_on_X()
		{
			// Arrange
			WorldTransform testInstance;
			testInstance.SetScale(1.f);
			testInstance.SetRotation(90.f, 0.f, 0.f);
			testInstance.SetPosition(0.f, 0.f, 0.f);

			// Act
			Matrix4D result = testInstance.GetMatrix();

			// Assert
			AssertExtension::AreEqual(1.f, result(0,0));
			AssertExtension::AreEqual(0.f, result(1,0));
			AssertExtension::AreEqual(0.f, result(2,0));
			AssertExtension::AreEqual(0.f, result(3,0));

			AssertExtension::AreEqual(0.f, result(0,1));
			AssertExtension::AreEqual(0.f, result(1,1));
			AssertExtension::AreEqual(1.f, result(2,1));
			AssertExtension::AreEqual(0.f, result(3,1));

			AssertExtension::AreEqual( 0.f, result(0,2));
			AssertExtension::AreEqual(-1.f, result(1,2));
			AssertExtension::AreEqual( 0.f, result(2,2));
			AssertExtension::AreEqual( 0.f, result(3,2));

			AssertExtension::AreEqual(0.f, result(0,3));
			AssertExtension::AreEqual(0.f, result(1,3));
			AssertExtension::AreEqual(0.f, result(2,3));
			AssertExtension::AreEqual(1.f, result(3,3));
		};

		[TestMethod]
		void test_WorldTransformation_Scale_GetMatrix_Only_Scale_And_Rotation_on_Y()
		{
			// Arrange
			WorldTransform testInstance;
			testInstance.SetScale(1.f);
			testInstance.SetRotation(0.f, 90.f, 0.f);
			testInstance.SetPosition(0.f, 0.f, 0.f);

			// Act
			Matrix4D result = testInstance.GetMatrix();

			// Assert
			AssertExtension::AreEqual( 0.f, result(0,0));
			AssertExtension::AreEqual( 0.f, result(1,0));
			AssertExtension::AreEqual(-1.f, result(2,0));
			AssertExtension::AreEqual( 0.f, result(3,0));

			AssertExtension::AreEqual(0.f, result(0,1));
			AssertExtension::AreEqual(1.f, result(1,1));
			AssertExtension::AreEqual(0.f, result(2,1));
			AssertExtension::AreEqual(0.f, result(3,1));

			AssertExtension::AreEqual(1.f, result(0,2));
			AssertExtension::AreEqual(0.f, result(1,2));
			AssertExtension::AreEqual(0.f, result(2,2));
			AssertExtension::AreEqual(0.f, result(3,2));

			AssertExtension::AreEqual(0.f, result(0,3));
			AssertExtension::AreEqual(0.f, result(1,3));
			AssertExtension::AreEqual(0.f, result(2,3));
			AssertExtension::AreEqual(1.f, result(3,3));
		};

		[TestMethod]
		void test_WorldTransformation_Scale_GetMatrix_Only_Scale_And_Rotation_on_Z()
		{
			// Arrange
			WorldTransform testInstance;
			testInstance.SetScale(1.f);
			testInstance.SetRotation(0.f, 0.f, 90.f);
			testInstance.SetPosition(0.f, 0.f, 0.f);

			// Act
			Matrix4D result = testInstance.GetMatrix();

			// Assert
			AssertExtension::AreEqual(0.f, result(0,0));
			AssertExtension::AreEqual(1.f, result(1,0));
			AssertExtension::AreEqual(0.f, result(2,0));
			AssertExtension::AreEqual(0.f, result(3,0));

			AssertExtension::AreEqual(-1.f, result(0,1));
			AssertExtension::AreEqual( 0.f, result(1,1));
			AssertExtension::AreEqual( 0.f, result(2,1));
			AssertExtension::AreEqual( 0.f, result(3,1));

			AssertExtension::AreEqual(0.f, result(0,2));
			AssertExtension::AreEqual(0.f, result(1,2));
			AssertExtension::AreEqual(1.f, result(2,2));
			AssertExtension::AreEqual(0.f, result(3,2));

			AssertExtension::AreEqual(0.f, result(0,3));
			AssertExtension::AreEqual(0.f, result(1,3));
			AssertExtension::AreEqual(0.f, result(2,3));
			AssertExtension::AreEqual(1.f, result(3,3));
		};

		[TestMethod]
		void test_WorldTransformation_Scale_GetMatrix_Scale_Rotation_And_Translate_45_degress()
		{
			// Arrange
			WorldTransform testInstance;
			testInstance.SetScale(1.f);
			testInstance.SetRotation(45.f, 0.f, 0.f);
			testInstance.SetPosition(10.f, 0.f, 0.f);

			// Act
			Matrix4D result = testInstance.GetMatrix();

			// Assert
			AssertExtension::AreEqual(1.f, result(0,0));
			AssertExtension::AreEqual(0.f, result(1,0));
			AssertExtension::AreEqual(0.f, result(2,0));
			AssertExtension::AreEqual(0.f, result(3,0));

			AssertExtension::AreEqual(0.f, result(0,1));
			AssertExtension::AreEqual(0.707106f, result(1,1));
			AssertExtension::AreEqual(0.707106f, result(2,1));
			AssertExtension::AreEqual(0.f, result(3,1));

			AssertExtension::AreEqual( 0.f, result(0,2));
			AssertExtension::AreEqual(-0.707106f, result(1,2));
			AssertExtension::AreEqual( 0.707106f, result(2,2));
			AssertExtension::AreEqual( 0.f, result(3,2));

			AssertExtension::AreEqual(10.f, result(0,3));
			AssertExtension::AreEqual(0.f, result(1,3));
			AssertExtension::AreEqual(0.f, result(2,3));
			AssertExtension::AreEqual(1.f, result(3,3));
		};

		[TestMethod]
		void test_WorldTransformation_Scale_GetMatrix_Scale_Rotation_On_Z_180_Translate_On_Z_minus_5()
		{
			// Arrange
			WorldTransform testInstance;
			testInstance.SetScale(1.f);
			testInstance.SetRotation(0.f, 0.f, 180.f);
			testInstance.SetPosition(0.f, 0.f, -5.f);

			// Act
			Matrix4D result = testInstance.GetMatrix();

			// Assert
			AssertExtension::AreEqual(-1.f, result(0,0));
			AssertExtension::AreEqual( 0.f, result(1,0));
			AssertExtension::AreEqual( 0.f, result(2,0));
			AssertExtension::AreEqual( 0.f, result(3,0));

			AssertExtension::AreEqual( 0.f, result(0,1));
			AssertExtension::AreEqual(-1.f, result(1,1));
			AssertExtension::AreEqual( 0.f, result(2,1));
			AssertExtension::AreEqual( 0.f, result(3,1));

			AssertExtension::AreEqual( 0.f, result(0,2));
			AssertExtension::AreEqual( 0.f, result(1,2));
			AssertExtension::AreEqual( 1.f, result(2,2));
			AssertExtension::AreEqual( 0.f, result(3,2));

			AssertExtension::AreEqual( 0.f, result(0,3));
			AssertExtension::AreEqual( 0.f, result(1,3));
			AssertExtension::AreEqual(-5.f, result(2,3));
			AssertExtension::AreEqual( 1.f, result(3,3));
		};

		[TestMethod]
		void test_WorldTransformation_Scale_GetMatrix_Scale_2_on_all_axis_Rotation_On_X_and_Y_45_Translate_1_on_all_axis()
		{
			// Arrange
			WorldTransform testInstance;
			testInstance.SetScale(2.f);
			testInstance.SetRotation(45.f, 45.f, 0.f);
			testInstance.SetPosition(1.f, 1.f, 1.f);

			// Act
			Matrix4D result = testInstance.GetMatrix();

			// Assert
			AssertExtension::AreEqual( 1.414213f, result(0,0));
			AssertExtension::AreEqual( 1.f,       result(1,0));
			AssertExtension::AreEqual(-1.f,       result(2,0));
			AssertExtension::AreEqual( 0.f,       result(3,0));

			AssertExtension::AreEqual( 0.f,       result(0,1));
			AssertExtension::AreEqual( 1.414213f, result(1,1));
			AssertExtension::AreEqual( 1.414213f, result(2,1));
			AssertExtension::AreEqual( 0.f,       result(3,1));

			AssertExtension::AreEqual( 1.414213f, result(0,2));
			AssertExtension::AreEqual(-1.f,       result(1,2));
			AssertExtension::AreEqual( 1.f,       result(2,2));
			AssertExtension::AreEqual( 0.f,       result(3,2));

			AssertExtension::AreEqual( 1.f,       result(0,3));
			AssertExtension::AreEqual( 1.f,       result(1,3));
			AssertExtension::AreEqual( 1.f,       result(2,3));
			AssertExtension::AreEqual( 1.f,       result(3,3));
		};
	};
}


