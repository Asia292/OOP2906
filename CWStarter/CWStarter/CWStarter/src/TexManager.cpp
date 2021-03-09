#include "TexManager.h"

TexManager::TexManager()
{
	//// SET SPRITESHEETS ////
	spritesheets["lvl1"] = loadSprite(".\\assets\\map1-1.png");
	spritesheets["lvl2"] = loadSprite(".\\assets\\map1-2.png");
	spritesheets["all"] = loadSprite(".\\assets\\allSprites.png");

	//// SET INT RECTS ////
	//// PLAYER ////
	setFrames("Idle", std::vector<sf::IntRect> { sf::IntRect(581, 60, 27, 37) });
	setFrames("Run", std::vector<sf::IntRect>
	{ sf::IntRect(325, 12, 30, 37),
		sf::IntRect(357, 12, 30, 37),
		sf::IntRect(389, 12, 30, 37),
		sf::IntRect(421, 12, 30, 37),
		sf::IntRect(453, 12, 30, 37),
		sf::IntRect(485, 12, 30, 37)});
	setFrames("SideJump", std::vector<sf::IntRect>
	{ sf::IntRect(613, 5, 27, 45),
		sf::IntRect(584, 5, 27, 45),
		sf::IntRect(547, 5, 27, 45),
		sf::IntRect(33, 54, 30, 45)});
	setFrames("Jump", std::vector<sf::IntRect>
	{ sf::IntRect(199, 2, 24, 48),
		sf::IntRect(231, 2, 24, 48),
		sf::IntRect(262, 2, 24, 48),
		sf::IntRect(295, 2, 24, 48)});
	setFrames("Daze", std::vector<sf::IntRect>
	{ sf::IntRect(100, 60, 27, 37),
		sf::IntRect(132, 60, 27, 37),
		sf::IntRect(164, 60, 27, 37),
		sf::IntRect(196, 60, 27, 37),
		sf::IntRect(228, 60, 27, 37),
		sf::IntRect(260, 60, 27, 37),
		sf::IntRect(292, 60, 27, 37),
		sf::IntRect(324, 60, 27, 37),
		sf::IntRect(356, 60, 27, 37),
		sf::IntRect(388, 60, 27, 37),
		sf::IntRect(420, 60, 27, 37),
		sf::IntRect(452, 60, 27, 37),
		sf::IntRect(485, 60, 27, 37),
		sf::IntRect(516, 60, 27, 37),
		sf::IntRect(549, 60, 27, 37),
		sf::IntRect(581, 60, 27, 37)});
	setFrames("Poof", std::vector<sf::IntRect>
	{ sf::IntRect(129, 103, 31, 43),
		sf::IntRect(161, 103, 31, 43),
		sf::IntRect(192, 103, 31, 43),
		sf::IntRect(223, 103, 31, 43),
		sf::IntRect(254, 103, 31, 43),
		sf::IntRect(289, 103, 31, 43),
		sf::IntRect(318, 103, 31, 43),
		sf::IntRect(349, 103, 31, 43),
		sf::IntRect(382, 103, 31, 43),
		sf::IntRect(416, 103, 31, 43),
		sf::IntRect(448, 103, 31, 43),
		sf::IntRect(479, 103, 31, 43),
		sf::IntRect(512, 103, 31, 43),
		sf::IntRect(256, 212, 27, 37)});

	//// ENEMIES ////
	setFrames("Bee", std::vector<sf::IntRect> 
	{ sf::IntRect(319, 244, 69, 40), 
		sf::IntRect(403, 244, 69, 40) });
	setFrames("HedgeHog", std::vector<sf::IntRect>
	{ sf::IntRect(19, 248, 55, 42),
		sf::IntRect(79, 248, 55, 42),
		sf::IntRect(136, 248, 55, 42),
		sf::IntRect(195, 248, 55, 42)});
	setFrames("SquishH", std::vector<sf::IntRect> { sf::IntRect(79, 220, 55, 70) });
	setFrames("SquishB", std::vector<sf::IntRect> { sf::IntRect(319, 244, 69, 40) });

	//// COLLECTABLES ////
	setFrames("Coin", std::vector<sf::IntRect>
	{ sf::IntRect(10, 164, 43, 43),
		sf::IntRect(54, 164, 43, 43),
		sf::IntRect(97, 164, 43, 43),
		sf::IntRect(141, 164, 43, 43),
		sf::IntRect(189, 164, 43, 43),
		sf::IntRect(234, 164, 43, 43)});
	setFrames("Cherry", std::vector<sf::IntRect> { sf::IntRect(427, 181, 18, 18) });
	setFrames("Apple", std::vector<sf::IntRect> { sf::IntRect(491, 182, 17, 17) });
	setFrames("Banan", std::vector<sf::IntRect> { sf::IntRect(400, 158, 15, 16) });

	//// MISC ////
	setFrames("Spring", std::vector<sf::IntRect> { sf::IntRect(337, 168, 35, 34) });
	setFrames("Platform", std::vector<sf::IntRect> { sf::IntRect(23, 304, 167, 97) });
	setFrames("Box", std::vector<sf::IntRect> { sf::IntRect(552, 161, 43, 41) });
	setFrames("Wall", std::vector<sf::IntRect> { sf::IntRect(561, 216, 52, 67) });
	setFrames("Door", std::vector<sf::IntRect> { sf::IntRect(517, 218, 17, 65) });

	//// UI ////
	setFrames("Banner", std::vector<sf::IntRect> { sf::IntRect(195, 303, 438, 94) });
	setFrames("Life", std::vector<sf::IntRect> { sf::IntRect(459, 154, 17, 15) });
	setFrames("UICoin", std::vector<sf::IntRect> { sf::IntRect(10, 164, 43, 43) });

	//// SET ANIMATION TIMES ////
	//// PLAYER ////
	animTime["Run"] = 0.5f;
	animTime["Jump"] = 1.f;
	animTime["Daze"] = 1.5f;
	animTime["Poof"] = 1.5f;
	//// MISC ////
	animTime["Bee"] = 0.4f;
	animTime["HedgeHog"] = 2.0f;
	animTime["Coin"] = 0.75f;
}


std::shared_ptr<sf::Texture> TexManager::loadSprite(std::string location)
{
	std::shared_ptr<sf::Texture> tex(new sf::Texture);
	if (!tex->loadFromFile(location))
		std::cout << "Cant load " << location << std::endl;

	return tex;
}

std::shared_ptr<sf::Texture> TexManager::getTexture(std::string keyName)
{
	return spritesheets[keyName];
}

void TexManager::setTexture(std::string keyName, Texture * target)
{
	target->setSpriteSheet(spritesheets[keyName]);
}

void TexManager::setFrames(std::string keyName, std::vector<sf::IntRect> keyFrames)
{
	frames[keyName] = keyFrames;
}

void TexManager::getFrames(std::string keyName, Texture * target)
{
	currState = keyName;
	target->setKeyFrames(frames[keyName], animTime[keyName]);
}

std::string TexManager::getState()
{
	//std::cout << currState << std::endl;
	return currState;
}

TexManager * TexManager::onlyInstance = nullptr;
unsigned short int TexManager::instanceCount = 0;
TexManager * TexManager::getInstance()
{
	if (instanceCount != 0)
		return onlyInstance;
	else
	{
		onlyInstance = new TexManager;
		instanceCount = 1;
		return onlyInstance;
	}
}

void TexManager::delInstance()
{
	//delete onlyInstance;
	onlyInstance = nullptr;
	instanceCount = 0;
}

TexManager::~TexManager()
{
	delInstance();
}