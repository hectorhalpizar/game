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
	};
}
