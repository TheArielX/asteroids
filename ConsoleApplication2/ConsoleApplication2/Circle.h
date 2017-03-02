#pragma once
#ifndef _CIRCLE_H_

class circle
{
public:
	circle(float x, float y, float radius);
	bool intersects(circle rhs);
private:
	float m_radius;
	float m_x;
	float m_y;

};
#endif //!_CIRCLE_H_