#include <allegro.h>
#include <pthread.h>
#include "GameLogic.h"

//create a new thread mutex to protect variables
pthread_mutex_t threadsafe = PTHREAD_MUTEX_INITIALIZER;
//Pointer to the game 
GameLogic *game;

bool finish;

//this thread 0
void* thread0(void* data)
{
    //get this thread id
    int my_thread_id = *((int*)data);

    //thread's main loop
    while(!finish)
    {
    	//lock the mutex to protect variables
    	pthread_mutex_lock(&threadsafe);
    	//lock the screen
        acquire_screen();

		game->update();
		game->draw();
		
				
        //unlock the screen
        release_screen();
        //unlock the mutex
        pthread_mutex_unlock(&threadsafe);

        //slow down (this thread only!)
    	rest(game->getGameSpeed());
    }

    // terminate the thread
    pthread_exit(NULL);

    return NULL;
}

//this thread 1
void* thread1(void* data)
{
    //get this thread id
    int my_thread_id = *((int*)data);
	bool temp;
    //thread's main loop
    while(!finish)
    {
		//lock the mutex to protect variables
		pthread_mutex_lock(&threadsafe);
		temp= game->startMusic();
        //unlock the mutex
		pthread_mutex_unlock(&threadsafe);
        //slow down (this thread only!)
    	if(!temp)rest(20);
    	else rest(500);
    }

    // terminate the thread
    pthread_exit(NULL);

    return NULL;
}

int main(void)
{
	int id;
    pthread_t pthread0;
    pthread_t pthread1;
    int threadid0 = 0;
    int threadid1 = 1;
    
    //initialize
    allegro_init();
    set_color_depth(24);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
    install_keyboard();
    install_mouse();
    install_timer();
    srand(time(NULL));
    //install a digital sound driver
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) 
    {
        allegro_message("Error initializing sound system");
        return 1;
    }
	show_mouse(screen);
	game = new GameLogic();
	finish = false;
	//create the thread 0
    id = pthread_create(&pthread0, NULL, thread0, (void*)&threadid0);

    //create the thread 1
    id = pthread_create(&pthread1, NULL, thread1, (void*)&threadid1);

	
	bool debug = false;
    //loop to keep game running for threads
    while (!key[KEY_ESC])
    {
    	//lock the mutex to protect double buffer
		pthread_mutex_lock(&threadsafe);
        if(debug)game->debug();
		if(key[KEY_LCONTROL]&&key[KEY_Z])debug=true;

		//unlock the mutex
        pthread_mutex_unlock(&threadsafe);
        rest (50);
        
    }
	finish = true;
	delete game;
	//kill the mutex (thread protection)
    pthread_mutex_destroy(&threadsafe);
    allegro_exit();
    return 0;
}
END_OF_MAIN()
