#include "Battle.h"
#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your name: ";

    std::string name{};
    std::getline(std::cin, name);
    if (name.empty())
        name = "Hero";

    Player player{ name };
    Enemy  enemy{ "Stone Golem", 200, 60 };

    Battle battle{ player, enemy };
    battle.run();

    return 0;
}
