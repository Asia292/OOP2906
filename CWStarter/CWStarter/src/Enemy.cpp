#include "Enemy.h"

Enemy::Enemy(b2World * world, TexManager *texMan, char type, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation):Character(world, texMan, position, size, orientation)
{

	left = body->GetPosition();
	right = body->GetPosition();
	moveR = true;
	pat = true;
	hitOnce = false;
	hitTwice = false;
	Size = size;

	left.x = left.x - 0.5;
	right.x = right.x + 0.5;

	manager = texMan;
	Type = type;
	switch (type)
	{
	case 'H':
		manager->getFrames("HedgeHog", this);
		break;
	case 'B':
		manager->getFrames("Bee", this);
		body->SetGravityScale(0.f);
		break;
	}
	setAnim();
}

void Enemy::patrol()
{
	if (pat)
	{
		if (body->GetPosition().x < left.x)
		{
			moveR = true;
			//std::cout << "Right" << std::endl;
		}
		else if (body->GetPosition().x > right.x)
		{
			moveR = false;
			
			//std::cout << "Left" << std::endl;
		}

		if (moveR)
		{
			body->SetLinearVelocity(b2Vec2(1, 0));
			setFlip(false);
		}
		else if (!moveR)
		{
			body->SetLinearVelocity(b2Vec2(-1, 0));
			setFlip(true);
			//std::cout << "Here" << std::endl;
		}
	}
}

void Enemy::setMove()
{
	moveR = !moveR;

	//std::cout << moveR << std::endl;
}

float Enemy::getHeight()
{
	float h = Size.y;

	return h;
}

void Enemy::setPat(bool patr)
{
	pat = patr;
}

void Enemy::attacked()
{
	currFrame = 0;
	switch (Type)
	{
	case 'H':
		changeFrames("SquishH");
		currSprite.setPosition(sf::Vector2f(currSprite.getPosition().x, currSprite.getPosition().y + 0.01f));
		setSize(sf::Vector2f(0.01f, 0.005f));
		break;
	case 'B':
		changeFrames("SquishB");
		setSize(sf::Vector2f(0.005f, 0.0025f));
		break;
	}

	setLoop(false);
	setAnim();

	pat = false;
	hitOnce = true;
	timer.restart();
}

bool Enemy::getHit1()
{
	//std::cout << "Get: " << hitOnce << std::endl;
	return hitOnce;
}

bool Enemy::getHit2()
{
	return hitTwice;
}

float Enemy::getTime()
{
	return timer.getElapsedTime().asSeconds();
}

void Enemy::setHit1(bool hit1)
{
	hitOnce = hit1;
	//std::cout << "set: " << hitOnce << std::endl;
}

void Enemy::setHit2(bool hit2)
{
	hitTwice = hit2;
}

bool Enemy::getMove()
{
	bool move = moveR;

	return move;
}

void Enemy::update(float timestep)
{
	Character::update(timestep);
	if (Type == 'B')
		currSprite.setScale(sf::Vector2f(currSprite.getScale().x * 0.5, currSprite.getScale().y * 0.5));

	patrol();
}

void Enemy::changeFrames(std::string frame)
{
	manager->getFrames(frame, this);
}

void Enemy::reset()
{
	setPat(true);
	setHit1(false);
	setHit2(false);

	setAnim();
	currFrame = 0;
	switch (Type)
	{
	case 'H':
		changeFrames("HedgeHog");
		break;
	case 'B':
		changeFrames("Bee");
	}
	setLoop(true);
}

Enemy::~Enemy()
{
	//body->GetWorld()->DestroyBody(body);
}