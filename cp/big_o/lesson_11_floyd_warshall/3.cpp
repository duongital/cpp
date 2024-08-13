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
        if (dist[k][j] != INF && dist[i][j] > dist[i][k] * dist[k][j]) {
          dist[i][j] = dist[i][k] * dist[k][j];
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
  int V, n, test = 1;
  while (scanf("%d", &V) == 1 && V) {
    int t = V;
    map<string, int> m;
    int count = 0;
    while (t--) {
      char str[50];
      scanf("%s", str);
      string k(str);
      m[k] = count;
      count++;
    }
    scanf("%d", &n);  // printf("ok");
    char a[50], b[50];
    double d;
    while (n--) {
      scanf("%s %lf %s", a, &d, b);
    }
    printf("Case %d: hello \n", test++);
  }
  return 0;
}

/*
3
USDollar
BritishPound
FrenchFranc
3
USDollar 0.5 BritishPound
BritishPound 10.0 FrenchFranc
FrenchFranc 0.21 USDollar

4
USDollar
BritishPound
FrenchFranc
Vietnamdong
6
USDollar 0.5 BritishPound
USDollar 4.9 FrenchFranc
BritishPound 10.0 FrenchFranc
BritishPound 1.99 USDollar
FrenchFranc 0.09 BritishPound
FrenchFranc 0.19 USDollar

0
*/