//Written By: Mandip Sangha
//Created On: Oct 9, 2016

#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <allegro.h>
#include <iostream>
#include <string>
#include <sstream>

#include "BaseInterface.h"
#include "SoundEffects.h"

using namespace std;

//PURPOSE - To create the live game screen for the game and uses the base interface class as a parent
class GameScreen : public BaseInterface {
	public:
		//PURPOSE:	THe different types of power ups
		enum PowerUpType{None = 0, DoubleJump = 1, Fly = 2, SlowTime = 3, Invulnerable = 4};
		
		//PURPOSE: 	Sets the default values for the object variables
		//INPUT:	Screen 		- The pointer to game screen
		//			ImagePage 		- The pointer to bitmap of start screen images
		//			SoundEffect	- The pointer to the sound effects
		//OUTPUT:	NONE
		GameScreen(BITMAP *Screen, BITMAP *ImagePage);
		//PURPOSE:	Free memory of buttons
		//INPUT:	NONE
		//OUTPUT:	NONE
		~GameScreen();
		//PURPOSE:	Updates the game timers
		//INPUT:	NONE
		//OUTPUT:	NONE
		void update();
		//PURPOSE:	Draws the live games status bar graphic
		//INPUT:	NONE
		//OUTPUT:	NONE
		void draw();
		//PURPOSE:	Help with debugging
		//INPUT:	NONE
		//OUTPUT:	NONE
		void debug();
		//PURPOSE:	Set the mScore and loads score image
		//INPUT:	Amount			- The amount to set the score
		//OUTPUT:	NONE
		void setScore(int Amount);
		//PURPOSE:	Activate's the power up given and sets variable to the right for
		//				amount
		//INPUT:	Type			- The type of power up to activate
		//OUTPUT:	NONE
		void setPowerUpType(PowerUpType Type);
		//PURPOSE:	Returns the mPowerUpType
		//INPUT:	NONE
		//OUTPUT:	mPowerUpType
		int getPowerUpType();
		//PURPOSE:	Returns the mScore
		//INPUT:	NONE
		//OUTPUT:	mScore
		int getScore();
	private:
		//PURPOSE:	Holds the player current score
		int mScore;
		//PURPOSE:	Hold current time left for an active power up
		int mPowerUpTimer;
		//PURPOSE:	The X positon of the current power up in the status bar
		int mActivePowerUpX;
		//PURPOSE:	The Y positon of the current power up in the status bar
		int mActivePowerUpY;
		//PURPOSE:	The width of individual number
		int mIndividualNumberWidth;
		//PURPOSE:	The height of individual number
		int mIndividualNumberHeight;
		//PURPOSE:	The current number of digits in the score
		int mCurrentDigitNumberScore;
		//PURPOSE:	The current number of digits in the timer	
		int mCurrentDigitNumberTimer;
		//PURPOSE:	The current power up type
		PowerUpType mPowerUpType;
		//PURPOSE:	The current score image
		BITMAP *mScoreImg;
		//PURPOSE:	The current active power up image
		BITMAP *mActivePowerUpImg;
		//PURPOSE:	The active power up text image
		BITMAP *mActivePowerUpTextImg;
		//PURPOSE:	The timer text image
		BITMAP *mTimerTextImg;
		//PURPOSE:	Holds all the power up images
		BITMAP *mAllPowerUpImg;
		//PURPOSE:	Holds all the digit images
		BITMAP *mAllDigitImg;
		
		//PURPOSE:	Set the score image based on the score
		//INPUT:	NONE
		//OUTPUT:	NONE
		void setScoreImg();
		//PURPOSE:	Set the timer image based on the timer
		//INPUT:	NONE
		//OUTPUT:	NONE
		void setTimerImg();
};

#endif
