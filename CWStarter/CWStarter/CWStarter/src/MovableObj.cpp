#include "MovableObj.h"

MovableObj::MovableObj(b2World * world, TexManager *texMan, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation) :Character(world, texMan, position, size, orientation)
{
	texMan->getFrames("Box", this);
	setSize(sf::Vector2f(0.005f, 0.005f));
}