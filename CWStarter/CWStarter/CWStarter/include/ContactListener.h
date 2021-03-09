#pragma once
/*!
\file ContactListener.h
*/

/*! \class ContactListener
\brief Defines what happens on collisions
*/
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemy.h"
#include "Player.h"
#include "BouncyPlat.h"
#include "MovingPlat.h"
#include "NormPlat.h"
#include "OneWayPlat.h"
#include "Hazard.h"
#include "PickUp.h"
#include "Sensor.h"
#include "Floor.h"

class ContactListener : public b2ContactListener
{
public:
	void BeginContact(b2Contact* contact);	 //!< Called when contact begins
	void EndContact(b2Contact* contact);	 //!< Called when contact ends
};
