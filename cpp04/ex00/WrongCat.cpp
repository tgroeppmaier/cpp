#include "WrongCat.hpp"
#include <string>
#include <iostream>

using std::cout;

WrongCat::WrongCat()
    : WrongAnimal("WrongCat") {
    cout << m_type << " default constructor called\n";
}

WrongCat::WrongCat(const WrongCat& other)
    : WrongAnimal(other) {
    cout << m_type << " copy constructor called\n";
}

WrongCat::~WrongCat() {
    cout << m_type << " default deconstructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other){
    if (this != &other){
        WrongAnimal::operator=(other);
    }
    return *this;
}

void WrongCat::makeSound() const{
    cout << m_sound << '\n';
}