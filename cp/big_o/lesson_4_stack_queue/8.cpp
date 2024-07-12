#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> arr;

  for (int i = 0; i < n; i++) {
    string e;
    cin >> e;
    arr.push_back(e);
  }
  for (string s : arr) {
    stack<char> stk;
    int count = 0;
    for (char c : s) {
      if (!stk.empty() && stk.top() == '<' && c == '>') {
        stk.pop();
        if (!stk.empty() && stk.top() == '<') {
          break;
        }
        count += 2;
      } else {
        stk.push(c);
      }
    }
    cout << count << endl;
  }

  return 0;
}