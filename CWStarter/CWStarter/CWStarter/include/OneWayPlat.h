#pragma once
/*!
\file OneWayPlat.h
*/

/*! \class OneWayPlat
\brief Platform that allows the player to pass through from underneath
*/
#include "Platform.h"

class OneWayPlat : public Platform
{
protected:
	sf::Vector2f pos;		//!< Position of the platform
	b2Fixture *fixture;		//!< The body's fixture

public:
	OneWayPlat() {};	//!< Default Constructor
	OneWayPlat(b2World * world, TexManager *texMan, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation);		//!< Full constructor

	void collide();		//!< Makes the platform collidable
	void pass();		//!< Makes it so the player can pass through the platform
	
	sf::Vector2f getPos();		//!< Returns the positon of the platform
};