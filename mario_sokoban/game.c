// this will basically house what I had already started putting in the play_game function...
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <SDL.h>
#include "constants.h"
#include "readfile.h"
#include "game.h"

// then it should call a readfile function that reads the contents of niveau.lvl into the map grid 2 dimensional array...

void play_game(SDL_Renderer *renderer){
	// initialise all variables needed	
	SDL_Texture *marioFaces[4] = {NULL};
	SDL_Texture *wall = NULL, *box = NULL, *objective = NULL, *okbox = NULL, *currentMario = NULL;
	SDL_Rect position, playerPosition;
	SDL_Event event;
	int proceed = 1, objectivesLeft = 0, i = 0, j = 0;
	int map_grid[NB_WIDTH][NB_HEIGHT] = {0};
	
	// use the load_image function to load in all sprite textures and the 4 mario faces...
	wall = load_image("sprites/mur.jpg", renderer);	
	box = load_image("sprites/caisse.jpg", renderer);	
	objective = load_image("sprites/objectif.png", renderer);	
	okbox = load_image("sprites/caisse_ok.jpg", renderer);	
	marioFaces[UP] = load_image("sprites/mario_haut.gif", renderer);	
	marioFaces[DOWN] = load_image("sprites/mario_bas.gif", renderer);	
	marioFaces[LEFT] = load_image("sprites/mario_gauche.gif", renderer);	
	marioFaces[RIGHT] = load_image("sprites/mario_droite.gif", renderer);	
	
	// set currentMario to be down facing
	currentMario = marioFaces[DOWN];

	// load the level into the map grid 2 dimensional array
	if (!load_level(map_grid)){
		proceed = 0;
	} 

	// nested for loop to check values of mapgrid[i][j] to set mario starting position and set his starting square to empty.
	for (i = 0; i < NB_WIDTH; i++){
		for (j = 0; j < NB_HEIGHT; j++){
			if (map_grid[i][j] == MARIO){ 
				playerPosition.x = i;
				playerPosition.y = j;
				map_grid[i][j] = EMPTY;
			}
		}
	}

	// main while loop to govern directional input and movement
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
					case SDLK_UP:
						currentMario = marioFaces[UP];
						move_player(map_grid, &playerPosition, UP); //makes request to move player in that direction and move_player decides whether it is allowed then overwrites value of playerPosition
						break;
					case SDLK_DOWN:
						currentMario = marioFaces[DOWN];
						move_player(map_grid, &playerPosition, DOWN);
						break;
					case SDLK_RIGHT:
						currentMario = marioFaces[RIGHT];
						move_player(map_grid, &playerPosition, RIGHT);
						break;
					case SDLK_LEFT:
						currentMario = marioFaces[LEFT];
						move_player(map_grid, &playerPosition, LEFT);
						break;
						
				}
				break;
		}

		SDL_RenderClear(renderer);

		objectivesLeft = 0;

		// nested for loop to render each sprite object in the map_grid 2d array.
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
					case OKBOX:
						SDL_RenderCopy(renderer, okbox, NULL, &position);
						break;
					case OBJECTIVE:
						SDL_RenderCopy(renderer, objective, NULL, &position);
						objectivesLeft = 1;
				}
			}
		}
		// if there are no objectives left (they've been replaced by OKBOX) then the game is won
		if (!objectivesLeft){
			proceed = 0;
		}

		position.x = playerPosition.x * BLOCK;
		position.y = playerPosition.y * BLOCK;
		SDL_RenderCopy(renderer, currentMario, NULL, &position);
		SDL_RenderPresent(renderer);
	}
}

void move_player(int map_grid[][NB_HEIGHT], SDL_Rect *playerPosition, int direction){
	switch(direction){
		case UP:
			if (playerPosition->y-1 < 0){
				break;
			}
			if (map_grid[playerPosition->x][playerPosition->y-1] == WALL){
				break;
			}
			if ((map_grid[playerPosition->x][playerPosition->y-1] == BOX || map_grid[playerPosition->x][playerPosition->y-1] == OKBOX) 
				&& (playerPosition->y-2 < 0 || map_grid[playerPosition->x][playerPosition->y-2] == WALL || map_grid[playerPosition->x][playerPosition->y-2] == BOX 
				|| map_grid[playerPosition->x][playerPosition->y-2] == OKBOX)
				){
				break;
			}
			move_box(&map_grid[playerPosition->x][playerPosition->y-1], &map_grid[playerPosition->x][playerPosition->y-2]);
			playerPosition->y--;
			break;
		case DOWN:
			if (playerPosition->y+1 > WINDOW_HEIGHT){
				break;
			}
			if (map_grid[playerPosition->x][playerPosition->y+1] == WALL){
				break;
			}
			if ((map_grid[playerPosition->x][playerPosition->y+1] == BOX || map_grid[playerPosition->x][playerPosition->y+1] == OKBOX) 
				&& (playerPosition->y+2 < 0 || map_grid[playerPosition->x][playerPosition->y+2] == WALL || map_grid[playerPosition->x][playerPosition->y+2] == BOX 
				|| map_grid[playerPosition->x][playerPosition->y+2] == OKBOX)
				){
				break;
			}
			move_box(&map_grid[playerPosition->x][playerPosition->y+1], &map_grid[playerPosition->x][playerPosition->y+2]);
			playerPosition->y++;
			break;
		case LEFT:
			if (playerPosition->x-1 < 0){
				break;
			}
			if (map_grid[playerPosition->x-1][playerPosition->y] == WALL){
				break;
			}
			if ((map_grid[playerPosition->x-1][playerPosition->y] == BOX || map_grid[playerPosition->x-1][playerPosition->y] == OKBOX) 
				&& (playerPosition->x-2 < 0 || map_grid[playerPosition->x-2][playerPosition->y] == WALL || map_grid[playerPosition->x-2][playerPosition->y] == BOX 
				|| map_grid[playerPosition->x-2][playerPosition->y] == OKBOX)
				){
				break;
			}
			move_box(&map_grid[playerPosition->x-1][playerPosition->y], &map_grid[playerPosition->x-2][playerPosition->y]);
			playerPosition->x--;
			break;
		case RIGHT:
			if (playerPosition->x+1 > WINDOW_WIDTH){
				break;
			}
			if (map_grid[playerPosition->x+1][playerPosition->y] == WALL){
				break;
			}
			if ((map_grid[playerPosition->x+1][playerPosition->y] == BOX || map_grid[playerPosition->x+1][playerPosition->y] == OKBOX) 
				&& (playerPosition->x+2 < 0 || map_grid[playerPosition->x+2][playerPosition->y] == WALL || map_grid[playerPosition->x+2][playerPosition->y] == BOX 
				|| map_grid[playerPosition->x+2][playerPosition->y] == OKBOX)
				){
				break;
			}
			move_box(&map_grid[playerPosition->x+1][playerPosition->y], &map_grid[playerPosition->x+2][playerPosition->y]);
			playerPosition->x++;
			break;
	}
}

void move_box(int *first_square, int *second_square){
	if (*first_square == BOX || *first_square == OKBOX){
		if (*second_square == OBJECTIVE){
			*second_square = OKBOX;
		}
		else{
			*second_square = BOX;
		}
		if (*first_square == OKBOX){
			*first_square = OBJECTIVE;
		}
		else{
			*first_square = EMPTY;
		}
	}
}

