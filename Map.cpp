#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Menu.h"
#include "Game.h"
#include "Entity.h"

using namespace std;
using namespace sf;

Map::Map()
{
	tablica[27][30] = { 0 };
}

void Map::zaladuj(string sciezka_mapy)
{
	ifstream tablica_mapy(sciezka_mapy);
	int x = 0, y = 0;
	while (!tablica_mapy.eof())
	{
		char blok;
		tablica_mapy >> blok;
		tablica[x][y] = blok - '0';
		if (tablica_mapy.peek() == '\n')
		{
			x++;
			y = 0;
		}
		else
		{
			y++;
		}
	}
	tekstura.loadFromFile("Grafika/tileMap.png");
	klatka.setTexture(&tekstura);
}

void Map::rysuj(RenderWindow* ingame)
{
	for (int x = 0; x < 28; x++)
	{
		for (int y = 0; y < 31; y++)
		{
			if (tablica[x][y] != 0)
			{
				klatka.setPosition(x * 16, y * 16);
				klatka.setTextureRect(IntRect((tablica[x][y] - 1) * 16, 0, 16, 16));
				ingame->draw(klatka);
			}
		}
	}
}

void Map::punkty(int& punkty)
{
	for (int x = 0; x < 28; x++)
	{
		for (int y = 0; y < 31; y++)
		{
			if (tablica[x][y] == 2)
			{
				punkty++;
			}
		}
	}
}

int Map::sciana(Vector2f pozycja)
{
	return tablica[(int)pozycja.x / 16][(int)pozycja.y / 16];
}

void Map::usun_punkt(Vector2f pozycja)
{
	tablica[(int)pozycja.x / 16][(int)pozycja.y / 16] = 0;
}

Map::~Map() {}
