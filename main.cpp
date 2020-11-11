#include "PatternAcorn.hpp"
#include "PatternBlock.hpp"
#include "RendererConsole.hpp"
#include "PatternGosperGliderGun.hpp"
#include "PatternBlinker.hpp"
#include "PatternGlider.hpp"
#include <thread>


#include <memory>

int main()
{
    
    LifeSimulator blockSimulator(45, 45);
    RendererConsole renderer;
    blockSimulator.insertPattern(PatternBlock(), 1, 1);
    for (size_t i = 0; i < 20; i++)
    {
        renderer.render(blockSimulator);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << " " << std::endl;
        blockSimulator.update();
    }
    LifeSimulator blinkerSimulator(45, 45);
    blinkerSimulator.insertPattern(PatternBlinker(), 1, 1);
    for (size_t i = 0; i < 20; i++)
    {
        renderer.render(blinkerSimulator);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << " " << std::endl;
        blinkerSimulator.update();
    }
    LifeSimulator acornSimulator(45, 45);
    acornSimulator.insertPattern(PatternAcorn(), 22, 22);
    for (size_t i = 0; i < 100; i++)
    {
        renderer.render(acornSimulator);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << " " << std::endl;
        acornSimulator.update();
    }
    LifeSimulator gliderSimulator(45, 45);
    gliderSimulator.insertPattern(PatternGlider(), 1, 1);
    for (size_t i = 0; i < 100; i++)
    {
        renderer.render(gliderSimulator);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << " " << std::endl;
        gliderSimulator.update();
    }
    LifeSimulator gunSimulator(45, 45);
    gunSimulator.insertPattern(PatternGosperGliderGun(), 1, 1);
    for (size_t i = 0; i < 100; i++)
    {
        renderer.render(gunSimulator);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << " " << std::endl;
        gunSimulator.update();
    }
    std::cout << " " << std::endl;

    return 0;
}
