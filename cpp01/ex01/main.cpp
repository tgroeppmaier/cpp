#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

// `std::cin >> num;` 
// This reads the user's input from the console and stores it in the `num` variable.

// `while (std::cin.fail() || num < 1 || num > 100) { ... }`
// This while loop continues as long as the user's input is invalid. 
// The input is considered invalid if any of the following conditions are true:
//    - `std::cin.fail()`: This condition is true if the previous input operation 
//      failed, such as if the user entered a non-numeric character.
//    - `num < 1 || num > 100`: This condition is true if the user's input is less 
//      than 1 or greater than 100.

// Inside the while loop, the following actions are performed to handle the invalid input:
//    - `std::cin.clear();`: This clears the error state of the `std::cin` 
//      object, allowing input operations to continue.
//    - `std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');`: This 
//      discards the rest of the line of input, up to and including the newline 
//      character (`'\n'`), effectively ignoring any additional characters the user 
//      entered after the invalid input.
//    - `std::cout << "Invalid input. Please enter a number between 1 and 100: ";`: 
//      This line outputs a message to the console, informing the user that their 
//      input was invalid and asking them to enter a number between 1 and 100 again.
//    - `std::cin >> num;`: This line attempts to read the user's input again.

int getNumber() {
    int num;

    std::cout << "Enter a number between 1 and 100: ";
    std::cin >> num;
    while (std::cin.fail() || num < 1 || num > 100) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number between 1 and 100: ";
        std::cin >> num;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Add this line
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