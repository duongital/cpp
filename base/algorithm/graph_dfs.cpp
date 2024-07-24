#include <bits/stdc++.h>

using namespace std;
const int MAX = 100;
int V, E;  // input using edge list

vector<int> graph[MAX];
bool visited[MAX];
int path[MAX];

void DFS(int s) {
  for (int i = 0; i < V; i++) {
    visited[i] = false;
    path[i] = -1;
  }

  visited[s] = true;
  stack<int> stk;
  stk.push(s);

  while (!stk.empty()) {
    int u = stk.top();
    stk.pop();

    for (int i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i];
      if (!visited[v]) {
        visited[v] = true;
        path[v] = u;
        stk.push(v);
      }
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

  DFS(0);
  cout << "print path array" << endl;
  for (int i = 0; i < V; i++) cout << path[i] << " ";
  cout << endl;
  cout << "print path recursion:" << endl;
  printPathRecusion(0, 2);

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