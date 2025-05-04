#include "stdafx.h"

#include <cmath>

#include "TestTools/AssertExtention.hpp"
#include "game_math.hpp"
#include "camera.hpp"
#include "Mocks/mock_camera.hpp"

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
	public ref class CameraTest
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
		void test_Camera_Look_at_minus_Z_on_the_origen()
		{
			// Arrange
			MockCamera testInstance;
			testInstance.SetPosition(Vector3D(0.F, 0.F, 0.F));
			testInstance.SetTarget(Vector3D(0.F, 0.F, -1.F));
			testInstance.SetUp(Vector3D(0.F, 1.F, 0.F));

			// Act
			Matrix4D result = testInstance.GetMatrix();

			// Assert
			AssertExtension::AreEqual(-1.f, result(0,0));
			AssertExtension::AreEqual( 0.f, result(1,0));
			AssertExtension::AreEqual( 0.f, result(2,0));
			AssertExtension::AreEqual( 0.f, result(3,0));

			AssertExtension::AreEqual( 0.f, result(0,1));
			AssertExtension::AreEqual( 1.f, result(1,1));
			AssertExtension::AreEqual( 0.f, result(2,1));
			AssertExtension::AreEqual( 0.f, result(3,1));

			AssertExtension::AreEqual( 0.f, result(0,2));
			AssertExtension::AreEqual( 0.f, result(1,2));
			AssertExtension::AreEqual(-1.f, result(2,2));
			AssertExtension::AreEqual( 0.f, result(3,2));

			AssertExtension::AreEqual( 0.f, result(0,3));
			AssertExtension::AreEqual( 0.f, result(1,3));
			AssertExtension::AreEqual( 0.f, result(2,3));
			AssertExtension::AreEqual( 1.f, result(3,3));

		};

		[TestMethod]
		void test_Camera_Look_at_minus_Z_with_position_on_Z_10()
		{
			// Arrange
			MockCamera testInstance;
			testInstance.SetPosition(Vector3D(0.F, 0.F, 10.F));
			testInstance.SetTarget(Vector3D(0.F, 0.F, -1.F));
			testInstance.SetUp(Vector3D(0.F, 1.F, 0.F));

			// Act
			Matrix4D result = testInstance.GetMatrix();

			// Assert
			AssertExtension::AreEqual(-1.f, result(0,0));
			AssertExtension::AreEqual( 0.f, result(1,0));
			AssertExtension::AreEqual( 0.f, result(2,0));
			AssertExtension::AreEqual( 0.f, result(3,0));

			AssertExtension::AreEqual( 0.f, result(0,1));
			AssertExtension::AreEqual( 1.f, result(1,1));
			AssertExtension::AreEqual( 0.f, result(2,1));
			AssertExtension::AreEqual( 0.f, result(3,1));

			AssertExtension::AreEqual( 0.f, result(0,2));
			AssertExtension::AreEqual( 0.f, result(1,2));
			AssertExtension::AreEqual(-1.f, result(2,2));
			AssertExtension::AreEqual( 0.f, result(3,2));

			AssertExtension::AreEqual( 0.f, result(0,3));
			AssertExtension::AreEqual( 0.f, result(1,3));
			AssertExtension::AreEqual(10.f, result(2,3));
			AssertExtension::AreEqual( 1.f, result(3,3));

		};

		[TestMethod]
		void test_Camera_on_the_origin_looking_at_plus_X()
		{
			// Arrange
			MockCamera testInstance;
			testInstance.SetPosition(Vector3D(0.F, 0.F, 0.F));
			testInstance.SetTarget(Vector3D(1.F, 0.F, 0.F));
			testInstance.SetUp(Vector3D(0.F, 1.F, 0.F));

			// Act
			Matrix4D result = testInstance.GetMatrix();

			// Assert
			AssertExtension::AreEqual( 0.f, result(0,0));
			AssertExtension::AreEqual( 0.f, result(1,0));
			AssertExtension::AreEqual(-1.f, result(2,0));
			AssertExtension::AreEqual( 0.f, result(3,0));

			AssertExtension::AreEqual( 0.f, result(0,1));
			AssertExtension::AreEqual( 1.f, result(1,1));
			AssertExtension::AreEqual( 0.f, result(2,1));
			AssertExtension::AreEqual( 0.f, result(3,1));

			AssertExtension::AreEqual( 1.f, result(0,2));
			AssertExtension::AreEqual( 0.f, result(1,2));
			AssertExtension::AreEqual( 0.f, result(2,2));
			AssertExtension::AreEqual( 0.f, result(3,2));

			AssertExtension::AreEqual( 0.f, result(0,3));
			AssertExtension::AreEqual( 0.f, result(1,3));
			AssertExtension::AreEqual( 0.f, result(2,3));
			AssertExtension::AreEqual( 1.f, result(3,3));
		};

		[TestMethod]
		void test_Camera_move_up()
		{
			// Arrange
			MockCamera testInstance;

			// Act
			testInstance.Maniputale(Camera::MOVE_UP);

			// Assert
			Vector3D resultPosition = testInstance.GetPosition();
			AssertExtension::AreEqual( 0.f, resultPosition.x);
			AssertExtension::AreEqual( 0.f, resultPosition.y);
			AssertExtension::AreEqual( 1.f, resultPosition.z);
		};

		[TestMethod]
		void test_Camera_move_down()
		{
			// Arrange
			MockCamera testInstance;

			// Act
			testInstance.Maniputale(Camera::MOVE_DOWN);

			// Assert
			Vector3D resultPosition = testInstance.GetPosition();
			AssertExtension::AreEqual( 0.f, resultPosition.x);
			AssertExtension::AreEqual( 0.f, resultPosition.y);
			AssertExtension::AreEqual(-1.f, resultPosition.z);
		};

		[TestMethod]
		void test_Camera_move_left()
		{
			// Arrange
			MockCamera testInstance;

			// Act
			testInstance.Maniputale(Camera::MOVE_LEFT);

			// Assert
			Vector3D resultPosition = testInstance.GetPosition();
			AssertExtension::AreEqual(-1.f, resultPosition.x);
			AssertExtension::AreEqual( 0.f, resultPosition.y);
			AssertExtension::AreEqual( 0.f, resultPosition.z);
		};

		[TestMethod]
		void test_Camera_move_right()
		{
			// Arrange
			MockCamera testInstance;

			// Act
			testInstance.Maniputale(Camera::MOVE_RIGHT);

			// Assert
			Vector3D resultPosition = testInstance.GetPosition();
			AssertExtension::AreEqual( 1.f, resultPosition.x);
			AssertExtension::AreEqual( 0.f, resultPosition.y);
			AssertExtension::AreEqual( 0.f, resultPosition.z);
		};

		[TestMethod]
		void test_Camera_page_up()
		{
			// Arrange
			MockCamera testInstance;

			// Act
			testInstance.Maniputale(Camera::PAGE_UP);

			// Assert
			Vector3D resultPosition = testInstance.GetPosition();
			AssertExtension::AreEqual( 0.f, resultPosition.x);
			AssertExtension::AreEqual( 1.f, resultPosition.y);
			AssertExtension::AreEqual( 0.f, resultPosition.z);
		};

		[TestMethod]
		void test_Camera_page_down()
		{
			// Arrange
			MockCamera testInstance;

			// Act
			testInstance.Maniputale(Camera::PAGE_DOWN);

			// Assert
			Vector3D resultPosition = testInstance.GetPosition();
			AssertExtension::AreEqual( 0.f, resultPosition.x);
			AssertExtension::AreEqual(-1.f, resultPosition.y);
			AssertExtension::AreEqual( 0.f, resultPosition.z);
		};

		[TestMethod]
		void test_Camera_speed_up()
		{
			// Arrange
			MockCamera testInstance;

			// Act
			testInstance.Maniputale(Camera::SPEED_UP);

			// Assert
			float result = testInstance.GetSpeed();
			AssertExtension::AreEqual(1.1f, result);
		};

		[TestMethod]
		void test_Camera_speed_down()
		{
			// Arrange
			MockCamera testInstance;

			// Act
			testInstance.Maniputale(Camera::SPEED_DOWN);

			// Assert
			float result = testInstance.GetSpeed();
			AssertExtension::AreEqual(0.9f, result);
		};

		[TestMethod]
		void test_Camera_speed_down_cap()
		{
			// Arrange
			MockCamera testInstance;
			testInstance.SetSpeed(0.1F);

			// Act
			testInstance.Maniputale(Camera::SPEED_DOWN);

			// Assert
			float result = testInstance.GetSpeed();
			AssertExtension::AreEqual(0.1F, result);
		};
	};
}


