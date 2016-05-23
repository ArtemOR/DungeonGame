//ѕодключаем заголовок модул€ '''Graphics''', а он автоматически подключает заголовок модул€ '''Window'''
# include <SFML/Graphics.hpp>
#include<windows.h>
# include "game_state.h"
# include "main_menu.h"
game_state coreState;
bool quitGame = false;
int main()
{
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Dungeon");

	coreState.SetWindow(&window);
	coreState.SetState(new main_menu());
	
	while (window.isOpen())
	{
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			// если событие "закрытие окна":
			if (Event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		
		window.clear(sf::Color::Black);
		coreState.Update();

		window.display();
		if (quitGame)
		{
			window.close();
		}
		Sleep(5);
	}

	return 0;
}