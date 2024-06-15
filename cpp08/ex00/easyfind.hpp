#include <algorithm>
#include <exception>
#include <iterator>

class NotFoundException : public std::exception {
public:
    const char* what() const throw() {
        return "Element not found in the container";
    }
};

template<typename T>
int easyfind(const T& container, int value) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw NotFoundException();
    }
    return std::distance(container.begin(), it);
}