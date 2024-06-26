#include <bits/stdc++.h>

using namespace std;

void bbsort(vector<int>& v) {
  int n = v.size();
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (v[i] > v[j]) {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
      }
    }
  }
}

int main() {
  vector<int> v = {15, 3, 2, 1, 4};
  for (int i : v) {
    cout << i << endl;
  }
  cout << "After:" << endl;
  bbsort(v);
  for (int i : v) {
    cout << i << endl;
  }
  return 0;
}