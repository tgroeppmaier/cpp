#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>

void extra() {
    int values[] = {1, 2, 3, 4, 5, 6};
    MutantStack<int> mstack(values, 6);
    MutantStack<int> copy = mstack;

    mstack.pop();

    MutantStack<int>::const_iterator it = mstack.begin();
    MutantStack<int>::const_iterator ite = mstack.end();

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << std::endl;

    MutantStack<int>::reverse_iterator ri = copy.rbegin();
    MutantStack<int>::reverse_iterator rit = copy.rend();

    while (ri != rit) {
        std::cout << *ri << std::endl;
        ++ri;
    }
    std::cout << std::endl;

    mstack = copy;
    it = mstack.begin();
    ite = mstack.end();
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << std::endl;
}


void subject() {
    MutantStack<int> mstack;


    // Push elements onto the stack
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Stack size after pop: " << mstack.size() << std::endl;

    // Push more elements
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Iterate over the stack
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "Stack elements:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << std::endl;
}

void subject2() {
    std::list<int> mstack;

    mstack.push_back(5);
    mstack.push_back(17);

    std::cout << "Top element: " << mstack.back() << std::endl;

    mstack.pop_back();

    std::cout << "Stack size after pop: " << mstack.size() << std::endl;

    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);

    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "Stack elements:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << std::endl;
}

int main() {
    subject();
    subject2();
    // extra();
    return 0;
}