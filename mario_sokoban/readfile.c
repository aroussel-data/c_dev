/*
 readfile.c
 --------
 - Purpose of this file is to manage the loading and saving of the map_grid 2d array into the level.lvl file.
 - Loading is done by using fgets() to read the continuous string of ints (0-4) representing different sprites in the level.lvl file into the 2d array map_grid. 
 - Saving is the inverse of the loading process, we take the contents of map_grid and write them to the level.lvl in a continuous string, e.g. 11400
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <SDL.h>
#include <SDL_image.h>
#include "readfile.h"
#include "constants.h"

int load_level(int map_grid[][NB_HEIGHT]){
	FILE *file = NULL;
	char file_contents[NB_WIDTH * NB_HEIGHT + 1] = {0};
	int i, j;

	file = fopen("level.lvl", "r");
	if (file == NULL){
		return 0;
	}

	fgets(file_contents, (NB_WIDTH * NB_HEIGHT + 1), file);

	for (i = 0; i < NB_WIDTH; i++){
		for (j = 0; j < NB_HEIGHT; j++){
			switch(file_contents[(i * NB_WIDTH) + j]){
				case '0':
					map_grid[j][i] = 0;
					break;
				case '1':
					map_grid[j][i] = 1;
					break;
				case '2':
					map_grid[j][i] = 2;
					break;
				case '3':
					map_grid[j][i] = 3;
					break;
				case '4':
					map_grid[j][i] = 4;
					break;
			}	
		}
	}

	fclose(file);

	return 1;
}

int save_level(int map_grid[][NB_HEIGHT]){
	FILE *file = NULL;
	int i, j;

	file = fopen("level.lvl", "w");
	if (file == NULL){
		return 0;
	}

	for (i = 0; i < NB_WIDTH; i++){
		for (j = 0; j < NB_HEIGHT; j++){
			fprintf(file, "%d", map_grid[j][i]);
		}
	}
	fclose(file);
	return 1;
}
