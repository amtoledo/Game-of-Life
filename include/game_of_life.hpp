#ifndef GAME_OF_LIFE_HPP
#define GAME_OF_LIFE_HPP

#include <SDL2/SDL.h>
#include <vector>
#include "grid.hpp"

class GameOfLife {
public:
    GameOfLife(int width, int height, int cellSize);
    ~GameOfLife();
    void initGrid();
    void updateGrid();
    void renderGrid(SDL_Renderer* renderer);
    bool handleEvents(bool paused);

private:
    int countNeighbors(int x, int y);
    int width;
    int height;
    int cellSize;
    Grid grid;
    Grid tempGrid;
};

#endif
