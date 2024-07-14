#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <deque>

using std::vector;
using std::list;
using std::string;

class PmergeMe {
private:
    template<typename Iterator>
    static Iterator findInsertPosition(Iterator first, Iterator last, 
                                       const int& value) {
        while (first != last) {
            // Calculate the middle iterator
            Iterator mid = first;
            std::advance(mid, std::distance(first, last) / 2);
            
            // If the middle element is less than the value, search in the right half
            if (*mid < value) {
                first = mid;
                ++first; // Move past mid
            } 
            // Otherwise, search in the left half
            else {
                last = mid;
            }
        }
        // Return the position where the value should be inserted
        return first;
    }

public:
template<typename Container>
static void FordJohnsonSort(Container& cont) {
    if (cont.size() <= 1) return;

    // Create main chain and pend chain
    Container mainChain;
    std::vector<int> pendChain;

    // Handle odd-sized container
    bool hasOdd = false;
    int odd;
    if (cont.size() % 2 != 0) {
        typename Container::iterator lastIt = cont.end();
        --lastIt;
        odd = *lastIt;
        cont.erase(lastIt);
        hasOdd = true;
    }

    // Create pairs
    typedef std::pair<int, int> ValuePair;
    std::vector<ValuePair> pairs;
    typename Container::iterator it = cont.begin();
    while (it != cont.end()) {
        int first = *it;
        ++it;
        int second = *it;
        ++it;
        if (first > second) {
            pairs.push_back(std::make_pair(first, second));
        } else {
            pairs.push_back(std::make_pair(second, first));
        }
    }

    // Sort the sequences of pairs by the first value
    std::sort(pairs.begin(), pairs.end());

    // Push the first element of each pair into mainChain, and the second into pendChain
    for (typename std::vector<ValuePair>::const_iterator pairIt = pairs.begin(); pairIt != pairs.end(); ++pairIt) {
        mainChain.push_back(pairIt->first);
        pendChain.push_back(pairIt->second);
    }

    // Merge pend elements into main chain
    for (size_t i = 0; i < pendChain.size(); ++i) {
        typename Container::iterator pairPosition = mainChain.begin();
        std::advance(pairPosition, i * 2 + 1);  // Position right after the higher number in the pair
        typename Container::iterator insertPos = findInsertPosition(mainChain.begin(), pairPosition, pendChain[i]);
        mainChain.insert(insertPos, pendChain[i]);
    }

    // Insert the odd element if it exists
    if (hasOdd) {
        mainChain.insert(findInsertPosition(mainChain.begin(), mainChain.end(), odd), odd);
    }

    // Swap mainChain with cont
    cont.swap(mainChain);
}

    template<typename Container>
    static void printContainer(const Container& cont) {
        typename Container::const_iterator it;
        for (it = cont.begin(); it != cont.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    template<typename Container>
    static void checkSort(const Container& cont) {
        typename Container::const_iterator it = cont.begin();
        typename Container::const_iterator next = it;
        ++next;

        for (; next != cont.end(); ++it, ++next) { 
            if (*it > *next) {
                std::cout << "Error, not sorted correctly\n";
                return;
            }
        }
        std::cout << "Sorted correctly\n";
    }

};

/* 

1. Pairs are sorted internally: Each pair is sorted so that the higher number comes first.
2. Sort pairs based on the higher number: The pairs are sorted based on the higher number.
3. Create the main chain with higher numbers: Extract the higher numbers from each pair to form the main chain.
4. Create the pend chain with lower numbers: Extract the lower numbers from each pair to form the pend chain.
5. Merge the pend chain into the main chain: Insert elements from the pend chain into the main chain at the correct positions.
6. Handle the odd element if it exists: If there is an odd element, insert it into the correct position in the main chain.

example: command line given: "5 10 1 0 22 3" 

create pairs:           
(5, 10), (1, 0), (22, 3)
sort pairs internally:  
(10, 5), (1, 0), (22, 3)
sort pairs based on higher number:
(1, 0), (10, 5), (22, 3)
create main chain with higher numbers:
1, 10, 22
create pend chain with lower numbers:
0, 5, 3
merge from pend into main range is from beginning up to the number it was initially paired with
0, 1, 10, 22
0, 1, 5, 10, 22
0, 1, 3, 5, 10, 22


*/

#endif