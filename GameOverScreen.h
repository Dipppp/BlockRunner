//Written By: Mandip Sangha
//Created On: Oct 13, 2016

#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <allegro.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "BaseInterface.h"
#include "SoundEffects.h"

using namespace std;

//PURPOSE - To create the gameover screen for the game and uses the base interface class as a parent
class GameOverScreen : public BaseInterface {
	public:
		//PURPOSE: 	Sets the default values for the object variables
		//INPUT:	Screen 		- The pointer to game screen
		//			ImagePage 	- The pointer to bitmap of help screen images
		//			SoundEffect	- The pointer to the sound effects
		//OUTPUT:	NONE
		GameOverScreen(BITMAP *Screen, BITMAP *ImagePage, SoundEffects *SoundEffect);
		//PURPOSE:	Free memorys of the pointers
		//INPUT:	NONE
		//OUTPUT:	NONE
		~GameOverScreen();
		//PURPOSE:	Loads the highscores and checks if the score is greater than any of 
		//				the scores loaded and if the score is greater than sets mNameEnter to false
		//INPUT:	Score		- The score the player acheived and to be check against the highscores
		//OUTPUT:	NONE
		void gameoverSwitch(int Score);
		//PURPOSE:	Update the dialog box with the input give if mNameEnter is false
		//INPUT:	NONE
		//OUTPUT:	NONE
		void update();
		//PURPOSE:	Calls all the methods need to draw the screen graphics
		//INPUT:	NONE
		//OUTPUT:	NONE
		void draw();
		//PURPOSE:	Draws the highscores information to the screen
		//INPUT:	NONE
		//OUTPUT:	NONE
		void displayHighScore();
		//PURPOSE:	Check if any of the buttons on the page were clicked and does 
		//				coreposding action for that button
		//INPUT:	X			- The x position of the point clicked
		//			Y			- The y position of the point clicked
		//OUTPUT:	NONE
		void clicked(int X, int Y);	
		//PURPOSE:	Sets mPlayAgain to false
		//INPUT:	NONE
		//OUTPUT:	NONE
		void unSetPlayAgain();
		//PURPOSE:	Returns the value in mPlayAgain
		//INPUT:	NONE
		//OUTPUT:	mPlayAgain
		bool getPlayAgain();	
		
	private:
		//PURPOSE:	The bitmap that contains all letter images
		BITMAP *mAllLetters;
		//PURPOSE:	The bitmap that contains all number images
		BITMAP *mAllNumbers;
		//PURPOSE:	Holds the highscore images
		BITMAP **mHighScores;
		//PURPOSE:	Holds the input box image
		BITMAP *mInputBox;
		//PURPOSE:	Holds the image that show the name user is inputing
		BITMAP *mNameBox;
		//PURPOSE:	Holds the names for all the highscores
		string *mName;
		//PURPOSE:	Holds the scores for all the highscores
		string *mScore;
		//PURPOSE: 	Holds the name for the new highscore achiever
		string mTempName;
		//PURPOSE:	The position the new high score goes in
		int mPositionToReplace;
		//PURPOSE:	The width individual of letters and numbers images
		int mLetterAndNumWidth;
		//PURPOSE:	The height individual of letters and numbers images
		int mLetterAndNumHeight;
		//PURPOSE:	The width of highscore line
		int mHighScoreWidth;
		//PURPOSE:	The height of highscore line
		int mHighScoreHeight;
		//PURPOSE:	Holds whether the new highscore's name was entered
		bool mNameEnter;
		//PURPOSE:	Holds the whether the playagain was selected
		bool mPlayAgain;
		//PURPOSE:	Point for the enter button
		Button *mEnterButton;
		//PURPOSE:	Point for the playagain button
		Button *mPlayAgainButton;
		
		//PURPOSE:	Loads the highscore save in the file into mName and mScore
		//INPUT:	NONE
		//OUTPUT:	NONE
		void loadFromFileHighScores();
		//PURPOSE:	Saves the current highscore to the file
		//INPUT:	NONE
		//OUTPUT:	NONE
		void saveToFileHighScores();
		//PURPOSE:	Loads the text(name) to the image pointer 
		//INPUT:	Text			- The text to put into the bitmap 
		//			image			- The image the text is load into
		//OUTPUT:	NONE
		void loadLetterToBitmap(string Text, BITMAP *image);
		//PURPOSE:	Loads the text(score) to the image pointer 
		//INPUT:	Text			- The text to put into the bitmap 
		//			image			- The image the text is load into
		//			BitmapStartX	- The x position to start adding the text to in the image
		//OUTPUT:	NONE
		void loadNumberToBitmap(string Text, BITMAP *image, int BitmapStartX);
		//PURPOSE:	Gets the input for the alphabet keys and returns the new CurrentString
		//INPUT:	CurrentString	- The string to add the letter too
		//OUTPUT:	CurrentString
		string inputText(string CurrentString);
};

#endif
