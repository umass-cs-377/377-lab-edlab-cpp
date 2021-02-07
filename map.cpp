#include <iostream>
#include <map>

using namespace std;

int main(){

    map<int, string> pokedex;

    pokedex.insert(pair<int, string>(2, "Ivysaur"));
    pokedex.insert(pair<int, string>(5, "Charizard"));
    pokedex.insert(pair<int, string>(6, "Squirtle"));
    pokedex.insert(pair<int, string>(25, "Pikachu"));
    pokedex.insert(pair<int, string>(39, "Jigglypuff"));

    for (auto pokemon = pokedex.begin(); pokemon != pokedex.end(); pokemon ++) {
        cout << pokemon->first << ": " << pokemon->second << endl;
    }

    //Question code goes here
}
