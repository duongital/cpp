#include <bits/stdc++.h>
#define pic pair<int, char>
#define vvi vector<vector<pic>>

using namespace std;
const int INF = 1e9;

vvi graph;
vvi dist;
vvi path;
int V = 100;

bool FloydWarshall(vvi& graph, vvi& dist) {
  // create current path matrix
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      dist[i][j] = graph[i][j];
      if (graph[i][j].first != INF && i != j)
        path[i][j].first = i;
      else
        path[i][j].first = -1;
    }
  }

  // main flow
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      if (dist[i][k].first == INF) continue;
      for (int j = 0; j < V; j++) {
        if (dist[k][j].first != INF &&
            dist[i][j].first > dist[i][k].first + dist[k][j].first) {
          dist[i][j].first = dist[i][k].first + dist[k][j].first;
          if (path[i][j].second) }
      }
    }
  }

  for (int i = 0; i < V; i++) {
    if (dist[i][i].first < 0) return false;
  }
  return true;
}

int main() {
  while (true) {
    int t;
    cin >> t;
    if (t == 0) break;
    graph = vvi(V, vector<pic>(V));
    dist = vvi(V, vector<pic>(V));
    path = vvi(V, vector<pic>(V));

    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (i != j)
          graph[i][j].first = INF;
        else
          graph[i][j].first = 0;
      }
    }
    while (t--) {
      char age, way, from, to;
      int energy;
      cin >> age >> way >> from >> to >> energy;
      if (way == 'U') {
        graph[from - 'A'][to - 'A'].first = energy;
      } else {
        graph[from - 'A'][to - 'A'].first = energy;
        graph[to - 'A'][from - 'A'].first = energy;
      }
    }

    if (FloydWarshall(graph, dist) == true)
      cout << "Has solution" << endl;
    else
      cout << "Graph contains negative weight cycle";
    return 0;
  }
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