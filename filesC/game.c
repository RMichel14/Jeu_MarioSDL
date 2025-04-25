#include "game.h"

SDL_Window *createWindow(int window_Width, int window_Height) {
    // une fenêtre
    SDL_Window *window = NULL;

    // initialisation de la video
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n",
                SDL_GetError());
        exit(EXIT_FAILURE); // On quitte le programme
    }

    // initialisation des images
    IMG_Init(IMG_INIT_PNG);

    const char *title = "MarioSDL";

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_Width, window_Height, SDL_WINDOW_OPENGL);

    if (window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    return window;
}

SDL_Renderer *createRenderer(SDL_Window *window) {
    // verification si la window existe sinon fin de programme
    if (window == NULL) exit(EXIT_FAILURE);

    SDL_Renderer *renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    return renderer;
}

SDL_Texture** loadTextures(SDL_Renderer* renderer, int* nbImagesRetour) {
    const char* filenames[] = {
        "background_accueil.png", // index 0
        "background_game.jpg",    // index 1
    };

    int nbImages = sizeof(filenames) / sizeof(filenames[0]);
    SDL_Texture** pTab = NULL;
    pTab = malloc(nbImages * sizeof(SDL_Texture*));

    if (!pTab) {
        printf("Erreur d'allocation mémoire.\n");
        return NULL;
    }

    for (int i = 0; i < nbImages; i++) {
        pTab[i] = load_texture_from_file(renderer, "images", filenames[i]);
        if (!pTab[i]) {
            printf("Échec du chargement : %s\n", filenames[i]);
            char fullPath[512];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", "images", filenames[i]); // creer le chemin complet vers l'image
            printf(fullPath);
        }
    }

    if (nbImagesRetour) *nbImagesRetour = nbImages;
    return pTab;
}

SDL_Texture* load_texture_from_file(SDL_Renderer* renderer, const char* folder, const char* filename) {
    char fullPath[512];
    snprintf(fullPath, sizeof(fullPath), "%s/%s", folder, filename); // creer le chemin complet vers l'image

    SDL_Texture* texture = IMG_LoadTexture(renderer, fullPath);
    if (!texture) {
        printf("Erreur lors du chargement de l'image : %s\n", IMG_GetError());
    }
    return texture;
}

void render_background(SDL_Renderer* renderer, SDL_Texture* background) {
    if (!background) return;

    int w, h;
    SDL_GetRendererOutputSize(renderer, &w, &h); // optient la taille de la fenetre (hauteur, largeur)

    SDL_Rect dstRect = { 0, 0, w, h };
    SDL_RenderCopy(renderer, background, NULL, &dstRect);
    SDL_RenderPresent(renderer);
}

void menu(SDL_Renderer* renderer, SDL_Texture** tableauTextures) {
    // Afficher le background
    SDL_RenderClear(renderer);
    render_background(renderer, tableauTextures[0]);
}

void game(SDL_Renderer* renderer, SDL_Texture** tableauTextures) {
    // Clean de la fenetre (optionnel car deja clear dans le changement)
    // SDL_RenderClear(renderer);
    // SDL_RenderPresent(renderer);

    // affichage du background
    render_background(renderer, tableauTextures[1]);
}