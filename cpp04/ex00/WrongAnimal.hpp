#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
protected:
    std::string m_type;
    std::string m_sound;

public:
    WrongAnimal();
    WrongAnimal(const std::string& type);
    WrongAnimal(const WrongAnimal& other);
    virtual ~WrongAnimal();

    WrongAnimal& operator=(const WrongAnimal& other);
    void makeSound() const;
    const std::string& getType() const;
};

#endif