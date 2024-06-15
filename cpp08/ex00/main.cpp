#include "easyfind.hpp"
#include <iostream>
#include <string>
#include <vector>

int main() {
  // Replace the {} initializer list with constructor syntax
  int arr[] = {10, 20, 30, 40, 50};
  std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
}
