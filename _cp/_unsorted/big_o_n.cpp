#include <iostream>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums) {
  // all product
  int all = 1;
  int countZero = 0;
  for (int i : nums) {
    int multiplyBy = i == 0 ? 1 : i;
    all *= multiplyBy;
    if (i == 0) {
      countZero++;
    }
  }

  vector<int> allZero(nums.size(), 0);

  if (countZero == 0) {
    for (int i = 0; i < nums.size(); i++) {
      allZero[i] = all / nums[i];
    }
  } else if (countZero == 1) {
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) allZero[i] = all;
    }
  }
  return allZero;
}

int main() {
  vector<int> test = {1, 2, 3, 4, 5};
  vector<int> test2 = productExceptSelf(test);
  // cout << test << endl;
  // return 0;
  cout << "hello" << endl;
  for (int i : test2) {
    cout << i << endl;
  }
  return 0;
}