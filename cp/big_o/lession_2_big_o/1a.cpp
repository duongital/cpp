#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> v;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }

  set<int> s;
  int start = 0, end = 0, currentSize = 0;
  for (end; end < n; end++) {
    s.insert(v[end]);

    if (end != 0 && v[end] == v[start]) {
      start++;
    }

    if (s.size() == k) {
      break;
    }
  }

  if (s.size() == k) {
    while (start < end && v[start] == v[start + 1]) {
      start++;
    }
    cout << start + 1 << " " << end + 1 << endl;
  } else {
    cout << -1 << " " << -1 << endl;
  }

  return 0;
}