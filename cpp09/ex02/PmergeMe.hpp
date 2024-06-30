#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <list>


using std::vector;
using std::list;

class PmergeMe {
    private:


    public:
        static void sort_vector(vector<int>& vec);
        
    
    void merge_sort(vector<int>& vec, int left, int right);
    void merge(vector<int>& vec, int left, int mid, int right);
    
        // static void sort_list(list<int>& lis);
};




#endif