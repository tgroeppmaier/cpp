#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
using std::string;

class Animal{
    protected:
        string m_type;
    
    public:
        Animal();
        Animal(const string& type);
        Animal(const Animal& other);
        ~Animal();

        Animal operator=(const Animal& other);
        void makeSound();

};


#endif