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
	public ref class PlaneTest
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
		void test_Plane_Default_constructor()
		{
			// Arrange & Act
			const Plane testInstance;
			
			// Assert
			Assert::AreEqual(0.f, testInstance.x);
			Assert::AreEqual(0.f, testInstance.y);
			Assert::AreEqual(0.f, testInstance.z);
			Assert::AreEqual(0.f, testInstance.w);
		};

		[TestMethod]
		void test_Plane_Second_constructor()
		{
			// Arrange & Act
			const Plane testInstance(1.f, 2.f, 3.f, 4.f);
			
			// Assert
			Assert::AreEqual(1.f, testInstance.x);
			Assert::AreEqual(2.f, testInstance.y);
			Assert::AreEqual(3.f, testInstance.z);
			Assert::AreEqual(4.f, testInstance.w);
		};

		[TestMethod]
		void test_Plane_Third_constructor()
		{
			// Arrange & Act
			const Vector3D aVector3D(1.f, 2.f, 3.f);
			const float w = 4.f;
			const Plane testInstance(aVector3D, w);
			
			// Assert
			Assert::AreEqual(1.f, testInstance.x);
			Assert::AreEqual(2.f, testInstance.y);
			Assert::AreEqual(3.f, testInstance.z);
			Assert::AreEqual(4.f, testInstance.w);
		};

		[TestMethod]
		void test_Plane_GetNormal()
		{
			// Arrange
			const Vector3D aVector3D(1.f, 2.f, 3.f);
			const float w = 4.f;
			const Plane testInstance(aVector3D, w);

			// Act
			Vector3D result = testInstance.GetNormal();
			
			// Assert
			Assert::AreEqual(1.f, result.x);
			Assert::AreEqual(2.f, result.y);
			Assert::AreEqual(3.f, result.z);
		};
	};	
}
