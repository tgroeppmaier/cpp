#include "Animal.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;

Animal::Animal(){
    cout << "Default animal Constructor called\n";
}

Animal::Animal(const string& type)
    : m_type(type){
    cout << m_type << "Constructor called\n";
}

Animal::Animal(const Animal& other)
    : Animal(other){
    cout << m_type << "Copy constructor called on\n";
}

Animal::~Animal(){
    cout << m_type << "Deconstructor called\n";
}

