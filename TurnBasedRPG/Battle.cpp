#include "Battle.h"
#include <iostream>
#include <limits>

Battle::Battle(Player& player, Enemy& enemy)
    : m_player{ player }
    , m_enemy{ enemy }
{
}

void Battle::printBar(int current, int maximum, int width) const
{
    int filled{ (maximum > 0) ? (current * width / maximum) : 0 };
    std::cout << '[';
    for (int i{ 0 }; i < width; ++i)
        std::cout << ((i < filled) ? '#' : '.');
    std::cout << "] " << current << '/' << maximum;
}

void Battle::printStatus() const
{
    std::cout << "\n------------------------------------\n";

    std::cout << "  " << m_enemy.getName() << '\n';
    std::cout << "  HP:        ";
    printBar(m_enemy.getHp(), m_enemy.getMaxHp(), 20);
    std::cout << '\n';
    std::cout << "  Toughness: ";
    printBar(m_enemy.getToughness(), m_enemy.getMaxToughness(), 20);
    std::cout << '\n';

    std::cout << "\n  " << m_player.getName() << '\n';
    std::cout << "  HP:        ";
    printBar(m_player.getHp(), m_player.getMaxHp(), 20);
    std::cout << '\n';
    std::cout << "  SP:     " << m_player.getSp()
        << '/' << Player::kMaxSp << '\n';
    std::cout << "  Energy: ";
    printBar(m_player.getEnergy(), Player::kMaxEnergy, 10);
    std::cout << '\n';

    std::cout << "------------------------------------\n";
}

void Battle::playerTurn()
{
    std::cout << "\nYour actions:\n";
    std::cout << "  [1] Basic Strike      (15 dmg | 10 break | +1 SP | +20 energy)\n";
    std::cout << "  [2] Skill             (28 dmg | 25 break | -1 SP | +30 energy)"
        << (m_player.getSp() < 1 ? " [NOT ENOUGH SP]" : "") << '\n';
    std::cout << "  [3] Ultimate          (60 dmg | 30 break | uses all energy)"
        << (!m_player.ultimateReady() ? " [NOT READY]" : " [READY]") << '\n';

    int choice{};
    while (true)
    {
        std::cout << "Choose: ";
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 1)
        {
            int dmg{ m_player.basicAttack() };
            m_enemy.takeDamage(dmg);
            m_enemy.reduceToughness(kBasicToughDmg);
            std::cout << m_player.getName()
                << " uses Basic Strike! Deals " << dmg << " damage.\n";
            break;
        }
        else if (choice == 2)
        {
            if (m_player.getSp() < 1)
            {
                std::cout << "Not enough SP.\n";
                continue;
            }
            int dmg{ m_player.useSkill() };
            m_enemy.takeDamage(dmg);
            m_enemy.reduceToughness(kSkillToughDmg);
            std::cout << m_player.getName()
                << " uses Skill! Deals " << dmg << " damage.\n";
            break;
        }
        else if (choice == 3)
        {
            if (!m_player.ultimateReady())
            {
                std::cout << "Ultimate is not ready yet.\n";
                continue;
            }
            int dmg{ m_player.useUltimate() };
            m_enemy.takeDamage(dmg);
            m_enemy.reduceToughness(kUltToughDmg);
            std::cout << m_player.getName()
                << " activates Ultimate! Deals " << dmg << " damage!\n";
            break;
        }
        else
        {
            std::cout << "Enter 1, 2, or 3.\n";
        }
    }

    if (m_enemy.isBroken())
        std::cout << ">> BREAK! " << m_enemy.getName()
        << " is stunned! <<\n";
}

void Battle::enemyTurn()
{
    if (m_enemy.isBroken())
    {
        std::cout << m_enemy.getName() << " is stunned and cannot act.\n";
        m_enemy.recoverFromBreak();
        return;
    }

    int dmg{ m_enemy.performAttack() };
    m_player.takeDamage(dmg);
    std::cout << m_enemy.getName() << " attacks for " << dmg << " damage!\n";
}

void Battle::run()
{
    std::cout << "\n=== BATTLE START ===\n";
    std::cout << m_player.getName() << " vs " << m_enemy.getName() << '\n';

    while (m_player.isAlive() && m_enemy.isAlive())
    {
        printStatus();
        playerTurn();

        if (!m_enemy.isAlive())
        {
            std::cout << "\n" << m_enemy.getName() << " is destroyed!\n";
            std::cout << "=== VICTORY ===\n";
            return;
        }

        enemyTurn();

        if (!m_player.isAlive())
        {
            std::cout << "\n" << m_player.getName() << " has been defeated.\n";
            std::cout << "=== DEFEAT ===\n";
            return;
        }
    }
}
