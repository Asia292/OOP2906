#include "PickUp.h"

PickUp::PickUp(b2World * world, TexManager *texMan, char type, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation)
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

	Type = type;
	texMan->setTexture("all", this);
	setPos(sf::Vector2f(position));
	switch (Type)
	{
	case 'C':
		texMan->getFrames("Coin", this);
		setAnim();
		break;
	case 'A':
		texMan->getFrames("Apple", this);
		setSize(sf::Vector2f(0.01f, 0.01f));
		break;
	case 'H':
		texMan->getFrames("Cherry", this);
		setSize(sf::Vector2f(0.01f, 0.01f));
		break;
	case 'B':
		texMan->getFrames("Banan", this);
		setSize(sf::Vector2f(0.01f, 0.01f));
		break;
	}

	del = false;
}

void PickUp::setUserData(void *data)
{
	body->SetUserData(data);
}

void PickUp::setDel(bool dele)
{
	del = dele;
	//std::cout << del << std::endl;
}

bool PickUp::getDel()
{
	return del;
}

char PickUp::getType()
{
	return Type;
}

PickUp::~PickUp()
{
	//body->GetWorld()->DestroyBody(body);
}