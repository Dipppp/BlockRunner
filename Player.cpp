#include "Player.h"

Player::Player(BITMAP *Screen, BITMAP *Image, SoundEffects *SoundEffects){
	mScreen = Screen;
	mCurState = Stand;
	mSoundEffects = SoundEffects;
	
	mAllImages = Image;
	//mCurImage = Image;
	mJumpAmountMax = 2;
	mJumpAmount = 0;
	mFlying = false;
	mFrameDelay = 1;
	
	mX = 50;
	mY = 200;
	mWidth = 50;
	mHeight = 100;
	mXSpeed = 0;
	mYSpeed = 0;
	mImagePage = create_bitmap(100,100); 
	blit(mAllImages,mImagePage,0,0,0,0,100,100);
	mCurImage = create_bitmap(50,100); 
	blit(mImagePage,mCurImage,0,0,0,0,50,100);
}

Player::~Player(){
	destroy_bitmap(mImagePage);
}

void Player::mapMove(double Amount){
	mX-=Amount;
}

void Player::jump(){
	if(!mFlying){
		if(mJumpAmount < mJumpAmountMax && mYSpeed <0){
			mYSpeed = 20;
			mSoundEffects->playSoundEffect(SoundEffects::Jump);
			mJumpAmount++;
		}
		if(mCurState != Jump){
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(150,100); 
			blit(mAllImages,mImagePage,0,100,0,0,150,100);
			
			mCurFrame = -1;
			mFrameCount = 3;
			mFrameMax = 3;
			mCurState = Jump;
			
			
		}
	}else{
		mYSpeed = 5;
		if(mCurState != FlyUp){
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(100,100); 
			blit(mAllImages,mImagePage,0,600,0,0,100,100);
			mCurFrame = -1;
			mFrameCount = 3;
			mFrameMax = 2;
			mCurState = FlyUp;
			mSoundEffects->playSoundEffect(SoundEffects::Fire);
		}
	}
}

void Player::jumpRight(){
	if(!mFlying){
		mXSpeed = 5;
		if(mJumpAmount < mJumpAmountMax && mYSpeed <0){
			mYSpeed = 20;
			mSoundEffects->playSoundEffect(SoundEffects::Jump);
			mJumpAmount++;
		}
		if( mCurState != JumpRight ){
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(200,100); 
			blit(mAllImages,mImagePage,0,400,0,0,200,100);
			mCurFrame = -1;
			mFrameCount = 3;
			mFrameMax = 4;
			mCurState = JumpRight;
		}
	}else{
		mYSpeed = 5;
		mXSpeed = 5;
		if(mCurState != FlyUpRight){
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(100,100); 
			blit(mAllImages,mImagePage,0,700,0,0,100,100);
			mCurFrame = -1;
			mFrameCount = 3;
			mFrameMax = 2;
			mCurState = FlyUpRight;
			mSoundEffects->playSoundEffect(SoundEffects::Fire);
		}
	}
}

void Player::moveRight(){
	if(!mFlying){
		mXSpeed = 5;
		if(mCurState != Right && mCurState != Jump && mCurState != JumpRight && mCurState != JumpLeft){
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(250,100); 
			blit(mAllImages,mImagePage,0,200,0,0,250,100);
			mCurFrame = -1;
			mFrameCount = mFrameDelay;
			mFrameMax = 5;
			mCurState = Right;
		}
	}else{
		mXSpeed = 5;
		if(mCurState != FlyRight){
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(100,100); 
			blit(mAllImages,mImagePage,0,1000,0,0,100,100);
			mCurFrame = -1;
			mFrameCount = 3;
			mFrameMax = 2;
			mCurState = FlyRight;
			mSoundEffects->playSoundEffect(SoundEffects::Fire);
		}
	}
}

void Player::duckRight(){
	if(!mFlying){
		mXSpeed = 5;
		if(mCurState != DuckRight && mCurState != Jump && mCurState != JumpRight && mCurState != JumpLeft){
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(100,50); 
			blit(mAllImages,mImagePage,0,1500,0,0,100,50);
			mCurFrame = -1;
			mFrameCount = 3;
			mFrameMax = 2;
			mCurState = DuckRight;
		}
	}else{
		mYSpeed = -5;
		mXSpeed = 5;
		if(mCurState != FlyDownRight){
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(100,100); 
			blit(mAllImages,mImagePage,0,1200,0,0,100,100);
			mCurFrame = -1;
			mFrameCount = 3;
			mFrameMax = 2;
			mCurState = FlyDownRight;
			mSoundEffects->playSoundEffect(SoundEffects::Fire);
		}
	}
}

void Player::jumpLeft(){
	if(!mFlying){
		mXSpeed = -5;
		if(mJumpAmount < mJumpAmountMax && mYSpeed <0){
			mYSpeed = 20;
			mSoundEffects->playSoundEffect(SoundEffects::Jump);
			mJumpAmount++;
		}
		if( mCurState != JumpLeft){
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(200,100); 
			blit(mAllImages,mImagePage,0,500,0,0,200,100);
			mCurFrame = -1;
			mFrameCount = 3;
			mFrameMax = 4;
			mCurState = JumpLeft;
		}
	}else{
		mYSpeed = 5;
		mXSpeed = -5;
		if(mCurState != FlyUpLeft){
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(100,100); 
			blit(mAllImages,mImagePage,0,800,0,0,100,100);
			mCurFrame = -1;
			mFrameCount = 3;
			mFrameMax = 2;
			mCurState = FlyUpLeft;
			mSoundEffects->playSoundEffect(SoundEffects::Fire);
		}
	}
}

void Player::moveLeft(){
	if(!mFlying){
		mXSpeed = -5;
		if(mCurState != Left && mCurState != Jump && mCurState != JumpRight && mCurState != JumpLeft){
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(250,100); 
			blit(mAllImages,mImagePage,0,300,0,0,250,100);
			mCurFrame = -1;
			mFrameCount = mFrameDelay;
			mFrameMax = 5;
			mCurState = Left;
		}
	}else{
		mXSpeed = -5;
		if(mCurState != FlyLeft){
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(100,100); 
			blit(mAllImages,mImagePage,0,1100,0,0,100,100);
			mCurFrame = -1;
			mFrameCount = 3;
			mFrameMax = 2;
			mCurState = FlyLeft;
			mSoundEffects->playSoundEffect(SoundEffects::Fire);
		}
	}
}

void Player::duckLeft(){
	if(!mFlying){
		mXSpeed = -5;
		if(mCurState != DuckLeft && mCurState != Jump && mCurState != JumpRight && mCurState != JumpLeft){
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(100,50); 
			blit(mAllImages,mImagePage,0,1600,0,0,250,50);
			mCurFrame = -1;
			mFrameCount = 3;
			mFrameMax = 2;
			mCurState = DuckLeft;
		}
	}else{
		mYSpeed = -5;
		mXSpeed = -5;
		if(mCurState != FlyDownLeft){
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(100,100); 
			blit(mAllImages,mImagePage,0,1300,0,0,100,100);
			mCurFrame = -1;
			mFrameCount = 3;
			mFrameMax = 2;
			mCurState = FlyDownLeft;
			mSoundEffects->playSoundEffect(SoundEffects::Fire);
		}
	}
}

void Player::duck(){
	if(!mFlying){
		if(mCurState != Duck && mCurState != Jump && mCurState != JumpRight && mCurState != JumpLeft){
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(50,50); 
			blit(mAllImages,mImagePage,0,1400,0,0,50,50);
			mCurFrame = -1;
			mFrameCount = 3;
			mFrameMax = 1;
			mCurState = Duck;
			mJumpAmount=0;
		}
	}else{
		mYSpeed = -5;
		if(mCurState != FlyDown){
			destroy_bitmap(mImagePage);
			mImagePage = create_bitmap(100,100); 
			blit(mAllImages,mImagePage,0,900,0,0,100,100);
			mCurFrame = -1;
			mFrameCount = 3;
			mFrameMax = 2;
			mCurState = FlyDown;
			mSoundEffects->playSoundEffect(SoundEffects::Fire);
		}
	}
}

void Player::stand(){
	if(mCurState != Stand){
		destroy_bitmap(mImagePage);
		mImagePage = create_bitmap(100,100); 
		blit(mAllImages,mImagePage,0,0,0,0,100,100);
		mCurFrame = -1;
		mFrameCount = 3;
		mFrameMax = 2;
		mCurState = Stand;
		mJumpAmount=0;
	}
}

void Player::gravityMoveDown(int GravitySpeed){
	if(mYSpeed>= -5 && !mFlying )mYSpeed-=GravitySpeed;
	if(mY >= 450 && mYSpeed < 0){
		//mYSpeed=0;
		mY = 450;
	}
}

void Player::update(){
	GameObject::animate();
	if(mCurState == Jump && !mFlying && mCurFrame == 2)mCurFrame = 1;
	if((mCurState == JumpLeft || mCurState == JumpRight )&& !mFlying && mCurFrame == 3)mCurFrame = 1;
	if(mX >= 700 && mXSpeed >=5){
		stopHorizontalSpeed();
	}else if(mX <= 100 && mXSpeed <= -5){
		stopHorizontalSpeed();
	}
	if(mY <= 100 && mYSpeed>0){}
	else GameObject::moveVertical();
	GameObject::moveHorzonital();
	mXSpeed = 0;
	if(mFlying)mYSpeed = 0;
}

void Player::draw(){
	if(mCurState == Duck || mCurState == DuckRight || mCurState == DuckLeft){
		draw_sprite(mScreen, mCurImage, mX, mY+(mHeight/2));
	}else{
		GameObject::draw();
	}
}

void Player::reset(){
	mCurState = Stand;
	mJumpAmountMax = 1;
	mJumpAmount = 0;
	mFlying = false;
	mX = 50;
	mY = 200;
	mWidth = 50;
	mHeight = 100;
	mXSpeed = 0;
	mYSpeed = 0;
	destroy_bitmap(mImagePage);
	destroy_bitmap(mCurImage);
	mImagePage = create_bitmap(100,100); 
	blit(mAllImages,mImagePage,0,0,0,0,100,100);
	mCurImage = create_bitmap(50,100); 
	blit(mImagePage,mCurImage,0,0,0,0,50,100);
}

void Player::mapOffSets(int XOffSet, int YOffSet){
	mMapXOffSetReAdjustment = XOffSet % 50;
	mMapYOffSetReAdjustment = YOffSet % 50;
}

void Player::collide(CollideType Direction){
	if(Direction == CUp && mYSpeed > 0)stopVerticalSpeed();
	else if(Direction == CDown && mYSpeed < 0){
		stopVerticalSpeed();
		collisionBottomReposition();
		
	}else if(Direction == CRight && mXSpeed > 0){
		stopHorizontalSpeed();
		collisionRightReposition();
	}else if(Direction == CLeft && mXSpeed < 0){
		stopHorizontalSpeed();
		collisionLeftReposition();
	}
	
	if(Direction == CDown && mYSpeed <= 0 && mXSpeed == 0){
		if(mDuckingPressed)duck();
		else stand();		
	}
}

void Player::setPowerUp(int Type){
	switch(Type){
		case 0:
			mJumpAmountMax = 1;
			mFlying = false;
			break;
		case 1:
			mJumpAmountMax = 2;
			break;
		case 2:
			mFlying =true;
			break;
	}
}

void Player::setDuckPress(bool Pressed){
	bool oldpress = mDuckingPressed;
	mDuckingPressed = Pressed;
	if(oldpress != mDuckingPressed  && mYSpeed == 0){
		if(mDuckingPressed && !mFlying){
			destroy_bitmap(mCurImage);
			mCurImage = create_bitmap(50,50); 
			clear_to_color(mCurImage, makecol(255,0,255));
		}else{
			destroy_bitmap(mCurImage);
			mCurImage = create_bitmap(50,100); 
			clear_to_color(mCurImage, makecol(255,0,255));
		}
	}
}

int Player::getX(){
	return mX;
}

int Player::getY(){
	if(mDuckingPressed)return mY+(mHeight/2);
	return mY;	
}

int Player::getXSpeed(){
	return mXSpeed;	
}

int Player::getYSpeed(){
	return mYSpeed;
}

int Player::getWidth(){
	return mWidth;
}

int Player::getHeight(){
	if(mDuckingPressed)return mHeight/2;
	return mHeight;
}

//Private Method
void Player::collisionBottomReposition(){
	int a = 1;
	if(mMapYOffSetReAdjustment==0)a=0;
	int temp = mY/50;
	temp = (temp+a) *50 ;
	mY = temp - mMapYOffSetReAdjustment;
}

void Player::collisionRightReposition(){
	int a = 0;
	if(mMapXOffSetReAdjustment >4)a=1;
	int temp = mX/50;
	temp = (temp+a) *50 ;
	mX = temp - mMapXOffSetReAdjustment;
}

void Player::collisionLeftReposition(){
	int a = 1;
	//if(mapXOffSetReAdjustment >4)a=0;
	int temp = mX/50;
	temp = (temp+a) *50 ;
	mX = temp - mMapXOffSetReAdjustment;
}

void Player::stopVerticalSpeed(){
	mYSpeed=0;
}

void Player::stopHorizontalSpeed(){
	mXSpeed=0;
}
