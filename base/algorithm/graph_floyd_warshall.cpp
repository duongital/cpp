#include <bits/stdc++.h>
#define vvi vector<vector<int>>

using namespace std;
const int INF = 1e9;

vvi graph;
vvi dist;
vvi path;
int V;

void printPath(vvi& path, int s, int f) {
  if (s == f) {
    cout << f << " ";
    return;
  }
  if (path[s][f] == -1) {
    cout << "No path";
    return;
  }
  printPath(path, s, path[s][f]);
  cout << f << " ";
}

void printSolution(vvi& path, vvi& dist) {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (i != j) {
        cout << i << " -> " << j << " : ";
        printPath(path, i, j);
        cout << endl;

        if (path[i][j] != -1) {
          cout << "Total length: " << dist[i][j] << endl;
        }
      }
    }
  }
}

bool FloydWarshall() {
  for (int i = 0; i < V; i++) {  // create current path, dist matrices
    for (int j = 0; j < V; j++) {
      dist[i][j] = graph[i][j];
      if (graph[i][j] != INF && i != j)
        path[i][j] = i;
      else
        path[i][j] = -1;
    }
  }

  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      if (dist[i][k] == INF) continue;
      for (int j = 0; j < V; j++) {
        if (dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          path[i][j] = path[k][j];
        }
      }
    }
  }

  for (int i = 0; i < V; i++) {  // check negative cycle
    if (dist[i][i] < 0) return false;
  }
  return true;
}

int main() {
  int temp;
  cin >> V;
  graph = vvi(V, vector<int>(V));
  dist = vvi(V, vector<int>(V));
  path = vvi(V, vector<int>(V));

  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      cin >> temp;
      if (temp == 0 && i != j)
        graph[i][j] = INF;
      else
        graph[i][j] = temp;
    }
  }

  if (FloydWarshall() == true)
    printSolution(path, dist);
  else
    cout << "Graph contains negative weight cycle";
  return 0;
}

/*
6
0 1 0 0 0 0
0 0 5 -2 0 7
0 0 0 0 0 -1
2 0 -1 0 4 0
0 0 0 3 0 0
0 0 0 0 1 0
*/