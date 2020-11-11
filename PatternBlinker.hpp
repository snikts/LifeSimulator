#include "Pattern.hpp"

class PatternBlinker : public Pattern
{

  public:
    char grid[3][3] = {
        { ' ', ' ', ' ' },
        { '*', '*', '*' },
        { ' ', ' ', ' ' }
    };
    virtual std::uint8_t getSizeX() const override { return 3; }
    virtual std::uint8_t getSizeY() const override { return 3; }
    virtual bool getCell(std::uint8_t x, std::uint8_t y) const override
    {
        if (x < 3 || y < 3)
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
