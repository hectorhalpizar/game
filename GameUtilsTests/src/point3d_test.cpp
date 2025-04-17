#include "stdafx.h"

#include <cmath>

#include "TestTools/AssertExtention.hpp"
#include "point3d.hpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace GameUtills::UnitTesting;

namespace GameUtilsTests
{
	[TestClass]
	public ref class Point3DTest
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
		void test_Point3D_Default_constructor()
		{
			// Arrange & Act
			const Point3D testInstance;
			
			// Assert
			Assert::AreEqual(0.f, testInstance.x);
			Assert::AreEqual(0.f, testInstance.y);
			Assert::AreEqual(0.f, testInstance.z);
		};

		[TestMethod]
		void test_Point3D_constructor_with_values()
		{
			// Arrange & Act
			const Point3D testInstance(1.f, 2.f, 3.f);
			
			// Assert
			Assert::AreEqual(1.f, testInstance.x);
			Assert::AreEqual(2.f, testInstance.y);
			Assert::AreEqual(3.f, testInstance.z);
		};

		[TestMethod]
		void test_Point3D_equals_operator_with_a_Vector3D()
		{
			// Arrange & Act
			Point3D testInstance;
			testInstance = Vector3D(5.f, 6.f, 7.f);
			
			// Assert
			Assert::AreEqual(5.f, testInstance.x);
			Assert::AreEqual(6.f, testInstance.y);
			Assert::AreEqual(7.f, testInstance.z);
		};

		[TestMethod]
		void test_Point3D_addition_operator_with_a_Vector3D()
		{
			// Arrange
			Point3D testInstance(1.f, 2.f, 3.f);
			Vector3D aVector = Vector3D(5.f, 6.f, 7.f);

			// Act
			Point3D result = testInstance + aVector;
			
			// Assert
			Assert::AreEqual(6.f, result.x);
			Assert::AreEqual(8.f, result.y);
			Assert::AreEqual(10.f, result.z);
		};

		[TestMethod]
		void test_Point3D_substraction_operator_with_a_Vector3D()
		{
			// Arrange
			Point3D testInstance(5.f, 6.f, 7.f);
			Vector3D aVector = Vector3D(1.f, 2.f, 3.f);

			// Act
			Point3D result = testInstance - aVector;
			
			// Assert
			Assert::AreEqual(4.f, result.x);
			Assert::AreEqual(4.f, result.y);
			Assert::AreEqual(4.f, result.z);
		};

		[TestMethod]
		void test_Vector3D_substraction_operator_with_two_Point3D_structs()
		{
			// Arrange
			Point3D testInstance(5.f, 6.f, 7.f);
			Point3D aPoint3D = Point3D(1.f, 2.f, 3.f);

			// Act
			Vector3D result = testInstance - aPoint3D;
			
			// Assert
			Assert::AreEqual(4.f, result.x);
			Assert::AreEqual(4.f, result.y);
			Assert::AreEqual(4.f, result.z);
		};
	};	
}
