#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void convert(string s) {
  stack<char> stack;
  string result;
  for (char c : s) {
    if (c == '(') continue;
    if (c == ')') {
      char temp = stack.top();
      result.push_back(temp);
      stack.pop();
    } else if (isalpha(c)) {
      result.push_back(c);
    } else {
      stack.push(c);
    }
  }
  cout << result << endl;
}

int main() {
  int n;
  cin >> n;

  vector<string> arr;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    arr.push_back(s);
  }

  for (string s : arr) {
    convert(s);
  }
  return 0;
}