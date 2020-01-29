#pragma once
#include "Entity.h"

using namespace std;
using namespace sf;

/**
*@brief
*klasa odpowiadaj¹ca za duszka
*/
class Monster : public Entity
{
private:
	Vector2f result;
public:
	/**
	*@brief
	*konstruktor
	*/
	Monster();
	/**
	*@brief
	*destruktor
	*/
	~Monster();
	/**
	*@brief
	*funkcja odpowiadaj¹ca za ustawienie duszka
	*@param mapToLoad mapa po której porusza siê duszek
	*@param path œcie¿ka do tekstury duszka
	*@param position wektor pocz¹tkowego po³o¿enia duszka
	*/
	void ustaw_potwora(Map* mapToLoad, string path, Vector2f position);
	/**
	*@brief
	*funkcja odpowiadaj¹ca za aktualizacje po³o¿enia duszka
	*/
	void zaktualizuj();
	/**
	*@brief
	*funkcja odpowiadaj¹ca za przeniesienie duszka w losowe miejsce
	*/
	void teleport();
	/**
	*@brief
	*funkcja odpowiadaj¹ca za przekazanie obecnego po³o¿enia duszka
	*/
	Vector2f uzyskaj_pozycje();
};

