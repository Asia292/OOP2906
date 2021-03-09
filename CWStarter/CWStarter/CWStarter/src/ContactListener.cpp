#include "ContactListener.h"

void ContactListener::BeginContact(b2Contact * contact)
{
	b2Body* bodyA = contact->GetFixtureA()->GetBody();
	b2Body* bodyB = contact->GetFixtureB()->GetBody();

	//void* ptrA = bodyA->GetUserData();
	//std::cout << ptrA << std::endl;

	std::pair<std::string, void *> *dataA = (std::pair<std::string, void *>*) bodyA->GetUserData();
	//std::cout << "1: " << dataA->first << " 2: " << dataA->second << std::endl;
	//std::cout << bodyA << std::endl << bodyB << std::endl;
	bool sensorA = contact->GetFixtureA()->IsSensor();
	
	std::pair<std::string, void *> *dataB = (std::pair<std::string, void *>*) bodyB->GetUserData();
	//std::cout << "A: " << dataA << " B :" << dataB << std::endl;
	//std::cout << "Type: " << typeid(Enemy).name() << " Comp: " << dataA->first << std::endl;
	bool sensorB = contact->GetFixtureB()->IsSensor();
	
	if (typeid(Enemy).name() == dataA->first)
	{
		//std::cout << "Here" << std::endl;
		if (typeid(Player).name() == dataB->first)
		{
			Enemy * enemy = static_cast<Enemy*>(dataA->second);		
			Player * player = static_cast<Player*>(dataB->second);

			if ((bodyB->GetPosition().y + player->getHeight()) < bodyA->GetPosition().y)
			{
				//std::cout << "HERE" << std::endl;
				if (enemy != nullptr)
				{
					//std::cout << "CL: " << enemy->getHit1() << std::endl << "CL2: " << enemy->getHit2() << std::endl;
					if (enemy->getHit1() == false)
						enemy->attacked();
					else if (enemy->getHit1() == true)
						enemy->setHit2(true);
				}
			}
			else if (bodyB->GetPosition().x < bodyA->GetPosition().x)
			{
				player->setHit(true);
				bodyB->SetLinearVelocity(b2Vec2(-1, 0));
				player->resetFrame();
				player->changeFrames("Daze");
				player->setLoop(false);
			}
			else if (bodyB->GetPosition().x > bodyA->GetPosition().x)
			{
				player->setHit(true);
				bodyB->SetLinearVelocity(b2Vec2(1, 0));
				player->resetFrame();
				player->changeFrames("Daze");
				player->setLoop(false);
			}
			//std::cout << "Player: " << bodyB->GetPosition().y + player->getHeight() << "    Enemy: " << bodyA->GetPosition().y/* + enemy->getHeight() */<< std::endl;
			if (enemy != nullptr) enemy->setMove();

			//std::cout << "Player hit enemy" << std::endl;
		}
	}

	if (typeid(Player).name() == dataA->first)
	{
		if (typeid(Enemy).name() == dataB->first)
		{
			Enemy * enemy = static_cast<Enemy*>(dataB->second);
			Player * player = static_cast<Player*>(dataA->second);


			if ((bodyA->GetPosition().y + player->getHeight()) < bodyB->GetPosition().y)
			{
				//std::cout << "HERE" << std::endl;
				if (enemy != nullptr)
				{
					//std::cout << "CL1: " << enemy->getHit1() << std::endl << "CL2: " << enemy->getHit2() << std::endl;
					if (enemy->getHit1() == false)
						enemy->attacked();
					else if (enemy->getHit1() == true)
						enemy->setHit2(true);
				}
			}
			else if (bodyA->GetPosition().x < bodyB->GetPosition().x)
			{
				player->setHit(true);
				bodyA->SetLinearVelocity(b2Vec2(-1, 0));
				player->resetFrame();
				player->changeFrames("Daze");
				player->setLoop(false);
			}
			else if (bodyA->GetPosition().x > bodyB->GetPosition().x)
			{
				player->setHit(true);
				bodyA->SetLinearVelocity(b2Vec2(1, 0));
				player->resetFrame();
				player->changeFrames("Daze");
				player->setLoop(false);
			}


			//std::cout << "Player: " << bodyA->GetPosition().y + player->getHeight() << "    Enemy: " << bodyB->GetPosition().y /*+ enemy->getHeight()*/ << std::endl;

			//enemy->change();
			
			if (enemy != nullptr) enemy->setMove();

			//std::cout << "Player hit enemy" << std::endl;
		}
		if (typeid(BouncyPlat).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataA->second);

			if ((bodyA->GetPosition().y + player->getHeight()) < bodyB->GetPosition().y)
			{
				bodyA->ApplyLinearImpulse(b2Vec2(0, 4.5), bodyA->GetPosition(), true);
				player->resetFrame();
				player->changeFrames("Jump");
				player->setLoop(false);
			}
			//std::cout << "Bounce : " << bodyA << std::endl;
		}
		if (typeid(MovingPlat).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataA->second);
			player->setGrounded(true);

			b2Vec2 velo = bodyB->GetLinearVelocity();
			bodyA->SetLinearVelocity(velo);

			//std::cout << velo.x << std::endl;
		}
		if (typeid(Hazard).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataA->second);

			player->setHit(true);
			player->resetFrame();
			player->changeFrames("Daze");
			player->setLoop(false);
		}
		if (typeid(PickUp).name() == dataB->first)
		{
			//removable.push_back(*bodyB);
			/*void *itm = dataB->second;
			*itm->setDel;	*/	// along the right lines - check lecture to change void * to item*
			//std::cout << dataB->second << std::endl;

			PickUp * item = static_cast<PickUp*>(dataB->second);

			//std::cout << item << std::endl;
			if (item != nullptr) item->setDel(true);

			//std::cout << "Yay item!" << std::endl;
		}
		if (typeid(NormPlat).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataA->second);
			player->setGrounded(true);
		}
		if (typeid(OneWayPlat).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataA->second);
			player->setGrounded(true);
		}
		if (typeid(Floor).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataA->second);
			player->setGrounded(true);
		}
	}

	if (typeid(BouncyPlat).name() == dataA->first)
	{
		if (typeid(Player).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataB->second);

			if ((bodyB->GetPosition().y + player->getHeight()) < bodyA->GetPosition().y)
			{
				bodyB->ApplyLinearImpulse(b2Vec2(0, 4.5), bodyB->GetPosition(), true);
				player->resetFrame();
				player->changeFrames("Jump");
				player->setLoop(false);
			}
			//std::cout << "Bounce : " << bodyA << std::endl;
		}
	}

	if (typeid(MovingPlat).name() == dataA->first)
	{
		if (typeid(Player).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataB->second);
			player->setGrounded(true);

			b2Vec2 velo = bodyA->GetLinearVelocity();
			bodyB->SetLinearVelocity(velo);

			//std::cout << velo.x << std::endl;
		}
	}

	if (typeid(NormPlat).name() == dataA->first)
	{
		if (typeid(Player).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataB->second);
			player->setGrounded(true);
		}
	}

	if (typeid(OneWayPlat).name() == dataA->first)
	{
		if (typeid(Player).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataB->second);
			player->setGrounded(true);
		}
	}

	if (typeid(Floor).name() == dataA->first)
	{
		if (typeid(Player).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataB->second);
			player->setGrounded(true);
		}
	}

	if (typeid(Hazard).name() == dataA->first)
	{
		if (typeid(Player).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataB->second);

			player->setHit(true);
			player->resetFrame();
			player->changeFrames("Daze");
			player->setLoop(false);
		}
	}

	if (typeid(PickUp).name() == dataA->first)
	{
		if (typeid(Player).name() == dataB->first)
		{
			PickUp * item = static_cast<PickUp*>(dataB->second);

			//std::cout << item << std::endl;
			if (item != nullptr) item->setDel(true);
		}
	}

	if (sensorA)
	{
		Sensor * sensor = static_cast<Sensor *>(bodyA->GetUserData());
		sensor->onAction(bodyB);
	}
	if (sensorB)
	{
		Sensor * sensor = static_cast<Sensor *>(bodyB->GetUserData());
		sensor->onAction(bodyA);
	}
}


void ContactListener::EndContact(b2Contact * contact)
{
	b2Body* bodyA = contact->GetFixtureA()->GetBody();
	b2Body* bodyB = contact->GetFixtureB()->GetBody();

	std::pair<std::string, void *> *dataA = (std::pair<std::string, void *>*) bodyA->GetUserData();
	std::pair<std::string, void *> *dataB = (std::pair<std::string, void *>*) bodyB->GetUserData();

	bool sensorA = contact->GetFixtureA()->IsSensor();
	bool sensorB = contact->GetFixtureB()->IsSensor();

	if (sensorA)
	{
		Sensor * sensor = static_cast<Sensor *>(bodyA->GetUserData());
		sensor->offAction(bodyB);
	}
	if (sensorB)
	{
		Sensor * sensor = static_cast<Sensor *>(bodyB->GetUserData());
		sensor->offAction(bodyA);
	}

	if (typeid(Player).name() == dataA->first)
	{
		if (typeid(NormPlat).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataA->second);
			player->setGrounded(false);
		}
		if (typeid(MovingPlat).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataA->second);
			player->setGrounded(false);
		}
		if (typeid(Floor).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataA->second);
			player->setGrounded(false);
		}
		if (typeid(OneWayPlat).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataA->second);
			player->setGrounded(false);
		}
		if (typeid(Enemy).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataA->second);
			player->setHit(false);
		}
		if (typeid(Hazard).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataA->second);
			player->setHit(false);
		}
	}

	if (typeid(OneWayPlat).name() == dataA->first)
	{
		if (typeid(Player).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataB->second);
			player->setGrounded(false);
		}
	}

	if (typeid(NormPlat).name() == dataA->first)
	{
		if (typeid(Player).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataB->second);
			player->setGrounded(false);
		}
	}

	if (typeid(MovingPlat).name() == dataA->first)
	{
		if (typeid(Player).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataB->second);
			player->setGrounded(false);
		}
	}

	if (typeid(Floor).name() == dataA->first)
	{
		if (typeid(Player).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataB->second);
			player->setGrounded(false);
		}
	}

	if (typeid(Enemy).name() == dataA->first)
	{
		if (typeid(Player).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataB->second);
			player->setHit(false);
		}
	}

	if (typeid(Hazard).name() == dataA->first)
	{
		if (typeid(Player).name() == dataB->first)
		{
			Player * player = static_cast<Player*>(dataB->second);
			player->setHit(false);
		}
	}
}

