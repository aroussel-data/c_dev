#ifndef CONSTANTS
#define CONSTANTS
#define BLOCK 34
#define NB_WIDTH 12
#define NB_HEIGHT 12
#define WINDOW_WIDTH (BLOCK * NB_WIDTH)
#define WINDOW_HEIGHT (BLOCK * NB_HEIGHT)
enum mario {UP, DOWN, LEFT, RIGHT};
enum objects {EMPTY, WALL, BOX, OBJECTIVE, MARIO, OKBOX};
#endif 
