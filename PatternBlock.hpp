#include "Pattern.hpp"

#include <vector>

class PatternBlock : public Pattern
{

  public:
    char grid[2][2] = { { '*', '*' }, { '*', '*' } };
    virtual std::uint8_t getSizeX() const override { return 2; }
    virtual std::uint8_t getSizeY() const override { return 2; }
    virtual bool getCell(std::uint8_t x, std::uint8_t y) const override
    {
        if (2 > x || 2 > y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
