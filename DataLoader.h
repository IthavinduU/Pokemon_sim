#ifndef DATALOADER_H
#define DATALOADER_H

#include "FirePokemon.h"
#include "WaterPokemon.h"
#include "GrassPokemon.h"
#include <vector>
#include <fstream>
#include <sstream>

class DataLoader
{
public:
    static std::vector<Pokemon *> loadPokemon(const std::string &filename)
    {
        std::vector<Pokemon *> pokemonList;
        std::ifstream file(filename);
        std::string line, name, type, weakness;
        int hp, attack;

        if (!file.is_open())
        {
            std::cerr << "Error: Could not open " << filename << std::endl;
            return pokemonList;
        }

        // Skip CSV header
        std::getline(file, line);

        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            std::getline(ss, name, ',');
            std::getline(ss, type, ',');
            ss >> hp;
            ss.ignore();
            ss >> attack;
            ss.ignore();
            std::getline(ss, weakness, ',');

            if (name.empty() || type.empty())
            {
                std::cout << "⚠ Warning: Skipping invalid row in CSV.\n";
                continue;
            }

            std::cout << "✅ Loading Pokémon: " << name << " (Type: " << type
                      << ", HP: " << hp << ", Attack: " << attack
                      << ", Weakness: " << weakness << ")\n";

            if (type == "Fire")
            {
                pokemonList.push_back(new FirePokemon(name, hp, attack));
            }
            else if (type == "Water")
            {
                pokemonList.push_back(new WaterPokemon(name, hp, attack));
            }
            else if (type == "Grass")
            {
                pokemonList.push_back(new GrassPokemon(name, hp, attack));
            }
            else
            {
                std::cout << "⚠ Warning: Skipping Pokémon with unsupported type: " << type << "\n";
            }
        }

        file.close();
        std::cout << "✅ Total Pokémon Loaded: " << pokemonList.size() << "\n";
        return pokemonList;
    }
};

#endif
