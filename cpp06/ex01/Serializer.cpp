#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
    if (!ptr) {
        return 0;
    }
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    if (raw == 0) {
        return NULL;
    }
    return reinterpret_cast<Data*>(raw);
}