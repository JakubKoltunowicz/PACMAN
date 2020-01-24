#pragma once
#include "Map.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

class Entity
{
public:
	Entity();
	~Entity();
	void ustaw_postac(Map* mapa_gry, string sciezka_tekstury, Vector2f pozycja);
	void rysuj(RenderWindow* ingame);
	bool czy_zyje;
protected:
	Map* map;
	Texture tekstura;
	Sprite obiekt;
	Vector2f wektor_kierunku, bufor_kierunku;
	void ustawKierunek(Vector2f kierunek);
	bool kolizja_z_sciana(Vector2f pozycja);
	void ruch();

	virtual void zmiana_kierunku() {};
	virtual void odbicie_od_sciany() {};
};
