#pragma once
#include "Map.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

/**
*@brief
*klasa odpowiadaj¹ca za postaci
*/
class Entity
{
private:
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
	*funkcja zwracajaca wektor kierunku
	*/
	Vector2f get_wektor_kierunku();
	/**
	*@brief
	*funkcja ustawiajaca wektor kierunku
	*@param n wektor ktory ma byc przypisany wektorowi kierunku
	*/
	void set_wektor_kierunku(Vector2f n);
	/**
	*@brief
	*funkcja zwracajaca bufor kierunku
	*/
	Vector2f get_bufor_kierunku();
	/**
	*@brief
	*funkcja ustawiajaca bufor kierunku
	*@param n wektor ktory ma byc przypisany buforowi kierunku
	*/
	void set_bufor_kierunku(Vector2f n);
	/**
	*@brief
	*funkcja zwracajaca obiekt
	*/
	Sprite get_obiekt();
	/**
	*@brief
	*funkcja ustawiajaca obiekt
	*@param n ma byc przypisany obiektowi
	*/
	void set_obiekt(Sprite n);
	/**
	*@brief
	*funkcja ustawiajaca teksturê obiektu
	*@param a pierwsza wspolrzedna tekstury
	*@param b druga wspolrzedna tekstury
	*@param c trzecia wspolrzedna tekstury
	*@param d czwarta wspolrzedna tekstury
	*/
	void set_obiekt_texture(int a, int b, int c, int d);
	/**
	*@brief
	*funkcja ustawiajaca rotacjê obiektu
	*/
	void set_obiekt_rotation();
	/**
	*@brief
	*funkcja ustawiajaca pozycjê obiektu
	*@param result to wektor z nowym po³o¿eniem obiektu
	*/
	void set_obiekt_position(Vector2f result);
	/**
	*@brief
	*funkcja zwracajaca mapê
	*/
	Map* get_map();
	/**
	*@brief
	*funkcja odpowiadaj¹ca za wylosowanie nowego wektora który nie bêdzie powodowa³ kolizji
	*/
	Vector2f losowy_kierunek();
	/**
	*@brief
	*funkcja odpowiadaj¹ca za wsprawdzenie czy nie zajdzie kolizja ze œcian¹ po przesuniêciu o wektor
	*@param pozycja obecne po³o¿enie postaci
	*/
	bool kolizja_z_sciana(Vector2f pozycja);
	/**
	*@brief
	*funkcja odpowiadaj¹ca za ustawienie postaci
	*@param mapToLoad mapa po której porusza siê postaæ
	*@param path œcie¿ka do tekstury postaci
	*@param pozycja wektor pocz¹tkowego po³o¿enia postaci
	*/
	void ustaw_postac(Map* mapa_gry, string sciezka_tekstury, Vector2f pozycja);
	/**
	*@brief
	*funkcja odpowiadaj¹ca za renderowanie postaci
	*@param ingame wskaŸnik na okno, na ktorym renderowana jest postaæ
	*/
	void rysuj(RenderWindow* ingame);
	/**
	*@brief
	*funkcja odpowiadaj¹ca za wczytanie do buforu_kierunku kolejnego ruchu postaci
	*@param kierunek wektor który ma byæ kolejnym ruchem i jest wysy³any o bufora kierunku
	*/
	void ustawKierunek(Vector2f kierunek);
	/**
	*@brief
	*funkcja odpowiadaj¹ca za wykonanie ruchu w sterowaniu automatycznym
	*/
	void ruch1();
	/**
	*@brief
	*funkcja odpowiadaj¹ca za wykonanie ruchu w sterowaniu rêcznym
	*/
	void ruch2();
	/**
	*@brief
	*funkcja odpowiadaj¹ca za zmianê kierunku ruchu na losowy po zderzenie ze œcian¹
	*/
	void odbicie_od_sciany();
	/**
	*@brief
	*funkcja odpowiadaj¹ca za przejœcie postaci przez drzwi w œrodkowej czêœci mapy po prawej i lewej stronie
	*/
	void przeskoczenie();

	/**
	*@brief
	*wirtualna funkcja odpowiadaj¹ca za obrócenie postaci po zmianie kierunku
	*/
	virtual void zmiana_kierunku() {};
};
