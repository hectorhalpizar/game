#include "game_utils.hpp"
#include "game_math.hpp"
#include <math.h>

using namespace gameutils::math;

namespace gameutils {
	Matrix4D MakePerspectiveProjectionTransform(PerspectiveProjection& p, float Width, float Height)
	{
		float ar         = Height / Width;
		float zRange     = p.zNear - p.zFar;
		float tanHalfFOV = tanf(ToRadian(p.FOV / 2.0f));

		Matrix4D result(1.F / tanHalfFOV, 0.F,                    0.F,                        0.F,
						0.F,              1.0F / (tanHalfFOV*ar), 0.F,                        0.F,
						0.F,              0.F,                    (-p.zNear - p.zFar)/zRange, 2.F * p.zFar * p.zNear / zRange,
						0.F,              0.F,                    1.F,                        0.F);

		return result;
	}
}
