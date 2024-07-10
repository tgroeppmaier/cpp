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
#include <limits>

using std::vector;
using std::list;
using std::string;

class PmergeMe {
private:
    template<typename Iterator>
    static Iterator binarySearch(Iterator first, Iterator last, int value) {
        while (first < last) {
            Iterator mid = first + (last - first) / 2;
            if (*mid < value) {
                first = mid + 1;
            } else {
                last = mid;
            }
        }
        return first;
    }

public:
    template<typename Container>
    static void FordJohnsonSort(Container& cont) {
        if (cont.size() <= 1) 
            return;

        typedef std::pair<int, int> ValuePair;

        // Handle odd-sized container
        bool hasOdd = false;
        int odd;
        if (cont.size() % 2 != 0) {
            odd = cont.back();
            cont.pop_back();
            hasOdd = true;
        }

        // Create pairs
        std::vector<ValuePair> pairs;
        typename Container::iterator it = cont.begin();
        while (it != cont.end()) {
            int first = *it++;
            if (it == cont.end()) break;
            int second = *it++;
            if (first > second) {
                pairs.push_back(ValuePair(first, second));
            } else {
                pairs.push_back(ValuePair(second, first));
            }
        }

        // Sort the sequences of pairs by the first value
        std::sort(pairs.begin(), pairs.end());

        // Clear the original container
        cont.clear();

        // Push the first element of each pair into cont
        for (typename std::vector<ValuePair>::const_iterator pairIt = pairs.begin(); pairIt != pairs.end(); ++pairIt) {
            cont.push_back(pairIt->first);
        }

        // Merge pend elements into main chain
        for (size_t i = 0; i < pairs.size(); ++i) {
            typename Container::iterator searchEnd = cont.begin() + i + 1;
            typename Container::iterator insertPos = binarySearch(cont.begin(), searchEnd, pairs[i].second);
            cont.insert(insertPos, pairs[i].second);
        }

        // Insert the odd element if it exists
        if (hasOdd) {
            typename Container::iterator insertPos = binarySearch(cont.begin(), cont.end(), odd);
            cont.insert(insertPos, odd);
        }
    }

    template<typename Container>
    static void printContainer(const Container& cont) {
        for (typename Container::const_iterator it = cont.begin(); it != cont.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
};

#endif