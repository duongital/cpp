#include <bits/stdc++.h>

using namespace std;

int main() {
  string target, paper;
  cin >> target >> paper;

  map<char, int> paperMap;
  map<char, int> targetMap;
  int yay = 0, oops = 0;
  for (char c : paper) paperMap[c] += 1;
  for (char c : target) targetMap[c] += 1;

  for (char c : target) {
    if (paperMap[c] > 0) {
      yay += 1;
      paperMap[c] -= 1;
      targetMap[c] -= 1;
    }
  }

  for (char c : target) {
    if (targetMap[c] > 0) {
      targetMap[c] -= 1;
      if (c < 97) {
        char newChar = tolower(c);
        if (paperMap[newChar] > 0) {
          oops += 1;
          paperMap[newChar] -= 1;
        }
      } else if (c >= 97) {
        char newChar = toupper(c);
        if (paperMap[newChar] > 0) {
          oops += 1;
          paperMap[newChar] -= 1;
        }
      }
    }
  }

  cout << yay << " " << oops << endl;
  return 0;
}