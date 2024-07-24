#include <bits/stdc++.h>

using namespace std;
const int MAX = 100;
int V, E;  // input using edge list

vector<int> graph[MAX];
bool visited[MAX];
int path[MAX];

void DFSRecursion(int s) {
  visited[s] = true;

  for (int i = 0; i < graph[s].size(); i++) {
    int v = graph[s][i];
    if (!visited[v]) {
      path[v] = s;
      DFSRecursion(v);
    }
  }
}

void printPathRecusion(int s, int f) {
  if (s == f) {
    cout << f << " ";
  } else if (path[f] == -1) {
    cout << "no path" << endl;
  } else {
    printPathRecusion(s, path[f]);
    cout << f << " ";
  }
}

int main() {
  cin >> V >> E;
  int t = E;
  while (t--) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  // reset visited and path
  for (int i = 0; i < V; i++) {
    visited[i] = false;
    path[i] = -1;
  }

  // DFS
  DFSRecursion(0);
  printPathRecusion(0, 5);
  return 0;
}

/*
6 8
0 1
0 3
1 2
1 3
1 5
2 5
3 4
3 5
*/