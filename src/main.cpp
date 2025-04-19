#include "engine/core/Engine.hpp"
#include "game/Game.hpp"

int main()
{
    Engine engine;
    if(!engine.init("Game"), 1280, 720)
    {
        return 1;
    }

    Game game;
    engine.setGame(&game);
    engine.run();
    engine.shutdown();

    return 0;
}
