#include "common.h"
#include "vec2.h"



Vec2::Vec2() {}

Vec2::Vec2(float xin, float yin)
	:x(xin), y(yin)
{}
//defining all operators for Vec2 classes
bool Vec2::operator == (const Vec2& rhs) const { return (x == rhs.x) && (y == rhs.y);}
bool Vec2::operator != (const Vec2& rhs) const { return (x != rhs.x) && (y != rhs.y);}

Vec2 Vec2::operator + (const Vec2& rhs) const  { return Vec2(x + rhs.x, y + rhs.y);}
Vec2 Vec2::operator - (const Vec2& rhs) const  { return Vec2(x - rhs.x, y - rhs.y);}
Vec2 Vec2::operator * (const Vec2& rhs) const  { return Vec2(x * rhs.x, y * rhs.y);}
Vec2 Vec2::operator / (const Vec2& rhs) const  { return Vec2(x / rhs.x, y / rhs.y);}

void Vec2::operator += (const Vec2& rhs)       { x += rhs.x; y += rhs.y;}
void Vec2::operator -= (const Vec2& rhs)       { x -= rhs.x; y -= rhs.y;}
void Vec2::operator *= (const Vec2& rhs)       { x *= rhs.x; y *= rhs.y;}
void Vec2::operator /= (const Vec2& rhs)       { x /= rhs.x; y /= rhs.y;}

//function to get the distance between 2 vectors and returns a scalar
float Vec2::dist(const Vec2& rhs) const
{
	float x2 = ((x + rhs.x) * (x + rhs.x));
	float y2 = ((y + rhs.y) * (y + rhs.y));
	return sqrtf(x2 + y2);
}