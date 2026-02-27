#include "StoneGolem.h"
#include <iostream>

StoneGolem::StoneGolem(std::string name, int maxHp, int maxToughness)
    : Enemy{ std::move(name), maxHp, maxToughness }
{
}

int StoneGolem::performAttack()
{
    ++m_turnCount;
    if (m_turnCount % 3 == 0)
    {
        std::cout << "  >> " << m_name
            << " raises both fists -- GROUND SLAM! <<\n";
        return 35;
    }
    return 20;
}
