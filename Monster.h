#pragma once
#include "Entity.h"

using namespace std;
using namespace sf;

/**
*@brief
*klasa odpowiadaj�ca za duszka
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
	*funkcja odpowiadaj�ca za ustawienie duszka
	*@param mapToLoad mapa po kt�rej porusza si� duszek
	*@param path �cie�ka do tekstury duszka
	*@param position wektor pocz�tkowego po�o�enia duszka
	*/
	void ustaw_potwora(Map* mapToLoad, string path, Vector2f position);
	/**
	*@brief
	*funkcja odpowiadaj�ca za aktualizacje po�o�enia duszka
	*/
	void zaktualizuj();
	/**
	*@brief
	*funkcja odpowiadaj�ca za przeniesienie duszka w losowe miejsce
	*/
	void teleport();
	/**
	*@brief
	*funkcja odpowiadaj�ca za przekazanie obecnego po�o�enia duszka
	*/
	Vector2f uzyskaj_pozycje();
};

