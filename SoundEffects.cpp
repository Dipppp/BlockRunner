#include "SoundEffects.h"

SoundEffects::SoundEffects(DATAFILE *Data){
	mTotalAmountSoundEffect = 5;
	mSoundEffect = new SAMPLE*[mTotalAmountSoundEffect];
	mSoundEffect[0] = (SAMPLE *)Data[CLICK_WAV].dat;//load_sample("SoundEffects/Click.wav");
    mSoundEffect[1] = (SAMPLE *)Data[FIRE_WAV].dat;//load_sample("SoundEffects/Fire.wav");
    mSoundEffect[2] = (SAMPLE *)Data[JUMP_WAV].dat;//load_sample("SoundEffects/Jump.wav");
    mSoundEffect[3] = (SAMPLE *)Data[POWERUP_WAV].dat;//load_sample("SoundEffects/PowerUp.wav");
    mSoundEffect[4] = (SAMPLE *)Data[TICKTOCK_WAV].dat;//load_sample("SoundEffects/TickTock.wav");
    mVolume = 255;
    mPan = 128;
    mPitch = 1000;
}

SoundEffects::~SoundEffects(){
	/*for (int i=0; i<mTotalAmountSoundEffect; i++){
        destroy_sample(mSoundEffect[i]);
    }
    delete mSoundEffect;*/
}

void SoundEffects::playSoundEffect(SoundEffect ToPlaySoundEffect){
	play_sample(mSoundEffect[(int)ToPlaySoundEffect], mVolume, mPan, mPitch, FALSE);
	/*switch(ToPlaySoundEffect){
		case Click:
			play_sample(mSoundEffect[0], mVolume, mPan, mPitch, FALSE);
			break;
		case Destroyed:
			play_sample(mSoundEffect[1], mVolume, mPan, mPitch, FALSE);
			break;
		case LaserFire:
			play_sample(mSoundEffect[2], mVolume, mPan, mPitch, FALSE);
			break;
		case MachineGunFire:
			play_sample(mSoundEffect[3], mVolume, mPan, mPitch, FALSE);
			break;
		case Thruster:
			play_sample(mSoundEffect[4], mVolume, mPan, mPitch, FALSE);
			break;
		case ShipUpgradeCollect:
			play_sample(mSoundEffect[5], mVolume, mPan, mPitch, FALSE);
			break;
		case Missile:
			play_sample(mSoundEffect[6], mVolume, mPan, mPitch, FALSE);
			break;
	}*/
}

void SoundEffects::soundEffectToggle(){
	if(mVolume == 255)mVolume = 0;
	else mVolume = 255;
}
