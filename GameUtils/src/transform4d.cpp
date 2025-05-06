#include "../internal/transform4d.hpp"

using namespace gameutils::math;

Transform4D::Transform4D()
{
	n[0][0] = 0.F; n[0][1] = 0.F; n[0][2] = 0.F;
	n[1][0] = 0.F; n[1][1] = 0.F; n[1][2] = 0.F;
	n[2][0] = 0.F; n[2][1] = 0.F; n[2][2] = 0.F;
	n[3][0] = 0.F; n[3][1] = 0.F; n[3][2] = 0.F;

	n[0][3] = n[1][3] = n[2][3] = 0.0F;
	n[3][3] = 1.0F;
}

Transform4D::Transform4D(float n00, float n01, float n02, float n03,
						 float n10, float n11, float n12, float n13,
						 float n20, float n21, float n22, float n23)
{
	n[0][0] = n00; n[0][1] = n01; n[0][2] = n02; n[0][3] = n03;
	n[1][0] = n10; n[1][1] = n11; n[1][2] = n12; n[1][3] = n13;
	n[2][0] = n20; n[2][1] = n21; n[2][2] = n22; n[2][3] = n23;
	n[3][0] = 0.F; n[3][1] = 0.F; n[3][2] = 0.F; n[3][3] = 1.F;

}

Transform4D::Transform4D(const Vector3D& a, const Vector3D& b,
						 const Vector3D& c, const Point3D& p)
{
	n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z; n[0][3] = p.x;
	n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z; n[1][3] = p.y;
	n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z; n[2][3] = p.z;
	n[3][0] = 0.F; n[3][1] = 0.F; n[3][2] = 0.F; n[3][3] = 1.F;
}

Vector3D& Transform4D::operator [](int j)
{
	return (*reinterpret_cast<Vector3D *>(n[j]));
}

const Vector3D& Transform4D::operator [](int j) const
{
	return (*reinterpret_cast<const Vector3D *>(n[j]));
}

const Point3D& Transform4D::GetTranslation(void) const
{
	return (*reinterpret_cast<const Point3D *>(n[3]));
}

void Transform4D::SetTranslation(const Point3D& p)
{
	n[3][0] = p.x;
	n[3][1] = p.y;
	n[3][2] = p.z;
}
