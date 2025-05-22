#ifndef DANGERS_H
#define DANGERS_H

// Inclusion des librairies
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Definitions des constantes des obstacles
#define MAX_OBSTACLES 10
#define OBSTACLE_WIDTH 40  // 40
#define OBSTACLE_HEIGHT 50 // 60
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Struct des obstacles
typedef struct _obstacle {
    SDL_Rect rect;
    int active;
} Obstacle;

/**
 * initilisation des obstacles
 */
void initObstacles();

/**
 * Apparition aléatoire des obstacles
 */
void spawnObstacle();

/**
 * Met a jour les obstacles pour qu'ils suivent les deplacements du background
 * @param scrollSpeed vitesse de deplacement du background
 */
void updateObstacles(int scrollSpeed);

/**
 * Affiche les obstacles
 * @param renderer
 */
void renderObstacles(SDL_Renderer* renderer);

/**
 * Verifie les collisions entre les obstacles et le joueur
 * @param player Rect du joueur
 * @return int (1: collision / 0: pas de collision)
 */
int checkCollision(SDL_Rect player);

#endif