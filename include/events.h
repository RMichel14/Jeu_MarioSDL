#ifndef EVENTS_H
#define EVENTS_H

// Inclusion des librairies
#include <SDL2/SDL.h>

/**
 * Attente d'un evenement et gestion de celui-ci
 * @param renderer
 */
void waitingEvent(SDL_Renderer *renderer, SDL_Texture **tableauTextures);

/**
 * Attente d'un evenement pendant le menu et gestion de celui-ci
 * @param renderer
 */
void waitingEventMenu(SDL_Renderer *renderer);

#endif