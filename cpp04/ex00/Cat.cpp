#include "Animal.hpp"
#include "Cat.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;

Cat::Cat()
    : Animal("Cat"),
      m_sound("meow") {
    cout << m_type << " default constructor called\n";
}

Cat::Cat(const Cat& other)
    : Animal("Cat"),
      m_sound(other.m_sound) {
    cout << m_type << " copy constructor called\n";
}

Cat::~Cat() {
    cout << m_type << " default deconstructor called\n";
}

Cat& Cat::operator=(const Cat& other){
    if (this != &other){
        Animal::operator=(other);
        m_sound = other.m_sound;
    }
    return *this;
}

void Cat::makeSound() const{
    cout << m_sound << '\n';
}