#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

using std::cout;

int main() {
    Data d;
    d.num = 777;
    d.text = "bla";
    Data* ptr = &d;
    Data* tmp;
    uintptr_t ptr_t;

    ptr_t = Serializer::serialize(ptr);
    tmp = Serializer::deserialize(ptr_t);
    if (tmp == ptr) {
        cout << "Operation successfull" << std::endl;
        cout << "num: " << tmp->num << std::endl;
        cout << "text: " << tmp->text << std::endl;
    }
    else {
        std::cerr << "Operation failed" << std::endl;
        return 1;
    }
    return 0;
}