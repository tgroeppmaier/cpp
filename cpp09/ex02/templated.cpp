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

// The std::lower_bound function in C++ is used to find the first position in a sorted range where a given value can be inserted without violating the order of the range. It performs a binary search with a complexity of O(log n), where n is the distance between begin and end.

template<typename Iterator>
Iterator findInsertPosition(Iterator begin, Iterator end, const typename std::iterator_traits<Iterator>::value_type& value) {
    return std::lower_bound(begin, end, value);
}

template<typename Container>
void fordJohnsonSort(Container& cont) {
    if (cont.size() <= 1) 
        return;

    // Handle odd-sized container
    bool hasOdd = false;
    typename Container::value_type odd;
    if (cont.size() % 2 != 0) {
        odd = cont.back();
        cont.pop_back();
        hasOdd = true;
    }

    // Create pairs
    typedef std::pair<typename Container::value_type, typename Container::value_type> ValuePair;
    std::vector<ValuePair> pairs;
    for (typename Container::iterator it = cont.begin(); it != cont.end(); ++it) {
        typename Container::value_type first = *it;
        ++it;
        typename Container::value_type second = *it;
        // Sort the pair internally
        if (second > first) {
            pairs.push_back(std::make_pair(second, first));
        }
        else 
            pairs.push_back(std::make_pair(first, second));
    }

    // Sort the sequences of pairs by the first value
    std::sort(pairs.begin(), pairs.end());


    // Push the second number and then first number of the first pair into result 
    Container result, pendChain;
    if (!pairs.empty()) {
        result.push_back(pairs.front().second);
        result.push_back(pairs.front().first);
    }
    
    // Start from the second pair
    for (typename std::vector<ValuePair>::iterator it = pairs.begin() + 1; it != pairs.end(); ++it) {
        result.push_back(it->first);
        pendChain.push_back(it->second);
    }


    // Step 3: Merge pend elements into main chain
    // Container result = mainChain;
 // Step 3: Merge pend elements into main chain
int jacobsthalIndex = 3;
typename Container::iterator pendIt = pendChain.begin();

// Insert the first element from pend chain
if (pendIt != pendChain.end()) {
    result.insert(findInsertPosition(result.begin(), result.end(), *pendIt), *pendIt);
    ++pendIt;
}

// Insert the second element from pend chain
if (pendIt != pendChain.end()) {
    result.insert(findInsertPosition(result.begin(), result.end(), *pendIt), *pendIt);
    ++pendIt;
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
    std::cout << std::endl << std::endl;
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