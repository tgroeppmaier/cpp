#include <ctime> // Include the ctime header for timing
#include <cstdlib> // For std::strtoll
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <sstream>
#include <limits>

using std::vector;
using std::list;
using std::string;
using std::cout;
using std::endl;

const int JACOBSTHAL_SIZE = 30;
int jacobsthal[JACOBSTHAL_SIZE] = {0, 1};

void initJacobsthal() {
    for (int i = 2; i < JACOBSTHAL_SIZE; ++i) {
        jacobsthal[i] = jacobsthal[i-1] + 2 * jacobsthal[i-2];
    }
}

template<typename Iterator>
Iterator findInsertPosition(Iterator begin, Iterator end, const typename std::iterator_traits<Iterator>::value_type& value) {
    return std::lower_bound(begin, end, value);
}

template<typename Container>
void fordJohnsonSort(Container& cont) {
    if (cont.size() <= 1) return;

    Container mainChain;
    Container pendChain;
    
    // Step 1: Pair elements and create main and pend chains
    while (cont.size() >= 2) {
        typename Container::value_type first = cont.front();
        cont.erase(cont.begin());
        typename Container::value_type second = cont.front();
        cont.erase(cont.begin());
        
        if (first < second) {
            mainChain.push_back(second);
            pendChain.push_back(first);
        } else {
            mainChain.push_back(first);
            pendChain.push_back(second);
        }
    }

    // Handle odd-sized container
    typename Container::value_type odd;
    bool hasOdd = false;
    if (!cont.empty()) {
        odd = cont.front();
        cont.erase(cont.begin());
        hasOdd = true;
    }

    // Step 2: Recursively sort main chain
    if (mainChain.size() > 1) {
        fordJohnsonSort(mainChain);
    }

    // Step 3: Merge pend elements into main chain
    Container result = mainChain;
    int jacobsthalIndex = 3;
    typename Container::iterator pendIt = pendChain.begin();

    // Insert first two elements of pend chain
    if (!pendChain.empty()) {
        result.insert(findInsertPosition(result.begin(), result.end(), *pendIt), *pendIt);
        ++pendIt;
        if (pendIt != pendChain.end()) {
            result.insert(findInsertPosition(result.begin(), result.end(), *pendIt), *pendIt);
            ++pendIt;
        }
    }

    // Insert remaining elements using Jacobsthal numbers
    while (pendIt != pendChain.end() && jacobsthalIndex < JACOBSTHAL_SIZE) {
        int nextJacobsthal = jacobsthal[jacobsthalIndex];
        while (nextJacobsthal - 1 < static_cast<int>(pendChain.size()) && 
               std::distance(pendChain.begin(), pendIt) < nextJacobsthal - 1) {
            result.insert(findInsertPosition(result.begin(), result.end(), *pendIt), *pendIt);
            ++pendIt;
            if (pendIt == pendChain.end()) break;
        }
        if (pendIt == pendChain.end()) break;
        ++jacobsthalIndex;
    }

    // Insert any remaining elements
    while (pendIt != pendChain.end()) {
        result.insert(findInsertPosition(result.begin(), result.end(), *pendIt), *pendIt);
        ++pendIt;
    }

    // Insert the odd element if it exists
    if (hasOdd) {
        result.insert(findInsertPosition(result.begin(), result.end(), odd), odd);
    }

    cont = result;
}

template<typename Container>
void printContainer(const Container& cont) {
    typename Container::const_iterator it;
    for (it = cont.begin(); it != cont.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <number of elements> ..." << std::endl;
        return 1;
    }
    initJacobsthal();

    std::vector<int> values;
    char* end;
    for (int i = 1; i < argc; ++i) {
        long long number = std::strtoll(argv[i], &end, 10); // Convert argument to long long

        // Check if the conversion was successful and the number is within int range
        if (*end != '\0' || number < 1 || number > std::numeric_limits<int>::max()) {
            std::cout << "Error: Number out of bounds " << argv[i] << std::endl;
            return 1;
        }
        values.push_back(static_cast<int>(number)); // Safe to cast here due to the bounds check
    }

    double duration;
    cout << "Before: ";
    printContainer(values);

    clock_t start = clock(); // Start timing
    fordJohnsonSort(values);
    clock_t stop = clock(); // Stop timing

    cout << "After: ";
    printContainer(values);
    duration = (double)(stop - start) / CLOCKS_PER_SEC * 1000000; // Calculate duration in microseconds
    cout << "Time to process a range of " << values.size() << " elements with std::vector: " 
        << duration << " us\n";

    list<int> lst;
    lst.assign(values.begin(), values.end());

    start = clock(); // Start timing
    fordJohnsonSort(lst);
    stop = clock(); // Stop timing
    duration = (double)(stop - start) / CLOCKS_PER_SEC * 1000000; // Calculate duration in microseconds
    cout << "Time to process a range of " << values.size() << " elements with std::list: " 
        << duration << " us\n";
    
    return 0;
}