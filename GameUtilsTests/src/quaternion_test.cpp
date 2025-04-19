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
	public ref class QuaternionTest
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
		void test_Quaternion_Default_constructor()
		{
			// Arrange & Act
			const Quaternion testInstance;
			
			// Assert
			Assert::AreEqual(0.f, testInstance.x);
			Assert::AreEqual(0.f, testInstance.y);
			Assert::AreEqual(0.f, testInstance.z);
			Assert::AreEqual(0.f, testInstance.w);
		};

		[TestMethod]
		void test_Quaternion_Second_constructor()
		{
			// Arrange & Act
			const Quaternion testInstance(1.f, 2.f, 3.f, 4.f);
			
			// Assert
			Assert::AreEqual(1.f, testInstance.x);
			Assert::AreEqual(2.f, testInstance.y);
			Assert::AreEqual(3.f, testInstance.z);
			Assert::AreEqual(4.f, testInstance.w);
		};

		[TestMethod]
		void test_Quaternion_Third_constructor()
		{
			// Arrange & Act
			const Vector3D aVector(1.f, 2.f, 3.f);
			const float w = 4.f;
			const Quaternion testInstance(aVector, w);
			
			// Assert
			Assert::AreEqual(1.f, testInstance.x);
			Assert::AreEqual(2.f, testInstance.y);
			Assert::AreEqual(3.f, testInstance.z);
			Assert::AreEqual(4.f, testInstance.w);
		};

		[TestMethod]
		void test_Quaternion_const_GetVectorPart()
		{
			// Arrange
			const Vector3D aVector(1.f, 2.f, 3.f);
			const float w = 4.f;
			Quaternion testInstance(aVector, w);

			// Act
			const Vector3D result = testInstance.GetVectorPart();
			
			// Assert
			Assert::AreEqual(1.f, result.x);
			Assert::AreEqual(2.f, result.y);
			Assert::AreEqual(3.f, result.z);
		};

		[TestMethod]
		void test_Quaternion_GetVectorPart()
		{
			// Arrange
			const Vector3D aVector(1.f, 2.f, 3.f);
			const float w = 4.f;
			const Quaternion testInstance(aVector, w);

			// Act
			Vector3D result = testInstance.GetVectorPart();
			
			// Assert
			Assert::AreEqual(1.f, result.x);
			Assert::AreEqual(2.f, result.y);
			Assert::AreEqual(3.f, result.z);
		};

		[TestMethod]
		void test_Quaternion_GetRotationMatrix()
		{
			// Arrange
			const Vector3D aVector(1.f, 2.f, 3.f);
			const float w = 4.f;
			Quaternion testInstance(aVector, w);

			// Act
			Matrix3D result = testInstance.GetRotationMatrix();

			
			// Assert
			Assert::AreEqual(-25.f, result(0, 0));
			Assert::AreEqual(-20.f, result(0, 1));
			Assert::AreEqual( 22.f, result(0, 2));
			Assert::AreEqual( 28.f, result(1, 0));
			Assert::AreEqual(-19.f, result(1, 1));
			Assert::AreEqual(  4.f, result(1, 2));
			Assert::AreEqual(-10.f, result(2, 0));
			Assert::AreEqual( 20.f, result(2, 1));
			Assert::AreEqual(- 9.f, result(2, 2));
		};

		[TestMethod]
		void test_Quaternion_SetRotationMatrix()
		{
			// Arrange
			const Vector3D aVector(1.f, 2.f, 3.f);
			const float w = 4.f;
			Quaternion testInstance(aVector, w);

			// Act
			Matrix3D rotationMatrix(1.f, 2.f, 3.f,
									2.f, 1.f, 3.f,
									3.f, 2.f, 1.f);
			testInstance.SetRotationMatrix(rotationMatrix);

			
			// Assert
			Assert::AreEqual(-0.25f, testInstance.x);
			Assert::AreEqual( 0.f, testInstance.y);
			Assert::AreEqual( 0.f, testInstance.z);
			Assert::AreEqual( 1.f, testInstance.w);
		};
	};	
}
