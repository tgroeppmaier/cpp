#include "PmergeMe.hpp"

int main() {
    std::vector<int> vec;
    int values[] = {55, 6, 3, 1, -7, 0, 2, 4545, -4545};
    for (size_t i = 0; i < sizeof(values) / sizeof(values[0]); ++i) {
        vec.push_back(values[i]);
    }

    PmergeMe::sort_vector(vec);

    return 0;
}