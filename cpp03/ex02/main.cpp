#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){
    // ClapTrap one("one");
    // ClapTrap two("two");
    // ClapTrap no_hp("0_hp", 0, 10, 10);
    // ClapTrap no_ep("0_ep", 10, 0, 10);

    // ClapTrap arr[2] = {ClapTrap("first"), ClapTrap("second")};
    // ClapTrap clone = arr[0];
    // ClapTrap boss("Boss", 100, 100, 10);
    // boss.attack("Player");
    // boss.takeDamage(100);
    // boss.beRepaired(20);
    // boss.printValues();
    // no_ep.attack("target");
    // no_hp.attack("target");

    // ScavTrap first("Scavy");
    // // first.printValues();
    // first.attack("target");
    // first.guardGate();
    // first.guardGate();

    FragTrap FragT("Fragy");
    FragT.attack("target");
    FragT.highFivesGuys();
}

