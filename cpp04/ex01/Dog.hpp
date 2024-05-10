#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal{
    private:
        std::string m_sound;
        Brain* m_brain;

    public:
        Dog();
        Dog(const Dog& other);
        ~Dog();

        Dog& operator=(const Dog& other);
        void makeSound() const;

        void setIdea(int index, const std::string& idea);
        std::string getIdea(int index) const;

};


#endif