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
*klasa odpowiadaj�ca za rozgrywk�
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
	*@param sciezka1 �cie�ka do mapy
	*@param sciezka2 �cie�ka do pacmana
	*@param sciezka3 �cie�ka do potwora
	*/
	Game(string sciezka1, string sciezka2, string sciezka3);
	/**
	*@brief
	*destruktor
	*/
	~Game();
	/**
	*@brief
	*funkcja odpowiadaj�ca za prowadzenie rozgrywki
	*/
	void go();
};

