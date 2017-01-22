#include "Enemy.h"

Enemy::Enemy(BITMAP *Screen, BITMAP *Image){
	mScreen = Screen;
	mSoundEffects = NULL;
	AllEnemyImages = Image; 
	mImagePage = create_bitmap(100,25);
	mCurImage = create_bitmap(25,25);
	mFrameDelay = 10;
	//	mCurImage = Image;
	
	
	mX = 0;
	mY = 0;
	mWidth = 25;
	mHeight = 25;
	mActive =false;
	mMovementCount = 0;
}

Enemy::~Enemy(){
}

void Enemy::update(){
	animate();
	movement();
	if(mX < 0)mActive = false;
}

void Enemy::mapMove(double XAmount, double YAmount){
	mX-=XAmount;
	mY+=YAmount;
}

void Enemy::spawn(Type EnemyType, int X, int Y){
	mEnemyType = EnemyType;
	mActive = true;
	switch(EnemyType){
		case One:
			mX = X;
			mY = Y;
			blit(AllEnemyImages,mImagePage,0,25,0,0,100,mHeight);
			break;
		case Two:
			mMovementCount = 0;
			mX = X+12;
			mY = Y-mHeight;
			blit(AllEnemyImages,mImagePage,0,0,0,0,100,mHeight);
			break;
		case Three:
			mMovementCount = 50;
			mX = X+12;
			mY = Y+100-mHeight;
			blit(AllEnemyImages,mImagePage,0,0,0,0,100,mHeight);
			break;
	}
}

void Enemy::deactive(){
	mActive = false;
}

bool Enemy::hit(int X, int Y){
	if(X >= mX && X <= mX+mWidth){
		if(Y >= mY && Y <= mY+mHeight){
			mActive = false;
			return true;
		}
	}
	return false;
}

bool Enemy::getActive(){
	return mActive;
}

//Private Method
void Enemy::movement(){
	if (mEnemyType == One){
		mX -= 3;	
	}else if(mEnemyType == Two || mEnemyType == Three){
		if(mMovementCount < 50){
			mY += 2;
		}else if(mMovementCount < 100){
			mY -= 2;
		}else{
			mMovementCount = 0;
		}
		mMovementCount++;
	}
}
