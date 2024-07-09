#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <number of elements> ..." << std::endl;
        return 1;
    }

   std::vector<int> values;
    char* end;
    for (int i = 1; i < argc; ++i) {
        long number = std::strtol(argv[i], &end, 10);

        if (*end != '\0' || number < 1 || number > std::numeric_limits<int>::max()) {
            std::cout << "Error: Number out of bounds " << argv[i] << std::endl;
            return 1;
        }
        values.push_back(static_cast<int>(number));
    }

    double duration;
    std::cout << "Before: ";
    PmergeMe::printContainer(values);

    clock_t start = clock();
    PmergeMe::FordJohnsonSort(values);
    clock_t stop = clock();

    std::cout << "After: ";
    PmergeMe::printContainer(values);
    duration = (double)(stop - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << values.size() << " elements with std::vector: " 
        << duration << " us\n";

    std::deque<int> lst;
    lst.assign(values.begin(), values.end());

    start = clock();
    PmergeMe::FordJohnsonSort(lst);
    stop = clock();
    duration = (double)(stop - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << values.size() << " elements with std::deque: " 
        << duration << " us\n";
    
    return 0;
}