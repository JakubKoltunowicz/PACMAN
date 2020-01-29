#pragma once
#include "Entity.h"
#include "Map.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

/**
*@brief
*klasa odpowiadaj¹ca za pacmana
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
	*funkcja odpowiadaj¹ca za ustawienie pacmana
	*@param mapToLoad mapa po której porusza siê pacman
	*@param path œcie¿ka do tekstury pacmana
	*@param position wektor pocz¹tkowego po³o¿enia pacmana
	*/
	void ustaw_pacmana(Map* mapToLoad, string path, Vector2f position);
	/**
	*@brief
	*funkcja odpowiadaj¹ca za aktualizacje po³o¿enia pacmana
	*@param punkty które zosta³y do zebrania do zakoñczenia gry
	*@param kontrola przechowuje informacje który rodzaj sterowania pacmanem zosta³ wybrany
	*/
	void zaktualizuj(int& punkty, bool kontrola);
	/**
	*@brief
	*funkcja odpowiadaj¹ca za obrócenie pacmana po zmianie kierunku
	*/
	void zmiana_kierunku();
	/**
	*@brief
	*funkcja odpowiadaj¹ca za kolizje pacmana z duszkiem
	*@param pozycja_potwora wektor z po³o¿eniem duszka
	*@param kolizja przechowuje informacje czy nast¹pi³a kolizja
	*/
	void kolizja(Vector2f pozycja_potwora, int& kolizja);
	/**
	*@brief
	*funkcja odpowiadaj¹ca za rozpoczêcie ruchu pacmana podczas przechodzenia z rêcznego sterowania w sterowanie automatczyne
	*/
	void start();
	/**
	*@brief
	*funkcja odpowiadaj¹ca za zatrzymanie pacmana podczas przechodzenia z automatyczngo sterowania w sterowanie rêczne
	*/
	void stop();
};

