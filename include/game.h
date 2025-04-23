#ifndef GAME_H
#define GAME_H

// Inclusion des librairies
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>

/**
 * Creation de la fenetre SDL
 * @param window_Width MACRO de taille
 * @param window_Height MACRO de taille
 * @return pointeur vers la fenetre SDL
 */
SDL_Window *createWindow(int window_Width, int window_Height);

/**
 * Creation du renderer
 * @param window pointeur vers la fenetre
 * @return pointeur vers le renderer
 */
SDL_Renderer *createRenderer(SDL_Window *window);

#endif