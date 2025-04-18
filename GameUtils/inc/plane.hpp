#ifndef __GAME_UTILS_PLANE_HPP__
#define __GAME_UTILS_PLANE_HPP__

#include "vector3d.hpp"

namespace gameutils {
	namespace math {
		struct Plane
		{
			float		x, y, z, w;

			Plane();

			Plane(float nx, float ny, float nz, float d);

			Plane(const Vector3D& n, float d);

			const Vector3D& GetNormal(void) const;
		};
	}
}


#endif // __GAME_UTILS_PLANE_HPP__