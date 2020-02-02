#include "Monster.h"
#include "Game.h"
#include "Menu.h"
#include "Map.h"
#include "Entity.h"
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

void Monster::zaktualizuj()
{
	ruch1();
}

void Monster::teleport()
{
	do
	{
		int rand1 = rand() % 448;
		int rand2 = rand() % 496;
		result.x = rand1;
		result.y = rand2;
	} while (kolizja_z_sciana(result));

	set_obiekt_position(result);
}

Vector2f Monster::uzyskaj_pozycje()
{
	return get_obiekt().getPosition();
}
