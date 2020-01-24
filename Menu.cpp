#include "Menu.h"
#include "Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

Menu::Menu(float width, float height)
{
	if (!czcionka.loadFromFile("Czcionki/font.ttf"))
	{
		cout << "Blad" << endl;
	}
	menu[0].setFont(czcionka);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("Graj");
	menu[0].setPosition(Vector2f(width / 2, height / (maksymalna_liczba_opcjii + 1) * 1));

	menu[1].setFont(czcionka);
	menu[1].setFillColor(Color::White);
	menu[1].setString("Options");
	menu[1].setPosition(Vector2f(width / 2, height / (maksymalna_liczba_opcjii + 1) * 2));

	menu[2].setFont(czcionka);
	menu[2].setFillColor(Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(Vector2f(width / 2, height / (maksymalna_liczba_opcjii + 1) * 3));

	wybrana_opcja = 0;
}

Menu::~Menu() {}

int Menu::przycisk(Event event, RenderWindow* window)
{
	if (event.key.code == Keyboard::Up)
	{
		doGory();
		return 0;
	}
	if (event.key.code == Keyboard::Down)
	{
		doDolu();
		return 0;
	}
	if (event.key.code == Keyboard::Return)
	{
		if (wybrana_opcja == 0)
		{
			//window->close();
			return 1;
		}
		if (wybrana_opcja == 1)
		{
			cout << "OPCJUJEMY" << endl;
			return 0;
		}
		if (wybrana_opcja == 2)
		{
			window->close();
			return 0;
		}
	}
}

void Menu::rysuj(RenderWindow* window)
{
	for (int i = 0; i < maksymalna_liczba_opcjii; i++)
	{
		window->draw(menu[i]);
	}
}

void Menu::doGory()
{
	if (wybrana_opcja - 1 >= 0)
	{
		menu[wybrana_opcja].setFillColor(Color::White);
		wybrana_opcja--;
		menu[wybrana_opcja].setFillColor(Color::Red);
	}
}

void Menu::doDolu()
{
	if (wybrana_opcja - 1 <= 0)
	{
		menu[wybrana_opcja].setFillColor(Color::White);
		wybrana_opcja++;
		menu[wybrana_opcja].setFillColor(Color::Red);
	}
}
