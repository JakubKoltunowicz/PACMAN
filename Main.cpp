#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Menu.h"
#include "Game.h"
#include "Map.h"

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1200, 800), "PACKMAN!");
	window.setFramerateLimit(60);
	Event event;
	Menu menu(window.getSize().x, window.getSize().y);
	while (window.isOpen())
	{
		window.clear(Color::Black);

		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyReleased)
			{
				if (menu.przycisk(event, &window) == 1)
				{
					Game game("Grafika/map1.txt", "Grafika/pacman.png", "Grafika/ghost.png");
					game.go();
				}
			}
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		window.clear();
		menu.rysuj(&window);
		window.display();
	}
	return 0;
}