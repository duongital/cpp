#include <iostream>
#include <vector>

std::vector<int> deleteConsecutiveSequences(const std::vector<int>& input) {
  std::vector<int> result;
  int sum = 0;

  for (int i = 0; i < input.size(); ++i) {
    sum += input[i];
    if (sum == 0) {
      // Skip all elements that were part of the sequence that summed to 0
      while (i < input.size() && sum == 0) {
        ++i;
        if (i < input.size()) {
          sum += input[i];
        }
      }
      // If the sum is still 0 after skipping, it means the entire vector sums
      // to 0
      if (sum == 0) {
        break;
      }
    } else {
      // Add the current element to the result vector
      result.push_back(input[i]);
    }
  }

  return result;
}

int main() {
  std::vector<int> test1 = {1, 2, -3, 3, 1};
  std::vector<int> test2 = {1, 2, 3, -3, 4};
  std::vector<int> test3 = {1, 2, 3, -3, -2};

  std::vector<int> result1 = deleteConsecutiveSequences(test1);
  std::vector<int> result2 = deleteConsecutiveSequences(test2);
  std::vector<int> result3 = deleteConsecutiveSequences(test3);

  std::cout << "Test 1: ";
  for (int num : result1) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  std::cout << "Test 2: ";
  for (int num : result2) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  std::cout << "Test 3: ";
  for (int num : result3) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}
