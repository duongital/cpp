#include <iostream>

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
  vector<int> duplicates;
  for (int i = 0; i < nums.size(); ++i) {
    int index = abs(nums[i]) - 1;  // Convert to 0-based index
    if (nums[index] < 0) {
      // If the number is negative, it's a duplicate
      duplicates.push_back(abs(nums[i]));
    } else {
      // Mark the number as visited by making it negative
      nums[index] = -nums[index];
    }
  }
  return duplicates;
}

int main() {
  vector<int> test{15, 20, 20, 2, 4};
  vector<int> result = findDuplicates(test);
  for (auto e : result) {
    cout << e << endl;
  }
  return 0;
}