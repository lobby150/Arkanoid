// Arkanoid.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include "Ball.h"
#include"Paletka.h"
#include"Block.h"
#include<algorithm>
#include<iostream>
#include<conio.h>
#include"Menu.h"
#include<Windows.h>
using namespace sf;
using namespace std;

template <class T1, class T2> bool isIntersecting(T1& A, T2& B)
{
	return A.right() >= B.left() && A.left() <= B.right() && A.bottom() >= B.top() && A.top() <= B.bottom();
}
bool kolizja(Paletka& paletka, Ball& ball)
{
	if (!isIntersecting(paletka, ball)) return false;
	
	ball.moveUp();

	if (ball.getPosition().x < paletka.getPosition().x)
	{
		ball.moveLeft();
	}
	else if (ball.getPosition().x > paletka.getPosition().x)
	{
		ball.moveRight();
	}
	else if (ball.getPosition().x == paletka.getPosition().x)
	{
		ball.moveUp();
	}
	
}

bool kolizja(Block& block, Ball& ball)
{
	if (!isIntersecting(block, ball)) return false;
	

	block.destroy();

	float left{ ball.right() - block.left() };
	float right{ block.right() - ball.left() };
	float top{ ball.bottom() - block.top() };
	float bottom{ block.bottom() - ball.top() };

	bool fromLeft(abs(left) < abs(right));
	bool fromTop(abs(top) < abs(bottom));

	float fromWhichX{ fromLeft ? left : right };
	float fromWhichY{ fromTop ? top : bottom };

	if (abs(fromWhichX) < abs(fromWhichY))
	{
		fromLeft ? ball.moveLeft() : ball.moveRight();
	}
	else {
		fromTop ? ball.moveUp() : ball.moveDown();

	}

}


int main()
{
	RenderWindow window{ VideoMode{800,600}, "Arkanoid - Kubiak Marcin " };
	window.setFramerateLimit(60);
	Menu menu(window.getSize().x, window.getSize().y);
	Event event;
	Texture menju;
	Sprite MENU1;
	menju.loadFromFile("arcanoid.png");
	MENU1.setTexture(menju);
	while (true)
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::KeyReleased:

				switch (event.key.code)
				{
				case Keyboard::Up:
					menu.MoveUp();
					break;
				case Keyboard::Down:
					menu.MoveDown();
					break;
					
				case Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
					{
						int liczba = 12, IloscZderzen = 50;
						cout << "Wcisnieto Graj, powodzenia " << endl;
						cout << "Twoja liczba zyc to: " << liczba << endl;
						unsigned blocksX{ 10 }, blocksY{ 5 }, blockWidth{ 60 }, blockHeight{ 20 };
						Ball ball(400, 300);
						Ball ball1(378, 280);
						Paletka paletka(600, 550);
						vector<Block> blocks;


						for (int i = 0; i < blocksY; i++)
						{
							for (int j = 0; j < blocksX; j++)
							{
								blocks.emplace_back((j + 1)*(blockWidth + 10), (i + 2)*(blockHeight + 5), blockWidth, blockHeight);
							}
						}


						Texture tekstura;
						tekstura.loadFromFile("arka.jpg");
						Sprite sprajt;
						Sprite loser;
						Texture porazka;
						porazka.loadFromFile("lostthegamecopy.png");
						
						sprajt.setTexture(tekstura);

						Texture win;
						Sprite winner;
						win.loadFromFile("win_big.png");

						while (window.isOpen())
						{
							window.clear();
							window.draw(sprajt);
							window.pollEvent(event);

							if (event.type == Event::Closed)
							{
								window.close();
								break;
							}
							
							ball.update();
							ball1.update();
							paletka.update();
							kolizja(paletka, ball);
							kolizja(paletka, ball1);
						
							

							for (auto& block : blocks)
							{
								if (kolizja(block, ball)|| kolizja(block,ball1))
								{
									IloscZderzen--;
									cout << "Pozostala ilosc klockow: " << IloscZderzen << endl;
								}
							}
							if (IloscZderzen == 0)
							{
								cout << "WYGRALES! GRATULACJE ";
								window.clear();
								winner.setTexture(win);
								window.draw(winner);
								window.display();
								Sleep(5000);
								break;
							}
						

							auto iterator = remove_if(begin(blocks), end(blocks), [](Block&block) {return block.isDestroyed(); });
							blocks.erase(iterator, end(blocks));

							
							window.draw(ball);
							window.draw(ball1);
							window.draw(paletka);

							for (auto& block : blocks)
							{
								window.draw(block);
							}
						
							window.display();
							if (ball.getPosition().x <800 && ball.getPosition().y==592 || (ball1.getPosition().x<800 && ball1.getPosition().y==592))
							{
								liczba--;
								cout << "OUCH, TWOJA LICZBA ZYC TO: " << liczba << endl;
								
							}
					
							if (liczba == 0)
							{
								cout << "PRZEGRALES! "; 
								window.clear();
								loser.setTexture(porazka);
								window.draw(loser);
								window.display();
								Sleep(5000);
								break;
							}
						}
					}
						break;
					case 1:
					{
						cout << "Wyszedles ";
						window.close();
						break;
					 }
						}
				}

				break;
			case Event::Closed:
					window.close();
					break;
			}
		 }
		window.clear();
		window.draw(MENU1);
		menu.draw(window);
		window.display();
		
	}





    return 0;
}

