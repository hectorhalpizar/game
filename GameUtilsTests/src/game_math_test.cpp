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
	public ref class GameMathTest
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
		void test_Vector3D_multiply_composed_asignation_operator_with_a_common_float()
		{
			// Arrange
			Vector3D testInstance = Vector3D(1, 2, 3);
			float commonFloat = 2.f;
			
			// Act
			testInstance *= 2.f;
			
			// Assert
			Assert::AreEqual(2.f, testInstance.x);
			Assert::AreEqual(4.f, testInstance.y);
			Assert::AreEqual(6.f, testInstance.z);
		};

		[TestMethod]
		void test_Vector3D_division_composed_asignation_operator_with_a_common_float()
		{
			// Arrange
			Vector3D testInstance = Vector3D(2, 4, 6);
			float commonFloat = 2.f;
			
			// Act
			testInstance /= 2.f;
			
			// Assert
			Assert::AreEqual(1.f, testInstance.x);
			Assert::AreEqual(2.f, testInstance.y);
			Assert::AreEqual(3.f, testInstance.z);
		};

		[TestMethod]
		void test_Vector3D_addition_composed_asignation_operator_with_other_Vector3D()
		{
			// Arrange
			Vector3D testInstance = Vector3D(1, 2, 3);
			Vector3D otherVector3D = Vector3D(1, 2, 3);
			
			// Act
			testInstance += otherVector3D;
			
			// Assert
			Assert::AreEqual(2.f, testInstance.x);
			Assert::AreEqual(4.f, testInstance.y);
			Assert::AreEqual(6.f, testInstance.z);
		};

		[TestMethod]
		void test_Vector3D_substraction_composed_asignation_operator_with_other_Vector3D()
		{
			// Arrange
			Vector3D testInstance = Vector3D(1, 2, 3);
			Vector3D otherVector3D = Vector3D(1, 2, 3);
			
			// Act
			testInstance -= otherVector3D;
			
			// Assert
			Assert::AreEqual(0.f, testInstance.x);
			Assert::AreEqual(0.f, testInstance.y);
			Assert::AreEqual(0.f, testInstance.z);
		};

		[TestMethod]
		void test_Vector3D_division_operator_with_other_Vector3D()
		{
			// Arrange
			const Vector3D aVector3D = Vector3D(2, 4, 6);
			float aFloatValue = 2.f;
			
			// Act
			Vector3D result = aVector3D / aFloatValue;
			
			// Assert
			Assert::AreEqual(1.f, result.x);
			Assert::AreEqual(2.f, result.y);
			Assert::AreEqual(3.f, result.z);
		};

		[TestMethod]
		void test_Vector3D_multiplication_operator_with_other_Vector3D()
		{
			// Arrange
			const Vector3D aVector3D = Vector3D(2, 4, 6);
			float aFloatValue = 2.f;
			
			// Act
			Vector3D result = aVector3D * aFloatValue;
			
			// Assert
			Assert::AreEqual(4.f, result.x);
			Assert::AreEqual(8.f, result.y);
			Assert::AreEqual(12.f, result.z);
		};

		[TestMethod]
		void test_Vector3D_magnitud_with_other_Vector3D()
		{
			// Arrange
			const Vector3D aVector3D = Vector3D(2, 4, 6);
			
			// Act
			float result = Magnitude(aVector3D);
			
			// Assert
			Assert::AreEqual(7.483315f, result);
		};

		[TestMethod]
		void test_Vector3D_normalize_with_other_Vector3D()
		{
			// Arrange
			const Vector3D aVector3D = Vector3D(2, 4, 6);
			
			// Act
			Vector3D result = Normalize(aVector3D);
			Vector3D expected(0.2672612f, 0.5345225f, 0.8017837f);
			
			// Assert
			AssertExtension::AreEqual(expected.x, result.x);
			AssertExtension::AreEqual(expected.y, result.y);
			AssertExtension::AreEqual(expected.z, result.z);
		};

		[TestMethod]
		void test_Vector3D_addition_with_other_Vector3D()
		{
			// Arrange
			Vector3D aVector3D = Vector3D(2, 4, 6);
			const Vector3D otherVector3D = Vector3D(1, 2, 3);
			
			// Act
			Vector3D result = aVector3D + otherVector3D;
			
			// Assert
			Assert::AreEqual(3.f, result.x);
			Assert::AreEqual(6.f, result.y);
			Assert::AreEqual(9.f, result.z);
		};

		[TestMethod]
		void test_Vector3D_substraction_with_other_Vector3D()
		{
			// Arrange
			Vector3D aVector3D = Vector3D(2, 4, 6);
			const Vector3D otherVector3D = Vector3D(1, 2, 3);
			
			// Act
			Vector3D result = aVector3D - otherVector3D;
			
			// Assert
			Assert::AreEqual(1.f, result.x);
			Assert::AreEqual(2.f, result.y);
			Assert::AreEqual(3.f, result.z);
		};

		[TestMethod]
		void test_Vector3D_Dot_with_other_Vector3D()
		{
			// Arrange
			const Vector3D aVector3D = Vector3D(2.5f, 4.5f, 6.5f);
			const Vector3D otherVector3D = Vector3D(1.5f, 2.5f, 3.5f);
			
			// Act
			float result = Dot(aVector3D, otherVector3D);
			
			// Assert
			Assert::AreEqual(37.75f, result);
		};

		[TestMethod]
		void test_Vector3D_Cross_with_other_Vector3D()
		{
			// Arrange
			const Vector3D aVector3D = Vector3D(2.5f, 4.5f, 6.5f);
			const Vector3D otherVector3D = Vector3D(1.5f, 2.5f, 3.5f);
			
			// Act
			Vector3D result = Cross(aVector3D, otherVector3D);
			
			// Assert
			Assert::AreEqual(-0.5f, result.x);
			Assert::AreEqual(1.f, result.y);
			Assert::AreEqual(-0.5f, result.z);
		};

		[TestMethod]
		void test_Vector3D_Project_with_other_Vector3D()
		{
			// Arrange
			const Vector3D aVector3D = Vector3D(2.5f, 4.5f, 6.5f);
			const Vector3D otherVector3D = Vector3D(1.5f, 2.5f, 3.5f);
			
			// Act
			Vector3D result = Project(aVector3D, otherVector3D);
			const Vector3D expected = Vector3D(2.728916f, 4.548193f, 6.36747f);
			
			// Assert
			AssertExtension::AreEqual(expected.x, result.x);
			AssertExtension::AreEqual(expected.y, result.y);
			AssertExtension::AreEqual(expected.z, result.z);
		};

		[TestMethod]
		void test_Vector3D_Reject_with_other_Vector3D()
		{
			// Arrange
			const Vector3D aVector3D = Vector3D(2.5f, 4.5f, 6.5f);
			const Vector3D otherVector3D = Vector3D(1.5f, 2.5f, 3.5f);
			
			// Act
			Vector3D result = Reject(aVector3D, otherVector3D);
			const Vector3D expected = Vector3D(-0.2289157f, -0.04819298f, 0.1325297f);
			
			// Assert
			AssertExtension::AreEqual(expected.x, result.x);
			AssertExtension::AreEqual(expected.y, result.y);
			AssertExtension::AreEqual(expected.z, result.z);
		};

		[TestMethod]
		void test_Point3D_Plus_Operator_With_One_Point3D_And_One_Vector3D()
		{
			// Arrange
			const Point3D aPoint3D = Point3D(2.5f, 4.5f, 6.5f);
			const Vector3D aVector3D = Vector3D(1.5f, 2.5f, 3.5f);
			
			// Act
			Point3D result = aPoint3D + aVector3D;
			
			// Assert
			AssertExtension::AreEqual( 4.f, result.x);
			AssertExtension::AreEqual( 7.f, result.y);
			AssertExtension::AreEqual(10.f, result.z);
		};

		[TestMethod]
		void test_Point3D_Minus_Operator_With_One_Point3D_And_One_Vector3D()
		{
			// Arrange
			const Point3D aPoint3D = Point3D(2.5f, 4.5f, 6.5f);
			const Vector3D aVector3D = Vector3D(1.5f, 2.5f, 3.5f);
			
			// Act
			Point3D result = aPoint3D - aVector3D;
			
			// Assert
			AssertExtension::AreEqual(1.f, result.x);
			AssertExtension::AreEqual(2.f, result.y);
			AssertExtension::AreEqual(3.f, result.z);
		};

		[TestMethod]
		void test_Vector3D_Minus_Operator_With_a_Point3D_And_other_Vector3D()
		{
			// Arrange
			const Point3D aPoint3D = Point3D(2.5f, 4.5f, 6.5f);
			const Point3D otherPoint3D = Point3D(1.5f, 2.5f, 3.5f);
			
			// Act
			Vector3D result = aPoint3D - otherPoint3D;
			
			// Assert
			AssertExtension::AreEqual(1.f, result.x);
			AssertExtension::AreEqual(2.f, result.y);
			AssertExtension::AreEqual(3.f, result.z);
		};

		[TestMethod]
		void test_DistPointLine_with_two_Point3D_structs_and_one_Vector3D_struct()
		{
			// Arrange
			const Point3D aPoint3D = Point3D(2.5f, 4.5f, 6.5f);
			const Point3D otherPoint3D = Point3D(9.5f, 10.5f, 11.5f);
			const Vector3D aVector3D = Vector3D(1.5f, 2.5f, 3.5f);
			
			// Act
			float result = DistPointLine(aPoint3D, otherPoint3D, aVector3D);
			
			// Assert
			AssertExtension::AreEqual(4.570729f, result);
		};

		[TestMethod]
		void test_DistLineLine_with_two_Point3D_structs_and_two_Vector3D_structs()
		{
			// Arrange
			const Point3D aPoint3D = Point3D(2.5f, 4.5f, 6.5f);
			const Point3D otherPoint3D = Point3D(9.5f, 10.5f, 11.5f);
			const Vector3D aVector3D = Vector3D(1.5f, 2.5f, 3.5f);
			const Vector3D otherVector3D = Vector3D(6.5f, 8.5f, 4.5f);
			
			// Act
			float result = DistLineLine(aPoint3D, aVector3D, otherPoint3D, otherVector3D);
			
			// Assert
			AssertExtension::AreEqual(2.064083f, result);
		};

		[TestMethod]
		void test_Vector4D_multiply_composed_asignation_operator_with_a_common_float()
		{
			// Arrange
			Vector4D testInstance = Vector4D(1, 2, 3, 4);
			float commonFloat = 2.f;
			
			// Act
			testInstance *= 2.f;
			
			// Assert
			Assert::AreEqual(2.f, testInstance.x);
			Assert::AreEqual(4.f, testInstance.y);
			Assert::AreEqual(6.f, testInstance.z);
			Assert::AreEqual(8.f, testInstance.w);
		};

		[TestMethod]
		void test_Vector4D_division_composed_asignation_operator_with_a_common_float()
		{
			// Arrange
			Vector4D testInstance = Vector4D(2, 4, 6, 8);
			float commonFloat = 2.f;
			
			// Act
			testInstance /= 2.f;
			
			// Assert
			Assert::AreEqual(1.f, testInstance.x);
			Assert::AreEqual(2.f, testInstance.y);
			Assert::AreEqual(3.f, testInstance.z);
			Assert::AreEqual(4.f, testInstance.w);
		};

		[TestMethod]
		void test_Vector4D_addition_composed_asignation_operator_with_other_Vector4D()
		{
			// Arrange
			Vector4D testInstance = Vector4D(1, 2, 3, 4);
			Vector4D otherVector4D = Vector4D(1, 2, 3, 4);
			
			// Act
			testInstance += otherVector4D;
			
			// Assert
			Assert::AreEqual(2.f, testInstance.x);
			Assert::AreEqual(4.f, testInstance.y);
			Assert::AreEqual(6.f, testInstance.z);
			Assert::AreEqual(8.f, testInstance.w);
		};

		[TestMethod]
		void test_Vector4D_substraction_composed_asignation_operator_with_other_Vector4D()
		{
			// Arrange
			Vector4D testInstance = Vector4D(1, 2, 3, 4);
			Vector4D otherVector4D = Vector4D(1, 2, 3, 4);
			
			// Act
			testInstance -= otherVector4D;
			
			// Assert
			Assert::AreEqual(0.f, testInstance.x);
			Assert::AreEqual(0.f, testInstance.y);
			Assert::AreEqual(0.f, testInstance.z);
			Assert::AreEqual(0.f, testInstance.w);
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

		[TestMethod]
		void test_Matrix3D_MakeInvolution()
		{
			// Arrange
			Vector3D aVector = Vector3D(-1.f, -1.f, -1.f);

			// Act
			Matrix3D result = MakeInvolution(aVector);

			// Assert
			AssertExtension::AreEqual(1.f, result(0,0));
			AssertExtension::AreEqual(2.f, result(0,1));
			AssertExtension::AreEqual(2.f, result(0,2));
			AssertExtension::AreEqual(2.f, result(1,0));
			AssertExtension::AreEqual(1.f, result(1,1));
			AssertExtension::AreEqual(2.f, result(1,2));
			AssertExtension::AreEqual(2.f, result(2,0));
			AssertExtension::AreEqual(2.f, result(2,1));
			AssertExtension::AreEqual(1.f, result(2,2));
		}

		[TestMethod]
		void test_Matrix3D_MakeScale_with_3_float_values()
		{
			// Arrange
			float sx = -1.f; float sy = -1.f; float sz = -1.f;

			// Act
			Matrix3D result = MakeScale(sx, sy, sz);

			// Assert
			AssertExtension::AreEqual(-1.f, result(0,0));
			AssertExtension::AreEqual( 0.f, result(0,1));
			AssertExtension::AreEqual( 0.f, result(0,2));
			AssertExtension::AreEqual( 0.f, result(1,0));
			AssertExtension::AreEqual(-1.f, result(1,1));
			AssertExtension::AreEqual( 0.f, result(1,2));
			AssertExtension::AreEqual( 0.f, result(2,0));
			AssertExtension::AreEqual( 0.f, result(2,1));
			AssertExtension::AreEqual(-1.f, result(2,2));
		}

		[TestMethod]
		void test_Matrix3D_MakeScale_with_a_Vector3D_and_the_scale()
		{
			// Arrange
			float s = -1.f;
			Vector3D aVector = Vector3D(-1.f, -1.f, -1.f);

			// Act
			Matrix3D result = MakeScale(s, aVector);

			// Assert
			AssertExtension::AreEqual(-1.f, result(0,0));
			AssertExtension::AreEqual(-2.f, result(0,1));
			AssertExtension::AreEqual(-2.f, result(0,2));
			AssertExtension::AreEqual(-2.f, result(1,0));
			AssertExtension::AreEqual(-1.f, result(1,1));
			AssertExtension::AreEqual(-2.f, result(1,2));
			AssertExtension::AreEqual(-2.f, result(2,0));
			AssertExtension::AreEqual(-2.f, result(2,1));
			AssertExtension::AreEqual(-1.f, result(2,2));
		}

		[TestMethod]
		void test_Matrix3D_MakeSkew()
		{
			// Arrange
			float t = 3.f;
			Vector3D aVector = Vector3D(-1.f,  2.f, -1.f);
			Vector3D bVector = Vector3D( 2.f, -1.f,  2.f);

			// Act
			Matrix3D result = MakeSkew(t, aVector, bVector);

			// Assert
			AssertExtension::AreEqual( 1.285093f, result(0,0));
			AssertExtension::AreEqual(-0.142546f, result(0,1));
			AssertExtension::AreEqual( 0.285093f, result(0,2));
			AssertExtension::AreEqual(-0.570186f, result(1,0));
			AssertExtension::AreEqual( 1.285093f, result(1,1));
			AssertExtension::AreEqual(-0.570186f, result(1,2));
			AssertExtension::AreEqual( 0.285093f, result(2,0));
			AssertExtension::AreEqual(-0.142546f, result(2,1));
			AssertExtension::AreEqual( 1.285093f, result(2,2));
		}

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

		[TestMethod]
		void test_Vector3D_multiply_operator_with_Transform4D_and_Vector3D()
		{
			// Arrange
			Transform4D aTransform = Transform4D(Vector3D( .10f, -.155f,  .100f),
											     Vector3D(-.15f,  .125f, -.095f),
												 Vector3D( .15f, -.100f,  .110f),
											      Point3D( .20f,  .150f,  .150f));

			Vector3D aVector3D = Vector3D(.10f, -.155f, .100f);

			// Act
			Vector3D result = aTransform * aVector3D;

			// Assert
			AssertExtension::AreEqual( 0.048250f, result.x);
			AssertExtension::AreEqual(-0.044874f, result.y);
			AssertExtension::AreEqual( 0.035725f, result.z);
		}

		[TestMethod]
		void test_Vector3D_multiply_operator_with_Transform4D_and_Point3D()
		{
			// Arrange
			Transform4D aTransform = Transform4D(Vector3D( .10f, -.155f,  .100f),
											     Vector3D(-.15f,  .125f, -.095f),
												 Vector3D( .15f, -.100f,  .110f),
											      Point3D( .20f,  .150f,  .150f));

			Point3D aPoint3D = Point3D(.10f, -.155f, .100f);

			// Act
			Point3D result = aTransform * aPoint3D;

			// Assert
			AssertExtension::AreEqual(0.248250f, result.x);
			AssertExtension::AreEqual(0.105125f, result.y);
			AssertExtension::AreEqual(0.185725f, result.z);
		}

		[TestMethod]
		void test_Vector3D_multiply_operator_with_Vector3D_and_Transform4D()
		{
			// Arrange
			Transform4D aTransform = Transform4D(Vector3D( .10f, -.155f,  .100f),
											     Vector3D(-.15f,  .125f, -.095f),
												 Vector3D( .15f, -.100f,  .110f),
											      Point3D( .20f,  .150f,  .150f));

			Vector3D aVector3D = Vector3D(.10f, -.155f, .100f);

			// Act
			Vector3D result = aVector3D * aTransform;

			// Assert
			AssertExtension::AreEqual( 0.044025f, result.x);
			AssertExtension::AreEqual(-0.043875f, result.y);
			AssertExtension::AreEqual( 0.041500f, result.z);
		}

				[TestMethod]
		void test_Transform4D_Inverse()
		{
			// Arrange
			Transform4D testInstance = Transform4D(Vector3D( .10f, -.155f,  .100f),
											       Vector3D(-.15f,  .125f, -.095f),
												   Vector3D( .15f, -.100f,  .110f),
											        Point3D( .20f,  .150f,  .150f));

			// Act
			Transform4D result = Inverse(testInstance);

			// Assert
			AssertExtension::AreEqual(-14.225936f, result(0,0));
			AssertExtension::AreEqual(- 7.531379f, result(0,1));
			AssertExtension::AreEqual( 12.552296f, result(0,2));
			AssertExtension::AreEqual(  2.092048f, result(0,3));
			AssertExtension::AreEqual(-23.598318f, result(1,0));
			AssertExtension::AreEqual( 13.389121f, result(1,1));
			AssertExtension::AreEqual( 44.351455f, result(1,2));
			AssertExtension::AreEqual(- 3.941424f, result(1,3));
			AssertExtension::AreEqual(- 7.447696f, result(2,0));
			AssertExtension::AreEqual( 18.410039f, result(2,1));
			AssertExtension::AreEqual( 35.983261f, result(2,2));
			AssertExtension::AreEqual(- 6.669456f, result(2,3));
			AssertExtension::AreEqual(  0.f,       result(3,0));
			AssertExtension::AreEqual(  0.f,       result(3,1));
			AssertExtension::AreEqual(  0.f,       result(3,2));
			AssertExtension::AreEqual(  1.f,       result(3,3));
		}

		[TestMethod]
		void test_Transform4D_Multiply_Operator_with_two_Transform4D_structs()
		{
			// Arrange
			Transform4D aTransform = Transform4D(Vector3D( .10f, -.155f,  .100f),
											     Vector3D(-.15f,  .125f, -.095f),
												 Vector3D( .15f, -.100f,  .110f),
											      Point3D( .20f,  .150f,  .150f));

			Transform4D otherTransform = Transform4D(Vector3D( .10f, -.155f,  .100f),
													 Vector3D( .25f, .125f,  -.095f),
													 Vector3D(-.10f, -.100f,  .110f),
													  Point3D( .25f, .150f,  -.150f));

			// Act
			Transform4D result = aTransform * otherTransform;

			// Assert
			AssertExtension::AreEqual( 0.048250f,  result(0,0));
			AssertExtension::AreEqual(-0.008000f,  result(0,1));
			AssertExtension::AreEqual( 0.021500f,  result(0,2));
			AssertExtension::AreEqual( 0.180000f,  result(0,3));
			AssertExtension::AreEqual(-0.044874f,  result(1,0));
			AssertExtension::AreEqual(-0.013625f,  result(1,1));
			AssertExtension::AreEqual(-0.008000f,  result(1,2));
			AssertExtension::AreEqual( 0.1450000f, result(1,3));
			AssertExtension::AreEqual( 0.035725f,  result(2,0));
			AssertExtension::AreEqual( 0.002675f,  result(2,1));
			AssertExtension::AreEqual( 0.0115999f, result(2,2));
			AssertExtension::AreEqual( 0.144250f,  result(2,3));
			AssertExtension::AreEqual(  0.f,       result(3,0));
			AssertExtension::AreEqual(  0.f,       result(3,1));
			AssertExtension::AreEqual(  0.f,       result(3,2));
			AssertExtension::AreEqual(  1.f,       result(3,3));
		}

		[TestMethod]
		void test_Quaternion_Multiply_Operator_with_two_Quaternion_structs()
		{
			// Arrange
			Quaternion aQuaternion = Quaternion(Vector3D( .10f, -.155f,  .100f), .5f);

			Quaternion otherQuaternion = Quaternion(Vector3D( .10f, -.155f,  .100f), .25f);

			// Act
			Quaternion result = aQuaternion * otherQuaternion;

			// Assert
			AssertExtension::AreEqual( 0.075000f,  result.x);
			AssertExtension::AreEqual(-0.116250f,  result.y);
			AssertExtension::AreEqual( 0.075000f,  result.z);
			AssertExtension::AreEqual( 0.080974f,  result.w);
		}

		[TestMethod]
		void test_Vector3D_Transform_with_a_Vector3D_and_Quaternion()
		{
			// Arrange
			Vector3D aVector3D = Vector3D( .10f, -.155f,  .100f);

			Quaternion aQuaternion = Quaternion(Vector3D( .10f, -.155f,  .100f), .25f);

			// Act
			Vector3D result = Transform(aVector3D, aQuaternion);

			// Assert
			AssertExtension::AreEqual( 0.010652f,  result.x);
			AssertExtension::AreEqual(-0.016511f,  result.y);
			AssertExtension::AreEqual( 0.010652f,  result.z);
		}

		[TestMethod]
		void test_Dot_with_a_Plane_and_Vector3D()
		{
			// Arrange
			Plane aPlane = Plane(Vector3D( .10f, -.155f,  .100f), .25f);

			Vector3D aVector3D = Vector3D( .10f, -.155f,  .100f);
		
			// Act
			float result = Dot(aPlane, aVector3D);

			// Assert
			AssertExtension::AreEqual(0.044025f,  result);
		}

		[TestMethod]
		void test_Dot_with_a_Plane_and_Point3D()
		{
			// Arrange
			Plane aPlane = Plane(Vector3D( .10f, -.155f,  .100f), .25f);

			Point3D aPoint3D = Point3D( .10f, -.155f,  .100f);

			// Act
			float result = Dot(aPlane, aPoint3D);

			// Assert
			AssertExtension::AreEqual(0.294025f,  result);
		}

		[TestMethod]
		void test_Transform4D_MakeReflection_with_a_Plane()
		{
			// Arrange
			Plane aPlane = Plane(Vector3D( .10f, -.155f,  .100f), .25f);

			// Act
			Transform4D result = MakeReflection(aPlane);

			// Assert
			AssertExtension::AreEqual( 0.980000f,  result(0,0));
			AssertExtension::AreEqual( 0.031000f,  result(0,1));
			AssertExtension::AreEqual(-0.020000f,  result(0,2));
			AssertExtension::AreEqual(-0.050000f,  result(0,3));
			AssertExtension::AreEqual( 0.031000f,  result(1,0));
			AssertExtension::AreEqual( 0.951950f,  result(1,1));
			AssertExtension::AreEqual( 0.0310000,  result(1,2));
			AssertExtension::AreEqual( 0.077500f, result(1,3));
			AssertExtension::AreEqual(-0.020000f,  result(2,0));
			AssertExtension::AreEqual( 0.031000f,  result(2,1));
			AssertExtension::AreEqual( 0.980000f, result(2,2));
			AssertExtension::AreEqual(-0.050000f,  result(2,3));
			AssertExtension::AreEqual(  0.f,       result(3,0));
			AssertExtension::AreEqual(  0.f,       result(3,1));
			AssertExtension::AreEqual(  0.f,       result(3,2));
			AssertExtension::AreEqual(  1.f,       result(3,3));
		}

		[TestMethod]
		void test_IntersectLinePlane_when_intersects()
		{
			// Arrange
			Point3D aPoint3D = Point3D( .750f, -.155f,  .525f);
			Vector3D aVector3D = Vector3D( -.425f, -.155f,  -.125f);
			Plane aPlane = Plane(Vector3D( .10f, -.155f,  .100f), .25f);
			Point3D resultPoint3D;

			// Act
			bool result = IntersectLinePlane(aPoint3D, aVector3D, aPlane, &resultPoint3D);

			// Assert
			Assert::AreEqual(true, result);
			AssertExtension::AreEqual(-4.759221f, resultPoint3D.x);
			AssertExtension::AreEqual(-2.164245f, resultPoint3D.y);
			AssertExtension::AreEqual(-1.095359f, resultPoint3D.z);
		}

		[TestMethod]
		void test_IntersectLinePlane_when_does_not_intersect()
		{
			// Arrange
			Point3D aPoint3D = Point3D( .0750f, 0.f,  .000000000000525f);
			Vector3D aVector3D = Vector3D( 0.f, -.0000000000255f,  -.00000000000125f);
			Plane aPlane = Plane(Vector3D( .00010f, 0.f, 0.f), .25f);
			Point3D resultPoint3D;

			// Act
			bool result = IntersectLinePlane(aPoint3D, aVector3D, aPlane, &resultPoint3D);

			// Assert
			Assert::AreEqual(false, result);
			Assert::AreEqual(0.f, resultPoint3D.x);
			Assert::AreEqual(0.f, resultPoint3D.y);
			Assert::AreEqual(0.f, resultPoint3D.z);
		}

		[TestMethod]
		void test_IntersectThreePlanes_when_intersects()
		{
			// Arrange
			Plane aPlane = Plane(Vector3D( .205f, -.155f,  .275f), .95f);
			Plane secondPlane = Plane(Vector3D( .10f, .075f,  .415f), .95f);
			Plane thirdPlane = Plane(Vector3D( -.035f, .075f,  .515f), .95f);
			Point3D resultPoint3D;

			// Act
			bool result = IntersectThreePlanes(aPlane, secondPlane, thirdPlane, &resultPoint3D);

			// Assert
			Assert::AreEqual(true, result);
			AssertExtension::AreEqual(-1.501124f, resultPoint3D.x);
			AssertExtension::AreEqual( 0.548236f, resultPoint3D.y);
			AssertExtension::AreEqual(-2.026518f, resultPoint3D.z);
		}

		[TestMethod]
		void test_IntersectThreePlanes_when_does_not_intersect()
		{
			// Arrange
			Plane aPlane = Plane(Vector3D( 0.f, -.000155f,  0.f), .0f);
			Plane secondPlane = Plane(Vector3D( .00010f, 0.f,  .415f), 0.f);
			Plane thirdPlane = Plane(Vector3D( 0.f, .075f,  0.f), .95f);
			Point3D resultPoint3D;

			// Act
			bool result = IntersectThreePlanes(aPlane, secondPlane, thirdPlane, &resultPoint3D);

			// Assert
			Assert::AreEqual(false, result);
			Assert::AreEqual(0.f, resultPoint3D.x);
			Assert::AreEqual(0.f, resultPoint3D.y);
			Assert::AreEqual(0.f, resultPoint3D.z);
		}

		[TestMethod]
		void test_Plane_Multiply_Operator_with_a_Plane_and_a_Transform4D()
		{
			// Arrange
			Plane aPlane = Plane(Vector3D( .150f, -.555f, .421f), .25f);
			Transform4D aTransform = Transform4D(Vector3D( .10f, -.155f,  .100f),
											     Vector3D(-.15f,  .125f, -.095f),
												 Vector3D( .15f, -.100f,  .110f),
											      Point3D( .20f,  .150f,  .150f));

			// Act
			Plane result = aPlane * aTransform;

			// Assert
			AssertExtension::AreEqual( 0.143125f, result.x);
			AssertExtension::AreEqual(-0.13187f, result.y);
			AssertExtension::AreEqual( 0.124310f, result.z);
			AssertExtension::AreEqual( 0.259900f, result.w);
		}

		[TestMethod]
		void test_Line_Transform_with_a_Line_and_a_Transform4D()
		{
			// Arrange
			Line aLine = Line(Vector3D( .150f, -.555f, .421f), 
							  Vector3D( .715f, -.945f, .025f));
			Transform4D aTransform = Transform4D(Vector3D( .10f, -.155f,  .100f),
											     Vector3D(-.15f,  .125f, -.095f),
												 Vector3D( .15f, -.100f,  .110f),
											      Point3D( .20f,  .150f,  .150f));

			// Act
			Line result = Transform(aLine, aTransform);

			// Assert
			AssertExtension::AreEqual( 0.161400f, result.direction.x);
			AssertExtension::AreEqual(-0.134725f, result.direction.y);
			AssertExtension::AreEqual( 0.114035f, result.direction.z);
			AssertExtension::AreEqual( 0.033746f, result.moment.x);
			AssertExtension::AreEqual( 0.006654f, result.moment.y);
			AssertExtension::AreEqual(-0.041583f, result.moment.z);
		}

		[TestMethod]
		void test_Line_XOR_Operator_with_two_Point3D_structs()
		{
			// Arrange
			Point3D firstPoint3D(.150f, -.555f, .421f);
			Point3D secondPoint3D(-.350f, .455f, -.345f);
			

			// Act
			Line result = firstPoint3D ^ secondPoint3D;

			// Assert
			AssertExtension::AreEqual(-0.5f, result.direction.x);
			AssertExtension::AreEqual( 1.009999f, result.direction.y);
			AssertExtension::AreEqual(-0.766000f, result.direction.z);
			AssertExtension::AreEqual(-8.005e-5f, result.moment.x);
			AssertExtension::AreEqual(-0.095599f, result.moment.y);
			AssertExtension::AreEqual(-0.125999f, result.moment.z);
		}

		[TestMethod]
		void test_Line_XOR_Operator_with_two_Plane_structs()
		{
			// Arrange
			Plane firstPlane = Plane(Vector3D( 0.f, -.155f,  0.485f), .585f);
			Plane secondPlane = Plane(Vector3D( .10f, .65f,  .415f), 0.645f);
			

			// Act
			Line result = firstPlane ^ secondPlane;

			// Assert
			AssertExtension::AreEqual( 0.379574f, result.direction.x);
			AssertExtension::AreEqual(-0.048500f, result.direction.y);
			AssertExtension::AreEqual(-0.015500f, result.direction.z);
			AssertExtension::AreEqual(-0.058499f, result.moment.x);
			AssertExtension::AreEqual(-0.480224f, result.moment.y);
			AssertExtension::AreEqual( 0.070050f, result.moment.z);
		}

		[TestMethod]
		void test_Plane_XOR_Operator_with_a_Line_and_Point3D()
		{
			// Arrange
			Line aLine = Line(Vector3D( .150f, -.555f, .421f), 
							  Vector3D( .715f, -.945f, .025f));
			Point3D aPoint3D(.150f, -.555f, .421f);
			

			// Act
			Plane result = aLine ^ aPoint3D;

			// Assert
			AssertExtension::AreEqual( 0.714999f, result.x);
			AssertExtension::AreEqual(-0.9449999f, result.y);
			AssertExtension::AreEqual( 0.025000f, result.z);
			AssertExtension::AreEqual(-0.642250f, result.w);
		}

		[TestMethod]
		void test_Vector4D_XOR_Operator_with_a_Point3D_and_a_Line()
		{
			// Arrange
			Line aLine = Line(Vector3D( .150f, -.555f, .421f), 
							  Vector3D( .715f, -.945f, .025f));
			Point3D aPoint3D(.150f, -.555f, .421f);
			

			// Act
			Plane result = aPoint3D ^ aLine;

			// Assert
			AssertExtension::AreEqual( 0.714999f, result.x);
			AssertExtension::AreEqual(-0.9449999f, result.y);
			AssertExtension::AreEqual( 0.025000f, result.z);
			AssertExtension::AreEqual(-0.642250f, result.w);
		}

		[TestMethod]
		void test_Plane_XOR_Operator_with_a_Line_and_a_Plane()
		{
			// Arrange
			Line aLine = Line(Vector3D( .150f, -.555f, .421f), 
							  Vector3D( .715f, -.945f, .025f));
			Plane aPlane = Plane(Vector3D( 0.f, -.155f,  0.485f), .585f);
			

			// Act
			Vector4D result = aLine ^ aPlane;

			// Assert
			AssertExtension::AreEqual(-0.366700f, result.x);
			AssertExtension::AreEqual(-0.671450f, result.y);
			AssertExtension::AreEqual( 0.135459f, result.z);
			AssertExtension::AreEqual(-0.290210f, result.w);
		}

		[TestMethod]
		void test_Plane_XOR_Operator_with_a_Plane_and_a_Line()
		{
			// Arrange
			Line aLine = Line(Vector3D( .150f, -.555f, .421f), 
							  Vector3D( .715f, -.945f, .025f));
			Plane aPlane = Plane(Vector3D( 0.f, -.155f,  0.485f), .585f);
			

			// Act
			Vector4D result = aPlane ^ aLine;

			// Assert
			AssertExtension::AreEqual(-0.366700f, result.x);
			AssertExtension::AreEqual(-0.671450f, result.y);
			AssertExtension::AreEqual( 0.135459f, result.z);
			AssertExtension::AreEqual(-0.290210f, result.w);
		}

		[TestMethod]
		void test_XOR_Operator_with_two_Line_structs()
		{
			// Arrange
			Line firstLine = Line(Vector3D( .150f, -.555f, .421f), 
								  Vector3D( .715f, -.945f, .025f));
			Line secondLine = Line(Vector3D( .715f, -.945f, .025f), 
								   Vector3D( .150f, -.555f, .421f));
			

			// Act
			float result = firstLine ^ secondLine;

			// Assert
			AssertExtension::AreEqual(-1.912640f, result);
		}

		[TestMethod]
		void test_XOR_Operator_with_a_Point_and_a_Plane()
		{
			// Arrange
			Point3D aPoint3D(.150f, -.555f, .421f);
			Plane aPlane(Vector3D( 0.f, -.155f,  0.485f), .585f);
			

			// Act
			float result = aPoint3D ^ aPlane;

			// Assert
			AssertExtension::AreEqual(0.8752099f, result);
		}

		[TestMethod]
		void test_XOR_Operator_with_a_Plane_and_a_Point()
		{
			// Arrange
			Point3D aPoint3D(.150f, -.555f, .421f);
			Plane aPlane(Vector3D( 0.f, -.155f,  0.485f), .585f);
			

			// Act
			float result = aPlane ^ aPoint3D;

			// Assert
			AssertExtension::AreEqual(-0.8752099f, result);
		}
	};	
}
