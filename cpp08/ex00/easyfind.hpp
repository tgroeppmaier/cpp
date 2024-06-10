#include <algorithm> // For std::find
#include <exception>
#include <iterator> // For std::distance

// Define a custom exception for not found cases
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