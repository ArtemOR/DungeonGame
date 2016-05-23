#pragma once
#pragma once

#include"entity.h"
class Wall :public Entity
{
public:
	Wall() :Entity("wall.png")
	{
		this->group_id = 2;
		//this->setPosition(sf::Vector2f(300, 300));
		//this->setColor(sf::Color::Blue);
	}
	void Update()
	{
		
	}
private:

};

