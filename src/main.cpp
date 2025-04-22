#include "../engine/core/Engine.hpp"
#include "../game/GameFactory.hpp"

int main()
{
    Engine engine;
    Game* game = createGameInstance();
    game->setEngine(&engine);

    if(!engine.init("Game", 1280, 720))
    {
        return 1;
    }

    engine.setGame(game);
    engine.run();
    engine.shutdown();

    return 0;
}
