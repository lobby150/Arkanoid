#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Paletka : public sf:: Drawable
{
public:
	Paletka(float t_X, float t_Y);
	Paletka() = delete;
	~Paletka() = default;
	void update();
	float left();
	float right();
	float top();
	float bottom();

	Vector2f getPosition();
private:
	RectangleShape shape;
	const float width{ 80.0f }; 
	const float height{ 20.0f };
	const float PalVelo{ 20.0f };
	Vector2f velo{ PalVelo, 0.f };
	void draw(RenderTarget& target, RenderStates state) const override;

};

