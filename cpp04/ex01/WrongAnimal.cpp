#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
    : m_type("WrongAnimal"){
    std::cout << "Default WrongAnimal Constructor called\n";
}   

WrongAnimal::WrongAnimal(const std::string& type)
    : m_type(type){
    std::cout << "WrongAnimal Constructor called for " << m_type << '\n';
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
    : m_type(other.m_type){
    std::cout << m_type << " Copy constructor called\n";
}

WrongAnimal::~WrongAnimal(){
    std::cout << m_type << " Deconstructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
    if(this != &other){
        m_type = other.m_type;
    }
    return *this;
}

void WrongAnimal::makeSound() const{
}

const std::string& WrongAnimal::getType() const{
    return(m_type);
}