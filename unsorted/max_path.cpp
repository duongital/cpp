#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxPathSum(vector<vector<int>>& grid) {
  int n = grid.size();
  vector<vector<int>> dp(n, vector<int>(n, 0));

  // Base case: the maximum sum at the upper-left corner is the value of the
  // Cell itself
  dp[0][0] = grid[0][0];

  // Fill the first row and first column of the dp array
  for (int i = 1; i < n; i++) {
    dp[i][0] = dp[i - 1][0] + grid[i][0];
    dp[0][i] = dp[0][i - 1] + grid[0][i];
  }

  // Fill the rest of the dp array
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
    }
  }

  // The maximum sum is at the lower-right corner
  return dp[n - 1][n - 1];
}

int main() {
  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  cout << "Maximum path sum: " << maxPathSum(grid) << endl;

  return 0;
}
