#include "Player.h"
#include "Game.h"
#include "Menu.h"
#include "Map.h"
#include "Entity.h"
#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

Player::Player() {}

Player::~Player() {}

void Player::ustaw_pacmana(Map* mapa_gry, string sciezka_tekstury, Vector2f pozycja)
{
	ustaw_postac(mapa_gry, sciezka_tekstury, pozycja);
	set_obiekt_texture(0, 0, 16, 16);
}

void Player::start()
{
	set_wektor_kierunku(Vector2f(0, 0));
	odbicie_od_sciany();
}

void Player::stop()
{
	set_bufor_kierunku(Vector2f(0, 0));
}

void Player::zaktualizuj(int& punkty, bool kontrola)
{
	if (kontrola == 0)
	{
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
		ruch2();
	}
	else
	{
		ruch1();
	}

	if (get_map()->sciana(get_obiekt().getPosition()) == 2)
	{
		get_map()->usun_punkt(get_obiekt().getPosition());
		punkty--;
	}
}

void Player::zmiana_kierunku()
{
	set_obiekt_rotation();
}

void Player::kolizja(Vector2f pozycja_potwora, int& kolizja)
{
	if (Vector2f(get_obiekt().getPosition().x / 16, get_obiekt().getPosition().y / 16) == Vector2f(pozycja_potwora.x / 16, pozycja_potwora.y / 16))
	{
		kolizja = 1;
	}
}

