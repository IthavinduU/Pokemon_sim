#ifndef GRASSPOKEMON_H
#define GRASSPOKEMON_H

#include "Pokemon.h"

class GrassPokemon : public Pokemon
{
public:
    GrassPokemon(std::string n, int h, int a)
        : Pokemon(n, "Grass", h, a, "Fire") {}

    void attack(Pokemon &target) override
    {
        int damage = attackPower;
        if (target.getType() == weakness)
            damage *= 2;
        if (target.getType() == "Water")
            damage /= 2;

        target.takeDamage(damage);
        std::cout << " " << name << " attacks " << target.getName()
                  << " dealing " << damage << " damage!\n";
    }
};

#endif
