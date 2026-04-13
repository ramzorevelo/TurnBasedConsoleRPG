#include "Enemy.h"
#include <algorithm>


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

ActionResult Enemy::performAttack()
{
    return ActionResult{ ActionResult::Type::Damage, 20 };
}
bool Enemy::hasDrop() const { return m_drop.has_value(); }

Enemy::Enemy(std::string name, int maxHp, int maxToughness, std::optional<Drop> drop)
    : Character{ std::move(name), maxHp }
    , m_toughness{ maxToughness }
    , m_maxToughness{ maxToughness }
    , m_drop{ std::nullopt } {
}

const std::optional<Drop>& Enemy::getDrop() const { return m_drop; }