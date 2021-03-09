#pragma once
/*!
\file Character.h
*/

/*! \class Character
\brief The base for characters within the game
*/
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TexManager.h"

class Character : public Texture
{
protected:
	b2Body * body = nullptr; //!< Box2D body
	const float density = 1.0f; //!< Density of the material - used to give mass
	const float friction = 0.4f; //!< Friction - is only friction from movement, not when static
	const float restitution = 0.1f; //!< Restitution - bouncyness of stuff

	TexManager * manager;		//!< Pointer to the texture manager passed in constructor

public:
	Character() {};		//!< Default constructor
	Character(b2World * world, TexManager *texMan, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation);		//!< Full constructor

	void update(float timestep);	//!< Updates textures
	void setUserData(void* data);	//!< Sets the user data of the body
};