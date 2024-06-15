#include <deque>
#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T, std::deque<T> > {
public:
    typedef typename std::deque<T>::iterator iterator;
    typedef typename std::deque<T>::const_iterator const_iterator;
    typedef typename std::deque<T>::reverse_iterator reverse_iterator;
    typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

    MutantStack() : std::stack<T, std::deque<T> >() {}
    
    MutantStack(const MutantStack& other) : std::stack<T, std::deque<T> >(other) {}

    MutantStack(const int* values, size_t count) {
        for (size_t i = 0; i < count; i++) {
            this->push(values[i]);
        }
    }
    
    ~MutantStack() {}

    MutantStack& operator=(const MutantStack<T>& other) {
        if (this != &other) {
            this->c = other.c;
        }
        return *this;
    }

    iterator begin() {
        return this->c.begin();
    }

    const_iterator begin() const {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }

    const_iterator end() const {
        return this->c.end();
    }

    reverse_iterator rbegin() {
        return this->c.rbegin();
    }

    const_reverse_iterator rbegin() const {
        return this->c.rbegin();
    }

    reverse_iterator rend() {
        return this->c.rend();
    }

    const_reverse_iterator rend() const {
        return this->c.rend();
    }
};