#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;

/**
*@brief
*klasa odpowiadajπca za menu
*/
class Menu
{
private:
	const int maksymalna_liczba_opcjii = 3;
	int wybrana_opcja;
	Font czcionka;
	Text menu[3];
public:
	/**
	*@brief
	*konstruktor
	*@param wifth szerokosc okna menu
	*@param height wysokosc okna menuu
	*/
	Menu(float wifth, float height);
	/**
	*@brief
	*destruktor
	*/
	~Menu();
	/**
	*@brief
	*funkcja odpowiadajπca za wypisanie przyciskÛw menu
	*@param window wskaünik na okno, na ktorym renderowane sπ elementy
	*/
	void rysuj(RenderWindow* window);
	/**
	*@brief
	*funkcja przesuwa wskaünik menu do gÛry
	*/
	void doGory();
	/**
	*@brief
	*funkcja przesuwa wskaünik menu do do≥u
	*/
	void doDolu();
	/**
	*@brief
	*funkcja odpowiadajπca za zdarzenie po naciúniÍciu przycisku w menu
	*@param event zdarzenie w oknie menu
	*@param window wskaünik na okno, na ktorym renderowane sπ elementy
	*/
	int przycisk(Event event, RenderWindow* window);
};

