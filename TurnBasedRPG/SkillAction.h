#pragma once
#include "IAction.h"

class SkillAction : public IAction
{
public:
    std::string label() const override;
    bool isAvailable(const Player& player) const override;
    ActionResult execute(Player& player, Enemy& enemy) override;
};