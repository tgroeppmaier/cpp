#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>


void subject(){
    // Animal test;
}

void extra(){
    Dog originalDog;
    originalDog.setIdea(0, "sniffing");
    Dog copyDog = originalDog;
    originalDog.setIdea(0, "barking");
    originalDog.makeSound();
    copyDog.makeSound();
    std::cout << copyDog.getIdea(0) << '\n';
    std::cout << originalDog.getIdea(0) << '\n';
    std::cout << copyDog.getIdea(0).size() << '\n';
}

int main(){
    subject();
    extra();

    return 0;
}

