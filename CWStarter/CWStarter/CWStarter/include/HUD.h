#pragma once
/*!
\file HUD.h
*/

/*! \class HUD
\brief Updates and displays information to player - lives, score, time
*/
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>

#include "TexManager.h"

class HUD : public Texture
{
	/*
	NEED
		- Background banner
		- Life sprites
		- Score count
		- Coin count (count down from set total needed)
		- Time(?)
	*/
private:
	Texture *banner;	//!< Banner sprite at the top of the screen
	Texture *lives[5];		//!< Life sprites
	Texture *coin;		//!< Coin sprite

	float x;	//!< X offset for life sprites
	float eTime;	//<! Elapsed time
	int min;	//!< Minutes of display time
	int sec;	//!< Seconds of display time
	int scoreCount;		//!< Players score
	int coinCount;		//!< Number of coins
	int lifeCount;		//!< Number of lives

	sf::Vector2f bannerOffset;		//!< Banner position relative to player
	sf::Vector2f lifeOffset[5];		//!< Lives position relative to player
	sf::Vector2f timeOffset;		//!< Time position relative to player
	sf::Vector2f coinOffset;		//!< Coin sprite position relative to player
	sf::Vector2f scoreOffset;		//!< Score position relative to player
	sf::Vector2f coinsOffset;		//!< Coin count position relative to player

	sf::Font passed;	//!< The font passed in
	sf::Text time;		//!< Time text
	sf::Text score;		//!< Score tect
	sf::Text coins;		//!< Number of coins text

public:
	HUD(TexManager *texMan, sf::Font &font);	//!< Constructor
	void moveHUD(sf::Vector2f pos);		//!< Move the HUD so it is always on screen
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;		//!< Draws everything
	void update(float timestep);		//!< Updates the textures and score, coin count and time text
	void updateScore(char Type);		//!< Updates the score value
	void updateCoins();		//!< Updates coin value
	void updateLives();		//!< Updates life count
	int getLives();		//!< Returns life count
	int finalScore();		//!< Calculates the final score - adds remaining time as a bonus
	int getCoins();		//!< Returns the coin count

};