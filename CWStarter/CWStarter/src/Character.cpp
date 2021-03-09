#include "Character.h"

Character::Character(b2World * world, TexManager *texMan, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation)
{
	b2BodyDef bodyDef;
	b2PolygonShape shape;
	b2FixtureDef fixtureDef;
	

	bodyDef.position.Set(position.x, position.y);
	bodyDef.angle = orientation;
	bodyDef.type = b2_dynamicBody;

	body = world->CreateBody(&bodyDef);

	shape.SetAsBox(size.x * 0.5f, size.y * 0.5f);
	shape.m_radius = 0.0f;

	fixtureDef.density = density;
	fixtureDef.friction = friction;
	fixtureDef.restitution = restitution;
	fixtureDef.shape = &shape;

	body->CreateFixture(&fixtureDef);
	body->SetFixedRotation(true);

	texMan->setTexture("all", this);
}


void Character::update(float timestep)
{
	Texture::update(timestep);
	b2Vec2 pos = body->GetPosition();
	currSprite.setPosition(pos.x, pos.y);
}

void Character::setUserData(void* data)
{
	//std::cout << "Set ptr " << data << std::endl;

	body->SetUserData(data);
}