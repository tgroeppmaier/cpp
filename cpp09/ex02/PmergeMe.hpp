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
    template<typename RandomAccessIterator>
    static RandomAccessIterator findInsertPosition(RandomAccessIterator first, RandomAccessIterator last, const typename std::iterator_traits<RandomAccessIterator>::value_type& value) {
    }

public:
    template<typename RandomAccessContainer>
    static void FordJohnsonSort(RandomAccessContainer& cont) {
        if (cont.size() <= 1) 
            return;

        bool hasOdd = false;
        typename RandomAccessContainer::value_type odd;
        if (cont.size() % 2 != 0) {
            odd = cont.back();
            cont.pop_back();
            hasOdd = true;
        }

        typedef std::pair<typename RandomAccessContainer::value_type, typename RandomAccessContainer::value_type> ValuePair;
        std::vector<ValuePair> pairs;
        for (typename RandomAccessContainer::iterator it = cont.begin(); it != cont.end(); std::advance(it, 2)) {
            typename RandomAccessContainer::value_type first = *it;
            typename RandomAccessContainer::value_type second = *(++it);
            if (first > second) {
                pairs.push_back(ValuePair(first, second));
            } else {
                pairs.push_back(ValuePair(second, first));
            }
        }

        std::sort(pairs.begin(), pairs.end());

        RandomAccessContainer result, pendChain;
        for (typename std::vector<ValuePair>::const_iterator pairIt = pairs.begin(); pairIt != pairs.end(); ++pairIt) {
            result.push_back(pairIt->first);
            pendChain.push_back(pairIt->second);
        }

        typename RandomAccessContainer::iterator resultIt = result.begin();
        for (typename RandomAccessContainer::iterator pendIt = pendChain.begin(); pendIt != pendChain.end(); ++pendIt) {
            // Find the insert position using binary search within the limited range
            typename RandomAccessContainer::iterator insertPos = findInsertPosition(result.begin(), resultIt, *pendIt);
            result.insert(insertPos, *pendIt);
            // Ensure the next search starts from the next position to maintain the original pairing limit
            if (resultIt != result.end()) {
                ++resultIt;
            }
        }

        if (hasOdd) {
            typename RandomAccessContainer::iterator insertPos = findInsertPosition(result.begin(), result.end(), odd);
            result.insert(insertPos, odd);
        }

        cont.swap(result); // Efficiently replace cont's contents with result
    }
};

#endif