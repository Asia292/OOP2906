#pragma once
/*!
\file Enemy.h
*/

/*! \class Enemy
\brief Creates and manipulates enemies
*/
#include "Character.h"

class Enemy : public Character
{
protected:
	b2Vec2 right;	//!< Rightmost position of patrol
	b2Vec2 left;	//!< Leftmost position of patrol
	sf::Vector2f Size;		//!< The size of the enemy
	bool pat;		//!< If the enemy should patrol or not
	bool hitOnce;		//!< If the enemy has been hit once
	bool hitTwice;		//!< If the enemy has been hit twice
	sf::Clock timer;	//!< Timer to see how long the enemy hasnt been patrolling for
	char Type;		//!< The type of enemy
public:
	Enemy() {};		//!< Default constructor
	~Enemy();		//!< Deconstructor
	Enemy(b2World * world, TexManager *texMan, char type, const sf::Vector2f& position, const sf::Vector2f &size, const float orientation);		//!< Full constructor

	bool moveR;		//!< If the enrmy should be moving right

	void patrol();		//!< Changes moveR bool based on position and applies velocity as required
	void setMove();		//!< Sets the moveR bool to its opposite
	void attacked();	//!< Changes enemies sprite, stops it patrolling and resets its timer when attacked by player
	void setPat(bool patr);		//!< Specifies the pat bool
	void setHit2(bool hit2);	//!< Specifies the hitTwice bool
	void setHit1(bool hit1);	//!< Specifies the hitOnce bool
	void update(float timestep);		//!< Calls Character update and patrol
	void changeFrames(std::string frame);		//!< Changes the enemies animation
	void reset();		//!< Resets the enemies animations, sets hit bools to false and starts patrol again

	bool getHit1();		//!< Return hitOnce bool
	bool getHit2();		//!< Return hitTwice bool
	bool getMove();		//!< Returns the moveR bool

	float getTime();	//!< Returns the time from the timer
	float getHeight();	//!< Gets the height of the enemy, used to compare its position to other objects
};