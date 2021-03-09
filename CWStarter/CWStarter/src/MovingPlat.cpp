#include "MovingPlat.h"

MovingPlat::MovingPlat(b2World * world, TexManager *texMan, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation) : Platform(world, texMan, position, size, orientation)
{
	texMan->setTexture("all", this);
	texMan->getFrames("Platform", this);
	setSize(sf::Vector2f(0.01f, 0.01f));

	left = body->GetPosition();
	right = body->GetPosition();
	moveR = true;

	left.x = left.x - 1;
	right.x = right.x + 1;

	//std::cout << "Left: " << left.x << "  Right: " << right.x << "	" << moveR << std::endl << "fix: " << fixtureDef.friction << std::endl;
}

void MovingPlat::update(float timestep)
{
	Texture::update(timestep);
	b2Vec2 pos = body->GetPosition();
	currSprite.setPosition(pos.x, pos.y);
	move();
}

void MovingPlat::move()
{
	if (body->GetPosition().x < left.x)
		moveR = true;
	else if (body->GetPosition().x > right.x)
		moveR = false;

	//std::cout << moveR << std::endl;

	if (moveR)
		body->SetLinearVelocity(b2Vec2(1, 0));
	else if (!moveR)
		body->SetLinearVelocity(b2Vec2(-1, 0));
}