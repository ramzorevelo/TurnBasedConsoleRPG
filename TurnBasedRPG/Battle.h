#pragma once
#include "Player.h"
#include "Enemy.h"

// Owns the main combat loop.
// Holds references to the Player and Enemy created in main().
class Battle
{
public:
    Battle(Player& player, Enemy& enemy);
    void run();

private:
    Player& m_player;
    Enemy& m_enemy;

    // Toughness damage each player action deals to the break gauge.
    static constexpr int kBasicToughDmg{ 10 };
    static constexpr int kSkillToughDmg{ 25 };
    static constexpr int kUltToughDmg{ 30 };

    void printStatus()  const;
    void printBar(int current, int maximum, int width) const;
    void playerTurn();
    void enemyTurn();
};
#pragma once
