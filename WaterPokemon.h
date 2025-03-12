#ifndef WATERPOKEMON_H
#define WATERPOKEMON_H

#include "Pokemon.h"

class WaterPokemon : public Pokemon
{
public:
    WaterPokemon(std::string n, int h, int a)
        : Pokemon(n, "Water", h, a, "Electric") {}

    void attack(Pokemon &target) override
    {
        int damage = attackPower;
        if (target.getType() == weakness)
            damage *= 2;
        if (target.getType() == "Fire")
            damage /= 2;

        target.takeDamage(damage);
        std::cout << name << " attacks " << target.getName()
                  << " dealing " << damage << " damage!\n";
    }
};

#endif
