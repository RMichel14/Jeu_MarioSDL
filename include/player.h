#ifndef PLAYER_H
#define PLAYER_H

// Inclusion des librairies
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/**
 * Faire avancer le personnage
 * @param renderer SDL Renderer
 * @param tableauTextures tableau de SDL Textures
 */
void avancer(SDL_Renderer *renderer, SDL_Texture **tableauTextures);

/**
 * Faire sauter le personnage
 */
void sauter();

/**
 * Faire redescendre le joueur 'au sol'
 * @param solY position du sol
 */
void gravite(int solY);

#endif