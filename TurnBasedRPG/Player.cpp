#include "Player.h"
#include <algorithm>

Player::Player(std::string name)
    : Character{ std::move(name), 120 }
{
}

int  Player::getSp()         const { return m_sp; }
int  Player::getEnergy()     const { return m_energy; }
bool Player::ultimateReady() const { return m_energy >= kMaxEnergy; }

void Player::gainSp(int amount)
{
    m_sp = std::min(kMaxSp, m_sp + amount);
}

void Player::gainEnergy(int amount)
{
    m_energy = std::min(kMaxEnergy, m_energy + amount);
}

int Player::basicAttack()
{
    gainSp(1);
    gainEnergy(20);
    return 15;
}

int Player::useSkill()
{
    --m_sp;
    gainEnergy(30);
    return 28;
}

int Player::useUltimate()
{
    m_energy = 0;
    gainSp(2);
    return 60;
}
