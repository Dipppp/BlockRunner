//Written By: Mandip Sangha
//Created On: Oct 1, 2016
//Modified On: Nov 14, 2016

#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <allegro.h>
#include "mappyal.h"
#include "defines.h"

#include "SoundEffects.h"
#include "Music.h"
#include "Images.h"
#include "StartScreen.h"
#include "HelpScreen.h"
#include "GameOverScreen.h"
#include "GameScreen.h"

#include "Player.h"
#include "PowerUps.h"
#include "Enemy.h"

//PURPOSE - Controls the whole game logic
class GameLogic {
	public:
		//PURPOSE:	Set all the default values for the game
		//INPUT:	NONE
		//OUTPUT:	NONE
		GameLogic();
		//PURPOSE:	Release all the pointers for game objects
		//INPUT:	NONE
		//OUTPUT:	NONE
		~GameLogic();
		//PURPOSE:	Updates all the game object and calls the user input method
		//				and collsion methods
		//INPUT:	NONE
		//OUTPUT:	NONE
		void update();
		//PURPOSE:	Draws all the game object on to the screen 
		//INPUT:	NONE
		//OUTPUT:	NONE
		void draw();
		//PURPOSE:	Used to debug the game
		//INPUT:	NONE
		//OUTPUT:	NONE
		void debug();
		//PUROSE:	To start music(USED ONLY FOR THREAD DEMONSTRATION)
		//INPUT:	NONE
		//OUTPUT:	Returns if music started
		bool startMusic();
		//PURPOSE:	Returns the speed of the game
		//INPUT:	NONE
		//OUTPUT:	mGameSpeed
		int getGameSpeed();
		
	private:
		//PURPOSE:	The bitmap the hold the game screen displayed to the user
		BITMAP *mBuffer;
		//PURPOSE:	Pointer to the player object	
		Player *mPlayer;
		//PURPOSE:	The pointer to the start screen
		StartScreen *mStartScreen;
		//PURPOSE:	The pointer to the help screen
		HelpScreen *mHelpScreen;
		//PURPOSE:	The pointer to the gameover screen
		GameOverScreen *mGameOverScreen;
		//PURPOSE:	The pointer to the game screen
		GameScreen *mGameScreen;
		//PURPOSE:	The pointer to all the images
		//Images *mImages;
		//PURPOSE:	Pointer to the game data
		DATAFILE *mData; 
		//PURPOSE:	The pointer to the sound effects
		SoundEffects *mSoundEffects;
		//PURPOSE:	The pointer to the music
		Music *mMusic;
		//PURPOSE:	The pointer to the power ups
		PowerUps **mPowerUps;
		//PURPOSE:	The pointer to the enemies
		Enemy **mEnemy;
		
		//PURPOSE:	The speed of the game
		int mGameSpeed;
		//PURPOSE:	The max speed the game can go
		int mGameSpeedMax;
		//PURPOSE:	The total number of power ups
		int mTotalPowerPointer;
		//PURPOSE:	The total number of enemies
		int mTotalEnemyPointer;
		//PURPOSE:	Holds the last column of the game map
		int mLastColumn;
		//PURPOSE:	Holds the maps X offset
		double mMapXOffSet;
		//PURPOSE:	Holds the maps Y offset
		double mMapYOffSet;
		//PURPOSE:	Holds the maps X offset speed
		double mMapXOffSetSpeed;
		//PURPOSE:	Holds the maps Y offset speed
		double mMapYOffSetSpeed;
		//PURPOSE:	Holds whether the player is ducking
		bool mPlayerDucked;
		//PURPOSE:	Holds whether the game is over
		bool mGameOver;
		//PURPOSE:	Holds whether the music is start or not
		bool mMusicStarted;
		
		//From book
		//PURPOSE:	Check the collision with the game map
		//INPUT:	x			- The x position to check
		//			y			- The y position to check
		//OUTPUT:	Return true if it does else false
		bool collided(int x, int y);
		//PURPOSE:	Checks if the player collided on the right side
		//INPUT:	NONE
		//OUTPUT:	Return true if it does else false
		bool checkPlayerRightCollision();
		//PURPOSE:	Checks if the player collided on the left side
		//INPUT:	NONE
		//OUTPUT:	Return true if it does else false
		bool checkPlayerLeftCollision();
		//PURPOSE:	Checks if the player collided on the bottom side
		//INPUT:	NONE
		//OUTPUT:	Return true if it does else false
		bool checkPlayerBottomCollision();
		//PURPOSE:	Checks if the player collided on the top side
		//INPUT:	NONE
		//OUTPUT:	Return true if it does else false
		bool checkPlayerTopCollision();
		//PURPOSE:	Does the corresponding action to the player for the inputs
		//INPUT:	NONE
		//OUTPUT:	NONE
		void playerInput();
		//PURPOSE:	Update the player data
		//INPUT:	NONE
		//OUTPUT:	NONE
		void playerLogic();
		//PURPOSE:	Does the corresponding action to the interface for the inputs
		//INPUT:	NONE
		//OUTPUT:	NONE
		void interfaceInputs();
		//PURPOSE:	Spawns the power ups when they show up on the map
		//INPUT:	NONE
		//OUTPUT:	NONE
		void spawnPowerUp();
		//PURPOSE:	Check if anything collides with power ups
		//INPUT:	NONE
		//OUTPUT:	NONE
		void checkPowerUpCollision();
		//PURPOSE:	Updates the power up data
		//INPUT:	NONE
		//OUTPUT:	NONE
		void powerUpLogic();
		//PURPOSE:	Spawns the enemies when they show up on the map
		//INPUT:	NONE
		//OUTPUT:	NONE
		void spawnEnemy();
		//PURPOSE:	Check if anything collides with enemies
		//INPUT:	NONE
		//OUTPUT:	NONE
		void checkEnemyCollision();
		//PURPOSE:	Updates the enemy data
		//INPUT:	NONE
		//OUTPUT:	NONE
		void enemyLogic();
};

#endif
