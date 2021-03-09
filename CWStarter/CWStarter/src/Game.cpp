#include "Game.h"

Game::Game()
{
	view.setCenter(0.f, 0.f);
	view.setSize(worldSize);

	world = new b2World(gravity);

	debugDraw.setWorld(world);
	
	font.loadFromFile(".\\assets\\Squares.otf");

	level = new Lvl1(texMan, world);
	hud = new HUD(texMan, font);


	gameOver.setFillColor(sf::Color(0, 0, 0, 150));
	gameOver.setSize(sf::Vector2f(1024, 800));		//sets the properties for the greyed out game over screen
	gameOver.setPosition(0, 0);

	finish.setFont(font);
	finish.setFillColor(sf::Color(35, 179, 241));
	finish.setOutlineColor(sf::Color::Black);
	finish.setOutlineThickness(3);
	finish.setCharacterSize(60);
	finish.setScale(sf::Vector2f(0.005f, 0.005f));
	

	//std::cout << items[0] << std::endl;
	world->SetContactListener(&listener);

	dead = false;
	fail = false;
	won = false;
	debug = false;
}

Game::~Game()
{
	// Clean up all pointers
	delete world;
	world = nullptr;

	delete level;
	level = nullptr;

	delete hud;
	hud = nullptr;
}

void Game::update(float timestep)
{
	// Camera pos
	playerPos = level->getPos();
	//playerPos.y = playerPos.y - 1.5f;
	view.setCenter(playerPos);
	hud->moveHUD(playerPos);


	// Update each dyanmic element - effectively update render information
	if (dead && level->player->getCurrFrame() == 13)
	{
		fail = true;
		finish.setString("GAME OVER");
		finish.setPosition(playerPos.x - 1.0, playerPos.y - 0.2);
	}
	if (level->player->getHome() && hud->getCoins() == 0)
	{
		won = true;
		int scr = hud->finalScore();
		finish.setString("	  YOU WIN \n SCORE: " + std::to_string(scr));
		finish.setPosition(playerPos.x - 1.0, playerPos.y - 0.2);
	}

	
	if (!fail && !won)
	{	
		// Update the world
		world->Step(timestep, velIterations, posIterations);


		level->update(timestep, dead);

		if (!dead)
			hud->update(timestep);

		if (level->player->getHit())
		{
			hud->updateLives();
			if (hud->getLives() == 0)
			{
				level->player->resetFrame();
				level->player->changeFrames("Poof");
				level->player->setLoop(false);
				dead = true;
			}
			level->player->setHit(false);
		}


		int e = 0;
		for (Enemy *enemi : level->enemies)
		{
			if (enemi != nullptr)
			{
				if (enemi->getHit1() == true)
				{
					if (enemi->getTime() < 5)
					{
						if (enemi->getHit2() == true)
						{
							//std::cout << "kill" << std::endl;
							delete enemi;
							level->enemies[e] = nullptr;
						}
					}
					else
					{
						//std::cout << "Reset" << std::endl;
						enemi->reset();
					}
				}
			}
			e++;
		}
		int i = 0;
		for (PickUp *item : level->items)
		{
			if (item != nullptr)
			{
				//std::cout << item->getDel() << std::endl;
				if (item->getDel() == true)
				{
					char type = item->getType();
					hud->updateScore(type);

					if (type == 'C')
						hud->updateCoins();

					delete item;
					level->items[i] = nullptr;
				}
			}
			i++;
		}
	}

	// Delete debug shapes
	if (debug) debugDraw.clear();


	//// UNIT TESTS ////
	/*velX = player->getVelo().x;
	velY = player->getVelo().y;
	posX = player->getPos().x;
	posY = player->getPos().y;*/
	//move = enemies[0]->getMove();
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	// Set the view
	target.setView(view);

	// Draw everything
	level->draw(target, sf::RenderStates::Default);
	hud->draw(target, sf::RenderStates::Default);

	// END
	if (fail || won)
	{
		target.draw(gameOver);
		target.draw(finish);
	}

	// Debug Draw
	if (debug) target.draw(debugDraw);
}

void Game::processKeyPress(sf::Keyboard::Key code)
{
	switch (code)
	{
	case sf::Keyboard::Tab:
		toggleDebug();
		break;
	case sf::Keyboard::D:
		level->player->moveRight();
		break;
	case sf::Keyboard::A:
		level->player->moveLeft();
		break;
	case sf::Keyboard::W:
		level->player->jump();
		break;
	}
	
}