#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  vector<int> arr;

  while (t--) {
    int e;
    cin >> e;
    arr.push_back(e);
  }

  sort(arr.begin(), arr.end());
  int mid = (arr.size() - 1) / 2;
  cout << arr[mid] << endl;

  return 0;
}