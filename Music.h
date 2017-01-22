//Written By: Mandip Sangha
//Created On: Oct 17, 2016
//Modified On: Nov 14, 2016
//NOTE: All music obtain from midiworld.com the 
//		extact location detailed in the game credits

#ifndef MUSIC_H
#define MUSIC_H

#include <allegro.h>
#include "defines.h"


//PURPOSE - The Class is for loading and playing the game's music
class Music {
	public:
		//PURPOSE: 	Sets all variables to default setting for the object
		//INPUT:	Data			- The pointer to game data
		//OUTPUT:	NONE
		Music(DATAFILE *Data);
		//PURPOSE:	Free memory 
		//INPUT:	NONE
		//OUTPUT:	NONE
		~Music();
		//PURPOSE:	Play the game music
		//INPUT:	NONE
		//OUTPUT:	NONE
		void play();
		//PURPOSE:	Pause and unpause the music
		//INPUT:	NONE
		//OUTPUT:	NONE
		void musicToggle();
	private:
		//PURPOSE:	Point to the music file
		MIDI **mMusic;
		//PURPOSE:	Holds if the music is puased or not
		bool mPaused;
};

#endif
