#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) {
  int len = s.length();
  int lastIndex = 0;
  for (int i = len - 1; i >= 0; i--) {
    if (s[i] == ' ') {
      continue;
    } else {
      lastIndex = i;
      break;
    }
  }
  int counter = 0;
  for (int i = lastIndex; i >= 0; i--) {
    if (s[i] == ' ') {
      break;
    } else {
      counter += 1;
    }
  }
  return counter;
}

int main() {
  std::string s = "Duong";
  s.push_back('!');  // Hello, world!
  int a = s.size();
  std::cout << a << std::endl;
  s.pop_back();
  s.erase(1, 1);
  std::cout << "pop back: " << s << endl;

  for (char c : s) {
    cout << "char: " << c << endl;
  }
  return 0;
}