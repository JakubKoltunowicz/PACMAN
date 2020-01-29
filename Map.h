#pragma once
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

/**
*@brief
*klasa odpowiadaj�ca za map�
*/
class Map
{
private:
	int tablica[28][31];
	Texture tekstura;
	RectangleShape klatka = RectangleShape(Vector2f(16, 16));
public:
	/**
	*@brief
	*konstruktor
	*/
	Map();
	/**
	*@brief
	*destruktor
	*/
	~Map();
	/**
	*@brief
	*funkcja odpowiadaj�ca za wczytanie mapy z pliku
	*@param sciezka_mapy �cie�ka do mapy
	*/
	void zaladuj(string sciezka_mapy);
	/**
	*@brief
	*funkcja odpowiadaj�ca za renderowanie mapy
	*@param ingame wska�nik na okno, na ktorym renderowana jest mapa
	*/
	void rysuj(RenderWindow* ingame);
	/**
	*@brief
	*funkcja odpowiadaj�ca za sprawdzenie jaki jest typ pola w wskazanym miejscu
	*@param pozycja zawiera miejsce kt�re ma by� sprawdzone
	*/
	int sciana(Vector2f pozycja);
	/**
	*@brief
	*funkcja odpowiadaj�ca za zmian� pola po zebraniu z niego punktu
	*@param pozycja zawiera miejsce kt�re ma by� zmienione
	*/
	void usun_punkt(Vector2f pozycja);
	/**
	*@brief
	*funkcja odpowiadaj�ca za zliczenie ile jest punkt�w do zebrania na mapie
	*@param punkty kt�re zosta�y do zebrania do zako�czenia gry
	*/
	void punkty(int& punkty);
};