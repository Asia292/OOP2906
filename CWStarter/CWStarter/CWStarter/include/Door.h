#pragma once
/*!
\file Door.h
*/

/*! \class Door
\brief Sliding door implemented with motor joint
*/
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include "TexManager.h"

class Door : public Texture
{
private:
	b2Body * top = nullptr;		//!< What the door is attatched to - the top of it
	b2Body * door = nullptr;		//!< The door itself
	b2MotorJoint * motor = nullptr;		//!< The motor joint that controls the door

	Texture *side;		//!< Sprite for top of the door
	Texture *dooor;		//!< Sprite for door itself

	const float density = 1.0f; //!< Density of the material - used to give mass
	const float friction = 0.4f; //!< Friction - only friction from movement, not when static
	const float restitution = 0.0f; //!< Restitution - bouncyness of stuff

	enum { CLOSED, OPEN, CLOSING, OPENING } state;		//!< Enum that defines the states the door can be in
	float eTime;	//!< Elapsed time
	float mTime;	//!< Motion time

public:
	Door() {};		//!< Default constructor
	Door(b2World * world, TexManager *texMan, const sf::Vector2f& position, const float orientation);		//!< Full constructor

	void setUserData(void* data);		//!< Sets the user data of the bodies
	void update(float timestep);		//!< Updates the textures and moves the door as required if state is opening or closing
	void open();		//!< Starts the door opening
	void close();		//!< Starts the door closing

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;		//!< Draws both door textures
};
