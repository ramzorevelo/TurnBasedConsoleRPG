#pragma once
#include "Player.h"
#include "Enemy.h"
#include "IAction.h"
#include <vector>
#include <memory>

class Battle
{
public:
    Battle(Player& player, Enemy& enemy, std::vector<std::unique_ptr<IAction>> actions);
    void run();

private:
    Player& m_player;
    Enemy& m_enemy;
    std::vector<std::unique_ptr<IAction>> m_actions;

    void printStatus() const;
    void printBar(int current, int maximum, int width) const;
    void playerTurn();
    void enemyTurn();
};