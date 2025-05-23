#include "blocs.h"

Platform platforms[MAX_PLATFORMS];

void initPlatforms() {
    for (int i = 0; i < MAX_PLATFORMS; i++) {
        platforms[i].active = 0;
    }
}

void spawnPlatform() {
    for (int i = 0; i < MAX_PLATFORMS; i++) {
        if (!platforms[i].active) {
            platforms[i].rect.w = PLATFORM_WIDTH;
            platforms[i].rect.h = PLATFORM_HEIGHT;

            // Apparaît à droite de l'écran, décalage aléatoire
            platforms[i].rect.x = SCREEN_WIDTH + (rand() % 200);

            // Hauteur aléatoire entre mi-hauteur et bas de l'écran
            platforms[i].rect.y = (SCREEN_HEIGHT / 2) + (rand() % (SCREEN_HEIGHT / 2 - PLATFORM_HEIGHT - 50));

            platforms[i].active = 1;
            break;
        }
    }
}

void updatePlatforms(int scrollSpeed) {
    for (int i = 0; i < MAX_PLATFORMS; i++) {
        if (platforms[i].active) {
            platforms[i].rect.x -= scrollSpeed;

            if (platforms[i].rect.x + PLATFORM_WIDTH < 0) {
                platforms[i].active = 0;
            }
        }
    }
}

void renderPlatforms(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 165, 42, 42, 255); // Marron
    for (int i = 0; i < MAX_PLATFORMS; i++) {
        if (platforms[i].active) {
            SDL_RenderFillRect(renderer, &platforms[i].rect);
        }
    }
}