#include "main.h"

App::App() {
	Screen = NULL;
	Running = true;
}

int App::Exec() {
	if(Init() == false){
		return -1;
	}
	SDL_Event event;
	while(Running){
		while(SDL_PollEvent(&event)){
			Event(&event);
		}
		Loop();
		Render();
	}
	Cleanup();
	return 0;
}
 
int main(int argc, char* argv[]) {
	App app;
	return app.Exec();
}
