//Written By: Mandip Sangha
//Created On: Oct 17, 2016
//NOTE: All image created by Mandip Sangha
//depreciate

#ifndef IMAGES_H
#define IMAGES_H

#include <allegro.h>


//PURPOSE - The Class is for loading all the images the game uses and puts them
//				in bitmap pointers
class Images {
	public:
		//PURPOSE:	Loads all the game image to there respective bitmaps
		//INPUT:	NONE
		//OUTPUT:	NONE
		Images();
		//PURPOSE:	Release all the bitmaps
		//INPUT:	NONE
		//OUTPUT:	NONE
		~Images();
		//PURPOSE:	Returns the bitmap pointer to the player's images
		//INPUT:	NONE
		//OUTPUT:	Return mPlayerImg
		BITMAP *getPlayerImage();
		//PURPOSE:	Returns the bitmap pointer to the all enemy types images
		//INPUT:	NONE
		//OUTPUT:	Return mEnemyImg
		BITMAP *getEnemyImage();
		//PURPOSE:	Returns the bitmap pointer to the all power up types images
		//INPUT:	NONE
		//OUTPUT:	Return mPowerUpsImg
		BITMAP *getPowerUpsImage();
		//PURPOSE:	Returns the bitmap pointer to the game screen's images
		//INPUT:	NONE
		//OUTPUT:	Return mGameScreenImg
		BITMAP *getGameScreenImages();
		//PURPOSE:	Returns the bitmap pointer to the start screen's images
		//INPUT:	NONE
		//OUTPUT:	Return mStartScreenImg
		BITMAP *getStartScreenImage();
		//PURPOSE:	Returns the bitmap pointer to the help screen's images
		//INPUT:	NONE
		//OUTPUT:	Return mHelpScreenImg
		BITMAP *getHelpScreenImage();
		//PURPOSE:	Returns the bitmap pointer to the gameover screen's images
		//INPUT:	NONE
		//OUTPUT:	Return mGameOverScreenImg
		BITMAP *getGameOverScreenImage();
	private:
		//PURPOSE:	Pointer the to the player's loaded images
		BITMAP *mPlayerImg;
		//PURPOSE:	Pointer the to the enemies loaded images
		BITMAP *mEnemyImg;
		//PURPOSE:	Pointer the to the power ups loaded images
		BITMAP *mPowerUpsImg;
		//PURPOSE:	Pointer the to the game screen loaded images
		BITMAP *mGameScreenImgs;
		//PURPOSE:	Pointer the to the start screen loaded images
		BITMAP *mStartScreenImg;
		//PURPOSE:	Pointer the to the help screen loaded images
		BITMAP *mHelpScreenImg;
		//PURPOSE:	Pointer the to the gameover screen loaded images
		BITMAP *mGameOverScreenImg;
};

#endif
