#include <ctime>
#include <cstdlib>
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
Iterator findInsertPosition(Iterator hint, Iterator end, const typename std::iterator_traits<Iterator>::value_type& value) {
    return std::lower_bound(hint, end, value);
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
    typename Container::iterator it = cont.begin();
    while (it != cont.end()) {
        typename Container::value_type first = *it;
        ++it;
        typename Container::value_type second = *it;
        ++it;
        // Sort the pair internally
        if (second < first) {
            pairs.push_back(std::make_pair(second, first));
        }
        else 
            pairs.push_back(std::make_pair(first, second));
    }

    // Sort the sequences of pairs by the first value
    std::sort(pairs.begin(), pairs.end());

    // Initialize result and pendChain
    Container result, pendChain;
    
    // Push the first element of each pair into result, and the second into pendChain
    for (typename std::vector<ValuePair>::const_iterator pairIt = pairs.begin(); pairIt != pairs.end(); ++pairIt) {
        result.push_back(pairIt->first);
        pendChain.push_back(pairIt->second);
    }

    // Step 3: Merge pend elements into main chain
    int jacobsthalIndex = 3;
    typename Container::iterator pendIt = pendChain.begin();
    typename Container::iterator insertionPoint = result.begin();

    // Insert the first element from pend chain
    if (pendIt != pendChain.end()) {
        insertionPoint = result.insert(findInsertPosition(result.begin(), result.end(), *pendIt), *pendIt);
        ++pendIt;
    }

    // Insert remaining elements using Jacobsthal numbers
    while (pendIt != pendChain.end() && jacobsthalIndex < JACOBSTHAL_SIZE) {
        int nextJacobsthal = jacobsthal[jacobsthalIndex];
        while (nextJacobsthal - 1 < static_cast<int>(pendChain.size()) && 
               std::distance(pendChain.begin(), pendIt) < nextJacobsthal - 1) {
            insertionPoint = result.insert(findInsertPosition(result.begin(), result.end(), *pendIt), *pendIt);
            ++pendIt;
            if (pendIt == pendChain.end()) break;
        }
        if (pendIt == pendChain.end()) break;
        ++jacobsthalIndex;
    }

    // Insert any remaining elements
    while (pendIt != pendChain.end()) {
        insertionPoint = result.insert(findInsertPosition(result.begin(), result.end(), *pendIt), *pendIt);
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
        long number = std::strtol(argv[i], &end, 10);

        if (*end != '\0' || number < 1 || number > std::numeric_limits<int>::max()) {
            std::cout << "Error: Number out of bounds " << argv[i] << std::endl;
            return 1;
        }
        values.push_back(static_cast<int>(number));
    }

    double duration;
    cout << "Before: ";
    printContainer(values);

    clock_t start = clock();
    fordJohnsonSort(values);
    clock_t stop = clock();

    cout << "After: ";
    printContainer(values);
    duration = (double)(stop - start) / CLOCKS_PER_SEC * 1000000;
    cout << "Time to process a range of " << values.size() << " elements with std::vector: " 
        << duration << " us\n";

    list<int> lst;
    lst.assign(values.begin(), values.end());

    start = clock();
    fordJohnsonSort(lst);
    stop = clock();
    duration = (double)(stop - start) / CLOCKS_PER_SEC * 1000000;
    cout << "Time to process a range of " << values.size() << " elements with std::list: " 
        << duration << " us\n";
    
    return 0;
}