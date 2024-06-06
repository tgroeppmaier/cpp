#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
private:
    T* m_array;
    unsigned int m_len;

public:
    Array() : m_len(0) {
        m_array = new T[m_len];
    }
    Array(unsigned int len) : m_len(len) {
        m_array = new T[m_len];
    }
    Array(const Array& other) : m_len(other.m_len), m_array(new T[other.m_len]) {
        for (unsigned int i = 0; i < m_len; i++) {
            m_array[i] = other.m_array[i];
        }
    }
    ~Array() {
        delete[] m_array;
    }

    // Operator overload

    Array& operator=(const Array& other) {
        if (this != &other) {
            T* tempArray = new T[other.m_len];
            for (unsigned int i = 0; i < other.m_len; i++) {
                tempArray[i] = other.m_array[i];
            }
            delete[] m_array;
            m_array = tempArray;
            m_len = other.m_len;
        }
        return *this;
    }

    T& operator[](unsigned int i) {
        if (i >= m_len) {
            throw std::out_of_range("Index out of range");
        }
        return m_array[i];
    }

    const T& operator[](unsigned int i) const {
        if (i >= m_len) {
            throw std::out_of_range("Index out of range");
        }
        return m_array[i];
    }

    // member function
    unsigned int size() const{
        return m_len;
    }
};

#endif