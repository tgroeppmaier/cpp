#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
private:
    int m_len;
    T* m_array;

public:
    Array() : m_len(0) {
        m_array = new T[m_len];
    }

    Array(int len) : m_len(len), m_array(NULL) {
        if (m_len < 0) {
            throw std::invalid_argument("Length must be non-negative");
        }
        m_array = new T[m_len];
    }

    Array(const Array& other) : m_len(other.m_len), m_array(new T[other.m_len]) {
        for (int i = 0; i < m_len; i++) {
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
            for (int i = 0; i < other.m_len; i++) {
                tempArray[i] = other.m_array[i];
            }
            delete[] m_array;
            m_array = tempArray;
            m_len = other.m_len;
        }
        return *this;
    }

    T& operator[](int i) {
        if (i < 0 || i >= m_len) {
            throw std::out_of_range("Index out of range");
        }
        return m_array[i];
    }

    const T& operator[](int i) const {
        if (i < 0 || i >= m_len) {
            throw std::out_of_range("Index out of range");
        }
        return m_array[i];
    }

    // member function
    int size() const{
        return m_len;
    }
};

#endif