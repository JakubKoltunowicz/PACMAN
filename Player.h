#pragma once
#include "Entity.h"
#include "Map.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Player : public Entity
{
public:
	Player();
	~Player();
	void ustaw_pacmana(Map* mapToLoad, string path, Vector2f position);
	void zaktualizuj(int& punkty);
	void zmiana_kierunku();
	void kolizja(Vector2f pozycja_potwora, int& kolizja);
};

