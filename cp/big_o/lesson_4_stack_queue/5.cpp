#include <bits/stdc++.h>

using namespace std;

string s;
stack<int> st;
map<char, int> val;

int main() {
  cin >> s;

  val['C'] = 120;
  val['H'] = 1;
  val['O'] = 16;
  val['('] = -1;
  val[')'] = 0;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      st.push(val[s[i]]);
    } else if (s[i] == ')') {
      int v = val[')'], total = 0;
      while (v != val['(']) {
        v = st.top();
        st.pop();
        if (v != val['(']) total += v;
      }
      st.push(total);
    } else if (s[i] == 'C' || s[i] == 'H' || s[i] == 'O') {
      st.push(val[s[i]]);
    } else {  // 2 -> 9
      int v = st.top();
      st.pop();
      st.push(v * (int)(s[i] - '0'));
    }
  }

  int res = 0;
  while (!st.empty()) {
    res += st.top();
    st.pop();
  }

  cout << res << endl;

  return 0;
}