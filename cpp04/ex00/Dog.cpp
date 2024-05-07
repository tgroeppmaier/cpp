#include "Animal.hpp"
#include "Dog.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;

Dog::Dog()
    : Animal("Dog"),
      m_sound("woof") {
    cout << m_type << " default constructor called\n";
}

Dog::Dog(const Dog& other)
    : Animal("Dog"),
      m_sound(other.m_sound) {
    cout << m_type << " copy constructor called\n";
}

Dog::~Dog() {
    cout << m_type << " default deconstructor called\n";
}

Dog& Dog::operator=(const Dog& other){
    if (this != &other){
        Animal::operator=(other);
        m_sound = other.m_sound;
    }
    return *this;
}

void Dog::makeSound() const{
    cout << m_sound << '\n';
}