#include <bits/stdc++.h>

using namespace std;

#define MAX 10

vector<int> graph[MAX];
bool visited[MAX];
int path[MAX];

int E, V;

void BFS(int s) {
  for (int i = 0; i < V; i++) {
    visited[i] = false;
    path[i] = -1;
  }

  queue<int> q;
  visited[s] = true;
  q.push(s);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i];
      if (!visited[v]) {
        visited[v] = true;
        q.push(v);
        path[v] = u;
      }
    }
  }
}

void printPathRecursion(int s, int f) {
  if (s == f) {
    cout << f << " ";
  } else if (path[f] == -1) {
    cout << "No path" << endl;
  } else {
    printPathRecursion(s, path[f]);
    cout << f << " ";
  }
}

int main() {
  cin >> V >> E;

  int T = E;
  while (T--) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  BFS(1);
  cout << "print path array" << endl;
  for (int i = 0; i < V; i++) cout << path[i] << " ";
  cout << endl;
  // cout << "print path recursion:" << endl;
  // printPathRecursion(0, 5);

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