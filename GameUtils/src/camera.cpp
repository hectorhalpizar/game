#include "camera.hpp"
#include "game_math.hpp"
#include <cassert>

using namespace gameutils;

Transform4D InitCameraTransform(Vector3D& Target, Vector3D& Up)
{
	Vector3D UpNorm = Normalize(Up);

	Vector3D N = Normalize(Target);
	Vector3D U = Normalize(Cross(UpNorm, N));
	Vector3D V = Cross(N, U);

	Point3D Origin;

	Transform4D result(U, V, N, Origin);

	return result;
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
				Vector3D Left = Cross(m_target, m_up);
				Left = Normalize(Left);
				Left *= m_speed;
				m_pos += Left;
			}
			break;

		case MOVE_RIGHT:
			{
				Vector3D Right = Cross(m_up, m_target);
				Right = Normalize(Right);
				Right *= m_speed;
				m_pos += Right;
			}
			break;

		case PAGE_UP:
			m_pos.y += m_speed;
			break;

		case PAGE_DOWN:
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

	Transform4D CameraRotateTrans = InitCameraTransform(m_target, m_up);

	Transform4D Result = CameraRotateTrans * CameraTranslation;

	return Result;
}
