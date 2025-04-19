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
	public ref class Transform4DTest
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
		void test_Transform4D_Default_constructor()
		{
			// Arrange & Act
			const Transform4D testInstance;
			
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
			Assert::AreEqual(1.f, testInstance(3,3));
		}

		[TestMethod]
		void test_Transform4D_Second_constructor()
		{
			// Arrange & Act
			const Transform4D testInstance(1.f,  2.f,  3.f,  4.f,
										   5.f,  6.f,  7.f,  8.f,
										   9.f, 10.f, 11.f, 12.f);
			
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
			Assert::AreEqual( 0.f, testInstance(3,0));
			Assert::AreEqual( 0.f, testInstance(3,1));
			Assert::AreEqual( 0.f, testInstance(3,2));
			Assert::AreEqual( 1.f, testInstance(3,3));
		}

		[TestMethod]
		void test_Transform4D_Third_constructor()
		{
			// Arrange & Act
			const Vector3D firstVector3D(1.f, 2.f, 3.f);
			const Vector3D secondVector3D(4.f, 5.f, 6.f);
			const Vector3D thirdVector3D(7.f, 8.f, 9.f);
			const Point3D point3D(10.f, 11.f, 12.f);
			
			const Transform4D testInstance(firstVector3D,
										   secondVector3D,
										   thirdVector3D,
										   point3D);
			
			// Assert
			Assert::AreEqual( 1.f, testInstance(0,0));
			Assert::AreEqual( 2.f, testInstance(1,0));
			Assert::AreEqual( 3.f, testInstance(2,0));
			Assert::AreEqual( 0.f, testInstance(3,0));
			Assert::AreEqual( 4.f, testInstance(0,1));
			Assert::AreEqual( 5.f, testInstance(1,1));
			Assert::AreEqual( 6.f, testInstance(2,1));
			Assert::AreEqual( 0.f, testInstance(3,1));
			Assert::AreEqual( 7.f, testInstance(0,2));
			Assert::AreEqual( 8.f, testInstance(1,2));
			Assert::AreEqual( 9.f, testInstance(2,2));
			Assert::AreEqual( 0.f, testInstance(3,2));
			Assert::AreEqual(10.f, testInstance(0,3));
			Assert::AreEqual(11.f, testInstance(1,3));
			Assert::AreEqual(12.f, testInstance(2,3));
			Assert::AreEqual( 1.f, testInstance(3,3));
		}

		[TestMethod]
		void test_Transform4D_Const_Bracket_Operator()
		{
			// Arrange & Act
			const Vector3D firstVector3D(1.f, 2.f, 3.f);
			const Vector3D secondVector3D(4.f, 5.f, 6.f);
			const Vector3D thirdVector3D(7.f, 8.f, 9.f);
			const Point3D point3D(10.f, 11.f, 12.f);
			
			const Transform4D testInstance(firstVector3D,
										   secondVector3D,
										   thirdVector3D,
										   point3D);
			
			// Assert
			Vector3D result = testInstance[0];
			Assert::AreEqual( 1.f, result.x);
			Assert::AreEqual( 2.f, result.y);
			Assert::AreEqual( 3.f, result.z);


			result = testInstance[1];
			Assert::AreEqual( 4.f, result.x);
			Assert::AreEqual( 5.f, result.y);
			Assert::AreEqual( 6.f, result.z);

			result = testInstance[2];
			Assert::AreEqual( 7.f, result.x);
			Assert::AreEqual( 8.f, result.y);
			Assert::AreEqual( 9.f, result.z);

			result = testInstance[3];
			Assert::AreEqual(10.f, result.x);
			Assert::AreEqual(11.f, result.y);
			Assert::AreEqual(12.f, result.z);
		}

		[TestMethod]
		void test_Transform4D_Bracket_Operator()
		{
			// Arrange & Act
			const Vector3D firstVector3D(1.f, 2.f, 3.f);
			const Vector3D secondVector3D(4.f, 5.f, 6.f);
			const Vector3D thirdVector3D(7.f, 8.f, 9.f);
			const Point3D point3D(10.f, 11.f, 12.f);
			
			Transform4D testInstance(firstVector3D,
									 secondVector3D,
									 thirdVector3D,
									 point3D);
			
			// Assert
			Vector3D result = testInstance[0];
			Assert::AreEqual( 1.f, result.x);
			Assert::AreEqual( 2.f, result.y);
			Assert::AreEqual( 3.f, result.z);


			result = testInstance[1];
			Assert::AreEqual( 4.f, result.x);
			Assert::AreEqual( 5.f, result.y);
			Assert::AreEqual( 6.f, result.z);

			result = testInstance[2];
			Assert::AreEqual( 7.f, result.x);
			Assert::AreEqual( 8.f, result.y);
			Assert::AreEqual( 9.f, result.z);

			result = testInstance[3];
			Assert::AreEqual(10.f, result.x);
			Assert::AreEqual(11.f, result.y);
			Assert::AreEqual(12.f, result.z);
		}

		[TestMethod]
		void test_Transform4D_Set_and_Get_Translation()
		{
			// Arrange & Act
			const Vector3D firstVector3D(1.f, 2.f, 3.f);
			const Vector3D secondVector3D(4.f, 5.f, 6.f);
			const Vector3D thirdVector3D(7.f, 8.f, 9.f);
			const Point3D point3D(10.f, 11.f, 12.f);
			
			Transform4D testInstance(firstVector3D,
									 secondVector3D,
									 thirdVector3D,
									 point3D);

			
			const Point3D newTranslation(22.f, 23.f, 24.f);
			testInstance.SetTranslation(newTranslation);
			
			// Assert
			Point3D result = testInstance.GetTranslation();
			Assert::AreEqual(22.f, result.x);
			Assert::AreEqual(23.f, result.y);
			Assert::AreEqual(24.f, result.z);
		}
	};	
}
