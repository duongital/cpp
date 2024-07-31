#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool hasTwoDivisor(int num) {
    int count = 0;
    for (int i = 0; i < num; i++) {
      if (i == 0) continue;
      if (i == 1) {
        count += 1;
      } else {
        if (num % i == 0) count += 1;
      }
    }
    return count == 2;
  }

  int nonSpecialCount(int l, int r) {
    int count = 0;
    for (int i = l; i <= r; i++) {
      if (!hasTwoDivisor(i)) count++;
    }
    return count;
  }
};

int main() {
  Solution s;
  // int res = s.nonSpecialCount(5, 7);
  // cout << res << endl;
  return 0;
}