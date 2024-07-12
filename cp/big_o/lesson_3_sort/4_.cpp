#include <bits/stdc++.h>

using namespace std;
const int MAX = 2005;
int ranking[MAX];

int main() {
  int n;
  cin >> n;

  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    arr.push_back(e);
  }

  vector<int> sortedArr = arr;
  sort(sortedArr.begin(), sortedArr.end(), greater<int>());
  for (int i = 0; i < n; i++) {
    int position = sortedArr[i];

    if (!ranking[position]) {
      ranking[position] = i + 1;
    }
  }

  for (int& e : arr) {
    cout << ranking[e] << " ";
  }

  return 0;
}