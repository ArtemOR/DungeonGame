#pragma once

#include"entity.h"
class MainCharacter :public Entity
{
public:
	MainCharacter():Entity("test.png")
	{
		this->group_id = 1;
	}
	void Update()
	{

	/*	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			this->move(sf::Vector2f(0, -1));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			this->move(sf::Vector2f(0, 1));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			this->move(sf::Vector2f(-1, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			this->move(sf::Vector2f(1, 0));
		}*/
		this->velocity.x = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
		this->velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
		Entity::Update();
	}

	void AddKey()
	{
		this->KeyCount++;
	}

	void RemoveKey()
	{
		this->KeyCount--;
	}
private:
	int KeyCount;
};

