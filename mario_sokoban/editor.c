/*
 editor.c
 --------
 - Purpose of this file is to render the editor window (option 2 in the game menu) and allow user to interact with the sprite textures.
 - Like the game.c file, we load the sprite textures into SDL_Textures and we load the level.lvl file into the 2d array map_grid. 
 - By selecting a different number (1-4), user can change the texture that they render to a square on the grid. This modifies the element of map_grid in-place with the sprite the user has selected at the time of the click. 
 - Right-click overwrites the map_grid element with the EMPTY constant (0), effectively deleting what was in that square on the screen.
 - User can only place one Mario per map.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <SDL.h>
#include "constants.h"
#include "readfile.h"
#include "editor.h"

void edit_game(SDL_Renderer *renderer){
	SDL_Texture *wall = NULL, *box = NULL, *objective = NULL, *mario = NULL;
	SDL_Rect position;
	SDL_Event event;
	int proceed = 1, i = 0, j = 0, selected_object = WALL, num_mario = 1;
	int map_grid[NB_WIDTH][NB_HEIGHT] = {0};

	// load sprites into textures
	wall = load_image("sprites/mur.jpg", renderer);	
	box = load_image("sprites/caisse.jpg", renderer);	
	objective = load_image("sprites/objectif.png", renderer);	
	mario = load_image("sprites/mario_bas.gif", renderer);

	// load the level into the map_grid 2 dimensional array
	if (!load_level(map_grid)){
		proceed = 0;
	}

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
					case SDLK_1:
						selected_object = WALL;
						break;
					case SDLK_2:
						selected_object = BOX;
						break;
					case SDLK_3:
						selected_object = MARIO;
						break;
					case SDLK_4:
						selected_object = OBJECTIVE;
						break;
					case SDLK_l:
						load_level(map_grid);
						break;
					case SDLK_s:
						// save_game();
						break;
				}
			case SDL_MOUSEBUTTONDOWN:
				switch(event.button.button){
					case SDL_BUTTON_LEFT:
						if (selected_object == MARIO){   
							if (num_mario < 1){  // only allow placement of mario if there is not already one
								map_grid[event.button.x/BLOCK][event.button.y/BLOCK] = selected_object;
								num_mario++;
							}
						}
						else{
							map_grid[event.button.x/BLOCK][event.button.y/BLOCK] = selected_object;
						}
						break;
						
					case SDL_BUTTON_RIGHT:
						if (map_grid[event.button.x/BLOCK][event.button.y/BLOCK] == MARIO){
							num_mario--;  // if we deleted a mario by right clicking, decrement count of num_mario by 1.
						}
						map_grid[event.button.x/BLOCK][event.button.y/BLOCK] = EMPTY;
						break;
				}
		}

		// clear the renderer
		SDL_RenderClear(renderer);

		// create the nested for loop for rendering all the textures
		for (i = 0; i < NB_WIDTH; i++){
			for (j = 0; j < NB_HEIGHT; j++){
			
				position.x = i * BLOCK;
				position.y = j * BLOCK;
				position.w = BLOCK;
				position.h = BLOCK;

				switch(map_grid[i][j]){
					case WALL:
						SDL_RenderCopy(renderer, wall, NULL, &position);
						break;
					case BOX:
						SDL_RenderCopy(renderer, box, NULL, &position);
						break;
					case MARIO:
						SDL_RenderCopy(renderer, mario, NULL, &position);
						break;
					case OBJECTIVE:
						SDL_RenderCopy(renderer, objective, NULL, &position);
						break;
				}

			}
		}
		SDL_RenderPresent(renderer);
	}
	// Free the textures to clear memory.
	SDL_DestroyTexture(wall);
	SDL_DestroyTexture(box);
	SDL_DestroyTexture(objective);
	SDL_DestroyTexture(mario);
}
