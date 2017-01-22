#include "GameObject.h"

GameObject::GameObject(){
	//Default setting
	mX = 0;
	mY = 0;
	mWidth = 0;
	mHeight = 0;
	mXSpeed = 0;
	mYSpeed = 0;
	
	mCurFrame = 0;
	mFrameMax = 4;
	mFrameCount	= 0;
	mFrameDelay = 30;
}

GameObject::~GameObject(){
	destroy_bitmap(mCurImage);
}

void GameObject::draw(){
	draw_sprite(mScreen, mCurImage, mX, mY);
}

void GameObject::update(){
	animate();
}

void GameObject::moveVertical(){
	mY -= mYSpeed;
}

void GameObject::moveHorzonital(){
	mX += mXSpeed;
}

void GameObject::animate(){
	mFrameCount++;
	if(mFrameCount > mFrameDelay){
		mCurFrame++;
		if(mCurFrame >= mFrameMax){
				mCurFrame = 0;
		}
		blit(mImagePage,mCurImage,mCurFrame * mWidth,0,0,0,mWidth,mHeight);
		mFrameCount = 0;	
	}
}

