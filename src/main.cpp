/**
 * @defgroup   MAIN main
 *
 * @brief      Brains of the game
 *
 * @author     schdoc
 * @date       2022
 */

#include "main.h"

App::App() {
	window = NULL;
	RUNNING = true;
	FULLSCREEN = false;
}

int App::exec() {
	if(init() == false){
		return -1;
	}
	SDL_Event evt;
	while(RUNNING){
		while(SDL_PollEvent(&evt)){
			event(&evt);
		}
		loop();
		render();
	}
	cleanup();
	return 0;
}
 
int main(int argc, char* argv[]) {
	App app;
	return app.exec();
}
