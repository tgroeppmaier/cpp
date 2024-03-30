#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int getNumber() {
    int num;

    std::cout << "Enter a number between 1 and 100: ";
    std::cin >> num;
    while (std::cin.fail() || num < 1 || num > 100) {  // if entered non numerical character
        std::cin.clear();                               // clear error state 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignoring any additional characters after the invalid input
        std::cout << "Invalid input. Please enter a number between 1 and 100: ";
        std::cin >> num;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return num;
}

std::string getName() {
    std::string hordeName;

    std::cout << "Enter the name of the horde: \n";
    std::getline(std::cin, hordeName);

    if (hordeName.empty()) {
        return "minion";
    }
    return hordeName;
}

int main(void) {
    int num = getNumber();
    std::string name = getName();

    Zombie *horde = zombieHorde(num, name);
    for (int i = 0; i < num; i++) {
        horde[i].announce();
    }

    delete[] horde;

    return 0;
}