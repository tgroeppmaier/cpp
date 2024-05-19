#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>


void subject(){
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete j;
    delete i;
    delete meta;
}

void wrong(){
    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* i = new WrongCat();
    WrongCat wcat;
    // std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output sound of Animal
    wcat.makeSound(); //will output sound of Animal
    meta->makeSound(); //will output sound of Animal
    delete i;
    delete meta;
}

void extra(){
    Animal* Ani = new Dog();
    Ani->makeSound();
    delete Ani;
}

int main(){
    subject();
    // wrong();
    extra();


    return 0;
}

