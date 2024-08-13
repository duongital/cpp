#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  vector<int> arr;
  while (tc--) {
    int e;
    scanf("%d", &e);
    arr.push_back(e);
  }

  map<int, int> m;
  for (int i = 0; i < arr.size(); i++) {
    m[arr[i]] = i;
  }

  sort(arr.begin(), arr.end());
  int minLoss = 1e9;
  for (int i = 1; i < arr.size(); i++) {
    int current = arr[i] - arr[i - 1];
    if (current < minLoss && m[arr[i]] < m[arr[i - 1]]) {
      minLoss = current;
    }
  }

  if (minLoss != 1e9) {
    cout << minLoss << endl;
  } else {
    cout << "-1" << endl;
  }

  return 0;
}