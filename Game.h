#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Monster.h"

using namespace std;
using namespace sf;

class Game
{
	Event game_event;
public:
	Game(string sciezka1, string sciezka2, string sciezka3);
	~Game();
	void go();
	int punkty;
	int kolizja;
	string sciezka_mapy, sciezka_pacman, sciezka_potwor;
	Map mapa_gry;
	Player player;
	Monster monster;
};

