#include "world_transform.hpp"
#include "transformation.h"
#include <game_math.hpp>

using namespace gameutils;
using namespace gameutils::math;

void WorldTransform::SetScale(float scale)
{
	m_scale = scale;
}

void WorldTransform::SetRotation(float x, float y, float z)
{
	m_rotation.x = x;
	m_rotation.y = y;
	m_rotation.z = z;
}

void WorldTransform::SetPosition(float x, float y, float z)
{
	m_pos.x = x;
	m_pos.y = y;
	m_pos.z = z;
}

void WorldTransform::Rotate(float x, float y, float z)
{
	m_rotation.x += x;
	m_rotation.y += y;
	m_rotation.z += z;
}

Matrix4D WorldTransform::GetMatrix()
{
	Point3D _ZeroPoint3D;

	// This is the scale in column-major order.
	Matrix3D _Scale3D = MakeScale(m_scale, m_scale, m_scale);
	Transform4D Scale(_Scale3D[0], _Scale3D[1], _Scale3D[2], _ZeroPoint3D);

	// This is the rotation in column-major order
	Matrix3D _RotationOnX = MakeRotationX(ToRadian(m_rotation.x));
	Matrix3D _RotationOnY = MakeRotationY(ToRadian(m_rotation.y));
	Matrix3D _RotationOnZ = MakeRotationZ(ToRadian(m_rotation.z));
	Matrix3D _Rotation3D = _RotationOnX *_RotationOnY * _RotationOnZ;
	// Matrix3D _Rotation3D = _RotationOnZ *_RotationOnY * _RotationOnX;
	Transform4D Rotation(_Rotation3D[0], _Rotation3D[1], _Rotation3D[2], _ZeroPoint3D);

	// This is the translation column-major order
	Transform4D Translation(1.f, 0.f, 0.f, m_pos.x,
							0.f, 1.f, 0.f, m_pos.y,
							0.f, 0.f, 1.f, m_pos.z);
    Transform4D Result = Translation * Rotation * Scale;

    return Result;
}