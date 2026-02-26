#include "Enemy.h"
#include <algorithm>

Enemy::Enemy(std::string name, int maxHp, int maxToughness)
    : Character{ std::move(name), maxHp }
    , m_toughness{ maxToughness }
    , m_maxToughness{ maxToughness }
{
}

int  Enemy::getToughness()    const { return m_toughness; }
int  Enemy::getMaxToughness() const { return m_maxToughness; }
bool Enemy::isBroken()        const { return m_isBroken; }

void Enemy::reduceToughness(int amount)
{
    m_toughness = std::max(0, m_toughness - amount);
    if (m_toughness == 0)
    {
        m_isBroken = true;
        m_toughness = m_maxToughness; // reset for the next cycle
    }
}

void Enemy::recoverFromBreak()
{
    m_isBroken = false;
}

int Enemy::performAttack()
{
    return 20;
}
