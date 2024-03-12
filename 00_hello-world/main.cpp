#include <iostream>
#include <set>

using namespace std;

string customSortString(string order, string s)
{
  string tempSet;
  for (char ch : order)
  {
    // check if a char in `order` included in `s`
    if (s.find(ch) != std::string::npos)
    {
      tempSet.push_back(ch);
    }
  }

  for (char ch : s)
  {
    if (tempSet.find(ch) == std::string::npos)
    {
      tempSet.push_back(ch);
    }
  }

  return tempSet;
}

int main()
{
  cout << "Hello world  ";
  customSortString("bcafg", "abcd");
  return 0;
}
