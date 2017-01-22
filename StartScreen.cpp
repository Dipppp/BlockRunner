#include "StartScreen.h"

StartScreen::StartScreen(BITMAP *Screen, BITMAP *ImagePage, SoundEffects *SoundEffect){
	mScreen = Screen;
	mImagePage = ImagePage;
	mBackgroundWidth = SCREEN_W;
	mBackgroundHeight = SCREEN_H;
	mBackgroundImage = create_bitmap(mBackgroundWidth,mBackgroundHeight);
	blit(mImagePage,mBackgroundImage,0,0,0,0,mBackgroundWidth,mBackgroundHeight);
	
	mStartButton = new Button(SoundEffect,248,159,303,103);
	mStart = false;
	mHelpButton = new Button(SoundEffect,248,278,303,103);
	mHelp = false;
	mCreditButton = new Button(SoundEffect,248,400,303,103);
	mBackButton = new Button(SoundEffect,0,0,250,103);
	mIntro=false;
	mCredit=false;
	timer = 75;
}

StartScreen::~StartScreen(){
	delete mStartButton;
	delete mHelpButton;
	delete mCreditButton;
}

void StartScreen::update(){
	if(!mIntro){
		blit(mImagePage,mBackgroundImage,1600,0,0,0,mBackgroundWidth,mBackgroundHeight);
	}else{
		if(!mCredit)blit(mImagePage,mBackgroundImage,0,0,0,0,mBackgroundWidth,mBackgroundHeight);
		else blit(mImagePage,mBackgroundImage,800,0,0,0,mBackgroundWidth,mBackgroundHeight);
	}
	timer--;
	if(timer <= 0)mIntro=true;
}

void StartScreen::clicked(int X, int Y){
	if(mIntro && !mCredit){
		if(mStartButton->clicked(X,Y))mStart = true;
		if(mCreditButton->clicked(X,Y))mCredit = true;
		if(mHelpButton->clicked(X,Y))mHelp = true;
	}
	if(mIntro && mCredit){
		if(mBackButton->clicked(X,Y))mCredit = false;
	}
}

void StartScreen::debug(){
	//for checking if button is in right position
	if(mIntro){
		if(!mCredit){
			mStartButton->draw(mScreen);
			mHelpButton->draw(mScreen);
			mCreditButton->draw(mScreen);
		}else {
			mBackButton->draw(mScreen);
		}
	}
}

bool StartScreen::getStarted(){
	return mStart;
}

bool StartScreen::getHelp(){
	if(mHelp){
		mHelp = false;
		return true;
	}
	return false;
}
