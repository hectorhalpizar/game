#ifndef __GAME_UTILS_QUATERNION_HPP__
#define __GAME_UTILS_QUATERNION_HPP__

#include "vector3d.hpp"
#include "matrix3d.hpp"

namespace gameutils {
	namespace math {
		struct Quaternion
		{
			float		x, y, z, w;

			Quaternion();

			Quaternion(float a, float b, float c, float s);

			Quaternion(const Vector3D& v, float s);

			Vector3D& GetVectorPart(void);

			const Vector3D& GetVectorPart(void) const;

			Matrix3D GetRotationMatrix(void);

			void SetRotationMatrix(const Matrix3D& m);
		};
	}
}


#endif // __GAME_UTILS_QUATERNION_HPP__