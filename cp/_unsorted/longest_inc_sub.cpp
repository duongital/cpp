#include <algorithm>  // for max function
#include <iostream>
#include <vector>

using namespace std;

// Function to find the longest increasing subsequence
vector<int> longestIncreasingSubsequence(vector<int>& nums) {
  int n = nums.size();
  // Initialize the length array with 1, as each element is a subsequence of
  // length 1
  vector<int> length(n, 1);
  // Initialize the previous array to track the indices of the elements that
  // make up the longest increasing subsequence
  vector<int> prev(n, -1);

  // Iterate over each element in the array
  for (int k = 0; k < n; k++) {
    // For each element, iterate over all previous elements
    for (int i = 0; i < k; i++) {
      // If the current element is greater than the previous element
      if (nums[i] < nums[k]) {
        // Update the length of the longest increasing subsequence ending at the
        // current element
        if (length[k] < length[i] + 1) {
          length[k] = length[i] + 1;
          // Update the previous index for the current element
          prev[k] = i;
        }
      }
    }
  }

  // Find the index of the last element of the longest increasing subsequence
  int maxIndex = 0;
  for (int i = 1; i < n; i++) {
    if (length[i] > length[maxIndex]) {
      maxIndex = i;
    }
  }

  // Reconstruct the longest increasing subsequence
  vector<int> lis;
  for (int i = maxIndex; i != -1; i = prev[i]) {
    lis.push_back(nums[i]);
  }
  // Reverse the subsequence to get it in increasing order
  reverse(lis.begin(), lis.end());

  return lis;
}

int main() {
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  vector<int> lis = longestIncreasingSubsequence(nums);
  cout << "Longest Increasing Subsequence: ";
  for (int num : lis) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
