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
  int left, right;
  for (int i = 0; i < n; i++) {
    int j = i;
    while (s.size() != k && j >= 0) {
      s.insert(v[j]);
      j--;
    }
    if (s.size() == k) {
      left = j + 1;
      right = i + 1;
      break;
    } else {
      left = -1;
      right = -1;
    }
  }

  cout << left << " " << right << endl;
  return 0;
}

/*
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

  int check[3] = {INT_MAX, -1, -1};
  for (int i = 0; i < n; i++) {
    set<int> s;
    int j = i;
    while (s.size() != k) {
      s.insert(v[j]);
      j++;
    }
    int length = j - i;
    if (s.size() == k && length < check[0]) {
      check[0] = length;
      check[1] = i + 1;
      check[2] = j;
    }

    // for (int j = i; j < n; j++) {
    //   s.insert(v[j]);
    //   if (s.size() == k) {
    //     int length = j - i + 1;
    //     if (length < check[0]) {
    //       check[0] = length;
    //       check[1] = i + 1;
    //       check[2] = j + 1;
    //     }
    //     break;
    //   }
    // }
  }

  cout << check[1] << " " << check[2] << endl;
  return 0;
}
*/