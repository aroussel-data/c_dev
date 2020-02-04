/*
 main.c
 --------
 - Purpose of this file is to initialise the SDL Window, Renderer and main menu.
 - User presses 1 to play game and 2 to enter into level editor.
 - User presses Esc or [X] to quit game.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <SDL.h>
#include <SDL_image.h>
#include "constants.h"
#include "main.h"
#include "game.h"

int main(int argc, char *argv[]){
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Texture *menu = NULL;
	SDL_Color black = {0, 0, 0, 255};
	SDL_Event event;
	int status = EXIT_FAILURE, proceed = 1;
	
	// initialise SDL, window and renderer.
	if(init(&window, &renderer, WINDOW_WIDTH, WINDOW_HEIGHT) != 0){
		goto Quit;
	}

	// set the window icon
	set_icon(window, "sprites/caisse.jpg");
	
	// set background colour
	setWindowColor(renderer, black);

	// load menu image	
	menu = load_image("sprites/menu_english.jpg", renderer);	

	// create main loop to represent game menu
	while(proceed){
		SDL_WaitEvent(&event);
		switch(event.type){ 
			case SDL_QUIT:
				proceed = 0;
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
					case SDLK_ESCAPE:
						proceed = 0;
						break;
					case SDLK_KP_1:
						// player chooses to play game
						play_game(renderer);
						break;
					case SDLK_KP_2:
						//player chooses to edit level
						edit_game(renderer);
						break;
				}
		}
		// in here we need the code that keeps displaying the menu in a loop
		SDL_RenderCopy(renderer, menu, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	status = EXIT_SUCCESS;

Quit:
	if (menu != NULL){
		SDL_DestroyTexture(renderer);
	}
	if (renderer != NULL){
		SDL_DestroyRenderer(renderer);	
	}
	if (window != NULL){
		SDL_DestroyWindow(window);
	}
	SDL_Quit(); 
	return status; 
}

int init(SDL_Window **window, SDL_Renderer **renderer, int width, int height){
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		fprintf(stderr, "failed to initialise: %s\n", SDL_GetError());
		return -1;
	}
	if (SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_RESIZABLE, window, renderer)){
		fprintf(stderr, "failed to CreateWindowAndRenderer: %s\n", SDL_GetError());
		return -1;
	}
	return 0;
}

SDL_Texture *load_image(const char path[], SDL_Renderer *renderer){
	SDL_Surface *surface = NULL;
	SDL_Texture *texture = NULL;	
	
	surface = IMG_Load(path);
	if (surface == NULL){
		fprintf(stderr, "failed IMG_Load: %s\n", SDL_GetError());
		return NULL;
	}
	
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL){
		fprintf(stderr, "CreateTextureFromSurface failed %s\n", SDL_GetError());
		return NULL;
	}
	SDL_FreeSurface(surface);
	return texture;
}

int setWindowColor(SDL_Renderer *renderer, SDL_Color color){
	if (SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a) < 0){
		return -1;
	};
	if (SDL_RenderClear(renderer) < 0){
		return -1;
	}
}

void set_icon(SDL_Window *window, const char icon_path[]){
	SDL_Surface *icon = NULL;
	icon = SDL_LoadBMP(icon_path);
		if (icon == NULL){
			fprintf(stderr, "failed LoadBMP of icon: %s\n", SDL_GetError());
			return NULL;
		}
		SDL_SetWindowIcon(window, icon);
}

