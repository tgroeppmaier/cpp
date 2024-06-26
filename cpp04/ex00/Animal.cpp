#include "Animal.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;

Animal::Animal()
    : m_type("Animal"){
    cout << "Default animal Constructor called\n";
}   

Animal::Animal(const string& type)
    : m_type(type){
    cout << "Animal Constructor called for " << m_type << '\n';
}

Animal::Animal(const Animal& other)
    : m_type(other.m_type){
    cout << "Animal copy constructor called\n";
}

Animal::~Animal(){
    cout << "Animal deconstructor called\n";
}

Animal& Animal::operator=(const Animal& other){
    if(this != &other){
        m_type = other.m_type;
    }
    return *this;
}

void Animal::makeSound() const{
}

const string& Animal::getType() const{
    return(m_type);
}

