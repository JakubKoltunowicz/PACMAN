#include "Game.h"
#include "Menu.h"
#include "Map.h"
#include "Entity.h"
#include "Player.h"
#include "Monster.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

Game::Game(string sciezka1, string sciezka2, string sciezka3)
{
	sciezka_mapy = sciezka1;
	sciezka_pacman = sciezka2;
	sciezka_potwor = sciezka3;
	punkty = 0;
	kolizja = 0;
}

Game::~Game() {}

void Game::go()
{
	mapa_gry.zaladuj(sciezka_mapy);
	mapa_gry.punkty(punkty);
	player.ustaw_pacmana(&mapa_gry, sciezka_pacman, Vector2f(224, 376));
	monster.ustaw_potwora(&mapa_gry, sciezka_potwor, sf::Vector2f(232, 184));
	RenderWindow ingame(VideoMode(448, 496), "PACMAN", Style::Default);
	while (ingame.isOpen())
	{
		if (kolizja == 1)
		{
			ingame.close();
		}
		if (punkty == 0)
		{
			ingame.close();
		}
		while (ingame.pollEvent(game_event))
		{
			if (game_event.type == Event::Closed)
			{
				ingame.close();
			}
		}

		ingame.clear();

		player.zaktualizuj(punkty, monster.uzyskaj_pozycje(), kolizja);
		monster.zaktualizuj();

		mapa_gry.rysuj(&ingame);
		player.rysuj(&ingame);
		monster.rysuj(&ingame);

		ingame.display();
	}
}