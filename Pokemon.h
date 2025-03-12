#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include "Interact.h"

class Pokemon : public Interact
{
protected:
    std::string name;
    std::string type;
    int hp;
    int attackPower;
    std::string weakness;

public:
    Pokemon(std::string n, std::string t, int h, int a, std::string w)
        : name(n), type(t), hp(h), attackPower(a), weakness(w) {}

    virtual void attack(Pokemon &target) = 0;

    bool isDefeated() const { return hp <= 0; }

    void takeDamage(int damage)
    {
        hp -= damage;
        if (hp < 0)
            hp = 0; 
    }

    void displayStats() const
    {
        std::cout << "🔹 " << name << " (Type: " << type << ", HP: " << hp
                  << ", Attack: " << attackPower << ", Weakness: " << weakness << ")\n";
    }

    void interact() override
    {
        if (hp > 0)
        {
            std::cout << "✨ " << name << " is happy to see you! It jumps happily!\n";
        }
        else
        {
            std::cout << "💤 " << name << " is resting and recovering from battle...\n";
        }
    }

    int getHP() const { return hp; }
    int getAttackPower() const { return attackPower; }
    std::string getType() const { return type; }
    std::string getWeakness() const { return weakness; }
    std::string getName() const { return name; }
};

#endif
