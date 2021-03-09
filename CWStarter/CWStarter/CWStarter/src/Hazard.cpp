#include "Hazard.h"

Hazard::Hazard(b2World * world, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation)
{
	b2BodyDef bodyDef;
	b2PolygonShape shape;
	b2FixtureDef fixtureDef;

	bodyDef.position.Set(position.x, position.y);
	bodyDef.angle = orientation;

	body = world->CreateBody(&bodyDef);

	shape.SetAsBox(size.x * 0.5f, size.y * 0.5f);
	shape.m_radius = 0.0f;

	fixtureDef.density = mk_fDensity;
	fixtureDef.friction = mk_fFriction;
	fixtureDef.restitution = mk_fRestitution;
	fixtureDef.shape = &shape;

	body->CreateFixture(&fixtureDef);
	body->SetFixedRotation(true);

	setPosition(position);
	setSize(size);
	setOrigin(size * 0.5f);
	setRotation(orientation);
	setFillColor(sf::Color::Cyan);
	setOutlineThickness(0.f);
}

void Hazard::setUserData(void *data)
{
	body->SetUserData(data);
}