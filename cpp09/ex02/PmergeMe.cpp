#include "PmergeMe.hpp"

using std::sort;


template <typename Container>
        void print_container(const Container& vec) {
            for(typename Container::const_iterator it = vec.begin(); it != vec.end(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }

void PmergeMe::sort_vector(vector<int>& vec) {
    if (vec.size() % 2 != 0) {
        int struggler = vec.back();
        vec.pop_back();
        (void)struggler;
    }
   
    print_container(vec);

    for (size_t i = 0; i < vec.size() - 1; i += 2) {
        if (vec[i] > vec[i + 1]) {
            std::swap(vec[i], vec[i + 1]);
            // std::cout << "swap " << vec[i] << " " << vec[i + 1] << std::endl;
        }
    }

    

    print_container(vec);
}
