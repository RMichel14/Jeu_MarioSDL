#ifndef BLOCS_H
#define BLOCS_H

// Inclusion des librairies
#include <SDL2/SDL.h>

// Definitions principales
#define MAX_PLATFORMS 10
#define PLATFORM_WIDTH 100
#define PLATFORM_HEIGHT 20
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

typedef struct _plateform {
    SDL_Rect rect;
    int active;
} Platform;


/**
 * Fonction d'apparition de plateformes
 * @param renderer
 */
void initPlatforms();

void spawnPlatform();
void updatePlatforms(int scrollSpeed);
void renderPlatforms(SDL_Renderer* renderer);

#endif