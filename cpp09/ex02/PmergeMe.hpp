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
            Iterator mid = first;
            std::advance(mid, std::distance(first, last) / 2);
            if (*mid < value) {
                first = mid;
                ++first;
            } 
            else {
                last = mid;
            }
        }
        return first;
    }

public:
    template<typename Container>
    static void FordJohnsonSort(Container& cont) {
        if (cont.size() <= 1) return;

        std::vector<int> tempCont(cont.begin(), cont.end());
        cont.clear();

        // Handle odd-sized container
        bool hasOdd = false;
        int odd;
        if (tempCont.size() % 2 != 0) {
            odd = tempCont.back();
            tempCont.pop_back();
            hasOdd = true;
        }

        // Create pairs
        typedef std::pair<int, int> ValuePair;
        std::vector<ValuePair> pairs;
        for (size_t i = 0; i < tempCont.size(); i += 2) {
            int first = tempCont[i];
            int second = tempCont[i + 1];
            if (first > second) {
                pairs.push_back(std::make_pair(first, second));
            } else {
                pairs.push_back(std::make_pair(second, first));
            }
        }

        // Sort the sequences of pairs by the first value
        std::sort(pairs.begin(), pairs.end());

        // Initialize pendChain
        std::vector<int> pendChain;

        // Push the first element of each pair into cont, and the second into pendChain
        for (typename std::vector<ValuePair>::const_iterator pairIt = pairs.begin(); pairIt != pairs.end(); ++pairIt) {
            cont.push_back(pairIt->first);
            pendChain.push_back(pairIt->second);
        }

        // Merge pend elements into main chain
        for (size_t i = 0; i < pendChain.size(); ++i) {
            typename Container::iterator pairPosition = cont.begin();
            std::advance(pairPosition, i * 2 + 1);  // Position right after the higher number in the pair
            typename Container::iterator insertPos = findInsertPosition(cont.begin(), pairPosition, pendChain[i]);
            cont.insert(insertPos, pendChain[i]);
        }

        // Insert the odd element if it exists
        if (hasOdd) {
            cont.insert(findInsertPosition(cont.begin(), cont.end(), odd), odd);
        }
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

#endif