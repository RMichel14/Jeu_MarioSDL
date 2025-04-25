#ifndef PLAYER_H
#define PLAYER_H

// Inclusion des librairies
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/**
 * Faire avancer le personnage
 */
void avancer(SDL_Renderer* renderer, SDL_Texture** tableauTextures);

#endif