#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;
using namespace std;
class Ball: public sf::Drawable
{
public:
	Ball(float X, float Y);
	Ball() = delete;
	~Ball() = default;
	void update();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	Vector2f getPosition();


	float left();
	float right();
	float top();
	float bottom();
private:
	CircleShape shape;
	const float Radius{ 10.0f };
	const float ballVelo{ 3.1f };
	Vector2f velo{ ballVelo, ballVelo };
	void draw(RenderTarget& target, RenderStates state) const override;

};
