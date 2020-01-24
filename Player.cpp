#include "Player.h"
#include "Game.h"
#include "Menu.h"
#include "Map.h"
#include "Entity.h"
#include "Player.h"
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#define M_PI 3.14159265358979323846

using namespace sf;
using namespace std;

Player::Player() {}

Player::~Player() {}

void Player::ustaw_pacmana(Map* mapa_gry, string sciezka_tekstury, Vector2f pozycja)
{
	ustaw_postac(mapa_gry, sciezka_tekstury, pozycja);
	obiekt.setTextureRect(IntRect(0, 0, 16, 16));
}

void Player::zaktualizuj(int& punkty, Vector2f pozycja_potwora, int& kolizja)
{
	if (Vector2f(obiekt.getPosition().x / 16, obiekt.getPosition().y / 16) == Vector2f(pozycja_potwora.x / 16, pozycja_potwora.y / 16))
	{
		kolizja = 1;
	}

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		ustawKierunek(Vector2f(-1, 0));
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		ustawKierunek(Vector2f(1, 0));
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		ustawKierunek(Vector2f(0, -1));
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		ustawKierunek(Vector2f(0, 1));
	}

	ruch();

	if (map->sciana(obiekt.getPosition()) == 2)
	{
		map->usun_punkt(obiekt.getPosition());
		punkty--;
	}
}

void Player::zmiana_kierunku()
{
	obiekt.setRotation(atan2(wektor_kierunku.y, wektor_kierunku.x) * (180.f / (float)M_PI));
}
