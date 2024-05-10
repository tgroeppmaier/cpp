#include "Animal.hpp"
#include "Dog.hpp"
// #include "Brain.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;

Dog::Dog()
    : Animal("Dog"),
      m_sound("woof"),
      m_brain(new Brain()) {
    cout << m_type << " default constructor called, Brain created\n";
}

Dog::Dog(const Dog& other)
    : Animal("Dog"),
      m_sound(other.m_sound),
      m_brain(new Brain(*other.m_brain)) {
      cout << m_type << " copy constructor called, Brain copied\n";
}

Dog::~Dog() {
    delete m_brain;
    cout << m_type << " default deconstructor called, Brain deleted\n";
}

Dog& Dog::operator=(const Dog& other){
    if (this != &other){
        Animal::operator=(other);
        m_sound = other.m_sound;
        delete m_brain;
        m_brain = new Brain(*other.m_brain);
    }
    return *this;
}

void Dog::makeSound() const{
    cout << m_sound << '\n';
}

void Dog::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        m_brain->setIdea(index, idea);
    }
}

string Dog::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return m_brain->getIdea(index);
    }
    return "";
}