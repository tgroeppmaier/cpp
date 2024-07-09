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
        static Iterator findInsertPosition(Iterator first, Iterator last, const typename std::iterator_traits<Iterator>::value_type& value) {
            while (first != last && *first < value) {
                ++first;
            }
            return first;
        }

    public:
        template<typename Container>
        static void FordJohnsonSort(Container& cont) {
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
            // Sort the pair internally. Higher number is first
            if (first > second) {
                pairs.push_back(std::make_pair(first, second));
            }
            else 
                pairs.push_back(std::make_pair(second, first));
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

        // Merge pend elements into main chain
        typename Container::iterator pendIt = pendChain.begin();
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
    static void printContainer(const Container& cont) {
        typename Container::const_iterator it;
        for (it = cont.begin(); it != cont.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl << std::endl;
    }
};




#endif