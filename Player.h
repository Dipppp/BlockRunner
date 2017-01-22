//Written By: Mandip Sangha
//Created On: Oct 4, 2016

#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

//PURPOSE - The Class is for the players object and uses the game object class as a parent
class Player : public GameObject {
	public:
		//PURPOSE:	Collision types
		enum CollideType{CUp = 0, CRight = 1, CDown = 2, CLeft = 3};
		
		//PURPOSE: 	Sets all variables to default setting for the object
		//INPUT:	Screen			- The game screen
		//			Image			- The images for the player
		//			SoundEffects	- The pointer to the sound effects
		//OUTPUT:	NONE
		Player(BITMAP *Screen, BITMAP *Image, SoundEffects *SoundEffects);
		//PURPOSE:	Free memory 
		//INPUT:	NONE
		//OUTPUT:	NONE
		~Player();
		//PURPOSE:	Move the player to the left by the amount given
		//INPUT:	Amount			- The amount to move by
		//OUTPUT:	NONE
		void mapMove(double Amount);
		//PURPOSE:	Use to make the player jump or fly if it is active
		//				and set mCurState and set mImagePage
		//INPUT:	NONE
		//OUTPUT:	NONE
		void jump();
		//PURPOSE:	Use to make the player jump right or fly right if it is active
		//				and set mCurState and set mImagePage
		//INPUT:	NONE
		//OUTPUT:	NONE
		void jumpRight();
		///PURPOSE:	Use to make the player right or fly right if it is active
		//				and set mCurState and set mImagePage
		//INPUT:	NONE
		//OUTPUT:	NONE
		void moveRight();
		//PURPOSE:	Use to make the player duck right or fly down and right if it is active
		//				and set mCurState and set mImagePage
		//INPUT:	NONE
		//OUTPUT:	NONE
		void duckRight();
		//PURPOSE:	Use to make the player jump left or fly left if it is active
		//				and set mCurState and set mImagePage	
		//INPUT:	NONE
		//OUTPUT:	NONE
		void jumpLeft();
		//PURPOSE:	Use to make the player left or fly left if it is active
		//				and set mCurState and set mImagePage	
		//INPUT:	NONE
		//OUTPUT:	NONE
		void moveLeft();
		///PURPOSE:	Use to make the player duck left or fly down left if it is active
		//				and set mCurState and set mImagePage
		//INPUT:	NONE
		//OUTPUT:	NONE
		void duckLeft();
		//PURPOSE:	Use to make the player duck or fly down if it is active
		//				and set mCurState and set mImagePage	
		//INPUT:	NONE
		//OUTPUT:	NONE
		void duck();
		//PURPOSE:	Use to make the player stand and set mCurState and set mImagePage	
		//INPUT:	NONE
		//OUTPUT:	NONE
		void stand();
		//PURPOSE:	The game gravity that pulls the player down by
		//INPUT:	GravitySpeed	- The gravity speed to add the players mYSpeed
		//OUTPUT:	NONE
		void gravityMoveDown(int GravitySpeed);
		//PURPOSE:	Updates the players animate and player x and y speed
		//INPUT:	NONE
		//OUTPUT:	NONE
		void update();
		//PURPOSE:	Draws the player's image
		//INPUT:	NONE
		//OUTPUT:	NONE
		void draw();
		//PURPOSE:	Reset the players data to the default start values
		//INPUT:	NONE
		//OUTPUT:	NONE
		void reset();
		//PURPOSE:	Set the offset readjustment values
		//INPUT:	XOffSet			- The current map X offset
		//			YOffSet			- The current map Y offset
		//OUTPUT:	NONE
		void mapOffSets(int XOffSet, int YOffSet);
		//PURPOSE:	Stops the player's speed and readjust the player position if need
		//				for the direction given
		//INPUT:	Direction		- The direction collision was in
		//OUTPUT:	NONE
		void collide(CollideType Direction);
		//PURPOSE:	Sets the type of power up that was actived 
		//INPUT:	Type			- Power up type to activate
		//OUTPUT:	NONE
		void setPowerUp(int Type);
		//PURPOSE:	Set whether the duck is pressed 
		//INPUT:	Pressed			- Holds whether the duck is pressed
		//OUTPUT:	NONE
		void setDuckPress(bool Pressed);
		//PURPOSE:	Return's the player's x position
		//INPUT:	NONE
		//OUTPUT:	mX
		int getX();
		//PURPOSE:	Return's the player's y position
		//INPUT:	NONE
		//OUTPUT:	mY
		int getY();
		//PURPOSE:	Return's the player's x speed 
		//INPUT:	NONE
		//OUTPUT:	mXSpeed
		int getXSpeed();
		//PURPOSE:	Return's the player's x speed 	
		//INPUT:	NONE
		//OUTPUT:	mYSpeed
		int getYSpeed();
		//PURPOSE:	Return's the player's width
		//INPUT:	NONE
		//OUTPUT:	mWidth
		int getWidth();
		//PURPOSE:	Return the player's	height
		//INPUT:	NONE
		//OUTPUT:	mHeight
		int getHeight();
		
	private:
		//PURPOSE: 	The different states can be in
		enum State{Stand = 0, Right = 1, JumpRight = 2, DuckRight = 3, Jump = 4, Duck = 5, Left = 6, JumpLeft = 7, DuckLeft = 8,
					FlyUp =9, FlyDown = 10, FlyRight = 11, FlyLeft = 12, FlyUpRight =13, FlyUpLeft = 14, FlyDownRight = 15, FlyDownLeft = 16};
		//PURPOSE: 	The current state the player is in 
		State mCurState;
		//PURPOSE:	The max amount of time the player can jump before hitting the ground
		int mJumpAmountMax;
		//PURPOSE:	The amount of time the player can jump before hitting the ground
		int mJumpAmount;
		//PURPOSE: 	The current map x offset readjustment
		double mMapXOffSetReAdjustment;
		//PURPOSE: 	The current map x offset readjustment
		double mMapYOffSetReAdjustment;
		//PURPOSE:	Hold's whether the player can fly
		bool mFlying;
		//PURPOSE:	Hold's whether the players duck is pressed
		bool mDuckingPressed;
		//PURPOSE:	Hold's all the players image
		BITMAP *mAllImages;
		
		//PURPOSE:	Reposition the player position if there's collision on the bottom
		//INPUT:	NONE
		//OUTPUT:	NONE
		void collisionBottomReposition();
		//PURPOSE:	Reposition the player position if there's collision on the right
		//INPUT:	NONE
		//OUTPUT:	NONE
		void collisionRightReposition();
		//PURPOSE:	Reposition the player position if there's collision on the left
		//INPUT:	NONE
		//OUTPUT:	NONE
		void collisionLeftReposition();
		//PURPOSE:	Stop the player's y speed
		//INPUT:	NONE
		//OUTPUT:	NONE
		void stopVerticalSpeed();
		//PURPOSE:	Stop the player's X speed
		//INPUT:	NONE
		//OUTPUT:	NONE
		void stopHorizontalSpeed();
};

#endif
