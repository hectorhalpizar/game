#ifndef __GAME_UTILS_WORLD_TRANSFORM_HPP__
#define __GAME_UTILS_WORLD_TRANSFORM_HPP__

#include "game_math.hpp"

using namespace gameutils::math;

namespace gameutils {

	class WorldTransform {
		public:
			WorldTransform() { }

			void SetScale(float scale);
			void SetRotation(float x, float y, float z);
			void SetPosition(float x, float y, float z);

			void Rotate(float x, float y, float z);

			Matrix4D GetMatrix();

		private:
			float m_scale;
			Vector3D m_rotation;
			Vector3D m_pos;
	};
};

#endif // __GAME_UTILS_WORLD_TRANSFORM_HPP__