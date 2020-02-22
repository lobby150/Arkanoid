#include "stdafx.h"
#include "Ball.h"
using namespace sf;
using namespace std;

Ball::Ball(float X, float Y)
{
	shape.setPosition(X, Y);
	shape.setRadius(this->Radius);
	shape.setFillColor(Color::Green);
    shape.setOrigin(this->Radius, this->Radius);

 }

void Ball::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

void Ball::update()
{
	shape.move(this->velo);

	if (this->left() < 0)
	{
		velo.x = ballVelo;
	}
	else if (this->right() > 800)
	{
		velo.x = -ballVelo;
	}

	if (this->top() < 0)
	{
		velo.y = ballVelo;
	}
	else if (this->bottom() > 600)
	{
		velo.y = -ballVelo;
	}
}

float Ball::left()
{
	return this->shape.getPosition().x - shape.getRadius();
}

float Ball::right()
{
	return this->shape.getPosition().x + shape.getRadius();
}

float Ball::top()
{
	return this->shape.getPosition().y - shape.getRadius();
}

float Ball::bottom()
{
	return this->shape.getPosition().y + shape.getRadius();
}

void Ball::moveDown()
{
	this->velo.y = ballVelo;
}
void Ball::moveUp() {
	this->velo.y = -ballVelo;
}
void Ball::moveRight() {
	this->velo.x = ballVelo;
}
void Ball::moveLeft(){
	this->velo.x = -ballVelo;
}

Vector2f Ball::getPosition()
{
	return shape.getPosition();
}