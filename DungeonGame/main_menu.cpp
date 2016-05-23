#include "main_menu.h"
#include "main_game.h"
main_menu::main_menu()
{
}



void main_menu::Initialize(sf::RenderWindow* window)
{
	
	this->font.loadFromFile("FontMaze.ttf");
	this->logo = sf::Text("Dungeon", font, 150U);
	this->logo.setOrigin(this->logo.getGlobalBounds().width / 2, /*this->logo.getGlobalBounds().height / 3*/ 0);
	this->logo.setPosition(window->getSize().x / 2, /*window->getSize().y / 3*/0);
	
	this->play = sf::Text("Play",font, 50U);
	this->play.setOrigin(this->play.getGlobalBounds().width / 3, 0);
	this->play.setPosition(window->getSize().x / 3, window->getSize().y / 2);
	
	this->quit = sf::Text("Quit", font, 50U);
	this->quit.setOrigin(this->quit.getGlobalBounds().width / 2,  0);
	this->quit.setPosition(window->getSize().x /1.5f, window->getSize().y / 2);


	this->selected = 0;
}
void main_menu::Update(sf::RenderWindow* window)
{
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && ! up )|| (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !right))
	{
		this->selected -= 1;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !left))
	{
		this->selected -= 1;
	}
	if (this->selected < 0)
	{
		this->selected = 1;
	}
	if (this->selected > 1)
	{
		this->selected = 0;
	}
	up = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	down = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
	left = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
	right = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
	{
		switch (this->selected)
		{
		case 0:
			coreState.SetState(new main_game());
			break;
		case 1:
			quitGame = true;
			break;
		default:
			break;
		}
	}

}
void main_menu::Render(sf::RenderWindow* window)
{
	this->play.setColor(sf::Color::White);
	this->quit.setColor(sf::Color::White);

	this->play.setString("Play");
	this->quit.setString("Quit");

	switch (this->selected)
	{
	case 0:
		this->play.setString("-Play");
		this->play.setColor(sf::Color(128, 0, 0));
		break;
	case 1:
		this->quit.setString("-Quit");
		this->quit.setColor(sf::Color(128,0,0));
		break;
	default:
		break;
	}
	window->draw(this->logo);
	window->draw(this->play);
	window->draw(this->quit);
}
void main_menu::Destroy(sf::RenderWindow* window)
{
}