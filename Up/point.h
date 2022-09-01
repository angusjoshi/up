#pragma once
class Point
{
public:
	Point()
		:x(0), y(0)
	{
	}
	Point(float _x, float _y)
		:x(_x), y(_y)
	{
	}
	float x;
	float y;
	Point& operator=(const Point& other)
	{
		x = other.x;
		y = other.y;
		return *this;
	}
	Point operator+(const Point& other)
	{
		return Point(x + other.x, y + other.y);
	}
	Point operator*(float i)
	{
		return Point(x * i, y * i);
	}

};