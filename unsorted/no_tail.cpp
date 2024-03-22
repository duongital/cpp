#include <iostream>

void noTailRecursion(int n) {
  if (n > 0) {
    noTailRecursion(n - 1);  // Recursive call
    std::cout << n << " ";
    noTailRecursion(n - 2);  // Another recursive call
  }
}

int main() {
  int num = 5;
  std::cout << "Non-Tail/Head Recursion: ";
  noTailRecursion(num);
  return 0;
}
