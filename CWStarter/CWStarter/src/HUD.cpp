#include "HUD.h"

HUD::HUD(TexManager *texMan, sf::Font &font)
{
	banner = new Texture();
	coin = new Texture();
	x = 0.4f;
	coinCount = 30;	
	scoreCount = 0;
	lifeCount = 5;
	min = 8;
	sec = 59;
	eTime = 0;
	passed = font;

	texMan->setTexture("all", banner);
	texMan->getFrames("Banner", banner);
	banner->setSize(sf::Vector2f(0.01f, 0.005f));
	bannerOffset = sf::Vector2f(0.0f, -1.5f);

	texMan->setTexture("all", coin);
	texMan->getFrames("UICoin", coin);
	coin->setSize(sf::Vector2f(0.015f, 0.015f));
	coinOffset = sf::Vector2f(1.5f, 1.1f);

	for (int i = 0; i < 5; i++)
	{
		lives[i] = new Texture();
		lifeOffset[i] = sf::Vector2f(x, -1.4f);
		x -= 0.2f;
	}

	for (Texture* life : lives)
	{
		texMan->setTexture("all", life);
		texMan->getFrames("Life", life);
		life->setSize(sf::Vector2f(0.01f, 0.01f));
	}

	score.setFont(passed);
	score.setFillColor(sf::Color::Blue);
	score.setOutlineColor(sf::Color::Black);
	score.setOutlineThickness(1);
	score.setCharacterSize(40);
	score.setScale(sf::Vector2f(0.005f, 0.005f));
	scoreOffset = sf::Vector2f(-1.8f, -1.5f);	

	time.setFont(passed);
	time.setFillColor(sf::Color::Blue);
	time.setOutlineColor(sf::Color::Black);
	time.setOutlineThickness(1);
	time.setCharacterSize(40);
	time.setScale(sf::Vector2f(0.005f, 0.005f));
	timeOffset = sf::Vector2f(1.0f, -1.5f);

	coins.setFont(passed);
	coins.setFillColor(sf::Color(241, 203, 35, 255));
	coins.setOutlineColor(sf::Color(237, 161, 59, 255));
	coins.setOutlineThickness(1);
	coins.setCharacterSize(40);
	coins.setScale(sf::Vector2f(0.005f, 0.005f));
	coinsOffset = sf::Vector2f(1.35f, 1.0f);
}

void HUD::moveHUD(sf::Vector2f pos)
{
	sf::Vector2f Bpos = sf::Vector2f(pos.x + bannerOffset.x, pos.y + bannerOffset.y);
	banner->setPos(Bpos);

	for (int i = 0; i < 5; i++)
	{
		sf::Vector2f Lpos = sf::Vector2f(pos.x + lifeOffset[i].x, pos.y + lifeOffset[i].y);
		lives[i]->setPos(Lpos);
	}

	sf::Vector2f Cpos = sf::Vector2f(pos.x + coinOffset.x, pos.y + coinOffset.y);
	coin->setPos(Cpos);

	sf::Vector2f Spos = sf::Vector2f((pos.x + scoreOffset.x), (pos.y + scoreOffset.y));
	score.setPosition(Spos);

	sf::Vector2f Cspos = sf::Vector2f((pos.x + coinsOffset.x), (pos.y + coinsOffset.y));
	coins.setPosition(Cspos);

	sf::Vector2f Tpos = sf::Vector2f((pos.x + timeOffset.x), (pos.y + timeOffset.y));
	time.setPosition(Tpos);
}

void HUD::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	banner->draw(target, states);
	coin->draw(target, states);

	for (int i = 0; i < lifeCount; i++)
		lives[i]->draw(target, states);
	target.draw(score);
	target.draw(coins);
	target.draw(time);
}

void HUD::update(float timestep)
{
	banner->update(timestep);
	coin->update(timestep);
	for (Texture* life : lives) life->update(timestep);

	score.setString(std::to_string(scoreCount));

	if (coinCount != 0)
		coins.setString(std::to_string(coinCount));
	else
	{
		coins.setCharacterSize(30);
		coinsOffset = sf::Vector2f(1.3f, 1.0f);
		coins.setString("EXIT");
	}

	eTime += timestep;
	if (eTime > 1.f)
	{
		if (sec != 0)
			sec--;
		else
		{
			if (min != 0)
			{
				min--;
				sec = 59;
			}
		}
		eTime = 0;
		//std::cout << min << ":" << sec << std::endl;
	}
	if (sec < 10)
		time.setString(std::to_string(min) + ":0" + std::to_string(sec));
	else
		time.setString(std::to_string(min) + ":" + std::to_string(sec));
}

void HUD::updateCoins()
{
	if (coinCount != 0)
		coinCount--;
}

void HUD::updateLives()
{
	if (lifeCount != 0)
		lifeCount--;
}

void HUD::updateScore(char Type)
{
	switch (Type)
	{
	case 'C':
		scoreCount += 5;
		break;
	case 'A':
		scoreCount += 10;
		break;
	case 'H':
		scoreCount += 15;
		break;
	case 'B':
		scoreCount += 20;
		break;
	}

	//std::cout << "Score: " << scoreCount << std::endl;
}

int HUD::getLives()
{
	return lifeCount;
}

int HUD::finalScore()
{
	int Mbonus = min * 60;
	int Sbonus = sec;
	int total = scoreCount + Mbonus + Sbonus;

	return total;
}

int HUD::getCoins()
{
	return coinCount;
}