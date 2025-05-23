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
 * @param lastSpawnTime Temps du dernier spawn d un obstacle
 * @return (1: le joueur est mort / 0: il est en vie)
 */
int avancer(SDL_Renderer *renderer, SDL_Texture **tableauTextures, Uint32 *lastSpawnTime, Uint32 *lastPlatformTime, Uint32 *platformInterval);

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