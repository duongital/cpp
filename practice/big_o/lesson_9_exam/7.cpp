#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    vector<string> dict;
    string s;
    while (cin >> s, s != "*") dict.push_back(s);
    cin.ignore();

    string line;
    while (getline(cin, line) && line != "") {
      stringstream ss(line);
      string first, second;
      ss >> first >> second;

      int start, end;
      for (int i = 0; i < dict.size(); i++) {
        if (dict[i] == first) start = i;
        if (dict[i] == second) end = i;
      }
      cout << first << " " << second << " " << end - start << endl;
    }
  }
  if (tc) cout << endl;
  return 0;
}