#ifndef __GAME_UTILS_TESTS_MOCK_CAMERA_HPP__
#define __GAME_UTILS_TESTS_MOCK_CAMERA_HPP__

namespace gameutils {
	class MockCamera : public Camera {
		public: 
			void SetPosition(Vector3D& pos)
			{
				m_pos = pos;
			}

			void SetTarget(Vector3D& target)
			{
				m_target = target;
			}

			void SetUp(Vector3D& up)
			{
				m_up = up;
			}

			void SetSpeed(float speed)
			{
				m_speed = speed;
			}

			Vector3D GetPosition()
			{
				return m_pos;
			}

			float GetSpeed()
			{
				return m_speed;
			}
	};
};

#endif // __GAME_UTILS_TESTS_MOCK_CAMERA_HPP__
