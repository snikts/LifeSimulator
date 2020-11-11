#include "LifeSimulator.hpp"

#include <cstdint>
#include <iostream>

LifeSimulator::LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY)
{
    x = sizeX;
    y = sizeY;
    for (int i = 0; i < y; ++i)
    {
        grid.push_back(std::vector<char>(x));
    }
}

void LifeSimulator::insertPattern(const Pattern& pattern, std::uint8_t startX, std::uint8_t startY)
{
    for (int i = 0; i < pattern.getSizeY(); ++i)
    {
        for (int j = 0; j < pattern.getSizeX(); ++j)
        {
            if (pattern.getCell(j, i))
            {
                grid[startY + i][startX + j] = '*';
            }
        }
    }


}

int LifeSimulator::tallyNeighbors(int x, int y) {
    int neighbors = 0;

    bool top = false;
    bool topLeft = false;
    bool topRight = false;
    bool left = false;
    bool right = false;
    bool bottom = false;
    bool bottomLeft = false;
    bool bottomRight = false;

    if (y - 1 >= 0)
    {
        top = getCell(x, y - 1);
        if (x - 1 >= 0)
        {
            topLeft = getCell(x - 1, y - 1);
        }
        if (x + 1 < getSizeX())
        {
            topRight = getCell(x + 1, y - 1);
        }
    }

    if (x - 1 >= 0)
    {
        left = getCell(x - 1, y);
    }
    if (x + 1 < getSizeX())
    {
        right = getCell(x + 1, y);
    }

    if (y + 1 < getSizeY())
    {
        bottom = getCell(x, y + 1);
        if (x - 1 >= 0)
        {
            bottomLeft = getCell(x - 1, y + 1);
        }
        if (x + 1 < getSizeX()) {
            bottomRight = getCell(x + 1, y + 1);
        }
        
    }


    if (topLeft)
    {
        neighbors = neighbors + 1;
    }
    if (top)
    {
        neighbors = neighbors + 1;
    }
    if (topRight)
    {
        neighbors = neighbors + 1;
    }
    if (left)
    {
        neighbors = neighbors + 1;
    }
    if (right)
    {
        neighbors = neighbors + 1;
    }
    if (bottomLeft)
    {
        neighbors = neighbors + 1;
    }
    if (bottom)
    {
        neighbors = neighbors + 1;
    }
    if (bottomRight)
    {
        neighbors = neighbors + 1;
    }
    //std::cout << "cell (" << x << ", " << y << ") has " << neighbors << "neighbors" << std::endl;
    return neighbors;

}

void LifeSimulator::update()
{
    std::vector<std::vector<char>> newGrid = grid;
    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < x; ++j)
        {
            // if cell (j, i) is alive
            if (getCell(j, i))
            {
                int neighbors = tallyNeighbors(j, i);

                if (neighbors == 2 || neighbors == 3) {
                    newGrid[i][j] = '*';
                }
                if (neighbors < 2)
                {
                    newGrid[i][j] = ' ';
                }
                if (neighbors > 3)
                {
                    newGrid[i][j] = ' ';
                }
            }
            // if cell (j, i) is dead
            else
            {
                int neighbors = tallyNeighbors(j, i);

                //if three of these cells are alive, make current cell alive
                if (neighbors == 3)
                {
                    newGrid[i][j] = '*';
                    //std::cout << "cell (" << j << ", " << i << ") died" << std::endl;
                }
            }
        }
    }
    grid = newGrid;
}

std::uint8_t LifeSimulator::getSizeX() const
{
    return x;
}

std::uint8_t LifeSimulator::getSizeY() const
{
    return y;
}

bool LifeSimulator::getCell(std::uint8_t x, std::uint8_t y) const
{

    if (grid[y][x] == '*')
    {
        return true;
    }
    else
    {
        return false;
    }


}
