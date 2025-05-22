#include "dangers.h"

Obstacle obstacles[MAX_OBSTACLES];

void initObstacles() {
    for (int i = 0; i < MAX_OBSTACLES; i++) {
        obstacles[i].active = 0;
    }
}

void spawnObstacle() {
    for (int i = 0; i < MAX_OBSTACLES; i++) {
        if (!obstacles[i].active) {
            obstacles[i].rect.w = OBSTACLE_WIDTH;
            obstacles[i].rect.h = OBSTACLE_HEIGHT;
            obstacles[i].rect.x = SCREEN_WIDTH + rand() % 200; // Apparait hors ecran
            obstacles[i].rect.y = SCREEN_HEIGHT - OBSTACLE_HEIGHT - 80; // sol

            obstacles[i].active = 1;
            break;
        }
    }
}

void updateObstacles(int scrollSpeed) {
    for (int i = 0; i < MAX_OBSTACLES; i++) {
        if (obstacles[i].active) {
            obstacles[i].rect.x -= scrollSpeed;

            // Desactiver si hors de l'ecran
            if (obstacles[i].rect.x + OBSTACLE_WIDTH < 0) {
                obstacles[i].active = 0;
            }
        }
    }
}

void renderObstacles(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Rouge
    for (int i = 0; i < MAX_OBSTACLES; i++) {
        if (obstacles[i].active) {
            SDL_RenderFillRect(renderer, &obstacles[i].rect);
        }
    }
}


int checkCollision(SDL_Rect player) {
    for (int i = 0; i < MAX_OBSTACLES; i++) {
        if (obstacles[i].active && SDL_HasIntersection(&player, &obstacles[i].rect)) {
            return 1; // collision detectee
        }
    }
    return 0; // pas de collision
}