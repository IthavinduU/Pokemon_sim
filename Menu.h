#ifndef MENU_H
#define MENU_H

#include "Trainer.h"
#include "Battle.h"
#include "DataLoader.h"

class Menu
{
public:
    static void showMenu()
    {
        Trainer player("Ash");
        Trainer gymLeader("Brock");

        std::vector<Pokemon *> pokemonList = DataLoader::loadPokemon("pokemon.csv");

        if (pokemonList.size() < 6)
        {
            std::cerr << "❌ Error: Not enough Pokémon in pokemon.csv! Need at least 6.\n";
            return;
        }

        for (int i = 0; i < 3; i++)
            player.addPokemon(pokemonList[i]);
        for (int i = 3; i < 6; i++)
            gymLeader.addPokemon(pokemonList[i]);

        int choice;
        while (true)
        {
            std::cout << "\n===== POKÉMON BATTLE SIMULATOR =====\n";
            std::cout << "1. View Pokémon Stats\n2. Battle Gym Leader\n3. Change Pokémon Order\n";
            std::cout << "4. View Player Statistics\n5. Interact with Pokémon\n6. Interact with Defeated Trainers\n7. Exit\n";
            std::cout << "Enter choice: ";
            std::cin >> choice;

            if (choice == 1)
                player.showPokemon();
            else if (choice == 2)
                Battle::startBattle(player, gymLeader);
            else if (choice == 3)
            {
                int i1, i2;
                player.showPokemon();
                std::cout << "Enter two Pokémon indices to swap (0-based): ";
                std::cin >> i1 >> i2;
                player.swapPokemon(i1, i2);
            }
            else if (choice == 4)
                player.displayStats();
            else if (choice == 5)
            {
                for (auto p : player.getPokemons())
                    p->interact();
            }
            else if (choice == 6)
                gymLeader.interact();
            else if (choice == 7)
            {
                std::cout << "Exiting game. Goodbye!\n";
                break;
            }
            else
                std::cout << "Invalid choice! Try again.\n";
        }

        for (auto p : pokemonList)
            delete p;
    }
};

#endif
