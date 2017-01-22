//Written By: Mandip Sangha
//Created On: Oct 17, 2016
//Modified On: Nov 14, 2016
//NOTE: All music obtain from soundbible.com the 
//		extact location detailed in the game credits

#ifndef SOUNDEFFECTS_H
#define SOUNDEFFECTS_H

#include <allegro.h>
#include "defines.h"


//PURPOSE - The Class is for loading and playing the game's sound effects
class SoundEffects {
	public:
		//PURPOSE:	The different types of sound effects
		enum SoundEffect{Click = 0, Fire = 1, Jump = 2, PowerUp = 3, TickTock = 4};
		//PURPOSE:	Loads all the game sound effects
		//INPUT:	Data			- The pointer to game data
		//OUTPUT:	NONE
		SoundEffects(DATAFILE *Data);
		//PURPOSE:	Release all the sound effects
		//INPUT:	NONE
		//OUTPUT:	NONE
		~SoundEffects();
		//PURPOSE:	Plays the sound effect that is selected
		//INPUT:	ToPlaySoundEffect		- The sound effect that is to play
		//OUTPUT:	NONE
		void playSoundEffect(SoundEffect ToPlaySoundEffect);
		//PURPOSE:	Turn sound effects on and off
		//INPUT:	NONE
		//OUTPUT:	NONE
		void soundEffectToggle();
	private:
		//PURPOSE:	Array that hold all sound effect
		SAMPLE **mSoundEffect;
		//PURPOSE:	Volume of sound effects
		double mVolume;
		//PURPOSE:	Pan of sound effects
    	int mPan;
    	//PURPOSE:	Pitch of sound effects
    	int mPitch;
    	//PURPOSE:	Total number of different sound effects
    	int mTotalAmountSoundEffect;
};

#endif
