#include "Level.h"
#include "Path.h"
#include "Game.h"

Level::Level(int numEnemies, float spawnInterval) :
    m_numEnemies(numEnemies),
    m_numEnemiesSpawned(0),
    m_spawnInterval(spawnInterval),
    m_timeSinceLastSpawn(0)
{
    // Spawn the first enemy immediately
    m_enemies.push_back(new Enemy);
    m_numEnemiesSpawned++;
}

Level::~Level()
{
    // Delete any remaining enemies in the level
    for (auto enemy : m_enemies) {
        delete enemy;
    }
}

void Level::update()
{
    // Spawn a new enemy if the spawn interval has elapsed and there are more enemies to spawn
    m_timeSinceLastSpawn += Game::deltaTime();
    if (m_numEnemiesSpawned < m_numEnemies && m_timeSinceLastSpawn >= m_spawnInterval) {
        m_enemies.push_back(new Enemy);
        m_numEnemiesSpawned++;
        m_timeSinceLastSpawn = 0;
    }

    // Update the position of each enemy in the level
    for (auto enemy : m_enemies) {
        enemy->update();
    }

    // Check if any enemy has reached the end of the path and delete it if so
    auto it = m_enemies.begin();
    while (it != m_enemies.end()) {
        if ((*it)->getDistanceTravelled() >= Path::TOTAL_DISTANCE) {
            delete (*it);
            it = m_enemies.erase(it);
        }
        else {
            it++;
        }
    }
}

void Level::render()
{
    Graphics graphics;

    // Draw each enemy in the level
    for (auto enemy : m_enemies) {
        enemy->render();
    }
}

bool Level::isFinished() const
{
    // The level is finished if all enemies have been defeated or have reached the end of the path
    return m_enemies.empty() && m_numEnemiesSpawned == m_numEnemies;
}
