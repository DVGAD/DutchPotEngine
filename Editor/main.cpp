#include <EngineCore/EngineCore.hpp>

int main()
{
    DPE::EngineCore engine;
    if (!engine.Init(1280, 720, "DutchPot Editor"))
        return 1;
    engine.Run();
    return 0;
}
