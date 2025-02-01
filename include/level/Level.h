#pragma once

#include <vector>
#include "Enemy.h"

class Level {
public:
    Level() = default;
    Level(int numEnemies, float spawnInterval);
    ~Level();

    void update();
    void render();
    bool isFinished() const;
private:
    std::vector<Enemy*> m_enemies;
    int m_numEnemies;
    int m_numEnemiesSpawned;
    float m_spawnInterval;
    float m_timeSinceLastSpawn;
};
