#ifndef ARRAY_HPP
#define ARRAY_HPP

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
        Array(const Array& other)
        ~Array() {
            delete[] array;
        }
};

#endif