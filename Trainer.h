#ifndef TRAINER_H
#define TRAINER_H

#include "Pokemon.h"
#include "Interact.h"
#include <vector>

class Trainer : public Interact
{
private:
    std::string name;
    std::vector<Pokemon *> team;
    int badges = 0;
    int battlesWon = 0;
    int battlesLost = 0;

public:
    Trainer(std::string n) : name(n) {}

    std::string getName() const { return name; }
    void addPokemon(Pokemon *p)
    {
        if (team.size() < 6)
        {
            team.push_back(p);
        }
    }

    void showPokemon()
    {
        std::cout << name << "'s Pokémon:\n";
        for (auto p : team)
        {
            p->displayStats();
        }
    }

    Pokemon *getFirstPokemon()
    {
        for (auto p : team)
        {
            if (!p->isDefeated())
                return p;
        }
        return nullptr;
    }

    void addWin() { battlesWon++; }
    void addLoss() { battlesLost++; }
    void addBadge() { badges++; }

    void displayStats()
    {
        std::cout << "📜 " << name << "'s Stats: Wins: " << battlesWon
                  << ", Losses: " << battlesLost << ", Badges: " << badges << "\n";
    }

    void swapPokemon(int index1, int index2)
    {
        if (index1 >= 0 && index1 < team.size() && index2 >= 0 && index2 < team.size())
        {
            if (team[index1]->isDefeated() || team[index2]->isDefeated())
            {
                std::cout << "❌ Cannot swap a fainted Pokémon!\n";
                return;
            }
            std::swap(team[index1], team[index2]);
            std::cout << "🔄 Pokémon order updated!\n";
        }
        else
        {
            std::cout << "❌ Invalid indices! Enter values between 0 and " << (team.size() - 1) << "\n";
        }
    }

    void interact() override
    {
        std::cout << "💬 " << name << " says: 'I'll train harder for next time!'\n";
    }

    std::vector<Pokemon *> getPokemons() { return team; }
};

#endif
