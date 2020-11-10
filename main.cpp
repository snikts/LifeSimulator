#include "PatternAcorn.hpp"
#include "PatternBlock.hpp"
#include "RendererConsole.hpp"
#include "PatternGosperGliderGun.hpp"
#include <thread>


#include <memory>

int main()
{
    LifeSimulator ls(25, 25);
    ls.insertPattern(PatternAcorn(), 1, 1);
    RendererConsole renderer;
    for (size_t i = 0; i < 20; i++)
    {
        //renderer.render(ls);
        //std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << " " << std::endl;
        ls.update();
    }
    std::cout << " " << std::endl;

    return 0;
}
