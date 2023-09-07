#include <iostream>
#include <map>


int main(){

    std::map<int, std::string> pokedex;

    pokedex.insert(std::pair<int, std::string>(4, "Ivysaur"));
    pokedex.insert(std::pair<int, std::string>(5, "Charizard"));
    pokedex.insert(std::pair<int, std::string>(6, "Squirtle"));
    pokedex.insert(std::pair<int, std::string>(25, "Pikachu"));
    pokedex.insert(std::pair<int, std::string>(39, "Jigglypuff"));

    for (auto pokemon = pokedex.begin(); pokemon != pokedex.end(); pokemon ++) {
        std::cout << pokemon->first << ": " << pokemon->second << std::endl;
    }

    //Question code goes here
}
