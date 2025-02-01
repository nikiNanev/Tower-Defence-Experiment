#pragma once
#include "../enemy/Enemy.h"

#include <vector>
#include <cstdlib>
#include <string>

class Tower
{
public:
    Tower();
    ~Tower();

    void update();
    void render();

    bool canAttack();
    void attack();

    // Setters and getters
    void setPosition(float x, float y);
    float getX() const;
    float getY() const;
    void setRange(float range);
    float getRange() const;
    void setDamage(float damage);
    float getDamage() const;
    // Setters
    void setMovable(bool isMovable);
    void setStatic(bool isStatic);
    void setDynamic(bool isDynamic);

    void setID(size_t id);
    void setHealth(unsigned short health);
    void setName(std::string name);
    void setDamage(unsigned short damage);
    void setPosition(size_t posX, size_t posY);
    void setSize(size_t width, size_t height);

    // Getters

    size_t getID();
    unsigned short getDamage();
    unsigned short getHealth();
    std::string getName();
    size_t getPosX();
    size_t getPosY();
    size_t getWidth();
    size_t getHeight();

private:
    float m_x, m_y;                        // Position
    float m_range;                         // Attack range
    float m_damage;                        // Attack damage
    float m_attackCooldown;                // Time until next attack
    bool m_attacking;                      // Whether the tower is currently attacking an enemy

    size_t id;
    unsigned short damage;
    unsigned short health;
    std::string name;

    bool isMovable = false;
    bool isStatic = false;
    bool isDynamic = false;

    size_t posX, posY;
    size_t width, height;
};
