#pragma once
/*!
\file MovableObj.h
*/

/*! \class MovableObj
\brief An object that the player can interact with and move
*/
#include "Character.h"

class MovableObj : public Character
{
public:
	MovableObj() {};	//!< Default constructor
	MovableObj(b2World * world, TexManager *texMan, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation);		//!< Full constructor
};