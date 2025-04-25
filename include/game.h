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

/**
 * Chargement des textures du dossier images
 * @return pointeur vers le tableau de textures
 */
SDL_Texture** loadTextures(SDL_Renderer* renderer, int* nbImagesRetour);

// Charge une texture PNG depuis un chemin complet vers un fichier
SDL_Texture* load_texture_from_file(SDL_Renderer* renderer, const char* folder, const char* filename);

// Affiche une texture en pleine fenêtre en background
void render_background(SDL_Renderer* renderer, SDL_Texture* background);

#endif