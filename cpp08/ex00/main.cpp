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

  std::list<int> lis;
  std::vector<int>::const_iterator start = vec.begin();
  std::vector<int>::const_iterator end = vec.end();
  lis.assign(start, end);
  for (std::list<int>::iterator it = lis.begin(); it != lis.end(); ++it) {
        std::cout << *it << " ";
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
