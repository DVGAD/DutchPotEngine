#include "EngineCore/EngineCore.hpp"

int main()
{
	// Create an instance of the EngineCore class
    DPE::EngineCore engine(1280, 720, "DutchPot Editor");
    engine.Run();
    return 0;
}
