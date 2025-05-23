#include "player.h"
#include "dangers.h"
#include "blocs.h"

// Definitions de certaines variables pour le saut (deplacement Y)
static int joueurY = -1; // position Y du joueur
static float vitesseY = 0; // vitesse verticale
static int enSaut = 0; // 1 si le joueur saute

int avancer(SDL_Renderer* renderer, SDL_Texture** tableauTextures, Uint32 *lastSpawnTime, Uint32 *lastPlatformTime, Uint32 *platformInterval) {
    static int scrollX = 0;
    const int scrollSpeed = 2;
    const int joueurWidth = 50, joueurHeight = 80;
    const int solY = 600-60-80; // position Y de référence du sol (calcul : 600 - 60 - 80)

    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

    if (joueurY == -1) joueurY = solY;

    // Appliquer la gravité
    gravite(solY);

    SDL_Texture *bg = tableauTextures[1];
    int bgWidth, bgHeight;
    SDL_QueryTexture(bg, NULL, NULL, &bgWidth, &bgHeight);

    scrollX -= scrollSpeed;
    if (scrollX <= -bgWidth)
        scrollX += bgWidth;

    SDL_RenderClear(renderer);

    for (int x = scrollX; x < windowWidth; x += bgWidth) {
        SDL_Rect dest = {x, 0, bgWidth, windowHeight};
        SDL_RenderCopy(renderer, bg, NULL, &dest);
    }

    SDL_Rect joueurRect = {100, joueurY, joueurWidth, joueurHeight};

    // Met a jour les obstacles
    updateObstacles(scrollSpeed);

    // Met a jour les plateformes
    updatePlatforms(scrollSpeed);

    // Verifie les collisions
    if (checkCollision(joueurRect)) {
        return 1; // Game Over / le joueur est mort
    }

    // Apparition aléatoire basée sur le temps
    Uint32 currentTime = SDL_GetTicks();
    Uint32 spawnInterval = 2000; // Temps entre deux spawns en ms (2 secondes)
    if (currentTime - *lastSpawnTime >= spawnInterval) {
        spawnObstacle();
        *lastSpawnTime = currentTime;
    }

    // Dans la boucle principale :
    Uint32 currentTime2 = SDL_GetTicks();
    if (currentTime2 - *lastPlatformTime >= *platformInterval) {
        spawnPlatform();
        *lastPlatformTime = currentTime2;
    }


    // Obstacles
    renderObstacles(renderer);

    // Plateforme
    renderPlatforms(renderer);

    // affichage du joueur
    SDL_RenderCopy(renderer, tableauTextures[3], NULL, &joueurRect);

    SDL_RenderPresent(renderer);

    return 0; // le joueur est en vie
}

void sauter() {
    // Appliquer une vitesse vers le haut si le joueur est au sol
    if (!enSaut) {
        vitesseY = -10.0f; // vitesse initiale de saut
        enSaut = 1;
    }
}

void gravite(int solY) {
    const float graviteForce = 0.2f;

    vitesseY += graviteForce;
    joueurY += (int)vitesseY;

    if (joueurY >= solY) {
        joueurY = solY;
        vitesseY = 0;
        enSaut = 0;
    }
}