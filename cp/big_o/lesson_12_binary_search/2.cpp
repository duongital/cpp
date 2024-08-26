#include <bits/stdc++.h>

using namespace std;

bool binarySearch(const vector<int> &v, int left, int right, int x) {
  while (left <= right) {
    int mid = (left + right) / 2;
    if (x == v[mid])
      return true;
    else if (x < v[mid])
      right = mid - 1;
    else
      left = mid + 1;
  }
  return false;
}

int main() {
  int TC;
  cin >> TC;

  while (TC--) {
    int a, b;
    cin >> a >> b;
    vector<int> arr;
    while (a--) {
      int x;
      cin >> x;
      arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    int count = 0;
    for (int e : arr) {
      if (binarySearch(arr, 0, arr.size() - 1, b - e)) count++;
    }
    cout << count / 2 << endl;
  }
  return 0;
}