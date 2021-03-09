#include "OneWayPlat.h"

OneWayPlat::OneWayPlat(b2World * world, TexManager *texMan, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation) : Platform(world, texMan, position, size, orientation)
{
	pos = position;
	fixture = body->GetFixtureList();
}

void OneWayPlat::collide()
{
	//std::cout << "COLLIDE" << std::endl;

	b2Filter filter;
	filter.maskBits = 0x0001;

	fixture->SetFilterData(filter);
}

void OneWayPlat::pass()
{
	//std::cout << "PASS" << std::endl;
	b2Filter filter;
	filter.maskBits = 0x0000;

	fixture->SetFilterData(filter);
}

sf::Vector2f OneWayPlat::getPos()
{
	return pos;
}