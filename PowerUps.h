//Written By: Mandip Sangha
//Created On: Oct 8, 2016

#ifndef POWERUPS_H
#define POWERUPS_H

#include "GameObject.h"

//PURPOSE - The Class is for the PowerUps object and uses the game object class as a parent
class PowerUps : public GameObject {
	public:
		//PURPOSE:	The different types of power up
		enum Type{DoubleJump = 1, Fly = 2, SlowTime = 3, Invulnerable = 4};
		
		//PURPOSE: 	Sets all variables to default setting for the object
		//INPUT:	Screen			- The game screen
		//			Image			- The images for the power ups
		//			SoundEffects	- The pointer to the sound effects
		//OUTPUT:	NONE
		PowerUps(BITMAP *Screen, BITMAP *Image, SoundEffects *mSoundEffects);
		//PURPOSE:	Free memory 
		//INPUT:	NONE
		//OUTPUT:	NONE
		~PowerUps();
		//PURPOSE:	Updates mActive if it run off the screen
		//INPUT:	NONE
		//OUTPUT:	NONE
		void update();
		//PURPOSE:	Moves the mX and mY by the amount given
		//INPUT:	XAmount			- The amount to move the mX by
		//			YAmount			- The amount to move the mY by 
		//OUTPUT:	NONE
		void mapMove(double XAmount, double YAmount);
		//PURPOSE:	Sets the power up type to draw 
		//INPUT:	PowerUpType		- The type of the power up to draw
		//			X				- The X position to be drawn at
		//			Y				- The Y position to be drawn at
		//OUTPUT:	NONE
		void setPowerUpType(Type PowerUpType, int X, int Y);
		//PURPOSE:	Deactives the power up 
		//INPUT:	NONE
		//OUTPUT:	NONE
		void deactive();
		//PURPOSE:	Check if the power up is hit the X and Y provided
		//INPUT:	X				- The x position to check
		//			Y				- The y position to check
		//OUTPUT:	Returns true if hit else false
		bool hit(int X, int Y);
		//PURPOSE:	Check if the power up is active
		//INPUT:	NONE
		//OUTPUT:	mActive
		bool getActive();
		//PURPOSE:	Returns the type of power up it is
		//INPUT:	NONE
		//OUTPUT:	mPowerUpType
		Type getType();
		//PURPOSE:	Returns the total of power up types there are
		//INPUT:	NONE
		//OUTPUT:	mTotalNumberOfTypes
		int getTotalNumberOfTypes();
	private:
		//PURPOSE:	Holds the type of power up it is
		Type mPowerUpType;
		//PURPOSE:	Holds the total number of power up types
		int mTotalNumberOfTypes;
		//PURPOSE:	Hold whether the power up is active or not
		bool mActive;
};

#endif
