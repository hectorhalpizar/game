#ifndef __GAME_UTILS_TRANSFORM_4D_HPP__
#define __GAME_UTILS_TRANSFORM_4D_HPP__

#include "matrix4d.hpp"
#include "vector3d.hpp"
#include "point3d.hpp"

namespace gameutils 
{
	namespace math
	{
		struct Transform4D : Matrix4D
		{
			Transform4D();

			Transform4D(float n00, float n01, float n02, float n03,
						float n10, float n11, float n12, float n13,
						float n20, float n21, float n22, float n23);

			Transform4D(const Vector3D& a, const Vector3D& b,
						const Vector3D& c, const Point3D& p);

			Vector3D& operator [](int j);

			const Vector3D& operator [](int j) const;

			const Point3D& GetTranslation(void) const;

			void SetTranslation(const Point3D& p);
		};
	}
}


#endif // __GAME_UTILS_TRANSFORM_4D_HPP__
