#include "Monster.h"
#include "Game.h"
#include "Menu.h"
#include "Map.h"
#include "Entity.h"
#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

Monster::Monster() {}

Monster::~Monster() {}

void Monster::ustaw_potwora(Map* mapToLoad, string path, Vector2f position)
{
	ustaw_postac(mapToLoad, path, position);
	ustawKierunek(losowy_kierunek());
}

Vector2f Monster::losowy_kierunek()
{
	int rand1 = rand() % 4;
	Vector2f result;

	switch (rand1)
	{
	case 0:
		result = Vector2f(1, 0);
		break;
	case 1:
		result = Vector2f(-1, 0);
		break;
	case 2:
		result = Vector2f(0, 1);
		break;
	case 3:
		result = Vector2f(0, -1);
		break;
	}

	if (kolizja_z_sciana(obiekt.getPosition() + result) || wektor_kierunku == result || Vector2f(wektor_kierunku.x * -1, wektor_kierunku.y * -1) == result)
	{
		return losowy_kierunek();
	}

	return result;

}

void Monster::zaktualizuj()
{
	ruch();
}

Vector2f Monster::uzyskaj_pozycje()
{
	return obiekt.getPosition();
}

void Monster::odbicie_od_sciany()
{
	ustawKierunek(losowy_kierunek());
}
