#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
    : m_type("WrongAnimal"), m_sound("mooooo"){
    std::cout << "Default WrongAnimal Constructor called\n";
}   

WrongAnimal::WrongAnimal(const std::string& type)
    : m_type(type), m_sound("mooooo"){
    std::cout << "WrongAnimal Constructor called for " << m_type << '\n';
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
    : m_type(other.m_type), m_sound(other.m_sound){
    std::cout << m_type << " Copy constructor called\n";
}

WrongAnimal::~WrongAnimal(){
    std::cout << m_type << " Deconstructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
    if(this != &other){
        m_type = other.m_type;
        m_sound = other.m_sound;
    }
    return *this;
}

void WrongAnimal::makeSound() const{
    std::cout << m_sound << '\n';
}

const std::string& WrongAnimal::getType() const{
    return(m_type);
}