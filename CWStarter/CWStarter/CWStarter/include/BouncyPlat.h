#pragma once
/*!
\file BouncyPlat.h
*/

/*! \class BouncyPlat
\brief Spring platform that bounces the player
*/
#include "Platform.h"

class BouncyPlat : public Platform
{
public:
	BouncyPlat() {};		//!< Default constructor
	BouncyPlat(b2World * world, TexManager *texMan, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation);		//!< Full constructor
};
