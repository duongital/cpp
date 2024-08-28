#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> res;

  void printVector(vector<int> v) {
    for (int i : v) {
      cout << i;
    }
    cout << endl;
  }

  void completeSearch(vector<int>& nums, int i, int n, vector<int>& temp) {
    if (i == n) {
      printVector(temp);
      res.push_back(temp);
    } else {
      completeSearch(nums, i + 1, n, temp);
      temp.push_back(nums[i]);
      completeSearch(nums, i + 1, n, temp);
      temp.pop_back();
    }
  }

  vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> temp = {};
    int n = nums.size();
    completeSearch(nums, 0, n, temp);
    return res;
  }
};

int main() {
  Solution s;
  vector<int> test = {1, 2, 3};
  s.subsets(test);
  return 0;
}