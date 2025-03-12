#ifndef FIREPOKEMON_H
#define FIREPOKEMON_H

#include "Pokemon.h"

class FirePokemon : public Pokemon
{
public:
    FirePokemon(std::string n, int h, int a)
        : Pokemon(n, "Fire", h, a, "Water") {}

    void attack(Pokemon &target) override
    {
        int damage = attackPower;
        if (target.getType() == weakness)
            damage *= 2;
        if (target.getType() == "Grass")
            damage /= 2;

        target.takeDamage(damage);
        std::cout << " " << name << " attacks " << target.getName()
                  << " dealing " << damage << " damage!\n";
    }
};

#endif
