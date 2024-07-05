#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  vector<int> soliderSizeList, availableSizeList;

  for (int i = 0; i < a; i++) {
    int x;
    cin >> x;
    soliderSizeList.push_back(x);
  }

  for (int i = 0; i < b; i++) {
    int x;
    cin >> x;
    availableSizeList.push_back(x);
  }

  int i = 0, j = 0, counter = 0;
  vector<string> result;
  while (i < a && j < b) {
    if (soliderSizeList[i] - x <= availableSizeList[j] &&
        availableSizeList[j] <= soliderSizeList[i] + y) {
      counter += 1;
      i++;
      j++;
      string s = to_string(i) + " " + to_string(j);
      result.push_back(s);
    } else if (soliderSizeList[i] < availableSizeList[j]) {
      i++;
    } else if (soliderSizeList[i] > availableSizeList[j]) {
      j++;
    }
  }

  cout << counter << endl;
  for (string e : result) {
    cout << e << endl;
  }

  return 0;
}