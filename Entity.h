#pragma once
#include "Map.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

/**
*@brief
*klasa odpowiadaj�ca za postaci
*/
class Entity
{
private:
	friend class Monster;
	friend class Player;
	bool czy_zyje;
	Texture tekstura;
	Map* map;
	Sprite obiekt;
	Vector2f wektor_kierunku, bufor_kierunku;

public:
	/**
	*@brief
	*konstruktor
	*/
	Entity();
	/**
	*@brief
	*destruktor
	*/
	~Entity();
	/**
	*@brief
	*funkcja odpowiadaj�ca za wylosowanie nowego wektora kt�ry nie b�dzie powodowa� kolizji
	*/
	Vector2f losowy_kierunek();
	/**
	*@brief
	*funkcja odpowiadaj�ca za wsprawdzenie czy nie zajdzie kolizja ze �cian� po przesuni�ciu o wektor
	*@param pozycja obecne po�o�enie postaci
	*/
	bool kolizja_z_sciana(Vector2f pozycja);
	/**
	*@brief
	*funkcja odpowiadaj�ca za ustawienie postaci
	*@param mapToLoad mapa po kt�rej porusza si� posta�
	*@param path �cie�ka do tekstury postaci
	*@param pozycja wektor pocz�tkowego po�o�enia postaci
	*/
	void ustaw_postac(Map* mapa_gry, string sciezka_tekstury, Vector2f pozycja);
	/**
	*@brief
	*funkcja odpowiadaj�ca za renderowanie postaci
	*@param ingame wska�nik na okno, na ktorym renderowana jest posta�
	*/
	void rysuj(RenderWindow* ingame);
	/**
	*@brief
	*funkcja odpowiadaj�ca za wczytanie do buforu_kierunku kolejnego ruchu postaci
	*@param kierunek wektor kt�ry ma by� kolejnym ruchem i jest wysy�any o bufora kierunku
	*/
	void ustawKierunek(Vector2f kierunek);
	/**
	*@brief
	*funkcja odpowiadaj�ca za wykonanie ruchu w sterowaniu automatycznym
	*/
	void ruch1();
	/**
	*@brief
	*funkcja odpowiadaj�ca za wykonanie ruchu w sterowaniu r�cznym
	*/
	void ruch2();
	/**
	*@brief
	*funkcja odpowiadaj�ca za zmian� kierunku ruchu na losowy po zderzenie ze �cian�
	*/
	void odbicie_od_sciany();
	/**
	*@brief
	*funkcja odpowiadaj�ca za przej�cie postaci przez drzwi w �rodkowej cz�ci mapy po prawej i lewej stronie
	*/
	void przeskoczenie();

	/**
	*@brief
	*wirtualna funkcja odpowiadaj�ca za obr�cenie postaci po zmianie kierunku
	*/
	virtual void zmiana_kierunku() {};
};
