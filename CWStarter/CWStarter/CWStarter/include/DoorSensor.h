#pragma once
/*!
\file DoorSensor.h
*/

/*! \class DoorSensor
\brief Sensor that opens a door on contact and closes it when contact ends
*/
#include "Sensor.h"
#include "Door.h"

class DoorSensor : public Sensor
{
public:
	DoorSensor() {};		//!< Default constructor
	DoorSensor(b2World * world, const sf::Vector2f& position, sf::Vector2f& size, Door * dor);		//!< Full constructor

	void onAction(b2Body * other);		//!< Action to do when sensor is triggered
	void offAction(b2Body * other);		//!< Action to do when sensor stops being triggered
	Door * door;	//!< The door passed in constructor
};