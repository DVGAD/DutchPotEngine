#include <EngineCore/EngineCore.hpp>
#include "Scenes/TestScene.hpp"


int main()
{
    DPE::EngineCore engine;

    if (!engine.Init(1280, 720, "DutchPot Editor"))
        return EXIT_FAILURE;

    engine.SetScene(std::make_unique<DPE::TestScene>());
    engine.Run();
    return EXIT_SUCCESS;
}
