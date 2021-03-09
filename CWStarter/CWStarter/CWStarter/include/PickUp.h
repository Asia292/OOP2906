#pragma once
/*!
\file PickUp.h
*/

/*! \class PickUp
\brief Defines everything that can be picked up by the player
*/
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "TexManager.h"

class PickUp : public Texture
{
protected:
	b2Body * body = nullptr; //!< Box2D body
	const float mk_fDensity = 1.0f; //!< Density of the material - used to give mass
	const float mk_fFriction = 0.4f; //!< Friction - only friction from movement, not when static
	const float mk_fRestitution = 0.0f; //!< Restitution - bouncyness of stuff
	char Type;		//!< The type of the pick up - Coin, Apple, Cherry, Bananna
	bool del;		//!< If the item should be deleted

public:
	PickUp() {};	//!< Default constructor
	~PickUp();		//!< Deconstructor
	PickUp(b2World * world, TexManager *texMan, char type, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation);		//!< Full constructor

	void setUserData(void* data);		//!< Sets the user data of the body
	void setDel(bool dele);		//!< Specifies the del bool
	bool getDel();		//!< Returns the del bool
	char getType();		//!< Return the item type
};