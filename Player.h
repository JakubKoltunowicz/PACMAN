#pragma once
#include "Entity.h"
#include "Map.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

/**
*@brief
*klasa odpowiadaj�ca za pacmana
*/
class Player : public Entity
{
public:
	/**
	*@brief
	*konstruktor
	*/
	Player();
	/**
	*@brief
	*destruktor
	*/
	~Player();
	/**
	*@brief
	*funkcja odpowiadaj�ca za ustawienie pacmana
	*@param mapToLoad mapa po kt�rej porusza si� pacman
	*@param path �cie�ka do tekstury pacmana
	*@param position wektor pocz�tkowego po�o�enia pacmana
	*/
	void ustaw_pacmana(Map* mapToLoad, string path, Vector2f position);
	/**
	*@brief
	*funkcja odpowiadaj�ca za aktualizacje po�o�enia pacmana
	*@param punkty kt�re zosta�y do zebrania do zako�czenia gry
	*@param kontrola przechowuje informacje kt�ry rodzaj sterowania pacmanem zosta� wybrany
	*/
	void zaktualizuj(int& punkty, bool kontrola);
	/**
	*@brief
	*funkcja odpowiadaj�ca za obr�cenie pacmana po zmianie kierunku
	*/
	void zmiana_kierunku();
	/**
	*@brief
	*funkcja odpowiadaj�ca za kolizje pacmana z duszkiem
	*@param pozycja_potwora wektor z po�o�eniem duszka
	*@param kolizja przechowuje informacje czy nast�pi�a kolizja
	*/
	void kolizja(Vector2f pozycja_potwora, int& kolizja);
	/**
	*@brief
	*funkcja odpowiadaj�ca za rozpocz�cie ruchu pacmana podczas przechodzenia z r�cznego sterowania w sterowanie automatczyne
	*/
	void start();
	/**
	*@brief
	*funkcja odpowiadaj�ca za zatrzymanie pacmana podczas przechodzenia z automatyczngo sterowania w sterowanie r�czne
	*/
	void stop();
};

