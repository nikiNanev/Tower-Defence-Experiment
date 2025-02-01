#ifndef GAME_H
#define GAME_H

#pragma once

#include "Graphics.h"
#include "Input.h"
#include "Tower.h"
#include "Enemy.h"
#include "Level.h"

#include <iostream>
#include <vector>

class Game
{
public:
    Game();
    ~Game();

    bool init();
    void loop();
    void cleanup();
    
    static double deltaTime();

private:
    Graphics graphics_;
    Input input_;
    std::vector<Tower> towers_;
    std::vector<Enemy> enemies_;
    Level level_;
};

#endif // GAME_H
