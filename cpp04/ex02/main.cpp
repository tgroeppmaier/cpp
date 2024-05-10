#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>


void subject(){
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
}

void extra(){
    Dog originalDog;
    originalDog.setIdea(0, "sniffing");
    Dog copyDog = originalDog;
    originalDog.setIdea(0, "pooping");
    originalDog.makeSound();
    copyDog.makeSound();
    std::cout << copyDog.getIdea(0) << '\n';
}

int main(){
    // subject();
    // extra();
    const int size = 8;
    Animal* array[size];
    
    for(int i = 0; i < size/2; i++){
        array[i] = new Dog();
    }
    for(int i = size/2; i < size; i++){
        array[i] = new Cat();
    }
    for(int i = 0; i < size; i++){
        delete array[i];
    }
    return 0;
}

