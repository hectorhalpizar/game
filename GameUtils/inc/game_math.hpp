#ifndef __GAME_UTILS_MATH_H__
#define __GAME_UTILS_MATH_H__

#include "../internal/private_headers.hpp"


namespace gameutils {
	namespace math {

		void TransposeArray(float *matrix, int *rows, int *cols);

		void MultiplyMatrixAsArray(float *A, float *B, float *Result, int m, int n, int p);


		inline Vector3D operator *(const Vector3D& v, float s)
		{
			return (Vector3D(v.x * s, v.y * s, v.z * s));
		}

		inline Vector3D operator /(const Vector3D& v, float s)
		{
			s = 1.0F / s;
			return (Vector3D(v.x * s, v.y * s, v.z * s));
		}

		inline Vector3D operator -(const Vector3D& v)
		{
			return (Vector3D(-v.x, -v.y, -v.z));
		}

		inline float Magnitude(const Vector3D& v)
		{
			return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
		}

		inline Vector3D Normalize(const Vector3D& v)
		{
			return (v / Magnitude(v));
		}

		inline Vector3D operator +(const Vector3D& a, const Vector3D& b)
		{
			return (Vector3D(a.x + b.x, a.y + b.y, a.z + b.z));
		}

		inline Vector3D operator -(const Vector3D& a, const Vector3D& b)
		{
			return (Vector3D(a.x - b.x, a.y - b.y, a.z - b.z));
		}

		inline float Dot(const Vector3D& a, const Vector3D& b)
		{
			return (a.x * b.x + a.y * b.y + a.z * b.z);
		}

		inline Vector3D Cross(const Vector3D& a, const Vector3D& b)
		{
			return (Vector3D(a.y * b.z - a.z * b.y,
							 a.z * b.x - a.x * b.z,
							 a.x * b.y - a.y * b.x));
		}

		inline Vector3D Project(const Vector3D& a, const Vector3D& b)
		{
			return (b * (Dot(a, b) / Dot(b, b)));
		}

		inline Vector3D Reject(const Vector3D& a, const Vector3D& b)
		{
			return (a - b * (Dot(a, b) / Dot(b, b)));
		}

		inline Point3D operator +(const Point3D& a, const Vector3D& b)
		{
			return (Point3D(a.x + b.x, a.y + b.y, a.z + b.z));
		}

		inline Point3D operator -(const Point3D& a, const Vector3D& b)
		{
			return (Point3D(a.x - b.x, a.y - b.y, a.z - b.z));
		}

		inline Vector3D operator -(const Point3D& a, const Point3D& b)
		{
			return (Vector3D(a.x - b.x, a.y - b.y, a.z - b.z));
		}

		float DistPointLine(const Point3D& q, const Point3D& p, const Vector3D& v);

		float DistLineLine(const Point3D& p1, const Vector3D& v1,
						   const Point3D& p2, const Vector3D& v2);

		Matrix3D Inverse(const Matrix3D& M);

		Matrix3D operator *(const Matrix3D& A, const Matrix3D& B);

		Vector3D operator *(const Matrix3D& M, const Vector3D& v);

		float Determinant(const Matrix3D& M);

		Matrix3D MakeRotationX(float t);

		Matrix3D MakeRotationY(float t);

		Matrix3D MakeRotationZ(float t);

		Matrix3D MakeRotation(float t, const Vector3D& a);

		Matrix3D MakeReflection(const Vector3D& a);

		Matrix3D MakeInvolution(const Vector3D& a);

		Matrix3D MakeScale(float sx, float sy, float sz);

		Matrix3D MakeScale(float s, const Vector3D& a);

		Matrix3D MakeSkew(float t, const Vector3D& a, const Vector3D& b);

		Matrix4D Inverse(const Matrix4D& M);

		Transform4D Inverse(const Transform4D& H);

		Transform4D operator *(const Transform4D& A, const Transform4D& B);

		Vector3D operator *(const Transform4D& H, const Vector3D& v);

		Point3D operator *(const Transform4D& H, const Point3D& p);

		Vector3D operator *(const Vector3D& n, const Transform4D& H);

		Quaternion operator *(const Quaternion& q1, const Quaternion& q2);

		Vector3D Transform(const Vector3D& v, const Quaternion& q);

		float Dot(const Plane& f, const Vector3D& v);

		float Dot(const Plane& f, const Point3D& p);

		Transform4D MakeReflection(const Plane& f);

		bool IntersectLinePlane(const Point3D& p, const Vector3D& v,
								const Plane& f, Point3D *q);

		bool IntersectThreePlanes(const Plane& f1, const Plane& f2,
								  const Plane& f3, Point3D *p);

		bool IntersectTwoPlanes(const Plane& f1, const Plane& f2,
								Point3D *p, Vector3D *v);

		Plane operator *(const Plane& f, const Transform4D& H);

		Line Transform(const Line& line, const Transform4D& H);

		inline Line operator ^(const Point3D& p, const Point3D& q)
		{
			return (Line(q.x - p.x, q.y - p.y, q.z - p.z,
			  p.y * q.z - p.z * q.y, p.z * q.x - p.x * q.z, p.x * q.y - p.y * q.x));
		}

		inline Line operator ^(const Plane& f, const Plane& g)
		{
			return (Line(f.z * g.y - f.y * g.z,
						 f.x * g.z - f.z * g.x,
						 f.y * g.x - f.x * g.y,
						 f.x * g.w - f.w * g.x,
						 f.y * g.w - f.w * g.y,
						 f.z * g.w - f.w * g.z));
		}

		inline Plane operator ^(const Line& L, const Point3D& p)
		{
			return (Plane(L.direction.y * p.z - L.direction.z * p.y + L.moment.x,
						  L.direction.z * p.x - L.direction.x * p.z + L.moment.y,
						  L.direction.x * p.y - L.direction.y * p.x + L.moment.z,
						 -L.moment.x * p.x - L.moment.y * p.y - L.moment.z * p.z));
		}

		inline Plane operator ^(const Point3D& p, const Line& L)
		{
			return (L ^ p);
		}

		inline Vector4D operator ^(const Line& L, const Plane& f)
		{
			return (Vector4D(
				  L.moment.y * f.z - L.moment.z * f.y + L.direction.x * f.w,
				  L.moment.z * f.x - L.moment.x * f.z + L.direction.y * f.w,
				  L.moment.x * f.y - L.moment.y * f.x + L.direction.z * f.w,
				 -L.direction.x * f.x - L.direction.y * f.y - L.direction.z * f.z));
		}

		inline Vector4D operator ^(const Plane& f, const Line& L)
		{
			return (L ^ f);
		}

		inline float operator ^(const Line& L1, const Line& L2)
		{
			return (-(Dot(L1.direction, L2.moment) + Dot(L2.direction, L1.moment)));
		}

		inline float operator ^(const Point3D& p, const Plane& f)
		{
			return (p.x * f.x + p.y * f.y + p.z * f.z + f.w);
		}

		inline float operator ^(const Plane& f, const Point3D& p)
		{
			return (-(p ^ f));
		}
	};
};

#endif // __GAME_UTILS_MATH_H__