#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
    switch (rand() % 3) {
        case 0: return new A;
        case 1: return new B;
        case 2: return new C;
    }
    return NULL;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A\n";
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B\n";
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C\n";
    }
}

void identify(Base& p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "A\n";
    } 
    catch (...) {}

    try {
        dynamic_cast<B&>(p);
        std::cout << "B\n";
    } 
    catch (...) {}

    try {
        dynamic_cast<C&>(p);
        std::cout << "C\n";
    } 
    catch (...) {}
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    Base* base = generate();
    identify(base);
    identify(*base);
    delete base;
    return 0;
}