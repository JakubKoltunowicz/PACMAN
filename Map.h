#pragma once
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Map
{
	int tablica[28][31];
	Texture tekstura;
	RectangleShape klatka = RectangleShape(Vector2f(16, 16));

public:
	Map();
	~Map();
	void zaladuj(string sciezka_mapy);
	void rysuj(RenderWindow* ingame);
	int sciana(Vector2f pozycja);
	void usun_punkt(Vector2f pozycja);
	void punkty(int& punkty);
};