#include "stdafx.h"
#include<iostream>
#include "Menu.h"
using namespace sf;
using namespace std;

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		cout << "Blad ";
	}

	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("Graj");
	menu[0].setPosition(Vector2f(width / 2.3f, height /3 * 1));


	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setString("Wyjdz");
	menu[1].setPosition(Vector2f(width / 2.3f, height/3 * 2));


	
	selectedItemIndex=0;
}




Menu::~Menu()
{
}

void Menu::draw(RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}
void Menu::MoveUp() {
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}
void Menu::MoveDown() {
	if (selectedItemIndex + 1 <MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}