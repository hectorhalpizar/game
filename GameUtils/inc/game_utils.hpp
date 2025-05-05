#ifndef __GAME_UTILS_HPP__
#define __GAME_UTILS_HPP__

#include "game_math.hpp"
#include "../internal/perspective_projection.hpp"

using namespace gameutils::math;

namespace gameutils
{
	Matrix4D MakePerspectiveProjectionTransform(PerspectiveProjection& p, float Width, float Height);
};

#endif // __GAME_UTILS_HPP__