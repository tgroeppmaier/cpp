#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer&) = delete;
        Serializer& operator=(const Serializer&) = delete;

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif