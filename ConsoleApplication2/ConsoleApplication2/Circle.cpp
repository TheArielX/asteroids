#include "Circle.h"
#include <iostream>

circle::circle(float x, float y, float radius)
{
	m_x = x;
	m_y = y;
	m_radius = radius;
}

bool circle::intersects(circle rhs)
{
	float diff_x = m_x - rhs.m_x;
	float diff_y = m_y - rhs.m_y;
	float d2 = (diff_x * diff_x) + (diff_y*diff_x);
	float r2;
	r2 = ((rhs.m_radius)*m_radius);
	if (r2 > d2)
	{
		return true;
	}
	else
	{
		return false;
	}
}