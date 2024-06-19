#include "easyfind.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>

using std::cout;

int main() {
  int arr[] = {10, 20, 30, 40, 50};
  std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
  cout << easyfind(vec, 10) << std::endl;

  // std::list<int> lis(std::begin(arr), std::end(arr));   cpp 11
  
  std::list<int> lis;
  std::list<int>::iterator it = lis.begin();
  for (size_t i = 0; i < vec.size(); ++i) {
    lis.push_back(vec.at(i));
    cout << *it << " ";
    ++it;
  }

  cout << std::endl;
  cout << easyfind(lis, 20) << std::endl;

  try {
    cout << easyfind(lis, 15) << std::endl;
  } 
  catch (const std::exception& e) {
    cout << "Exception caught: " << e.what() << std::endl;
  }
  
  return 0;
}
