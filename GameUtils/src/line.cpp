#include "line.hpp"

using namespace gameutils::math;

Line::Line()
{
}

Line::Line(float vx, float vy, float vz, float mx, float my, float mz) :
		direction(vx, vy, vz), moment(mx, my, mz)
{
}

Line::Line(const Vector3D& v, const Vector3D& m)
{
	direction = v;
	moment = m;
}
