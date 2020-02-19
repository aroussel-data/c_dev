# c_dev
Repo of files made while familiarising myself with C language and SDL library.

I'm currently finishing a Mario Sokoban clone written in C based on the one in [this great course](https://openclassrooms.com/en/courses/19980-apprenez-a-programmer-en-c?status=published). However, because the course uses an out of date version of the SDL library, I am writing it to be up to date with the current SDL2.0 library. 

This mainly involved:
- using the SDL Texture structs rather than the older SDL Surface structs.
- no longer setting VideoCreateMode, but rather just initialising a Window & Screen.
- using hardware accelerated rendering (video card) instead of software rendering (cpu).
- no longer using the "Blit" function to render surfaces to the screen, but rather using RenderClear, RenderCopy, and RenderPresent to blit textures onto the screen. 

Need to add:
- the ability to specify the file we want to load and save
- ability to create multiple levels
