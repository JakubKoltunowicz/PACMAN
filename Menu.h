#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;

/**
*@brief
*klasa odpowiadaj�ca za menu
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
	*funkcja odpowiadaj�ca za wypisanie przycisk�w menu
	*@param window wska�nik na okno, na ktorym renderowane s� elementy
	*/
	void rysuj(RenderWindow* window);
	/**
	*@brief
	*funkcja przesuwa wska�nik menu do g�ry
	*/
	void doGory();
	/**
	*@brief
	*funkcja przesuwa wska�nik menu do do�u
	*/
	void doDolu();
	/**
	*@brief
	*funkcja odpowiadaj�ca za zdarzenie po naci�ni�ciu przycisku w menu
	*@param event zdarzenie w oknie menu
	*@param window wska�nik na okno, na ktorym renderowane s� elementy
	*/
	int przycisk(Event event, RenderWindow* window);
};

