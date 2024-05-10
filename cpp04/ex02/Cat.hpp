#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        std::string m_sound;
        Brain* m_brain;

    public:
        Cat();
        Cat(const Cat& other);
        ~Cat();

        Cat& operator=(const Cat& other);
        void makeSound() const;

        void setIdea(int index, const std::string& idea);
        std::string getIdea(int index) const;
};

#endif