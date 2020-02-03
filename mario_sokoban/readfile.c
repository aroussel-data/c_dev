#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <SDL.h>
#include <SDL_image.h>
#include "readfile.h"
#include "constants.h"

// this file will read in the levels.lvl file and write the contents to the map grid 2d array.

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
