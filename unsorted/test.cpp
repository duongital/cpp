#include <iostream>

using namespace std;

int solution(vector<int> &A) {
  // Implement your solution here
  vector<int> prefixSum(A.size(), A[0]);
  for (int i = 1; i < A.size(); i++) {
    prefixSum[i] = prefixSum[i - 1] + A[i];
  }
  for (int i : prefixSum) cout << i << endl;

  int minValue = INFINITY;
  for (int i = 1; i < A.size(); i++) {
    int left = prefixSum[i];
    int prefixSumSize = prefixSum.size();
    int right = prefixSum[prefixSumSize - 1] - left;
    int subtract = abs(left - right);
    minValue = std::min(minValue, subtract);
  }
  return minValue;
}

int main() {
  vector<int> sample = {1, 2, 3, 4};
  int res = solution(sample);
  cout << "result min: " << res;
  return 0;
}