#include "../../include/enemy/Enemy.h"

Enemy::Enemy() : m_x(0), m_y(0), m_speed(0), m_health(0), m_distanceTravelled(0)
{
}

Enemy::~Enemy()
{
}

void Enemy::update()
{
    // Move the enemy along the path
    m_x += m_speed;
    m_distanceTravelled += m_speed;
}

void Enemy::render()
{
}

void Enemy::setPosition(float x, float y)
{
    m_x = x;
    m_y = y;
}

float Enemy::getX() const
{
    return m_x;
}

float Enemy::getY() const
{
    return m_y;
}

void Enemy::setSpeed(float speed)
{
    m_speed = speed;
}

float Enemy::getSpeed() const
{
    return m_speed;
}

void Enemy::setHealth(float health)
{
    m_health = health;
}

float Enemy::getHealth() const
{
    return m_health;
}

void Enemy::takeDamage(float damage)
{
    m_health -= damage;
}

float Enemy::getDistanceTravelled() const
{
    return m_distanceTravelled;
}
