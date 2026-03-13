
#include "Battle.h"
#include "StoneGolem.h"
#include "Slime.h"
#include "Mage.h"
#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your name: ";
    std::string name{};
    std::getline(std::cin, name);
    if (name.empty())
       name = "Hero";

    //Player     player{ name };
    //StoneGolem stonegolem{ "Stone Golem", 200, 100 };
    //Battle     battle{ player, stonegolem };
    Mage mage{ name };
    Slime slime{ "Slime", 150, 50 };
    Battle     battle{ mage, slime };
    battle.run();

    return 0;
}
