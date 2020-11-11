#include "Pattern.hpp"

#include <vector>

class PatternGlider : public Pattern
{

  public:
    std::vector<std::vector<char>> grid = {
        { ' ', '*', ' ' },
        { ' ', ' ', '*' },
        { '*', '*', '*' }
    };
    virtual std::uint8_t getSizeX() const override
    {
        uint8_t max = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            if (grid[i].size() > max)
            {
                max = static_cast<uint8_t>(grid[i].size());
            }
        }
        return max;
    }
    virtual std::uint8_t getSizeY() const override { return static_cast<uint8_t>(grid.size()); }
    virtual bool getCell(std::uint8_t x, std::uint8_t y) const override
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
};
