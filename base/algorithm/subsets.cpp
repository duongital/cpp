#include <iostream>
#include <vector>

// Function to print a subset
void printSubset(const std::vector<int> subset) {
  for (int element : subset) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
}

// Function to generate all subsets of a given array
void generateSubsets(const std::vector<int> array) {
  int n = array.size();
  int totalSubsets = 1 << n;  // 2^n

  for (int i = 0; i < totalSubsets; i++) {
    std::vector<int> subset;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        subset.push_back(array[j]);
      }
    }
    printSubset(subset);
  }
}

int main() {
  std::vector<int> array = {1, 2, 3};
  generateSubsets(array);
  return 0;
}
