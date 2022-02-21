/**
 * @defgroup   ANIM animation
 *
 * @brief      Animation controller header from sdltutorials
 *
 * @author     schdoc
 * @date       2022
 */

#ifndef _ANIM_H_
#define _ANIM_H_

#include <SDL.h>

class Animator{
	private:
		int frame;
		int frameDelta;
		int rate; // ms
		int ticks;
	public:
		int length; // in frames
		bool bounce;
		Animator();
		void step();
		void setRate(int to);
		void setFrame(int to);
		int getFrame();
};

#endif
