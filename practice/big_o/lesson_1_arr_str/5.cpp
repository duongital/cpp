#include <bits/stdc++.h>

using namespace std;

int main() {
  int n1, n2, k, m;
  cin >> n1 >> n2 >> k >> m;
  vector<int> arr1, arr2;

  for (int i = 0; i < n1; i++) {
    int x;
    cin >> x;
    arr1.push_back(x);
  }

  for (int i = 0; i < n2; i++) {
    int x;
    cin >> x;
    arr2.push_back(x);
  }

  int left = arr1[k - 1];
  int right = arr2[arr2.size() - m];
  if (left < right) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}