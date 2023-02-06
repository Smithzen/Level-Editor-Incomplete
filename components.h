#pragma once
#include "common.h"
//components that may be given to entities as needed
//Ctransform will allow entities to move or not
class CTransform
{
public:
	sf::Vector2f pos = { 0.0, 0.0 };
	Vec2 velocity = { 0.0, 0.0 };
	float angle = 0;

	CTransform(const sf::Vector2f& p, const Vec2& v, float a)
		:pos(p), velocity(v), angle(a) {}

};

//Cshape will give a base shape of either a circle or a rectangle to entities
//circle can be given points to look like any regular polygon however they are still circles of the radius given
class CShape
{
public:
	sf::CircleShape circle;

	CShape(float radius, int points, const sf::Color& fill, const sf::Color& outline, float thickness)
		: circle(radius, points)
	{
		circle.setOutlineColor(outline);
		circle.setFillColor(fill);
		circle.setOutlineThickness(thickness);
		circle.setOrigin(radius, radius);
	}

	sf::RectangleShape rectangle;

	CShape(sf::Vector2f size)
		: rectangle(size)
	{
		rectangle.setOrigin(25, 25);
	}

	sf::Sprite sprite;

	CShape()
	{
		sprite.setOrigin(12, 12);
	}

};


class CCollision
{
public:
	float radius = 0;
	CCollision(float r)
		:radius(r) {}

	Vec2 collision_rect = Vec2(25, 25);
	CCollision(Vec2 col_rect)
		:collision_rect(col_rect) {}
};



class CInput
{
public:
	bool up = false;
	bool left = false;
	bool right = false;
	bool down = false;

	CInput() {}
};

class CGravity
{
public:
	Vec2 acceleration = Vec2(0, 0.5f);
	CGravity(Vec2 a)
		:acceleration(a) {}
};