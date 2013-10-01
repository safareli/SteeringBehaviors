#include "../include/Base.h"
#include "../include/gl.h"
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <Box2D/Box2D.h>

extern void draw();
extern void setup();

using namespace Base;
namespace Base{
    int WIDTH, HEIGHT;
    int displayWidth, displayHeight;
    bool isFullScreen(){
        return WIDTH == displayWidth && HEIGHT == displayHeight;
    }

    void log(std::string const &str){
        std::cout << str<< "\n";
    }
    void log(double d){
        std::cout << d<< "\n";
    }

    void size(int w, int h){
        WIDTH = w;
        HEIGHT = h;

		if(isFullScreen())
            SDL_SetVideoMode(WIDTH,HEIGHT,32,SDL_OPENGL | SDL_FULLSCREEN);
        else
            SDL_SetVideoMode(WIDTH,HEIGHT,32,SDL_OPENGL);
    }

    int run(){
	    SDL_Init(SDL_INIT_EVERYTHING);
        const SDL_VideoInfo * lInfo = SDL_GetVideoInfo();
        displayWidth = lInfo->current_w;
        displayHeight = lInfo->current_h;
		Uint32 start;
		SDL_Event event;
		bool running=true;
		setup();
		GL::init();
		while(running)
		{
			start=SDL_GetTicks();
			while(SDL_PollEvent(&event))
			{
				switch(event.type)
				{
					case SDL_QUIT:
						running=false;
						break;
					case SDL_KEYDOWN:
						switch(event.key.keysym.sym)
						{
							case SDLK_ESCAPE:
								running=false;
								break;
						}
						break;
	                case SDL_MOUSEBUTTONDOWN:
						break;
	                case SDL_MOUSEBUTTONUP:
						break;
					case SDL_MOUSEMOTION:
						break;
				}
			}
            GL::update();
			draw();
			world->Step(1.0/30.0,8,3);	//update
			SDL_GL_SwapBuffers();
			if(1000.0/30>SDL_GetTicks()-start)
				SDL_Delay(1000.0/30-(SDL_GetTicks()-start));
		}
		SDL_Quit();
		return 0;
    }
}
