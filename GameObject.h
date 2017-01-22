//Written By: Mandip Sangha
//Created On: Oct 1, 2016

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <allegro.h>
#include <math.h>

#include "SoundEffects.h"

//PURPOSE - The Class is the base class for all game objects
class GameObject {
	public:
		//PURPOSE: 	Sets all variables to default setting for the object
		//INPUT:	NONE
		//OUTPUT:	NONE
		GameObject();
		//PURPOSE:	Free the mCurImage bitmap from memory
		//INPUT:	NONE
		//OUTPUT:	NONE
		~GameObject();
		//PURPOSE:	Draw the objects sprite to the buffer use the picture/image in mCurImage bitmap
		//INPUT:	NONE
		//OUTPUT:	NONE
		void draw();
		
	private:
	protected:
		//PURPOSE:	The X, Y position and the Width, Height and Speed of the object
		double mX, mY;
		int mWidth, mHeight;
		double mXSpeed, mYSpeed;
		//PURPOSE:	The current frame in the animation sequence that the object is in
		int mCurFrame;
		int mFrameMax;
		int mFrameCount, mFrameDelay;
		//PURPOSE:	The delay for the object after the object been destroyed
		int mDestroyedTimer;
		//PURPOSE:	The pointer to the bitmap that is the game screen and what everything is drawn on
		BITMAP *mScreen;
		//PURPOSE:	The current image of the object to draw
		BITMAP *mCurImage;
		//PURPOSE:	The image that holds all the images for all the animation states
		BITMAP *mImagePage;
		//PURPOSE: The pointer to the sound effects
		SoundEffects *mSoundEffects;
		
		//PURPOSE:	Calls the animate method to animate the object
		//INPUT:	NONE
		//OUTPUT:	NONE
		void update();
		//PURPOSE:	Move's the object vertically
		//INPUT:	NONE
		//OUTPUT:	NONE
		void moveVertical();
		//PURPOSE:	Move's the object horzonitally
		//INPUT:	NONE
		//OUTPUT:	NONE
		void moveHorzonital();
		//PURPOSE:	Animates the object
		//INPUT:	NONE
		//OUTPUT:	NONE
		void animate();
};

#endif
