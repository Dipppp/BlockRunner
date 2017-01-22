#include "GameLogic.h"

GameLogic::GameLogic(){
	mData = load_datafile("GameData.dat"); 
	char mapLoc[] = {"Images/Map.FMP"};
	MapLoad(mapLoc);
	mBuffer = create_bitmap(SCREEN_W, SCREEN_H);
	clear(mBuffer);
	//mImages = new Images();
	mSoundEffects = new SoundEffects(mData);
	mMusic = new Music(mData);
	mPlayer = new Player(mBuffer,(BITMAP *)mData[PLAYERIMAGES_BMP].dat,mSoundEffects);
	mStartScreen = new StartScreen(mBuffer,(BITMAP *)mData[STARTSCREENIMAGES_BMP].dat,mSoundEffects);
	mHelpScreen = new HelpScreen(mBuffer,(BITMAP *)mData[HELPSCREENIMAGES_BMP].dat,mSoundEffects);
	mGameOverScreen = new GameOverScreen(mBuffer,(BITMAP *)mData[GAMEOVERSCREENIMAGES_BMP].dat,mSoundEffects);
	mGameScreen = new GameScreen(mBuffer,(BITMAP *)mData[GAMESCREENIMAGES_BMP].dat);
		
	
	mTotalPowerPointer = 5;
	mPowerUps = new PowerUps*[mTotalPowerPointer];
	for(int i = 0; i < mTotalPowerPointer; i++){
		mPowerUps[i] = new PowerUps(mBuffer,(BITMAP *)mData[POWERUPIMAGES_BMP].dat,mSoundEffects);
	}
	
	mTotalEnemyPointer = 3;
	mEnemy = new Enemy*[mTotalEnemyPointer];
	for(int i = 0; i < mTotalEnemyPointer; i++){
		mEnemy[i] = new Enemy(mBuffer,(BITMAP *)mData[ENEMYIMAGES_BMP].dat);
	}
	
	mMapXOffSet = 50;
	mMapYOffSet = 250;
	mPlayerDucked = false;
	
	mGameSpeed = mGameSpeedMax = 60;
	mMapXOffSetSpeed = 1;
	mMapYOffSetSpeed = 0;
	
	mGameOver = false;
	mMusicStarted = false;
	
	mLastColumn = 0;
}

GameLogic::~GameLogic(){
	//delete mImages;
	
	delete mSoundEffects;
	delete mPlayer;
	delete mStartScreen;
	delete mHelpScreen;
	delete mGameOverScreen;
	delete mGameScreen;
	for(int i = 0; i < mTotalPowerPointer; i++){
		delete mPowerUps[i];
	}
	delete mPowerUps;
	destroy_bitmap(mBuffer);
	MapFreeMem ();
	unload_datafile(mData); 
	
}

void GameLogic::update(){
	interfaceInputs();
	if(!mGameOver){
		if(!mStartScreen->getStarted())mStartScreen->update();
		if(mStartScreen->getHelp())mHelpScreen->mainHelpSwitch();
		if(mStartScreen->getStarted() && !mHelpScreen->getActive()){
			
			playerLogic();
			powerUpLogic();
			enemyLogic();
			mLastColumn = mMapXOffSet/mapblockwidth +17;
			if(mGameScreen->getPowerUpType() == 3) mGameSpeed-=10;
			else mGameSpeed = mGameSpeedMax;
			mMapXOffSet+=mMapXOffSetSpeed;
			mMapYOffSet+=mMapYOffSetSpeed;
			mGameScreen->setScore(mMapXOffSet);
			mGameScreen->update();
			if(mMapYOffSet >= 550 || mPlayer->getX()+mPlayer->getWidth() <= 0){
				mGameOver = true;
				mGameOverScreen->gameoverSwitch(mGameScreen->getScore());
			}
			if(((int)mMapXOffSet % 1200) == 0)mMapXOffSetSpeed++;
		}
	}else{
		mGameOverScreen->update();
		if(mGameOverScreen->getPlayAgain()){
			mGameOverScreen->unSetPlayAgain();
			mPlayer->reset();
			mGameScreen->setScore(0);
			mGameScreen->setPowerUpType(GameScreen::None);
			for(int j = 0; j < mTotalEnemyPointer; j++){
					mEnemy[j]->deactive();
			}
			for(int j = 0; j < mTotalPowerPointer; j++){
				mPowerUps[j]->deactive();
			}
			mMapXOffSet = 1;
			mMapYOffSet = 300;
			mPlayerDucked = false;
			
			mGameSpeed = mGameSpeedMax = 60;
			mMapXOffSetSpeed = 1;
			mMapYOffSetSpeed = 0;
			
			mGameOver = false;
		}
	}
}

void GameLogic::draw(){
	clear(mBuffer);
	if(!mGameOver){
		if(mHelpScreen->getActive()) mHelpScreen->draw();
		if(!mStartScreen->getStarted() && !mHelpScreen->getActive()) mStartScreen->draw();
		if(mStartScreen->getStarted() && !mHelpScreen->getActive()){
			//draw the background tiles
			MapDrawBG(mBuffer, mMapXOffSet, mMapYOffSet, 0, 0, SCREEN_W, SCREEN_H);
		    //draw foreground tiles
			MapDrawFG(mBuffer, mMapXOffSet, mMapYOffSet, 0, 0, SCREEN_W, SCREEN_H, 0);
			//draw the active power ups
			for(int i = 0; i < mTotalPowerPointer; i++){
				if(mPowerUps[i]->getActive())mPowerUps[i]->draw();
			}
			for(int i = 0; i < mTotalEnemyPointer; i++){
				if(mEnemy[i]->getActive())mEnemy[i]->draw();
			}
			//draw the players
			mPlayer->draw();
			//draw the active game screen in game menu
			mGameScreen->draw();
		}
	}else{
		mGameOverScreen->draw();
	}
	blit(mBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
}

void GameLogic::debug(){
	if(mHelpScreen->getActive()) mHelpScreen->debug();
	if(!mStartScreen->getStarted() && !mHelpScreen->getActive()) mStartScreen->debug();
	if(mStartScreen->getStarted() && !mHelpScreen->getActive()){
		rectfill(mBuffer, 0, 0, 500, 100, makecol(255,255,255));
		textprintf_ex(mBuffer, font, 0,0, 2, -1,"player X %d, offset X %f",mPlayer->getX(),mMapXOffSet); 
		//textprintf_ex(mBuffer, font, 0,20, 2, -1,"offset speed X %f",mMapXOffSetSpeed); 
		textprintf_ex(mBuffer, font, 0,10, 2, -1,"player Y %d, offset Y %f",mPlayer->getY(),mMapYOffSet); 
		textprintf_ex(mBuffer, font, 0,20, 2, -1,"player Y speed %d",mPlayer->getYSpeed()); 
		/*int j;
		for( j = 0; j < mTotalPowerPointer; j++){
			if(!mPowerUps[j]->getActive())break;
		}
		textprintf_ex(mBuffer, font, 350,0, 2, -1,"Active power up %d",j); 
		mGameScreen->debug();*/
	}
	
	blit(mBuffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
}

bool GameLogic::startMusic(){
	if(mStartScreen->getStarted() && !mHelpScreen->getActive()){
		if(!mMusicStarted){
			mMusic->play();
			mMusicStarted = true;
			return true;
		}
	}
	return false;
}

int GameLogic::getGameSpeed(){
	return mGameSpeed;
}

//Private Method
bool GameLogic::collided(int x, int y){
	BLKSTR *blockdata;
	
	int testX = ((double)mMapXOffSet/(double)mapblockwidth)+((double)x/(double)mapblockwidth);
	int testY = ((double)mMapYOffSet/(double)mapblockheight)+((double)y/(double)mapblockheight);
	blockdata = MapGetBlock((int)testX, (int)testY);
	return blockdata->tl || blockdata->tr || blockdata->bl || blockdata->br;
}

bool GameLogic::checkPlayerRightCollision(){
	//Does use speed because it keeps it from hit wall complete and -5 so that collision is not detected when
	//	just on the ground
	return collided(mPlayer->getX()+mPlayer->getWidth(),mPlayer->getY()) 
		|| collided(mPlayer->getX()+mPlayer->getWidth(),mPlayer->getY()+(mPlayer->getHeight()/2))
		|| collided(mPlayer->getX()+mPlayer->getWidth(),mPlayer->getY()+(mPlayer->getHeight()-5));
}

bool GameLogic::checkPlayerLeftCollision(){
	//-5 so that collision is not detected when just on the ground
	return collided(mPlayer->getX()+mPlayer->getXSpeed(),mPlayer->getY()) 
		|| collided(mPlayer->getX()+mPlayer->getXSpeed(),mPlayer->getY()+(mPlayer->getHeight()/2))
		|| collided(mPlayer->getX()+mPlayer->getXSpeed(),mPlayer->getY()+(mPlayer->getHeight()-5));
}

bool GameLogic::checkPlayerBottomCollision(){
	return collided(mPlayer->getX(),mPlayer->getY()+mPlayer->getHeight()) 
		|| collided(mPlayer->getX()+mPlayer->getWidth()-1,mPlayer->getY()+mPlayer->getHeight());
}

bool GameLogic::checkPlayerTopCollision(){
	if(mPlayerDucked)return collided(mPlayer->getX(),mPlayer->getY()-50) || collided(mPlayer->getX()+mPlayer->getWidth()-1,mPlayer->getY()-50);
	return collided(mPlayer->getX(),mPlayer->getY()) || collided(mPlayer->getX()+mPlayer->getWidth()-1,mPlayer->getY());
}

void GameLogic::playerInput(){
	if(key[KEY_D] && key[KEY_W]){
		if(!mPlayerDucked)mPlayer->jumpRight();
	}else if(key[KEY_A] && key[KEY_W]){
		if(!mPlayerDucked)mPlayer->jumpLeft();
	}else if(key[KEY_S] && key[KEY_A]){
		mPlayerDucked = true;
		mPlayer->duckLeft();
	}else if(key[KEY_S] && key[KEY_D]){
		mPlayerDucked = true;
		mPlayer->duckRight();
	}else if(key[KEY_D]){
		if(!mPlayerDucked)mPlayer->moveRight();
	}else if(key[KEY_A]){
		if(!mPlayerDucked)mPlayer->moveLeft();
	}else if(key[KEY_W]){
		if(!mPlayerDucked)mPlayer->jump();
	}else if(key[KEY_S]){
		mPlayerDucked = true;
		mPlayer->duck();
	}else{
		if(mPlayerDucked){
			if(checkPlayerTopCollision())mPlayerDucked= true;
			else mPlayerDucked= false;
		}
	}
}

void GameLogic::playerLogic(){
	mPlayer->mapOffSets((int)mMapXOffSet, (int)mMapYOffSet);
	mPlayer->update();
	
	mPlayer->gravityMoveDown(1);
	playerInput();
	
	
	
	if(checkPlayerRightCollision()){
		mPlayer->collide(Player::CRight);
	}
	if(checkPlayerLeftCollision()){
		mPlayer->collide(Player::CLeft);
	}
	if(checkPlayerBottomCollision()){
		mPlayer->collide(Player::CDown);
		mMapYOffSetSpeed = 0;
		if((int)mMapYOffSet%10 < 5 && (int)mMapYOffSet%10 != 0){
			mMapYOffSet -= (int)mMapYOffSet%10;
		}else if((int)mMapYOffSet%10 > 5){
			mMapYOffSet += (int)mMapYOffSet%10;
		}
	}else if(mPlayer->getY() >= 450){
		mMapYOffSetSpeed=5;
	}
	if(checkPlayerTopCollision()){
		mPlayer->collide(Player::CUp);
	}else if(mPlayer->getY() <= 100 && mPlayer->getYSpeed() >=0){
		if(mMapYOffSet - mPlayer->getYSpeed() > 0)mMapYOffSetSpeed=-1*mPlayer->getYSpeed();
		else mMapYOffSetSpeed = 0;
	}
	mPlayer->setDuckPress(mPlayerDucked);
	mPlayer->setPowerUp(mGameScreen->getPowerUpType());
	mPlayer->mapMove(mMapXOffSetSpeed);
}

void GameLogic::interfaceInputs(){
	if(key[KEY_H] && (key[KEY_LCONTROL] || key[KEY_RCONTROL])){
		if(mStartScreen->getStarted())mHelpScreen->quickHelpSwitch();
	}
	
	if(key[KEY_M] && (key[KEY_LCONTROL] || key[KEY_RCONTROL])){
	}
	
	if(mouse_b & 1){
		if(!mHelpScreen->getActive() && !mStartScreen->getStarted()){
			mStartScreen->clicked(mouse_x, mouse_y);
		}
		if(!mHelpScreen->getActive() && mStartScreen->getStarted() && mGameOver)mGameOverScreen->clicked(mouse_x, mouse_y);
		if(mHelpScreen->getActive())mHelpScreen->clicked(mouse_x, mouse_y);
	}
}

void GameLogic::spawnPowerUp(){
	BLKSTR *blockdata;
	int XOffset = (int)mMapXOffSet % 50;
	int YOffset = (int)mMapYOffSet % 50;
	int X = mMapXOffSet/mapblockwidth;
	int Y = mMapYOffSet/mapblockheight;
	
	if(mLastColumn != 17+X){
		MapChangeLayer(1);
		for(int i = 0; i<(SCREEN_H/50); i++){
			blockdata = MapGetBlock(17+X, i+Y);
			if(blockdata->user1 < mPowerUps[0]->getTotalNumberOfTypes() && blockdata->user1 != 0){
				for(int j = 0; j < mTotalPowerPointer; j++){
					if(!mPowerUps[j]->getActive()){
						mPowerUps[j]->setPowerUpType((PowerUps::Type)blockdata->user1,(17*50)+XOffset,(i*50)-(YOffset));
						break;
					}
				}
			}
		}
		MapChangeLayer(0);
	}
}

void GameLogic::checkPowerUpCollision(){
	for(int i = 0; i < mTotalPowerPointer; i++){
		if(mPowerUps[i]->getActive()){
			if((mPowerUps[i]->hit(mPlayer->getX()+mPlayer->getWidth(),mPlayer->getY())) 
				|| (mPowerUps[i]->hit(mPlayer->getX()+mPlayer->getWidth(),mPlayer->getY()+(mPlayer->getHeight())))
				|| (mPowerUps[i]->hit(mPlayer->getX()+(mPlayer->getWidth()/2),mPlayer->getY()))
				|| (mPowerUps[i]->hit(mPlayer->getX()+(mPlayer->getWidth()/2),mPlayer->getY()+(mPlayer->getHeight())))
				|| (mPowerUps[i]->hit(mPlayer->getX(),mPlayer->getY()))
				|| (mPowerUps[i]->hit(mPlayer->getX(),mPlayer->getY()+(mPlayer->getHeight())))){
				mGameScreen->setPowerUpType((GameScreen::PowerUpType)mPowerUps[i]->getType());
			}
		}
	}
}

void GameLogic::powerUpLogic(){
	spawnPowerUp();
	for(int j = 0; j < mTotalPowerPointer; j++){
		if(mPowerUps[j]->getActive())mPowerUps[j]->mapMove(mMapXOffSetSpeed,mMapYOffSetSpeed);
	}
	checkPowerUpCollision();
}

void GameLogic::spawnEnemy(){
	BLKSTR *blockdata;
	int XOffset = (int)mMapXOffSet % 50;
	int YOffset = (int)mMapYOffSet % 50;
	int X = mMapXOffSet/mapblockwidth;
	int Y = mMapYOffSet/mapblockheight;	
	if(mLastColumn != 17+X){
		MapChangeLayer(2);
		for(int i = 0; i<(SCREEN_H/50); i++){
			blockdata = MapGetBlock(17+X, i+Y);
			if(blockdata->user1 != 0){
				for(int j = 0; j < mTotalEnemyPointer; j++){
					if(!mEnemy[j]->getActive()){
						mEnemy[j]->spawn((Enemy::Type)blockdata->user1,(17*50)+XOffset,(i*50)+YOffset);
						break;
					}
				}
			}
		}
		MapChangeLayer(0);
	}
}

void GameLogic::checkEnemyCollision(){
	if(mGameScreen->getPowerUpType() != 4){
		for(int i = 0; i < mTotalEnemyPointer; i++){
			if(mEnemy[i]->getActive()){
				if((mEnemy[i]->hit(mPlayer->getX()+mPlayer->getWidth(),mPlayer->getY())) 
					|| (mEnemy[i]->hit(mPlayer->getX()+mPlayer->getWidth(),mPlayer->getY()+(mPlayer->getHeight())))
					|| (mEnemy[i]->hit(mPlayer->getX()+mPlayer->getWidth(),mPlayer->getY()+(mPlayer->getHeight()/2)))
					|| (mEnemy[i]->hit(mPlayer->getX()+(mPlayer->getWidth()/2),mPlayer->getY()))
					|| (mEnemy[i]->hit(mPlayer->getX()+(mPlayer->getWidth()/2),mPlayer->getY()+(mPlayer->getHeight())))
					|| (mEnemy[i]->hit(mPlayer->getX()+(mPlayer->getWidth()/2),mPlayer->getY()+(mPlayer->getHeight()/2)))
					|| (mEnemy[i]->hit(mPlayer->getX(),mPlayer->getY()))
					|| (mEnemy[i]->hit(mPlayer->getX(),mPlayer->getY()+(mPlayer->getHeight())))){
					mGameOver = true;
					mGameOverScreen->gameoverSwitch(mGameScreen->getScore());
				}
			}
		}
	}
}

void GameLogic::enemyLogic(){
	spawnEnemy();
	for(int j = 0; j < mTotalEnemyPointer; j++){
		if(mEnemy[j]->getActive()){
			mEnemy[j]->mapMove(mMapXOffSetSpeed,mMapYOffSetSpeed);
			mEnemy[j]->update();
		}
	}
	checkEnemyCollision();
}
