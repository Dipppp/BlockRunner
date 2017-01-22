#include "PowerUps.h"

PowerUps::PowerUps(BITMAP *Screen, BITMAP *Image, SoundEffects *SoundEffects){
	mScreen = Screen;
	
	mImagePage = Image;
	mCurImage = create_bitmap(25,25); 
	mSoundEffects = SoundEffects;
		//mCurImage = Image;
	
	mTotalNumberOfTypes = 4;
	
	mX = 0;
	mY = 0;
	mWidth = 25;
	mHeight = 25;
	mActive =false;
}

PowerUps::~PowerUps(){
}
		
void PowerUps::update(){
	if(mX+mWidth < 0)mActive =false;
	if(mY+mHeight < 0)mActive = false;
	if(mY > 600)mActive = false;
}

void PowerUps::mapMove(double XAmount, double YAmount){
	mX-=XAmount;
	mY-=YAmount;
}

void PowerUps::setPowerUpType(Type PowerUpType, int X, int Y){
	mY = Y+25;
	mX = X+12;
	mActive = true;
	switch (PowerUpType){
		case DoubleJump:
			mPowerUpType = DoubleJump;
			blit(mImagePage,mCurImage,0,0,0,0,mWidth,mHeight);
			break;
		case Fly:
			mPowerUpType = Fly;
			blit(mImagePage,mCurImage,25,0,0,0,mWidth,mHeight);
			break;
		case SlowTime:
			mPowerUpType = SlowTime;
			blit(mImagePage,mCurImage,50,0,0,0,mWidth,mHeight);
			break;
		case Invulnerable:
			mPowerUpType = Invulnerable;
			blit(mImagePage,mCurImage,75,0,0,0,mWidth,mHeight);
			break;
	}
}

void PowerUps::deactive(){
	mActive = false;
}

bool PowerUps::hit(int X, int Y){
	if(X >= mX && X <= mX+mWidth){
		if(Y >= mY && Y <= mY+mHeight){
			mActive = false;
			switch (mPowerUpType){
				case DoubleJump:
					mSoundEffects->playSoundEffect(SoundEffects::PowerUp);
					break;
				case Fly:
					mSoundEffects->playSoundEffect(SoundEffects::PowerUp);
					break;
				case SlowTime:
					mSoundEffects->playSoundEffect(SoundEffects::TickTock);
					break;
				case Invulnerable:
					mSoundEffects->playSoundEffect(SoundEffects::PowerUp);
					break;
			}
			return true;
		}
	}
	return false;
}

bool PowerUps::getActive(){
	return mActive;
}

PowerUps::Type PowerUps::getType(){
	return mPowerUpType;
}

int PowerUps::getTotalNumberOfTypes(){
	return mTotalNumberOfTypes;
}
