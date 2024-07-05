#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>

const int JACOBSTHAL_SIZE = 30;
int jacobsthal[JACOBSTHAL_SIZE] = {0, 1};

void initJacobsthal() {
    for (int i = 2; i < JACOBSTHAL_SIZE; ++i) {
        jacobsthal[i] = jacobsthal[i-1] + 2 * jacobsthal[i-2];
    }
}

void binaryInsert(std::vector<int>& arr, int start, int end, int value) {
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] < value) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    arr.insert(arr.begin() + start, value);
}

void fordJohnsonSort(std::vector<int>& arr) {
    if (arr.size() <= 1) return;

    std::vector<int> mainChain;
    std::vector<int> pendChain;
    
    for (size_t i = 0; i < arr.size() - 1; i += 2) {
        if (arr[i] < arr[i + 1]) {
            mainChain.push_back(arr[i + 1]);
            pendChain.push_back(arr[i]);
        } else {
            mainChain.push_back(arr[i]);
            pendChain.push_back(arr[i + 1]);
        }
    }

    int odd = -1;
    if (arr.size() % 2 == 1) {
        odd = arr.back();
    }

    if (mainChain.size() > 1) {
        fordJohnsonSort(mainChain);
    }

    std::vector<int> result = mainChain;
    int jacobsthalIndex = 3;
    size_t insertIndex = 0;

    if (!pendChain.empty()) {
        binaryInsert(result, 0, result.size(), pendChain[0]);
        if (pendChain.size() > 1) {
            binaryInsert(result, 0, result.size(), pendChain[1]);
            insertIndex = 2;
        } else {
            insertIndex = 1;
        }
    }

    while (insertIndex < pendChain.size() && jacobsthalIndex < JACOBSTHAL_SIZE) {
        int nextJacobsthal = jacobsthal[jacobsthalIndex];
        while (nextJacobsthal - 1 < static_cast<int>(pendChain.size()) && insertIndex < static_cast<size_t>(nextJacobsthal - 1)) {
            binaryInsert(result, 0, result.size(), pendChain[insertIndex]);
            ++insertIndex;
        }
        if (insertIndex >= pendChain.size()) break;
        ++jacobsthalIndex;
    }

    // Insert any remaining elements
    while (insertIndex < pendChain.size()) {
        binaryInsert(result, 0, result.size(), pendChain[insertIndex]);
        ++insertIndex;
    }

    if (odd != -1) {
        binaryInsert(result, 0, result.size(), odd);
    }

    arr = result;
}

int main() {
    initJacobsthal();
    int values[] = {7, 3, 9, 1, 5, 8, 2, 6, 4};
    std::vector<int> arr(values, values + sizeof(values) / sizeof(values[0]));
    
    fordJohnsonSort(arr);
    
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}