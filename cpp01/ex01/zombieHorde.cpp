#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie* aHorde = new Zombie[N];
    for (int i = 0; i < N; i++)
        aHorde[i].setName(name);
    return (aHorde);
}