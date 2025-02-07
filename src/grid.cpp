#include "grid.hpp"
#include <cstdlib>
#include <ctime>

Grid::Grid(int width, int height) : 
    width(width), 
    height(height), 
    cells(width, std::vector<bool>(height, false)), 
    tempCells(width, std::vector<bool>(height, false)) {}

void Grid::randomize() {
    std::srand(std::time(0));
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            cells[x][y] = std::rand() % 2;
        }
    }
}

int Grid::countNeighbors(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                count += cells[nx][ny];
            }
        }
    }
    return count;
}

void Grid::update() {
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            int neighbors = countNeighbors(x, y);
            if (cells[x][y]) {
                tempCells[x][y] = neighbors == 2 || neighbors == 3;
            } else {
                tempCells[x][y] = neighbors == 3;
            }
        }
    }
    cells.swap(tempCells);
}

void Grid::render(SDL_Renderer* renderer, int cellSize) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            if (cells[x][y]) {
                SDL_Rect cellRect = {x * cellSize, y * cellSize, cellSize, cellSize};
                SDL_RenderFillRect(renderer, &cellRect);
            }
        }
    }
}