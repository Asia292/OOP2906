#include "Player.h"

Player::Player(b2World * world, TexManager *texMan, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation) :Character(world, texMan, position, size, orientation)
{
	manager = texMan;
	manager->getFrames("Idle", this);
	setAnim();
	setFlip(true);
	
	hit = false;
	isGrounded = false;
	home = false;
	Size = size;
}

void Player::moveRight()
{
	if ((manager->getState() != "Daze" || (manager->getState() == "Daze" && currFrame == 15)) && manager->getState() != "Poof")
	{
		b2Vec2 velo = body->GetLinearVelocity();
		velo.x = 2;
		body->SetLinearVelocity(velo);

		if (manager->getState() != "Run" && isGrounded)
		{
			currFrame = 0;
			manager->getFrames("Run", this);
			setLoop(true);
		}
		setFlip(true);
	}
}

void Player::moveLeft()
{
	if ((manager->getState() != "Daze" || (manager->getState() == "Daze" && currFrame == 15)) && manager->getState() != "Poof")
	{
		b2Vec2 velo = body->GetLinearVelocity();
		velo.x = -2;
		body->SetLinearVelocity(velo);

		if (manager->getState() != "Run" && isGrounded)
		{
			currFrame = 0;
			manager->getFrames("Run", this);
			setLoop(true);
		}
		setFlip(false);
	}
}

void Player::jump()
{
	if (isGrounded && manager->getState() != "Poof")
	{
		currFrame = 0;
		manager->getFrames("Jump", this);
		setLoop(false);
		//m_body->ApplyLinearImpulse(b2Vec2(0, 2), m_body->GetPosition(), true);
		b2Vec2 velo = body->GetLinearVelocity();
		velo.y = -4;
		body->SetLinearVelocity(velo);
	}
}

float Player::getHeight()
{
	float h = Size.y;
	h = h / 2;

	return h;
}

b2Vec2 Player::getVelo()
{
	b2Vec2 vel = body->GetLinearVelocity();

	return vel;
}

b2Vec2 Player::getPos()
{
	b2Vec2 pos = body->GetPosition();

	return pos;
}

void Player::setGrounded(bool ground)
{
	isGrounded = ground;
}

void Player::changeFrames(std::string frame)
{
	manager->getFrames(frame, this);
}

void Player::update(float timestep)
{
	Character::update(timestep);
	if ((isGrounded && manager->getState() == "Jump" && currFrame == 3) || (getVelo().x == 0 && manager->getState() != "Jump" && manager->getState() != "Poof"))
	{
		currFrame = 0;
		manager->getFrames("Idle", this);
	}
}

void Player::resetFrame()
{
	currFrame = 0;
}

bool Player::getHit()
{
	return hit;
}

void Player::setHit(bool Hit)
{
	hit = Hit;
}

int Player::getCurrFrame()
{
	return currFrame;
}

void Player::setHome(bool Home)
{
	home = Home;
}

bool Player::getHome()
{
	return home;
}