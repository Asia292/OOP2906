#pragma once
#include <gtest/gtest.h>

#define private public
#define protected public
#include "game.h"

/*TEST(GameInternals, ToggleDebug) 
{
	Game game;

	bool debugBefore = game.debug;
	game.toggleDebug();
	bool debugAfter = game.debug;

	EXPECT_NE(debugBefore, debugAfter);
}

TEST(GameInternals, Tab) 
{
	Game game;

	bool debugBefore = game.debug;
	sf::Keyboard::Key key = sf::Keyboard::Tab;
	game.processKeyPress(key);
	bool debugAfter = game.debug;

	EXPECT_NE(debugBefore, debugAfter);
}*/

TEST(Singleton, TextureManagerSingleton)
{
	TexManager * texMan1;
	TexManager * texMan2;

	texMan1 = TexManager::getInstance();
	texMan2 = TexManager::getInstance();

	EXPECT_EQ(texMan1, texMan2);
}

//// ANIMATION ////
TEST(Animation, LoopNextFrame)
{
	TexManager * texMan = TexManager::getInstance();
	Texture * sprite = new Texture();

	sprite->setLoop(true);
	texMan->setTexture("all", sprite);
	texMan->getFrames("Run", sprite);

	sf::IntRect frameBefore = sprite->frames[sprite->currFrame];
	sprite->nextFrame();
	sf::IntRect frameAfter = sprite->frames[sprite->currFrame];

	EXPECT_NE(frameBefore, frameAfter);
}

TEST(Animation, LoopResetFrame)
{
	TexManager * texMan = TexManager::getInstance();
	Texture * sprite = new Texture();

	sprite->setLoop(true);
	texMan->setTexture("all", sprite);
	texMan->getFrames("Run", sprite);
	sprite->currFrame = 5;

	sf::IntRect frameOne = sprite->frames[0];
	sprite->nextFrame();
	sf::IntRect frameAfter = sprite->frames[sprite->currFrame];

	EXPECT_EQ(frameOne, frameAfter);
}

TEST(Animation, NoLoopNextFrame)
{
	TexManager * texMan = TexManager::getInstance();
	Texture * sprite = new Texture();

	sprite->setLoop(false);
	texMan->setTexture("all", sprite);
	texMan->getFrames("Run", sprite);

	sf::IntRect frameBefore = sprite->frames[sprite->currFrame];
	sprite->nextFrame();
	sf::IntRect frameAfter = sprite->frames[sprite->currFrame];

	EXPECT_NE(frameBefore, frameAfter);
}

TEST(Animation, NoLoopNoResetFrame)
{
	TexManager * texMan = TexManager::getInstance();
	Texture * sprite = new Texture();

	sprite->setLoop(false);
	texMan->setTexture("all", sprite);
	texMan->getFrames("Run", sprite);
	sprite->currFrame = 5;

	sf::IntRect lastFrame = sprite->frames[5];
	sprite->nextFrame();
	sf::IntRect frameAfter = sprite->frames[sprite->currFrame];

	EXPECT_EQ(lastFrame, frameAfter);
}

TEST(Animation, Flip)
{
	TexManager * texMan = TexManager::getInstance();
	Texture * sprite = new Texture();

	sprite->setAnim();
	texMan->setTexture("all", sprite);
	texMan->getFrames("Run", sprite);

	sf::Vector2f scaleBefore = sprite->currSprite.getScale();
	sprite->setFlip(true);
	sprite->update(1.f);
	sf::Vector2f scaleAfter = sprite->currSprite.getScale();

	EXPECT_NE(scaleBefore.y, scaleAfter.y);
}

//// PLAYER FUNCTIONS ////
TEST(PlayerFunctions, PlayerLeft)
{
	b2World * world = new b2World(b2Vec2(0, 9.81));
	TexManager * texMan = TexManager::getInstance();
	Game game;
	Player * player = new Player(world, texMan, sf::Vector2f(0, 0), sf::Vector2f(1, 1), 0.f);

	float velBefore = player->getVelo().x;
	player->moveLeft();
	float velAfter = player->getVelo().x;

	float velKeyBefore = game.level->player->getVelo().x;
	sf::Keyboard::Key key = sf::Keyboard::A;
	game.processKeyPress(key);	
	float velKeyAfter = game.level->player->getVelo().x;

	EXPECT_GT(velBefore, velAfter);
	EXPECT_GT(velKeyBefore, velKeyAfter);
}

TEST(PlayerFunctions, PlayerRight)
{
	b2World * world = new b2World(b2Vec2(0, 9.81));
	TexManager * texMan = TexManager::getInstance();
	Game game;
	Player * player = new Player(world, texMan, sf::Vector2f(0, 0), sf::Vector2f(1, 1), 0.f);

	float velBefore = player->getVelo().x;
	player->moveRight();
	float velAfter = player->getVelo().x;

	float velKeyBefore = game.level->player->getVelo().x;
	sf::Keyboard::Key key = sf::Keyboard::D;
	game.processKeyPress(key);
	float velKeyAfter = game.level->player->getVelo().x;

	EXPECT_LT(velBefore, velAfter);
	EXPECT_LT(velKeyBefore, velKeyAfter);
}

TEST(PlayerFunctions, PlayerJumpIsGrounded)
{
	b2World * world = new b2World(b2Vec2(0, 9.81));
	TexManager * texMan = TexManager::getInstance();
	Game game;
	Player * player = new Player(world, texMan, sf::Vector2f(0, 0), sf::Vector2f(1, 1), 0.f);

	player->isGrounded = true;
	float velBefore = player->getVelo().y;
	player->jump();
	float velAfter = player->getVelo().y;

	game.level->player->isGrounded = true;
	float velKeyBefore = game.level->player->getVelo().y;
	sf::Keyboard::Key key = sf::Keyboard::W;
	game.processKeyPress(key);
	float velKeyAfter = game.level->player->getVelo().y;

	EXPECT_GT(velBefore, velAfter);
	EXPECT_GT(velKeyBefore, velKeyAfter);
}

TEST(PlayerFunctions, PlayerJumpIsNotGrounded)
{
	b2World * world = new b2World(b2Vec2(0, 9.81));
	TexManager * texMan = TexManager::getInstance();
	Player * player = new Player(world, texMan, sf::Vector2f(0, 0), sf::Vector2f(1, 1), 0.f);

	player->isGrounded = false;
	float velBefore = player->getVelo().y;
	player->jump();
	float velAfter = player->getVelo().y;

	EXPECT_EQ(velBefore, velAfter);
}

TEST(PlayerFunctions, PlayerHit)
{
	b2World * world = new b2World(b2Vec2(0, 9.81));
	TexManager * texMan = TexManager::getInstance();
	Player * player = new Player(world, texMan, sf::Vector2f(0, 0), sf::Vector2f(1, 1), 0.f);

	bool hitBefore = player->getHit();
	player->setHit(true);
	bool hitAfter = player->getHit();

	EXPECT_NE(hitBefore, hitAfter);
}

//// ENEMY FUNCTIONS ////
TEST(EnemyFunctions, SwitchDirections)
{
	b2World * world = new b2World(b2Vec2(0, 9.81));
	TexManager * texMan = TexManager::getInstance();
	Enemy * enemy = new Enemy(world, texMan, 'H', sf::Vector2f(0, 0), sf::Vector2f(1, 1), 0.f);

	enemy->patrol();
	float velBefore = enemy->body->GetLinearVelocity().x;
	enemy->moveR = false;
	enemy->patrol();
	float velAfter = enemy->body->GetLinearVelocity().x;

	EXPECT_NE(velBefore, velAfter);
}

TEST(EnemyFunctions, PatrolStopsOnAttack)
{
	b2World * world = new b2World(b2Vec2(0, 9.81));
	TexManager * texMan = TexManager::getInstance();
	Enemy * enemy = new Enemy(world, texMan, 'H', sf::Vector2f(0, 0), sf::Vector2f(1, 1), 0.f);

	bool patBefore = enemy->pat;
	enemy->attacked();
	bool patAfter = enemy->pat;

	EXPECT_NE(patBefore, patAfter);
}

TEST(EnemyFunctions, HitOnceOnAttack)
{
	b2World * world = new b2World(b2Vec2(0, 9.81));
	TexManager * texMan = TexManager::getInstance();
	Enemy * enemy = new Enemy(world, texMan, 'H', sf::Vector2f(0, 0), sf::Vector2f(1, 1), 0.f);

	bool hitBefore = enemy->getHit1();
	enemy->attacked();
	bool hitAfter = enemy->getHit1();

	EXPECT_NE(hitBefore, hitAfter);
}

TEST(EnemyFunctions, PatrolStartOnReset)
{
	b2World * world = new b2World(b2Vec2(0, 9.81));
	TexManager * texMan = TexManager::getInstance();
	Enemy * enemy = new Enemy(world, texMan, 'H', sf::Vector2f(0, 0), sf::Vector2f(1, 1), 0.f);

	enemy->attacked();
	bool patBefore = enemy->pat;
	enemy->reset();
	bool patAfter = enemy->pat;
	bool expected = true;

	EXPECT_NE(patBefore, patAfter);
	EXPECT_EQ(expected, patAfter);
}

TEST(EnemyFunctions, NoHit1OnReset)
{
	b2World * world = new b2World(b2Vec2(0, 9.81));
	TexManager * texMan = TexManager::getInstance();
	Enemy * enemy = new Enemy(world, texMan, 'H', sf::Vector2f(0, 0), sf::Vector2f(1, 1), 0.f);

	enemy->attacked();
	bool hitBefore = enemy->getHit1();
	enemy->reset();
	bool hitAfter = enemy->getHit1();
	bool expected = false;

	EXPECT_NE(hitBefore, hitAfter);
	EXPECT_EQ(expected, hitAfter);
}

TEST(EnemyFunctions, NoHit2OnReset)
{
	b2World * world = new b2World(b2Vec2(0, 9.81));
	TexManager * texMan = TexManager::getInstance();
	Enemy * enemy = new Enemy(world, texMan, 'H', sf::Vector2f(0, 0), sf::Vector2f(1, 1), 0.f);

	enemy->setHit2(true);
	bool hitBefore = enemy->getHit2();
	enemy->reset();
	bool hitAfter = enemy->getHit2();
	bool expected = false;

	EXPECT_NE(hitBefore, hitAfter);
	EXPECT_EQ(expected, hitAfter);
}

//// PLATFORMS ////
TEST(Platforms, MovingPlatformSwitchDirection)
{
	b2World * world = new b2World(b2Vec2(0, 9.81));
	TexManager * texMan = TexManager::getInstance();
	MovingPlat * plat = new MovingPlat(world, texMan, sf::Vector2f(0, 0), sf::Vector2f(1, 1), 0.f);

	plat->move();
	float velBefore = plat->body->GetLinearVelocity().x;
	plat->moveR = false;
	plat->move();
	float velAfter = plat->body->GetLinearVelocity().x;

	EXPECT_NE(velBefore, velAfter);
}

TEST(Platforms, OneWayCollide)
{
	b2World * world = new b2World(b2Vec2(0, 9.81));
	TexManager * texMan = TexManager::getInstance();
	OneWayPlat * plat = new OneWayPlat(world, texMan, sf::Vector2f(0, 0), sf::Vector2f(1, 1), 0.f);

	uint16 maskExpected = 0x0001;
	uint16 maskBefore = plat->fixture->GetFilterData().maskBits;
	plat->collide();
	uint16 maskAfter = plat->fixture->GetFilterData().maskBits;

	EXPECT_NE(maskBefore, maskAfter);
	EXPECT_EQ(maskExpected, maskAfter);
}

TEST(Platforms, OneWayPass)
{
	b2World * world = new b2World(b2Vec2(0, 9.81));
	TexManager * texMan = TexManager::getInstance();
	OneWayPlat * plat = new OneWayPlat(world, texMan, sf::Vector2f(0, 0), sf::Vector2f(1, 1), 0.f);

	uint16 maskExpected = 0x0000;
	uint16 maskBefore = plat->fixture->GetFilterData().maskBits;
	plat->pass();
	uint16 maskAfter = plat->fixture->GetFilterData().maskBits;

	EXPECT_NE(maskBefore, maskAfter);
	EXPECT_EQ(maskExpected, maskAfter);
}

//// SENSORS ////
TEST(SensorDoor, OnActionOpen)
{
	b2World * world = new b2World(b2Vec2(0, 9.81));
	TexManager * texMan = TexManager::getInstance();
	Door * door = new Door(world, texMan, sf::Vector2f(0, 0), 0.f);
	DoorSensor * sensor = new DoorSensor(world, sf::Vector2f(5, 5), sf::Vector2f(1, 1), door);

	int stateBefore = (int)door->state;
	sensor->onAction(door->door);
	int stateAfter = (int)door->state;
	int expected = 3;

	EXPECT_NE(stateBefore, stateAfter);
	EXPECT_EQ(expected, stateAfter);
}

TEST(SensorDoor, OffActionClose)
{
	b2World * world = new b2World(b2Vec2(0, 9.81));
	TexManager * texMan = TexManager::getInstance();
	Door * door = new Door(world, texMan, sf::Vector2f(0, 0), 0.f);
	DoorSensor * sensor = new DoorSensor(world, sf::Vector2f(5, 5), sf::Vector2f(1, 1), door);

	sensor->onAction(door->door);
	int stateBefore = (int)door->state;
	door->update(2.0f);
	sensor->offAction(door->door);
	int stateAfter = (int)door->state;
	int expected = 2;

	EXPECT_NE(stateBefore, stateAfter);
	EXPECT_EQ(expected, stateAfter);
}

TEST(SensorHome, OnActionTrue)
{
	b2World * world = new b2World(b2Vec2(0, 9.81));
	TexManager * texMan = TexManager::getInstance();
	Player * player = new Player(world, texMan, sf::Vector2f(0, 0), sf::Vector2f(1, 1), 0.f);
	HomeSensor * sensor = new HomeSensor(world, sf::Vector2f(5, 5), sf::Vector2f(1, 1), player);

	bool homeBefore = player->getHome();
	sensor->onAction(player->body);
	bool homeAfter = player->getHome();
	bool expected = true;

	EXPECT_NE(homeBefore, homeAfter);
	EXPECT_EQ(expected, homeAfter);
}

TEST(SensorHome, OffActionFalse)
{
	b2World * world = new b2World(b2Vec2(0, 9.81));
	TexManager * texMan = TexManager::getInstance();
	Player * player = new Player(world, texMan, sf::Vector2f(0, 0), sf::Vector2f(1, 1), 0.f);
	HomeSensor * sensor = new HomeSensor(world, sf::Vector2f(5, 5), sf::Vector2f(1, 1), player);

	sensor->onAction(player->body);
	bool homeBefore = player->getHome();
	sensor->offAction(player->body);
	bool homeAfter = player->getHome();
	bool expected = false;

	EXPECT_NE(homeBefore, homeAfter);
	EXPECT_EQ(expected, homeAfter);
}

//// HUD ////
TEST(HudUpdates, CoinUpdateScore)
{
	sf::Font font;
	TexManager * texMan = TexManager::getInstance();
	HUD * hud = new HUD(texMan, font);

	int scoreBefore = hud->scoreCount;
	hud->updateScore('C');
	int scoreAfter = hud->scoreCount;
	int expected = 5;

	EXPECT_NE(scoreBefore, scoreAfter);
	EXPECT_EQ(expected, scoreAfter);
}

TEST(HudUpdates, AppleUpdateScore)
{
	sf::Font font;
	TexManager * texMan = TexManager::getInstance();
	HUD * hud = new HUD(texMan, font);

	int scoreBefore = hud->scoreCount;
	hud->updateScore('A');
	int scoreAfter = hud->scoreCount;
	int expected = 10;

	EXPECT_NE(scoreBefore, scoreAfter);
	EXPECT_EQ(expected, scoreAfter);
}

TEST(HudUpdates, CherryUpdateScore)
{
	sf::Font font;
	TexManager * texMan = TexManager::getInstance();
	HUD * hud = new HUD(texMan, font);

	int scoreBefore = hud->scoreCount;
	hud->updateScore('H');
	int scoreAfter = hud->scoreCount;
	int expected = 15;

	EXPECT_NE(scoreBefore, scoreAfter);
	EXPECT_EQ(expected, scoreAfter);
}

TEST(HudUpdates, BanannaUpdateScore)
{
	sf::Font font;
	TexManager * texMan = TexManager::getInstance();
	HUD * hud = new HUD(texMan, font);

	int scoreBefore = hud->scoreCount;
	hud->updateScore('B');
	int scoreAfter = hud->scoreCount;
	int expected = 20;

	EXPECT_NE(scoreBefore, scoreAfter);
	EXPECT_EQ(expected, scoreAfter);
}

TEST(HudUpdates, LivesUpdate)
{
	sf::Font font;
	TexManager * texMan = TexManager::getInstance();
	HUD * hud = new HUD(texMan, font);

	int livesBefore = hud->lifeCount;
	hud->updateLives();
	int livesAfter = hud->lifeCount;

	EXPECT_GT(livesBefore, livesAfter);
}

TEST(HudUpdates, CoinCountUpdate)
{
	sf::Font font;
	TexManager * texMan = TexManager::getInstance();
	HUD * hud = new HUD(texMan, font);

	int coinsBefore = hud->coinCount;
	hud->updateCoins();
	int coinsAfter = hud->coinCount;

	EXPECT_GT(coinsBefore, coinsAfter);
}