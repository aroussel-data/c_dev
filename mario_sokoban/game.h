#ifndef GAME
#define GAME
void play_game(SDL_Renderer *renderer);
void move_player(int map_grid[][NB_HEIGHT], SDL_Rect *playerPosition, int direction);
#endif

