#ifndef __GAME_UTILS_POINT3D_HPP__
#define __GAME_UTILS_POINT3D_HPP__

#include "vector3d.hpp"

namespace gameutils {
	namespace math {
		struct Point3D : public Vector3D
		{
			Point3D();

			Point3D(float a, float b, float c);

			Point3D& operator =(const Vector3D& v);
		};
	}
}

#endif // __GAME_UTILS_POINT3D_HPP__