#include <bits/stdc++.h>

using namespace std;

void count(string& s) {
  unordered_map<char, int> m;
  for (char c : s) {
    m[c]++;
  }

  for (const auto& pair : m) {
    cout << "key: " << pair.first << ", value: " << pair.second << endl;
  }

  // unordered_map<char, int>::iterator iter;
  // for (iter = m.begin(); iter != m.end(); ++iter) {
  //   cout << iter->first << " - " << iter->second << endl;
  // }
}

int main() {
  std::cout << "Hello" << std::endl;
  string exmaple = "hello world";
  count(exmaple);
  return 0;
}