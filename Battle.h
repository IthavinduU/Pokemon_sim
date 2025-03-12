#ifndef BATTLE_H
#define BATTLE_H

#include "Trainer.h"

class Battle
{
public:
    static void startBattle(Trainer &player, Trainer &opponent)
    {
        std::cout << "\n⚔️ Battle: " << player.getName() << " vs " << opponent.getName() << "\n";

        Pokemon *playerPokemon = player.getFirstPokemon();
        Pokemon *opponentPokemon = opponent.getFirstPokemon();

        if (!playerPokemon || !opponentPokemon)
        {
            std::cout << "❌ One of the trainers has no Pokémon left!\n";
            return;
        }

        while (playerPokemon && opponentPokemon)
        {
            std::cout << "👉 " << playerPokemon->getName() << " attacks!\n";
            playerPokemon->attack(*opponentPokemon);

            if (opponentPokemon->isDefeated())
            {
                std::cout << "❌ " << opponentPokemon->getName() << " fainted!\n";
                opponentPokemon = opponent.getFirstPokemon();
                if (!opponentPokemon)
                {
                    std::cout << "🏆 " << player.getName() << " WINS!\n";
                    player.addWin();
                    player.addBadge();
                    return;
                }
            }

            std::cout << "👈 " << opponentPokemon->getName() << " attacks!\n";
            opponentPokemon->attack(*playerPokemon);

            if (playerPokemon->isDefeated())
            {
                std::cout << "❌ " << playerPokemon->getName() << " fainted!\n";
                playerPokemon = player.getFirstPokemon();
                if (!playerPokemon)
                {
                    std::cout << "🏆 " << opponent.getName() << " WINS!\n";
                    player.addLoss();
                    return;
                }
            }
        }
    }
};

#endif
