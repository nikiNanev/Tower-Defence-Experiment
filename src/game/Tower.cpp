#include "Tower.h"
#include <cmath>

Tower::Tower()
    : m_x(0.0f), m_y(0.0f), m_range(50.0f), m_damage(10.0f),
      m_attackCooldown(0.0f), m_attacking(false)
{}

Tower::~Tower() {}

void Tower::update() {
    // Find enemies within range
    // m_enemiesInRange.clear();
    // for (auto enemy : EnemyManager::getEnemies()) {
    //     if (std::hypot(enemy->getX() - m_x, enemy->getY() - m_y) <= m_range) {
    //         m_enemiesInRange.push_back(enemy);
    //     }
    // }

    // // Select target if attacking or no target
    // if (m_attacking && m_target) {
    //     if (std::hypot(m_target->getX() - m_x, m_target->getY() - m_y) > m_range) {
    //         m_attacking = false;
    //         m_target = nullptr;
    //     }
    // }

    // if (!m_attacking || !m_target) {
    //     // Select a new target from enemies in range
    //     m_target = nullptr;
    //     for (auto enemy : m_enemiesInRange) {
    //         if (!m_target || enemy->getDistanceTravelled() > m_target->getDistanceTravelled()) {
    //             m_target = enemy;
    //         }
    //     }
    //     m_attacking = m_target != nullptr;
    // }

    // // Attack target if ready
    // if (canAttack() && m_attacking && m_target) {
    //     attack();
    // }
    // else {
    //     m_attackCooldown -= Time::getDeltaTime();
    // }
}

void Tower::render() {
    //Graphics::drawRect(m_x, m_y, 20.0f, 20.0f, { 255, 255, 0, 255 });
}

bool Tower::canAttack() {
    return m_attackCooldown <= 0.0f;
}

void Tower::attack() {
    //enemy->takeDamage(m_damage);
    m_attackCooldown = 1.0f;
}

void Tower::setPosition(float x, float y) {
    m_x = x;
    m_y = y;
}

float Tower::getX() const {
    return m_x;
}

float Tower::getY() const {
    return m_y;
}

void Tower::setRange(float range) {
    m_range = range;
}

float Tower::getRange() const {
    return m_range;
}

void Tower::setDamage(float damage) {
    m_damage = damage;
}

float Tower::getDamage() const {
    return m_damage;
}
