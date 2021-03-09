#include "Door.h"

Door::Door(b2World * world, TexManager *texMan, const sf::Vector2f& position, const float orientation)
{
	b2BodyDef bodyDef;
	b2PolygonShape shape;
	b2FixtureDef fixtureDef;

	bodyDef.position.Set(position.x, position.y);
	bodyDef.angle = orientation;

	door = world->CreateBody(&bodyDef);
	top = world->CreateBody(&bodyDef);

	shape.m_radius = 0.0f;

	fixtureDef.density = density;
	fixtureDef.friction = friction;
	fixtureDef.restitution = restitution;
	fixtureDef.shape = &shape;

	//// DOOR ////
	shape.SetAsBox(0.5f * 0.5f, 0.16f * 0.5f, b2Vec2(-0.25f, 0.f), 0.f);
	door->CreateFixture(&fixtureDef);
	dooor = new Texture();
	//// ANCHOR/SIDE ////
	shape.SetAsBox(0.7f * 0.5f, 0.04f * 0.5f, b2Vec2(-0.85f, -0.10f), 0.f);
	top->CreateFixture(&fixtureDef);
	shape.SetAsBox(0.7f * 0.5f, 0.04f * 0.5f, b2Vec2(-0.85f, 0.10f), 0.f);
	top->CreateFixture(&fixtureDef);
	shape.SetAsBox(0.18f * 0.5f, 0.18f * 0.5f, b2Vec2(-1.11f, 0.f), 0.f);
	top->CreateFixture(&fixtureDef);
	side = new Texture();

	//// JOINT ////
	door->SetType(b2BodyType::b2_dynamicBody);
	b2MotorJointDef jointDef;
	jointDef.Initialize(top, door);
	jointDef.maxForce = 1000.0f; // Force much large than we'd ever need
	jointDef.maxTorque = 1000.0f; // Avoid rotation with high torque
	motor = (b2MotorJoint*)world->CreateJoint(&jointDef);

	//// SFML ////
	texMan->setTexture("all", side);
	texMan->getFrames("Wall", side);
	side->setPos(sf::Vector2f(top->GetPosition().x, top->GetFixtureList()->GetAABB(0).GetCenter().y + 0.26));
	side->setSize(sf::Vector2f(0.01f, 0.01f));

	texMan->setTexture("all", dooor);
	texMan->getFrames("Door", dooor);
	dooor->setPos(sf::Vector2f(door->GetPosition().x, door->GetFixtureList()->GetAABB(0).GetCenter().y));
	dooor->setSize(sf::Vector2f(0.01f, 0.009f));

	mTime = 1.5f;
	state = CLOSED;
}

void Door::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	dooor->draw(target, states);
	side->draw(target, states);
}

void Door::setUserData(void *data)
{
	door->SetUserData(data);
	top->SetUserData(data);
}

void Door::update(float timestep)
{
	side->update(timestep);
	dooor->update(timestep);

	if (state == OPENING)
	{
		eTime += timestep;

		float t = eTime / mTime;
		float dist;

		if (t < 1.0f)
			dist = t * -0.5f;
		else
		{
			dist = -0.5f;
			state = OPEN;
		}

		motor->SetLinearOffset(b2Vec2(dist, 0));
	}

	if (state == CLOSING)
	{
		eTime += timestep;

		float t = eTime / mTime;
		float dist;

		if (t < 1.0f)
			dist = (1.0f - t)*-0.5f;
		else
		{
			dist = 0.0f;
			state = CLOSED;
		}

		motor->SetLinearOffset(b2Vec2(dist, 0));
	}

	dooor->setPos(sf::Vector2f(door->GetPosition().x, door->GetFixtureList()->GetAABB(0).GetCenter().y));
}

void Door::open()
{
	//std::cout << "Opening" << std::endl;
	if (state == CLOSED)
	{
		eTime = 0.f;
		state = OPENING;
	}
	if (state == CLOSING)
	{
		eTime = mTime - eTime;
		state = OPENING;
	}
}

void Door::close()
{
	//std::cout << "Closing" << std::endl;
	if (state == OPEN)
	{
		eTime = 0.f;
		state = CLOSING;
	}
	if (state == OPENING)
	{
		eTime = mTime - eTime;
		state == CLOSING;
	}
}