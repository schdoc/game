/**
 * @defgroup   FRAMELIMITER framelimiter
 *
 * @brief      Framelimiter. For older machines that may not run the game at same speed (from sdltutorials)
 *
 * @author     schdoc
 * @date       2022
 */

#ifndef _FRAMELIMIT_H_
#define _FRAMELIMIT_H_

#include <SDL.h>

class Framelimiter{
	public:
		static Framelimiter fps;
		int getFPS();
		float getFactor();
		Framelimiter();
		void loop();
	private:
		int oldtime;
		int newtime;
		float speed;
		int numframes;
		int frames;
};

#endif
