#include "../engine/core/Engine.hpp"
#include "../game/GameFactory.hpp"

int main()
{
    Engine engine;
    Game* game = createGameInstance();
    game->setEngine(&engine);

    if(!engine.init("Game", SCREEN_WIDTH, SCREEN_HEIGHT))
    {
        return 1;
    }

    engine.setGame(game);
    engine.run();
    engine.shutdown();

    return 0;
}
