#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  vector<vector<int>> v = {};
  while (t--) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }

  // find max
  int max = 0, idx = 0;
  for (int i = 0; i < v.size(); i++) {
    int gap = v[i][1] - v[i][0];
    if (gap >= max) {
      max = gap;
      idx = i;
    };
  }

  // size is 1 will cover itself
  if (v.size() == 1) {
    cout << 1 << endl;
  } else {
    int left = v[idx][0];
    int right = v[idx][1];
    int count = 0;

    for (int i = 0; i < v.size(); i++) {
      if (v[i][0] >= left && v[i][1] <= right) count++;
    }

    if (count == v.size()) {  // cover all other segments
      cout << idx + 1 << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}