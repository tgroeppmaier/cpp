#include "PmergeMe.hpp"
#include "limits"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <number of elements> ..." << std::endl;
        return 1;
    }

    std::vector<int> vec;
    char* end;
    for (int i = 1; i < argc; ++i) {
        long number = std::strtol(argv[i], &end, 10);

        if (*end != '\0' || number < 1 || number > std::numeric_limits<int>::max()) {
            std::cout << "Error: Number out of bounds " << argv[i] << std::endl;
            return 1;
        }
        vec.push_back(static_cast<int>(number));
    }

    std::deque<int> deq;
    deq.assign(vec.begin(), vec.end());

    double duration;
    std::cout << "Before: ";
    PmergeMe::printContainer(vec);

    clock_t start = clock();
    PmergeMe::FordJohnsonSort(vec);
    clock_t stop = clock();

    std::cout << "After: ";
    PmergeMe::printContainer(vec);
    duration = (double)(stop - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " 
        << duration << " us\n";

    start = clock();
    PmergeMe::FordJohnsonSort(deq);
    stop = clock();

    duration = (double)(stop - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " 
        << duration << " us\n";
    PmergeMe::checkSort(vec);
    PmergeMe::checkSort(deq);

    return 0;
}