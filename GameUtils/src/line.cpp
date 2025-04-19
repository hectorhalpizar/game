#include "line.hpp"

using namespace gameutils::math;

Line::Line() : direction(0.f, 0.f, 0.f), moment(0.f, 0.f, 0.f)
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
