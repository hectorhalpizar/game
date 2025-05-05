#ifndef __GAME_UTILS_CAMERA_HPP__
#define __GAME_UTILS_CAMERA_HPP__

#include "game_math.hpp"

using namespace gameutils::math;

namespace gameutils {

	class Camera {
		public:

			enum Action {
				MOVE_UP,
				MOVE_DOWN,
				MOVE_LEFT,
				MOVE_RIGHT,
				MOVE_FORWARD,
				MOVE_BACKWARD,
				SPEED_UP,
				SPEED_DOWN
			};

			Camera();

			void SetPosition(float x, float y, float z);

			void Maniputale(Action cameraAction);

			Matrix4D GetMatrix();

		protected:
			Vector3D m_pos;
			Vector3D m_target;
			Vector3D m_up;
			float m_speed;
	};
};
#endif // __GAME_UTILS_CAMERA_HPP__