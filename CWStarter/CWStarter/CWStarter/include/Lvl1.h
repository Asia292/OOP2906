#pragma once
/*!
\file Lvl1.h
*/

/*! \class Lvl1
\brief Defines and creates the first level of the game
*/
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>

#include "TexManager.h"
#include "Player.h"
#include "Enemy.h"
#include "NormPlat.h"
#include "BouncyPlat.h"
#include "MovingPlat.h"
#include "OneWayPlat.h"
#include "Hazard.h"
#include "PickUp.h"
#include "MovableObj.h"
#include "DoorSensor.h"
#include "HomeSensor.h"
#include "Door.h"
#include "Floor.h"

class Lvl1 : public Texture
{
protected:
	
	NormPlat *platforms[4];		//!< Array of all normal platforms
	BouncyPlat *bounce[11];		//!< Array of all bounce platforms
	MovingPlat *moving[3];		//!< Array of all moving platforms
	OneWayPlat *oneWay[18];		//!< Array of all one way platforms
	Hazard *hazard[8];		//!< Array of all hazards


	MovableObj *box;	//!< The box that the player can move
	DoorSensor *sensor;		//!< The sensor that controls the door
	Door *door;			//!< The door
	HomeSensor *home;		//!< Sensor that dictates home

	Floor *floors[8];		//!< Array of all floors
	b2Vec2 floorOne[12];	//!< Array of floor one vectors
	b2Vec2 floorTwo[10];		//!< Array of floor two vectors
	b2Vec2 floorThree[16];	//!< Array of floor three vectors
	b2Vec2 floorFour[7];	//!< Array of floor four vectors
	b2Vec2 floorFive[17];	//!< Array of floor five vectors
	b2Vec2 floorSix[7];		//!< Array of floor six vectors
	b2Vec2 floorSeven[5];	//!< Array of floor seven vectors
	b2Vec2 floorEight[15];	//!< Array of floor eight vectors

public:
	Lvl1(TexManager * textMan, b2World * world);		//!< Constructor
	~Lvl1();	//!< Deconstructor
	void update(float timeStep, bool over);		//!< Updates everything except if game over (the bool passed in), then only updates the player to play final animation
	sf::Vector2f getPos();		//!< Returns player position in sf::Vector2f form

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;		//!< Draws everything

	Enemy *enemies[9];		//!< Array of all enemies - public so game class can edit it
	PickUp *items[89];		//!< Array of all items - public so game class can edit it
	Player *player;		//!< The player - public so game class can access it's functions
};