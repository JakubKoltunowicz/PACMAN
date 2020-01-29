#pragma once
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

/**
*@brief
*klasa odpowiadaj¹ca za mapê
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
	*funkcja odpowiadaj¹ca za wczytanie mapy z pliku
	*@param sciezka_mapy œcie¿ka do mapy
	*/
	void zaladuj(string sciezka_mapy);
	/**
	*@brief
	*funkcja odpowiadaj¹ca za renderowanie mapy
	*@param ingame wskaŸnik na okno, na ktorym renderowana jest mapa
	*/
	void rysuj(RenderWindow* ingame);
	/**
	*@brief
	*funkcja odpowiadaj¹ca za sprawdzenie jaki jest typ pola w wskazanym miejscu
	*@param pozycja zawiera miejsce które ma byæ sprawdzone
	*/
	int sciana(Vector2f pozycja);
	/**
	*@brief
	*funkcja odpowiadaj¹ca za zmianê pola po zebraniu z niego punktu
	*@param pozycja zawiera miejsce które ma byæ zmienione
	*/
	void usun_punkt(Vector2f pozycja);
	/**
	*@brief
	*funkcja odpowiadaj¹ca za zliczenie ile jest punktów do zebrania na mapie
	*@param punkty które zosta³y do zebrania do zakoñczenia gry
	*/
	void punkty(int& punkty);
};