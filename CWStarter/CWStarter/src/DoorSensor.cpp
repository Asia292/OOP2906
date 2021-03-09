#include "DoorSensor.h"

DoorSensor::DoorSensor(b2World * world, const sf::Vector2f& position, sf::Vector2f& size, Door * dor) : Sensor(world, position, size)
{
	door = dor;

	setPosition(position);
	setSize(size);
	setOrigin(size * 0.5f);
	setRotation(0);
	setFillColor(sf::Color(76, 76, 76, 255));
}

void DoorSensor::onAction(b2Body * other)
{
	door->open();
}

void DoorSensor::offAction(b2Body * other)
{
	door->close();
}