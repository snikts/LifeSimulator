#include "RendererConsole.hpp"
void RendererConsole::render(const LifeSimulator& simulation)
{
    rlutil::cls();
    rlutil::hidecursor();
    for (int i = 0; i < simulation.getSizeY(); ++i)
    {
        for (int j = 0; j < simulation.getSizeX(); ++j)
        {
            if (simulation.getCell(j, i))
            {
                rlutil::locate(i, j);
                rlutil::setChar('*');
            }
        }
    }
    rlutil::showcursor();
}