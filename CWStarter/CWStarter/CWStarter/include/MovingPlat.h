#pragma once
/*!
\file MovingPlat.h
*/

/*! \class MovingPlat
\brief Platform that moves between two defined points
*/
#include "Platform.h"

class MovingPlat : public Platform
{
protected:
	b2Vec2 right;		//!< Rightmost position of move
	b2Vec2 left;		//!< Leftmost position of move
	bool moveR;		//!< If the platform should be moving right

public:
	MovingPlat() {};		//!< Default constructor
	MovingPlat(b2World * world, TexManager *texMan, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation);		//!< Full constructor

	void update(float timestep);		//!< Updates textures and moves the platform
	void move();		//!< Defines what way the platform should be moving and moves it
};