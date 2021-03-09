#pragma once
/*!
\file Player.h
*/

/*! \class Player
\brief Creates and controls the player
*/
#include "Character.h"

class Player : public Character
{
protected:
	sf::Vector2f Size;	//!< The size of the player
	bool isGrounded;	//!< If the player is grounded
	bool home;		//!< If the player has reached home
public:
	Player() {};	//!< Default constructor
	Player(b2World * world, TexManager *texMan, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation);		//!< Full constructor
	void moveLeft();	//!< Moves the player left
	void moveRight();	//!< Moves the player right
	void jump();	//!< Makes the player jump
	bool hit;	//!< If the player has been hit or not
		
	float getHeight();		//!< Gets the height of the player, used to compare its position to other objects
	b2Vec2 getVelo();		//!< Gets the players velocity
	b2Vec2 getPos();		//!< Gets the players position
	void setGrounded(bool ground);		//!< Sets the isGrounded bool
	void changeFrames(std::string frame);		//!< Changes the players animation
	void update(float timestep);		//!< Calls Character update and returns animation to idle if needed
	void resetFrame();		//!< Sets the frame to 0 to start animation from beginning
	void setHit(bool Hit);		//!< Sets the hit bool
	bool getHit();		//!< Returns the hit bool
	int getCurrFrame();		//!< Returns the current frame of the animation
	void setHome(bool Home);		//!< Sets the home bool
	bool getHome();		//!< Returns the home bool
};