#include <bits/stdc++.h>

using namespace std;

int slidingWindowAtMost(vector<int> &nums, int goal) {
  int start = 0, currentSum = 0, totalCount = 0;

  // Iterate through the array using a sliding window approach
  for (int end = 0; end < nums.size(); end++) {
    currentSum += nums[end];

    // Adjust the window by moving the start pointer to the right
    // until the sum becomes less than or equal to the goal
    while (start <= end && currentSum > goal) {
      currentSum -= nums[start++];
    }

    // Update the total count by adding the length of the current subarray
    totalCount += end - start + 1;
  }
  return totalCount;
}

int numSubarraysWithSum(vector<int> &nums, int goal) {
  return slidingWindowAtMost(nums, goal) - slidingWindowAtMost(nums, goal - 1);
}

int main() {
  vector<int> test = {1, 0, 1, 0, 1};
  int x = numSubarraysWithSum(test, 2);
  cout << x << endl;

  return 0;
}