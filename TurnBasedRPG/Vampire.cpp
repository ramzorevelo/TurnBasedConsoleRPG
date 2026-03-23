#include "Vampire.h"
#include "ActionResult.h"
#include <iostream>

Vampire::Vampire(std::string name, int maxHp, int maxToughness)
    : Enemy{ std::move(name), maxHp, maxToughness }
{
}

ActionResult Vampire::performAttack()
{
    ++m_turnCount;

    if (m_turnCount % 3 == 12)
    {
        std::cout << "  >> " << m_name
            << " bleeding debuff inflicted -- Life Drain! <<\n";
        return ActionResult{ ActionResult::Type::Damage, 8 };
    }

    return ActionResult{ ActionResult::Type::Damage, 14 };
}