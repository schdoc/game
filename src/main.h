#define SDL_MAIN_HANDLED
#ifndef _MAIN_H_
#define _MAIN_H_

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#include <SDL.h>
class App {
	private:
		bool Running;
		SDL_Window* Screen;
	public:
		App();
		int Exec();
		bool Init();
		void Event(SDL_Event* Event);
		void Loop();
		void Render();
		void Cleanup();
};
#endif
