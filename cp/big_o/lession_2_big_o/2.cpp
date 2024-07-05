#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  vector<int> arrA, arrB;

  for (int i = 0; i < a; i++) {
    int x;
    cin >> x;
    arrA.push_back(x);
  }

  for (int i = 0; i < b; i++) {
    int x;
    cin >> x;
    arrB.push_back(x);
  }

  int i = 0, j = 0;
  int res = arrA.size();
  while (i < a && j < b) {
    if (arrA[i] > arrB[j]) {
      j++;

    } else {
      i++;
      j++;
      res--;
    }
  }

  cout << res << endl;

  return 0;
}