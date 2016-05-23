#include<stdio.h>
#include "main_menu.h"
#include "main_game.h"
#include "wall.h"
#include "key.h"
#include "main_character.h"


int testLevel[] = {
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,2,
	2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,
	2,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
	2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
	2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
	2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
	2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
	2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
	2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
	2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
	2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
	2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
	2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
//	2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
//	2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
//	2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
//	2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
//	2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
};

void UpdateCollisions(Entity *  entityA, Entity *  entityB)
{
	if (entityA->Group() == 1 && entityB->Group() == 2)
	{
		entityA->move(sf::Vector2f(-entityA->velocity.x, -entityA->velocity.y));
		//entityB->SetActive(0);
	}
}

main_game::main_game()
{
	this->manager = new EntityManager();
}

void main_game::LoadLevel(int levelData[])
{
	for (int y = 0; y < 15; y++)
	{
		for (int x = 0; x < 20; x++)
		{

			std::string name = "";
			switch (levelData[x + y * 20])
			{
			case 1:
				name = "mainCharacter";
				this->manager->AddEntity(name, new MainCharacter());
				break;
			case 2:
				name = "wall";
				this->manager->AddEntity(name, new Wall());
	
				break;
			case 3:
				name = "key";
				this->manager->AddEntity(name, new Key());

				break;
			default:
				continue;
			}
			this->manager->Get(name)->setPosition(x * 32, y * 32);
		}
	}
}


	void main_game::Initialize(sf::RenderWindow* window)
	{
		
		this->manager->SetCollisionMethod(UpdateCollisions);
		
		this->LoadLevel(testLevel);
		//this->manager->AddEntity("main", new MainCharacter());
		//this->manager->AddEntity("wall", new Wall());
		//this->manager->Get("wall")->setPosition(300, 300);
	}
	void main_game::Update(sf::RenderWindow* window)
	{	
		manager->Update();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) 
		{
			coreState.SetState(new main_menu());	
		}
		
	}
	void main_game::Render(sf::RenderWindow* window)
	{
		manager->Render(window);
	}
	void main_game::Destroy(sf::RenderWindow* window)
	{		
		delete manager;
	}
