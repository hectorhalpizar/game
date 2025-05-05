#ifndef __GAME_UTILS_PERSPECTIVE_PROJECTION_HPP__
#define __GAME_UTILS_PERSPECTIVE_PROJECTION_HPP__

namespace gameutils
{
	struct PerspectiveProjection
	{
		float FOV;
		float zNear;
		float zFar;

		PerspectiveProjection()
		{
			FOV = 0.F;
			zNear = 0.F;
			zFar = 0.F;
		}

		PerspectiveProjection(float FOV, float zNear, float zFar)
		{
			this->FOV = FOV;
			this->zNear = zNear;
			this->zFar = zFar;
		}
	};
};

#endif // __GAME_UTILS_PERSPECTIVE_PROJECTION_HPP__
