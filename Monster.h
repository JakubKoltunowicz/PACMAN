#pragma once
#include "Entity.h"

using namespace std;
using namespace sf;

class Monster : public Entity
{
public:
	Monster();
	~Monster();
	void ustaw_potwora(Map* mapToLoad, string path, Vector2f position);
	void zaktualizuj();
	Vector2f uzyskaj_pozycje();
protected:
	void odbicie_od_sciany();
	Vector2f losowy_kierunek();
};

