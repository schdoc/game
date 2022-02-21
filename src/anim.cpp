#include "anim.h"

Animator::Animator(){
	frame = 0;
	length = 0;
	frameDelta = 1;
	rate = 100;
	ticks = 0;
	bounce = false;
}

void Animator::step(){
	if(ticks + rate > SDL_GetTicks()){
		return;
	}
	ticks = SDL_GetTicks();
	frame += frameDelta;
	if(bounce){
		if(frameDelta >= length || frameDelta <= 0){
			frameDelta = -frameDelta;
		}
	}
	else{
		if(frame >= length){
			frame = 0;
		}
	}
}

void Animator::setRate(int to){
	rate = to;
}

void Animator::setFrame(int to){
	if(to < 0 || to >= length){
		return;
	}
	frame = to;
}

int Animator::getFrame(){
	return frame;
}
