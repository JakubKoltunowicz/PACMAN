#include "Entity.h"
#include "Map.h"
#include "Game.h"
#include "Player.h"
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#define M_PI 3.14159265358979323846

using namespace std;
using namespace sf;

Entity::Entity()
{
	czy_zyje = 1;
	map = NULL;
}

Entity::~Entity() {}

Vector2f Entity::get_wektor_kierunku()
{
	return wektor_kierunku;
}

void Entity::set_wektor_kierunku(Vector2f n)
{
	wektor_kierunku = n;
}

Vector2f Entity::get_bufor_kierunku()
{
	return wektor_kierunku;
}

void Entity::set_bufor_kierunku(Vector2f n)
{
	wektor_kierunku = n;
}

Sprite Entity::get_obiekt()
{
	return obiekt;
}

void Entity::set_obiekt(Sprite n)
{
	obiekt = n;
}

void Entity::set_obiekt_texture(int a, int b, int c, int d)
{
	obiekt.setTextureRect(IntRect(a, b, c, d));
}

void Entity::set_obiekt_rotation()
{
	obiekt.setRotation(atan2(wektor_kierunku.y, wektor_kierunku.x) * (180.f / (float)M_PI));
}

void Entity::set_obiekt_position(Vector2f result)
{
	obiekt.setPosition(result);
}

Map* Entity::get_map()
{
	return map;
}

void Entity::ustaw_postac(Map* mapa_gry, string sciezka_tekstury, Vector2f pozycja)
{
	map = mapa_gry;

	tekstura.loadFromFile(sciezka_tekstury);
	obiekt.setTexture(tekstura);

	obiekt.setOrigin(Vector2f(8, 8));
	obiekt.setPosition(pozycja);

	wektor_kierunku = Vector2f(0, 0);
	bufor_kierunku = Vector2f(0, 0);
}

void Entity::rysuj(RenderWindow* ingame)
{
	ingame->draw(obiekt);
}

void Entity::ruch1()
{
	if (!kolizja_z_sciana(obiekt.getPosition() + bufor_kierunku))
	{
		wektor_kierunku = bufor_kierunku;
		zmiana_kierunku();
	}
	if (kolizja_z_sciana(obiekt.getPosition() + wektor_kierunku))
	{
		wektor_kierunku = Vector2f(0, 0);
		odbicie_od_sciany();
	}

	obiekt.move(Vector2f(wektor_kierunku.x * 0.5, wektor_kierunku.y * 0.5));
	przeskoczenie();
}

void Entity::ruch2()
{
	if (!kolizja_z_sciana(obiekt.getPosition() + bufor_kierunku))
	{
		wektor_kierunku = bufor_kierunku;
		zmiana_kierunku();
	}
	if (kolizja_z_sciana(obiekt.getPosition() + wektor_kierunku))
	{
		wektor_kierunku = Vector2f(0, 0);
	}

	obiekt.move(Vector2f(wektor_kierunku.x * 0.5, wektor_kierunku.y * 0.5));
	
	przeskoczenie();
}

void Entity::przeskoczenie()
{
	obiekt.setPosition(Vector2f((float)fmod(obiekt.getPosition().x, 448), (float)fmod(obiekt.getPosition().y, 496)));

	if (obiekt.getPosition().x < 0)
	{
		obiekt.setPosition(Vector2f(448, obiekt.getPosition().y));
	}
	if (obiekt.getPosition().y < 0)
	{
		obiekt.setPosition(Vector2f(obiekt.getPosition().x, 496));
	}
}

void Entity::ustawKierunek(Vector2f kierunek)
{
	bufor_kierunku = kierunek;
}

bool Entity::kolizja_z_sciana(Vector2f pozycja)
{
	return
		map->sciana(pozycja + Vector2f(-8, -8)) == 1 ||
		map->sciana(pozycja + Vector2f(7, -8)) == 1 ||
		map->sciana(pozycja + Vector2f(7, 7)) == 1 ||
		map->sciana(pozycja + Vector2f(-8, 7)) == 1;
}

void Entity::odbicie_od_sciany()
{
	ustawKierunek(losowy_kierunek());
}

Vector2f Entity::losowy_kierunek()
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
