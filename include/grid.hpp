#ifndef GRID_HPP
#define GRID_HPP

#include <SDL2/SDL.h>
#include <vector>

class Grid {
private:
    int width;
    int height;
    std::vector<std::vector<bool>> tempCells;
public:
    Grid(int width, int height);
    void randomize();
    int countNeighbors(int x, int y);
    void update();
    void render(SDL_Renderer* renderer, int cellSize);
    std::vector<std::vector<bool>> cells;

};

#endif
