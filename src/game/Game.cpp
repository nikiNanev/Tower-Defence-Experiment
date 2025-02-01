#include "Game.h"

#include <chrono>

Game::Game()
{
    // Constructor
    std::cout << "Init ctor for Game" << std::endl;
}

Game::~Game()
{
    // Destructor
}

bool Game::init()
{
    // Initialize graphics and input systems
    if (!graphics_.init())
    {
        return false;
    }

    if (!input_.init())
    {
        return false;
    }

    // Load game assets
    // ...

    // Set up game level
    // ...

    return true;
}

double Game::deltaTime()
{
    auto now = std::chrono::high_resolution_clock::now();

    // Convert to duration since epoch in seconds (double)
    double time_in_seconds = std::chrono::duration<double>(
                                 now.time_since_epoch())
                                 .count();
    return time_in_seconds;
}

void Game::loop()
{
    while (!input_.quitRequested())
    {
        // Process player input
        input_.update();

        // Update game state
        // for (auto &tower : towers_)
        // {
        //     tower.update(enemies_);
        // }

        // for (auto &enemy : enemies_)
        // {
        //     enemy.update();
        // }

        // Render graphics
        graphics_.render();

        // Delay to maintain consistent frame rate
        // ...
    }
}

void Game::cleanup()
{
    // Free game assets
    // ...

    // Shut down graphics and input systems
    graphics_.cleanup();
}
