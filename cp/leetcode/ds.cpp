#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << "Hello" << endl;
  vector<int> v = {1, 2, 3};
  vector<int>::iterator it;  // what is type of it? pointer?
  it = v.begin() + 1;
  v.insert(it, 9);

  for (int i : v) {
    cout << i << endl;
  }

  string s = "abz";
  bool b = s[0] == 48;

  int result = isalpha(s[2]);
  cout << b << endl;
  cout << result << endl;

  s[0] = 'b';
  cout << s << endl;
  return 0;
}

// string is dynamic array <char> with additional util functions: find, substr,
// append... similar to dynamic array: size, empty, clear, intert, erase...

// number char: 48-57
// >>> s[0] >=48 && s[0] <= 57

// a - A = 32 = 97 - 65
