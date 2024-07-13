#include <deque>
#include <iostream>

using namespace std;

int main() {
  int P, C, number;
  char ch;
  int counter = 1;
  while (cin >> P >> C && P != 0) {
    cout << "Case " << counter++ << ":\n";

    deque<int> li;
    for (int i = 1; i <= min(P, C); i++) li.push_back(i);

    while (C--) {
      cin >> ch;
      if (ch == 'N') {
        cout << li.front() << endl;
        li.push_back(li.front());
        li.pop_front();
      } else {
        cin >> number;
        li.push_front(number);
        deque<int>::iterator ilter = li.begin() + 1;
        for (; ilter != li.end(); ilter++)
          if (*ilter == number) {
            li.erase(ilter);
            break;
          }
      }
    }
  }
  return 0;
}