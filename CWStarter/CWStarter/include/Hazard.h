#pragma once
/*!
\file Hazard.h
*/

/*! \class Hazard
\brief Defines the box2d hazard body
*/
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <iostream>

class Hazard : public sf::RectangleShape
{
protected:
	b2Body * body = nullptr; //!< Box2D body
	const float mk_fDensity = 1.0f; //!< Density of the material - used to give mass
	const float mk_fFriction = 0.4f; //!< Friction - only friction from movement, not when static
	const float mk_fRestitution = 0.0f; //!< Restitution - bouncyness of stuff

public:
	Hazard() {};	//!< Default constructor
	Hazard(b2World * world, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation);		//!< Full constructor

	void setUserData(void* data);		//!< Sets the user data of the body
};