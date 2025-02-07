#include "game_of_life.hpp"
#include <ctime>
#include <cstdlib>

GameOfLife::GameOfLife(int width, int height, int cellSize): 
        width(width), 
        height(height), 
        cellSize(cellSize), 
        grid(width, height),
        tempGrid(width, height)
        {}

GameOfLife::~GameOfLife() {}

void GameOfLife::initGrid() {
    grid.randomize();
}

int GameOfLife::countNeighbors(int x, int y) {
    return grid.countNeighbors(x, y);
}

void GameOfLife::updateGrid() {
    grid.update();
}

void GameOfLife::renderGrid(SDL_Renderer* renderer) {
    grid.render(renderer, cellSize);
}

bool GameOfLife::handleEvents(bool paused) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            exit(0);
        }
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_SPACE) {
                // stop and return the game
                paused = !paused;
            }
            if (event.key.keysym.sym == SDLK_r) {
                initGrid();
            }
        }
    }
    return paused;
}
