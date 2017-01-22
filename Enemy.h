//Written By: Mandip Sangha
//Created On: Oct 4, 2016

#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"

//PURPOSE - The Class is for the Enemy object and uses the game object class as a parent
class Enemy : public GameObject {
	public:
		//PURPOSE:The different type of enemies
		enum Type{One = 1, Two = 2, Three = 3};
		
		//PURPOSE: 	Sets all variables to default setting for the object
		//INPUT:	Screen			- The game screen
		//			Image			- The images for the enemy
		//OUTPUT:	NONE
		Enemy(BITMAP *Screen, BITMAP *Image);
		//PURPOSE:	Free memory 
		//INPUT:	NONE
		//OUTPUT:	NONE
		~Enemy();
		//PURPOSE:	Updates the enemy's animate and movement
		//INPUT:	NONE
		//OUTPUT:	NONE
		void update();
		//PURPOSE:	Move the enemy along with the map
		//INPUT:	XAmount			- The amount to the x position of the enemy by
		//			YAmount			- The amount to the y position of the enemy by
		//OUTPUT:	NONE
		void mapMove(double XAmount, double YAmount);
		//PURPOSE:	Used to spawn the enemy type given and the location given
		//INPUT:	EnemyType		- The type of enemy to spawn
		//			X				- The X position to spawn at
		//			Y				- The Y position to spawn at
		//OUTPUT:	NONE
		void spawn(Type EnemyType, int X, int Y);
		//PURPOSE:	Deactivates the enemy
		//INPUT:	NONE
		//OUTPUT:	NONE
		void deactive();
		//PURPOSE:	Check if the x and y position hit the enemy
		//INPUT:	X				- X position to check
		//			Y				- Y position to check
		//OUTPUT:	NONE
		bool hit(int X, int Y);
		//PURPOSE:	Return's if the enemy is active or not
		//INPUT:	NONE
		//OUTPUT:	mActive
		bool getActive();
	private:
		//PURPOSE:	Count the number of time the enemy moved
		int mMovementCount;
		//PURPOSE:	Holds whether the enemy is active or not
		bool mActive;
		//PURPOSE:	The type of enemy it is 
		Type mEnemyType;
		//PURPOSE:	All the enemy images
		BITMAP *AllEnemyImages;
		
		//PURPOSE:	Moves the enemy depending on the type of enemy it is 
		//INPUT:	NONE
		//OUTPUT:	NONE
		void movement();
};

#endif
