#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;

Cat::Cat()
    : Animal("Cat"),
      m_sound("meow"),
      m_brain(new Brain()) {
    cout << m_type << " default constructor called, Brain created\n";
}

Cat::Cat(const Cat& other)
    : Animal("Cat"),
      m_sound(other.m_sound),
      m_brain(new Brain(*other.m_brain)) {
    cout << m_type << " copy constructor called, Brain copied\n";
}

Cat::~Cat() {
    delete m_brain;
    cout << m_type << " default deconstructor called, Brain deleted\n";
}

Cat& Cat::operator=(const Cat& other){
    if (this != &other){
        Animal::operator=(other);
        m_sound = other.m_sound;
        delete m_brain;
        m_brain = new Brain(*other.m_brain);
    }
    return *this;
}

void Cat::makeSound() const{
    cout << m_sound << '\n';
}

void Cat::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        m_brain->setIdea(index, idea);
    }
}

string Cat::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return m_brain->getIdea(index);
    }
    return "";
}