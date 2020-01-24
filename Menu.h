#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;

const int maksymalna_liczba_opcjii = 3;

class Menu
{
	const int maksymalna_liczba_opcjii = 3;
	int wybrana_opcja;
	Font czcionka;
	Text menu[3];

public:
	Menu(float wifth, float height);
	~Menu();

	void rysuj(RenderWindow* window);
	void doGory();
	void doDolu();
	int przycisk(Event event, RenderWindow* window);
};

