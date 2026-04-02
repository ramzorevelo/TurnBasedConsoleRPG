#pragma once
#include "ActionResult.h"
#include "Player.h"
#include "Enemy.h"
#include <string>

class IAction
{
public:
    virtual ~IAction() = default;

    virtual std::string label() const = 0;

    virtual ActionResult execute(Player& player, Enemy& enemy) = 0;

    virtual bool isAvailable(const Player&) const { return true; }

};