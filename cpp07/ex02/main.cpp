#include <iostream>
#include <cstdlib>
#include "Array.hpp"

    struct Mystruct {
        int value;
    };

#define MAX_VAL 750
int main(int, char**)
{   
    // test complex data type
    Array<Mystruct> struct_array(10);
    for (int i = 0; i < 10; i++) {
        struct_array[i].value = i;
        std::cout << struct_array[i].value << std::endl;
    }

    Array<int> numbers(MAX_VAL);

    // test size function
    std::cout << "size = " << numbers.size() << std::endl;

    Array<int> nothing(0);
    int* mirror = new int[MAX_VAL];
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    //SCOPE
    {
        // test copy assignment and deep copy
        Array<int> tmp = numbers;
        tmp[0] = 777;
        std::cout << "numbers[0] = " << numbers[0] << std::endl;
        std::cout << "tmp[0] = " << tmp[0] << std::endl;

        // test copy constructor and deep copy
        Array<int> test(tmp);
        tmp[0] = 666;
        std::cout << "test[0] = " << test[0] << std::endl;
        std::cout << "tmp[0] = " << tmp[0] << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }


    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

    delete [] mirror;//
    return 0;
}