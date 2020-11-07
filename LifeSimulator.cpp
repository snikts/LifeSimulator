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

void LifeSimulator::update()
{
    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < x; ++j)
        {
            // if cell (i, j) is alive
            if (getCell(j, i))
            {
                int neighbors = 0;
                // check cells:
                //(i+1, j)
                if (j + 1 < x)
                {
                    bool right = getCell(j + 1, i);
                    if (right)
                    {
                        neighbors = neighbors + 1;
                    }
                }
                //(i-1, j)
                if (j - 1 > 0)
                {
                    bool left = getCell(j - 1, i);
                    if (left)
                    {
                        neighbors = neighbors + 1;
                    }
                }
                //(i+1, j+1)
                if (j + 1 < x && i + 1 < y)
                {
                    bool bottomRight = getCell(j + 1, i + 1);
                    if (bottomRight)
                    {
                        neighbors = neighbors + 1;
                    }
                }
                //(i, j+1)
                if (i + 1 < y)
                {
                    bool bottom = getCell(j, i + 1);
                    if (bottom)
                    {
                        neighbors = neighbors + 1;
                    }
                }
                //(i-1, j+1)
                if (j - 1 > 0 && i + 1 < y)
                {
                    bool bottomLeft = getCell(j - 1, i + 1);
                    if (bottomLeft)
                    {
                        neighbors = neighbors + 1;
                    }
                }
                //(i+1, j-1)
                if (j + 1 < x && i - 1 > 0)
                {
                    bool topRight = getCell(j + 1, i - 1);
                    if (topRight)
                    {
                        neighbors = neighbors + 1;
                    }
                }
                //(i, j-1)
                if (i - 1 > 0)
                {
                    bool top = getCell(j, i - 1);
                    if (top)
                    {
                        neighbors = neighbors + 1;
                    }
                }
                //(i-1, j-1)
                if (j - 1 > 0 && i - 1 > 0)
                {
                    bool topLeft = getCell(j - 1, i - 1);
                    if (topLeft)
                    {
                        neighbors = neighbors + 1;
                    }
                }

                //if more than three of these cells are alive
                if (neighbors > 3)
                {
                    //kill current cell
                    grid[j][i] = ' ';
                }
                //if less than 2 of these cells are alive
                if (neighbors < 2)
                {
                    //kill current cell
                    grid[j][i] = ' ';
                }
            }
            // if cell (i, j) is dead
            else
            {
                int neighbors = 0;
                // check cells:
                //(i+1, j)
                if (j + 1 < x)
                {
                    bool right = getCell(j + 1, i);
                    if (right)
                    {
                        neighbors = neighbors + 1;
                    }
                }
                //(i-1, j)
                if (j - 1 > 0)
                {
                    bool left = getCell(j - 1, i);
                    if (left)
                    {
                        neighbors = neighbors + 1;
                    }
                }
                //(i+1, j+1)
                if (j + 1 < x && i + 1 < y)
                {
                    bool bottomRight = getCell(j + 1, i + 1);
                    if (bottomRight)
                    {
                        neighbors = neighbors + 1;
                    }
                }
                //(i, j+1)
                if (i + 1 < y)
                {
                    bool bottom = getCell(j, i + 1);
                    if (bottom)
                    {
                        neighbors = neighbors + 1;
                    }
                }
                //(i-1, j+1)
                if (j - 1 > 0 && i + 1 < y)
                {
                    bool bottomLeft = getCell(j - 1, i + 1);
                    if (bottomLeft)
                    {
                        neighbors = neighbors + 1;
                    }
                }
                //(i+1, j-1)
                if (j + 1 < x && i - 1 > 0)
                {
                    bool topRight = getCell(j + 1, i - 1);
                    if (topRight)
                    {
                        neighbors = neighbors + 1;
                    }
                }
                //(i, j-1)
                if (i - 1 > 0)
                {
                    bool top = getCell(j, i - 1);
                    if (top)
                    {
                        neighbors = neighbors + 1;
                    }
                }
                //(i-1, j-1)
                if (j - 1 > 0 && i - 1 > 0)
                {
                    bool topLeft = getCell(j - 1, i - 1);
                    if (topLeft)
                    {
                        neighbors = neighbors + 1;
                    }
                }

                //if three of these cells are alive, make current cell alive
                if (neighbors == 3)
                {
                    grid[j][i] = '*';
                }
            }
        }
    }
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
    if (x < LifeSimulator::x && y < LifeSimulator::y)
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
    else
    {
        return false;
    }
}
