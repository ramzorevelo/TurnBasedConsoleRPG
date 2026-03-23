#include "VampireBat.h"
#include "ActionResult.h"
#include <iostream>

VampireBat::VampireBat(std::string name, int maxHp, int maxToughness)
    : Enemy{ std::move(name), maxHp, maxToughness }
{
}

ActionResult VampireBat::performAttack()
{
    ++m_turnCount;

    if (m_turnCount % 3 == 0)
    {
        std::cout << "  >> " << m_name
            << "HHAHAHAHA<<\n";
        heal(12);
        return ActionResult{ ActionResult::Type::Damage, 8 };
    }

    return ActionResult{ ActionResult::Type::Damage, 14 };
}