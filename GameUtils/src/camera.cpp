#include "camera.hpp"
#include "game_math.hpp"
#include <cassert>

using namespace gameutils;

Matrix4D InitCameraTransform(Vector3D& Target, Vector3D& Up)
{
	Vector3D UpNorm = Normalize(Up);

	Vector3D N = Normalize(Target);
	Vector3D U = Normalize(Cross(UpNorm, N));
	Vector3D V = Cross(N, U);

	Point3D Origin;

	Matrix4D m;
    m[0][0] = U.x;   m[0][1] = U.y;   m[0][2] = U.z;   m[0][3] = 0.0f;
    m[1][0] = V.x;   m[1][1] = V.y;   m[1][2] = V.z;   m[1][3] = 0.0f;
    m[2][0] = N.x;   m[2][1] = N.y;   m[2][2] = N.z;   m[2][3] = 0.0f;
    m[3][0] = 0.0f;  m[3][1] = 0.0f;  m[3][2] = 0.0f;  m[3][3] = 1.0f;

	return m;
}

Camera::Camera() 
{
	m_pos = Vector3D(0.F, 0.F, 0.F);
	m_target = Vector3D(0.F, 0.F, 1.F);
	m_up = Vector3D(0.F, 1.F, 0.F);
	m_speed = 1.F;
}

void Camera::SetPosition(float x, float y, float z)
{
    m_pos.x = x;
    m_pos.y = y;
    m_pos.z = z;
}

void Camera::Maniputale(Action CameraAction)
{
	switch (CameraAction) {
		case MOVE_UP:
			m_pos += (m_target * m_speed);
			break;

		case MOVE_DOWN:
			m_pos -= (m_target * m_speed);
			break;

		case MOVE_LEFT:
			{
				Vector3D Left = Cross(m_up, m_target);
				Left = Normalize(Left);
				Left *= m_speed;
				m_pos += Left;
			}
			break;

		case MOVE_RIGHT:
			{
				Vector3D Right = Cross(m_target, m_up);
				Right = Normalize(Right);
				Right *= m_speed;
				m_pos += Right;
			}
			break;

		case MOVE_FORWARD:
			m_pos.y += m_speed;
			break;

		case MOVE_BACKWARD:
			m_pos.y -= m_speed;
			break;

		case SPEED_UP:
			m_speed += 0.1f;
			// printf("Speed changed to %f\n", m_speed);
			break;

		case SPEED_DOWN:
			m_speed -= 0.1f;
			if (m_speed < 0.1f) {
				m_speed = 0.1f;
			}
			// printf("Speed changed to %f\n", m_speed);
			break;
    }
}

Matrix4D Camera::GetMatrix()
{
	Transform4D CameraTranslation = MakeMove(-m_pos.x, -m_pos.y, -m_pos.z);

	Matrix4D CameraRotateTrans = InitCameraTransform(m_target, m_up);

	Matrix4D Result = CameraRotateTrans * CameraTranslation;

	return Result;
}
