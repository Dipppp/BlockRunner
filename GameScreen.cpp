#include "GameScreen.h"

GameScreen::GameScreen(BITMAP *Screen, BITMAP *ImagePage){
	mScreen = Screen;
	mImagePage = ImagePage;
	mBackgroundWidth = SCREEN_W;
	mBackgroundHeight = 75;
	mBackgroundImage = create_bitmap(mBackgroundWidth,mBackgroundHeight);
	blit(mImagePage,mBackgroundImage,0,0,0,0,mBackgroundWidth,mBackgroundHeight);
	mActivePowerUpTextImg = create_bitmap(60,12); 
	blit(mImagePage,mActivePowerUpTextImg,0,75,0,0,60,12);
	mAllDigitImg = create_bitmap(100,12);
	blit(mImagePage,mAllDigitImg,0,88,0,0,100,12);
	mAllPowerUpImg = create_bitmap(100,25);
	blit(mImagePage,mAllPowerUpImg,0,101,0,0,100,25);
	mActivePowerUpImg = create_bitmap(25,25);
	mScore = 0;
	mPowerUpType = None;
	mPowerUpTimer = 0;
	
	mIndividualNumberWidth = 10;
	mIndividualNumberHeight = 12;
	mCurrentDigitNumberScore = 1;
	mCurrentDigitNumberTimer = 1;
	mScoreImg = create_bitmap(mIndividualNumberWidth*mCurrentDigitNumberScore,mIndividualNumberHeight);
	mTimerTextImg = create_bitmap(mIndividualNumberWidth*mCurrentDigitNumberTimer,mIndividualNumberHeight);
}

GameScreen::~GameScreen(){
	destroy_bitmap(mScoreImg);
	destroy_bitmap(mActivePowerUpImg);
	destroy_bitmap(mActivePowerUpTextImg);
	destroy_bitmap(mTimerTextImg);
	destroy_bitmap(mAllPowerUpImg);
	destroy_bitmap(mAllDigitImg);
}

void GameScreen::update(){
	mPowerUpTimer--;
	if(mPowerUpTimer > 0)setTimerImg();
	if(mPowerUpTimer == 0)mPowerUpType = None;
}

void GameScreen::draw(){
	BaseInterface::draw();
	draw_sprite(mScreen, mScoreImg, 121, 15);
	if(mPowerUpTimer >= 0){
		draw_sprite(mScreen, mTimerTextImg, 121, 42);
		draw_sprite(mScreen, mActivePowerUpImg, mActivePowerUpX, mActivePowerUpY);
		draw_sprite(mScreen, mActivePowerUpTextImg, mActivePowerUpX+30, mActivePowerUpY+5);
	}
}

void GameScreen::debug(){
	textprintf_ex(mScreen, font, 0,30, 2, -1,"Score %d",mScore);
	textprintf_ex(mScreen, font, 0,40, 2, -1,"Type %d",mPowerUpType);
}

void GameScreen::setScore(int Amount){
	mScore = Amount*10;
	setScoreImg();
}

void GameScreen::setPowerUpType(PowerUpType Type){
	switch (Type){
		case DoubleJump:
			mActivePowerUpX = 300;
			mActivePowerUpY = 10;
			blit(mAllPowerUpImg,mActivePowerUpImg,0,0,0,0,25,25);
			if(mPowerUpType == Type)mPowerUpTimer += 150;
			else mPowerUpTimer = 150;
			break;
		case Fly:
			mActivePowerUpX = 300;
			mActivePowerUpY = 41;
			blit(mAllPowerUpImg,mActivePowerUpImg,25,0,0,0,25,25);
			if(mPowerUpType == Type)mPowerUpTimer += 100;
			else mPowerUpTimer = 100;
			break;
		case SlowTime:
			mActivePowerUpX = 550;
			mActivePowerUpY = 10;
			blit(mAllPowerUpImg,mActivePowerUpImg,50,0,0,0,25,25);
			if(mPowerUpType == Type)mPowerUpTimer += 20;
			else mPowerUpTimer = 20;
			break;
		case Invulnerable:
			mActivePowerUpX = 550;
			mActivePowerUpY = 41;
			blit(mAllPowerUpImg,mActivePowerUpImg,75,0,0,0,25,25);
			if(mPowerUpType == Type)mPowerUpTimer += 25;
			else mPowerUpTimer = 25;
			break;
		case None:
			mPowerUpTimer = -1;
			break;
	}
	mPowerUpType = Type;
}

int GameScreen::getPowerUpType(){
	return (int)mPowerUpType;
}

int GameScreen::getScore(){
	return mScore;
}

//Private method 
void GameScreen::setScoreImg(){
	int temp = mScore;
	int numDigit = 0;
	int digit = 0;
	int x, y, x2; 
	if(mScore > 0){
		while(temp !=0){
			temp /= 10;
			numDigit++;
		}
		if(mCurrentDigitNumberScore != numDigit){
			mCurrentDigitNumberScore = numDigit;
			destroy_bitmap(mScoreImg);
			mScoreImg = create_bitmap(mIndividualNumberWidth*mCurrentDigitNumberScore,mIndividualNumberHeight);
		}
		temp = mScore;
		while(temp !=0){
			digit = temp % 10;
			temp /= 10;
			x = mIndividualNumberWidth*digit;
			x2 = mIndividualNumberWidth*(numDigit-1);
			numDigit -= 1;
			blit(mAllDigitImg,mScoreImg,x,0,x2,0,mIndividualNumberWidth,mIndividualNumberHeight);	
		}
		
	}else{
		blit(mAllDigitImg,mScoreImg,0,0,0,0,mIndividualNumberWidth,mIndividualNumberHeight);
	}
}

void GameScreen::setTimerImg(){
	int temp = mPowerUpTimer;
	int numDigit = 0;
	int digit = 0;
	int x, y, x2; 
	if(mScore > 0){
		while(temp !=0){
			temp /= 10;
			numDigit++;
		}
		if(mCurrentDigitNumberTimer != numDigit){
			mCurrentDigitNumberTimer = numDigit;
			destroy_bitmap(mTimerTextImg);
			mTimerTextImg = create_bitmap(mIndividualNumberWidth*mCurrentDigitNumberTimer,mIndividualNumberHeight);
		}
		temp = mPowerUpTimer;
		while(temp !=0){
			digit = temp % 10;
			temp /= 10;
			x = mIndividualNumberWidth*digit;
			x2 = mIndividualNumberWidth*(numDigit-1);
			numDigit -= 1;
			blit(mAllDigitImg,mTimerTextImg,x,0,x2,0,mIndividualNumberWidth,mIndividualNumberHeight);	
		}
		
	}else{
		blit(mAllDigitImg,mTimerTextImg,0,0,0,0,mIndividualNumberWidth,mIndividualNumberHeight);
	}
}
