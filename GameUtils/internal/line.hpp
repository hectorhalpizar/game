#ifndef __GAME_UTILS_LINE_HPP__
#define __GAME_UTILS_LINE_HPP__

#include "vector3d.hpp"

namespace gameutils {
	namespace math {
		struct Line
		{
			Vector3D	direction;
			Vector3D	moment;

			Line();

			Line(float vx, float vy, float vz, float mx, float my, float mz);

			Line(const Vector3D& v, const Vector3D& m);
		};
	}
}

#endif // __GAME_UTILS_LINE_HPP__