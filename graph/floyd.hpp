#include "graph/graph.hpp"

template <typename T, typename GT>
vector<vector<T>> floyd(GT &g) {
  const T inf = numeric_limits<T>::max() / 2;
  int n = g.n;
  vector<vector<T>> dist(n, vector<T>(n, inf));
  for (int i = 0; i < n; i++) {
    dist[i][i] = 0;
    for (int id : g.g[i]) {
      auto e = g.edges[id];
      dist[i][e.to] = min<T>(dist[i][e.to], e.cost);
    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      if (dist[i][k] == inf) continue;
      for (int j = 0; j < n; j++) {
        if (dist[k][j] == inf) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  return dist;
}
