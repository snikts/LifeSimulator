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

    virtual bool getCell(std::uint8_t x, std::uint8_t y) const override
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
};
