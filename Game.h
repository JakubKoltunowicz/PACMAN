#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Monster.h"

using namespace std;
using namespace sf;

/**
*@brief
*klasa odpowiadaj¹ca za rozgrywkê
*/
class Game
{
private:
	int punkty, kolizja, kontrola;
	string sciezka_mapy, sciezka_pacman, sciezka_potwor;
	Map mapa_gry;
	Player player;
	Monster monster;
	Event game_event;
public:
	/**
	*@brief
	*konstruktor
	*@param sciezka1 œcie¿ka do mapy
	*@param sciezka2 œcie¿ka do pacmana
	*@param sciezka3 œcie¿ka do potwora
	*/
	Game(string sciezka1, string sciezka2, string sciezka3);
	/**
	*@brief
	*destruktor
	*/
	~Game();
	/**
	*@brief
	*funkcja odpowiadaj¹ca za prowadzenie rozgrywki
	*/
	void go();
};

