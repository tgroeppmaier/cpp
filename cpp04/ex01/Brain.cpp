#include "Brain.hpp"
#include "iostream"
#include "string"

using std::cout;
using std::string;

Brain::Brain(){
    cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; i++) {
        m_ideas[i] = other.m_ideas[i];
    }
    std::cout << "Brain copy constructor called\n";
}

Brain::~Brain(){
    cout << "Brain default deconstructor called\n";
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            m_ideas[i] = other.m_ideas[i];
        }
    }
    return *this;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        m_ideas[index] = idea;
    }
}

string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return m_ideas[index];
    }
    return "";
}