#pragma once
/*!
\file NormPlat.h
*/

/*! \class NormPlat
\brief Normal platform in game - seperate class to distinguish in contact listener
*/
#include "Platform.h"

class NormPlat : public Platform
{
public:
	NormPlat() {};		//!< Default constructor
	NormPlat(b2World * world, TexManager *texMan, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation);		//!< Full constructor
};
