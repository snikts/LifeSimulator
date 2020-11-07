#include "Pattern.hpp"

#include <vector>

class PatternAcorn : public Pattern
{

  public:
    std::vector<std::vector<char>> grid = {
        { ' ', '*', ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', '*', ' ', ' ', ' ' },
        { '*', '*', ' ', ' ', '*', '*', '*' }
    };
    virtual std::uint8_t getSizeX() const override
    {
        int max = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            if (grid[i].size() > max)
            {
                max = grid[i].size();
            }
        }
        return max;
    }
    virtual std::uint8_t getSizeY() const override { return grid.size(); }
    bool getCell(std::uint8_t x, std::uint8_t y)
    {
        if (x < getSizeX() || y < getSizeY())
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
    virtual bool getCell(std::uint8_t x, std::uint8_t y) const override
    {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == '*')
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
};
