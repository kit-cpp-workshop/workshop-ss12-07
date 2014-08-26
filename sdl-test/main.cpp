#include <iostream>
#include <SDL/SDL.h>

using namespace std;

int main()
{
  // SDL initialisieren
  SDL_Init(SDL_INIT_VIDEO);

  // Unsere Zeichenfläche erstellen
  SDL_Surface* screen = SDL_SetVideoMode(640, 480, 24, SDL_SWSURFACE);

  // Die benötigte Farbe erstellen
  Uint32 color_red = SDL_MapRGB(screen->format, 255, 0, 0);

  // Fülle Zeichenfläche mit Farbe
  SDL_FillRect(screen, NULL, color_red);

  // Bildschirm Updaten
  SDL_UpdateRect(screen, 0, 0, 0, 0);


  // Event-Container
  SDL_Event event;

  // Event loop
  bool exitLoop = false;
  while(!exitLoop){

    // auf nächstes Event warten
    SDL_WaitEvent(&event);
    // Nun steckt in "event" ein Event

    switch(event.type)
    {
      case SDL_KEYDOWN:
        cout << "mod: " << event.key.keysym.mod
             << "; scancode: " << (int)event.key.keysym.scancode
             << "; sym: " << event.key.keysym.sym
             << "; unicode: " << event.key.keysym.unicode
             << endl;
        if(event.key.keysym.sym==SDLK_ESCAPE)
          exitLoop=true;
        break;
      case SDL_QUIT:
        exitLoop = true;
        break;
      default:
        break;
    }


  }

  //cout << "Press return to exit" << endl;
  //cin.get();

  // SDL korrekt herunterfahren
  SDL_Quit();

  return 0;
}

