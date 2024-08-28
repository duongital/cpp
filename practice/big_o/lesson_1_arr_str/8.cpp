#include <bits/stdc++.h>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  int s_count[26] = {};
  int t_count[26] = {};

  for (char c : s) {
    s_count[c - 'a'] += 1;
  }

  for (char c : t) {
    t_count[c - 'a'] += 1;
  }

  // chech match with 2 loops nested
  // check if need tree
  int isNeedTree = false, isAutomation = false, isArray = false;
  for (int i = 0; i < 26; i++) {
    if (s_count[i] < t_count[i]) {
      isNeedTree = true;
    }
  }

  // check automation
  //   isAutomation = !isNeedTree && s.size() != t.size();
  for (int i = 0; i < 26; i++) {
    if (s_count[i] > t_count[i]) {
      isAutomation = true;
    }
  }

  // check is array
  int index_found = 0, match = -1;
  for (int i = 0; i < t.size(); i++) {
    index_found = s.find_first_of(t[i], match + 1);

    if (index_found > match) {
      match = index_found;
    } else {
      isArray = true;
      break;
    }
  }

  if (isNeedTree) {
    cout << "need tree" << endl;
  } else if (isAutomation && isArray) {
    cout << "both" << endl;
  } else if (isAutomation) {
    cout << "automaton" << endl;
  } else {
    cout << "array" << endl;
  }

  return 0;
}

// fibo naci do phuc tam 2^n: ve cay nhi phan, nhị là 2 trong 2 mũ n
// permuation do phuc tap n!