#include <bits/stdc++.h>

using namespace std;

int binarySearch(const vector<int> &v, int left, int right, int x) {
  while (left <= right) {
    int mid = (left + right) / 2;
    if (x == v[mid])
      return mid + 1;  // return position not index
    else if (x < v[mid])
      right = mid - 1;
    else if (x > v[mid])
      left = mid + 1;
  }
  return -1;
}

int main() {
  int a, b;
  int atCase = 1;
  while (scanf("%d %d", &a, &b), (a || b)) {
    vector<int> v;
    while (a--) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    cout << "CASE# " << atCase << ":" << endl;
    atCase++;
    while (b--) {
      int x;
      cin >> x;
      int searchResult = binarySearch(v, v[0], v[v.size() - 1], x);
      if (searchResult == -1) {
        cout << x << " not found" << endl;
      } else {
        cout << x << " found at " << searchResult << endl;
      }
    }
  }
  return 0;
}