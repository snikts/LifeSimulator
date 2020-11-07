#include "PatternAcorn.hpp"
#include "RendererConsole.hpp"

#include <memory>

int main()
{
    LifeSimulator ls(10, 10);
    ls.insertPattern(PatternAcorn(), 5, 5);
    RendererConsole renderer;
    renderer.render(ls);

    return 0;
}
