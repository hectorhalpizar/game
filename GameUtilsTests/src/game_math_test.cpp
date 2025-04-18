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
	};	
}
