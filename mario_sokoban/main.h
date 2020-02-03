#ifndef MAIN
#define MAIN
#include <SDL.h>
#include <SDL_image.h>
int init(SDL_Window **window, SDL_Renderer **renderer, int width, int height);
SDL_Texture *load_image(const char path[], SDL_Renderer *renderer);
int setWindowColor(SDL_Renderer *renderer, SDL_Color color);
void set_icon(SDL_Window *window, const char icon_path[]);
#endif
