#include <SDL2/SDL.h>
#include "game_of_life.hpp"

const int WINDOW_WIDTH = 1600;
const int WINDOW_HEIGHT = 1200;
const int CELL_SIZE = 8;

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    GameOfLife game(WINDOW_WIDTH / CELL_SIZE, WINDOW_HEIGHT / CELL_SIZE, CELL_SIZE);
    game.initGrid();

    bool running = true;
    bool paused = false;

    while (running) {
        if (!paused) {
            paused = game.handleEvents(paused);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            game.updateGrid();
            game.renderGrid(renderer);
            SDL_RenderPresent(renderer);
            SDL_Delay(100);
        }else {
            paused = game.handleEvents(paused);
        }        
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
