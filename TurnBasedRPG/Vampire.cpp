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

    if (m_turnCount % 3 == 0)
    {
        std::cout << "  >> " << m_name
            << " bleeding debuff inflicted -- Life Drain! <<\n";
        heal(12);
        return ActionResult{ ActionResult::Type::Damage, 8 };
        //jwyrh8wyhdf8ywgbu8yawbf7ye
    }

    return ActionResult{ ActionResult::Type::Damage, 14 };
}