
#include <iostream>
#include <cassert>

#include <SDL/SDL.h>


// macros which could come in handy, but are not required
#define SDL_LOCK_OR(PSURFACE) \
	if( SDL_MUSTLOCK(PSURFACE) && 0 != SDL_LockSurface(PSURFACE) )

#define SDL_UNLOCK(PSURFACE) \
	if( SDL_MUSTLOCK(PSURFACE) ) { SDL_UnlockSurface(PSURFACE); }



bool draw(SDL_Surface* p_surf, SDL_Rect& p_pRect, Uint32 p_color, Uint32 p_bgColor);
void eventLoop(SDL_Surface* p_surf, SDL_Rect& p_rect, Uint32 p_rectColor, Uint32 p_bgColor);


// for some reason, SDL requires the main to be of C linkage -- I just don't see why
#ifdef _WIN32
#undef main
#endif

int main()
{
	SDL_Rect myRect;
		myRect.x = 10;
		myRect.y = 10;
		myRect.w = 42;
		myRect.h = 42;

	SDL_Color myColor;
		myColor.r = 50;
		myColor.g = 100;
		myColor.b = 255;


	//+ initialize SDL
		int res = SDL_Init(SDL_INIT_VIDEO);
		if(0 != res)
		{
			std::cerr << "Failed to init SDL." << std::endl;

			std::cin.get();
			return -1;
		}
	//- SDL initialized


	SDL_Surface* screen = NULL;

	// I think the following programming trick is called error-loop.
	// It doesn't actually loop (is called only once), but can be exited with break;
	do
	{
		//+ create video surface to draw upon
			screen = SDL_SetVideoMode(640, 480, 24, SDL_SWSURFACE);
			if(NULL == screen)
			{
				std::cerr << "Could not create the video surface." << std::endl;
				break;
			}
		//- screen is a valid surface


		//+ fit colors to video mode
			Uint32 mappedMyColor = SDL_MapRGB(screen->format, myColor.r, myColor.g, myColor.b);
			Uint32 bg = SDL_MapRGB(screen->format, 0, 0, 0);
		//- mappedMyColor and bg have been mapped to video mode


		// handle events such as mouse moves and clicks, program exit
		eventLoop(screen, myRect, mappedMyColor, bg);
	}while(false);


	//+ release the video surface
		if(NULL != screen)
		{
			SDL_FreeSurface(screen);
		}else
		{
			//- no video surface has ever been created
			std::cout << "Please press <ENTER> to exit." << std::endl;
			std::cin.get();
		}
	//- video surface released


	// de-init SDL
	SDL_Quit();


	return 0;
}


bool draw(SDL_Surface* p_surf, SDL_Rect& p_pRect, Uint32 p_color, Uint32 p_bgColor)
{
	int res = 0;

	//+ lock the surface if necessary, exit function in case of error
	if( SDL_MUSTLOCK(p_surf) )
	{
		if( 0 != SDL_LockSurface(p_surf) )
		{
			std::cerr << "Could not lock the video surface." << std::endl;
			return false;
		}
	}
	//- surface locked

		// fill the whole surface with the background color
		res = SDL_FillRect(p_surf, NULL, p_bgColor);
		if(0 != res)
		{
			std::cerr << "Failed to draw background." << std::endl;
			return false;
		}

		// draw the rect
		res = SDL_FillRect(p_surf, &p_pRect, p_color);
		if(0 != res)
		{
			std::cerr << "Failed to draw rectangle." << std::endl;
			return false;
		}

	// unlock surface if necessary
	if( SDL_MUSTLOCK(p_surf) )
	{
		SDL_UnlockSurface(p_surf);
	}


	// here: flush the surface to screen, actually draw it
	SDL_UpdateRect(p_surf, 0, 0, 0, 0);

	return true;
}


void eventLoop(SDL_Surface* p_surf, SDL_Rect& p_rect, Uint32 p_rectColor, Uint32 p_bgColor)
{
	bool exitLoop = false;
	while(!exitLoop)
	{
		SDL_Event event;

		// wait until an event is raised
		if(0 == SDL_WaitEvent(&event))
		{
			std::cerr << "Failed to wait for an event." << std::endl;
			exitLoop = true;
			break;
		}
		//- the event variable contains a valid event


		// an event has been raised, but there are different kinds of events
		switch(event.type)
		{
		case SDL_MOUSEMOTION:
			// move the box
			p_rect.x = event.motion.x;
			p_rect.y = event.motion.y;
			if(false == draw(p_surf, p_rect, p_rectColor, p_bgColor))
			{
				break;
			}
		break;


		case SDL_MOUSEBUTTONDOWN:
			// change the background color
			p_bgColor = SDL_MapRGB(p_surf->format, 255, 255, 255);

			if(false == draw(p_surf, p_rect, p_rectColor, p_bgColor))
			{
				break;
			}
		break;
		case SDL_MOUSEBUTTONUP:
			// change the background color
			p_bgColor = SDL_MapRGB(p_surf->format, 0, 0, 0);

			if(false == draw(p_surf, p_rect, p_rectColor, p_bgColor))
			{
				break;
			}
		break;


		case SDL_QUIT:
			exitLoop = true;
		break;

		default:
			// just wait for the next event
		break;
		} // switch(event.type)
	} // while(!exitLoop) [event loop]
}
