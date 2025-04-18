#ifndef __GAME_UTILS_VECTOR3D_HPP__
#define __GAME_UTILS_VECTOR3D_HPP__

#include <math.h>

namespace gameutils {
	namespace math {
		struct Vector3D
		{
			float		x, y, z;

			Vector3D();

			Vector3D(float a, float b, float c);

			float& operator [](int i);

			const float& operator [](int i) const;

			Vector3D& operator *=(float s);

			Vector3D& operator /=(float s);

			Vector3D& operator +=(const Vector3D& v);

			Vector3D& operator -=(const Vector3D& v);

			private:
				void init(float x, float y, float z);
		};
	}
}
#endif // __GAME_UTILS_VECTOR3D_HPP__
