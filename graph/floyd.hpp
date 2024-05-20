#pragma once
#include "graph/base.hpp"

template <typename T, typename GT>
vector<vector<T>> floyd(GT &G) {
  int n = G.n;
  vv(T, dist, n, n, infty<T>);
  rep(i, n) {
    dist[i][i] = 0;
    for (auto e : G[i]) ckmin(dist[i][e.to], e.cost);
  }
  rep(k, n) rep(i, n) {
    if (dist[i][k] == infty<T>) continue;
    rep(j, n) {
      if (dist[k][j] == infty<T>) continue;
      ckmin(dist[i][j], dist[i][k] + dist[k][j]);
    }
  }
  return dist;
}
