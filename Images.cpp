#include "Images.h"

Images::Images(){
	mPlayerImg = load_bitmap("Images/PlayerImages.bmp", NULL);
	mEnemyImg = load_bitmap("Images/EnemyImages.bmp", NULL);
	mPowerUpsImg = load_bitmap("Images/PowerUpImages.bmp", NULL);
	mGameScreenImgs = load_bitmap("Images/GameScreenImages.bmp", NULL);
	mStartScreenImg = load_bitmap("Images/StartScreenImages.bmp", NULL);
	mHelpScreenImg = load_bitmap("Images/HelpScreenImages.bmp", NULL);
	mGameOverScreenImg = load_bitmap("Images/GameOverScreenImages.bmp", NULL);
}

Images::~Images(){
	destroy_bitmap(mPlayerImg);
	destroy_bitmap(mEnemyImg);
	destroy_bitmap(mPowerUpsImg);
	destroy_bitmap(mGameScreenImgs);
	destroy_bitmap(mStartScreenImg);
	destroy_bitmap(mHelpScreenImg);
	destroy_bitmap(mGameOverScreenImg);
}

BITMAP *Images::getPlayerImage(){
	return mPlayerImg;
}

BITMAP *Images::getEnemyImage(){
	return mEnemyImg;
}

BITMAP *Images::getPowerUpsImage(){
	return mPowerUpsImg;
}

BITMAP *Images::getGameScreenImages(){
	return mGameScreenImgs;
}

BITMAP *Images::getStartScreenImage(){
	return mStartScreenImg;
}

BITMAP *Images::getHelpScreenImage(){
	return mHelpScreenImg;
}

BITMAP *Images::getGameOverScreenImage(){
	return mGameOverScreenImg;
}
