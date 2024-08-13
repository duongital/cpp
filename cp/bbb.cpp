#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string kthDistinct(vector<string>& arr, int k) {
    map<string, int> m;
    for (string s : arr) {
      m[s]++;
    }
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
      if (m[arr[i]] == 1) count++;
      if (m[arr[i]] == 1 && count == k) {
        return arr[i];
      }
    }
    return "";
  }
};

int main() {
  Solution s;
  vector<string> arr = {"d", "b", "c", "b", "c", "a"};
  s.kthDistinct(arr, 2);
  return 0;
}

/*
I have changed the routing structure or a big refactoring with it.
Carefully tested on staging but it failed or incident with authen on production.
I create a PR to revert my code and make it normal on prd. Then I investiage the
issue and test on stage with know test case. Lesson learn: test coverage not
counted by lines of code.

Be on time, make sure that we have a good internet connection and audio quality.
Build trust by implementing features without issue or at its least.
Have a good communication and being helpful with teammates.
*/