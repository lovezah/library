---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph.hpp\"\n\ntemplate <typename T> \nstruct Edge\
    \ {\n  int from, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int,\
    \ bool directed = false>\nstruct graph {\n  static constexpr bool is_directed\
    \ = directed;\n  int n, m;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n\
    \  vector<edge_type> edges;\n  vector<vector<int>> g;\n\n  graph(int _n) : n(_n),\
    \ m(0) {\n    g.resize(n);\n  }\n\n  void add(int from, int to, T cost = 1, int\
    \ i = -1) {\n    assert(0 <= from && from < n && 0 <= to && to < n);\n    if (i\
    \ == -1) i = m++;\n    g[from].push_back((int) edges.size());\n    edges.push_back(edge_type({from,\
    \ to, cost, i}));\n    if (!is_directed) {\n      g[to].push_back((int) edges.size());\n\
    \      edges.push_back(edge_type({to, from, cost, i}));\n    }\n  }\n};\n#line\
    \ 3 \"graph/floyd_warshall.hpp\"\n\ntemplate <typename T, typename GT>\nvector<vector<T>>\
    \ floyd_warshall(GT &g) {\n  const T inf = numeric_limits<T>::max() / 2;\n  int\
    \ n = g.n;\n  vector<vector<T>> dist(n, vector<T>(n, inf));\n  for (int i = 0;\
    \ i < n; i++) {\n    dist[i][i] = 0;\n    for (int id : g.g[i]) {\n      auto\
    \ e = g.edges[id];\n      dist[i][e.to] = min<T>(dist[i][e.to], e.cost);\n   \
    \ }\n  }\n  for (int k = 0; k < n; k++) {\n    for (int i = 0; i < n; i++) {\n\
    \      if (dist[i][k] == inf) continue;\n      for (int j = 0; j < n; j++) {\n\
    \        if (dist[k][j] == inf) continue;\n        dist[i][j] = min(dist[i][j],\
    \ dist[i][k] + dist[k][j]);\n      }\n    }\n  }\n  return dist;\n}\n"
  code: "#pragma once\n#include \"graph/graph.hpp\"\n\ntemplate <typename T, typename\
    \ GT>\nvector<vector<T>> floyd_warshall(GT &g) {\n  const T inf = numeric_limits<T>::max()\
    \ / 2;\n  int n = g.n;\n  vector<vector<T>> dist(n, vector<T>(n, inf));\n  for\
    \ (int i = 0; i < n; i++) {\n    dist[i][i] = 0;\n    for (int id : g.g[i]) {\n\
    \      auto e = g.edges[id];\n      dist[i][e.to] = min<T>(dist[i][e.to], e.cost);\n\
    \    }\n  }\n  for (int k = 0; k < n; k++) {\n    for (int i = 0; i < n; i++)\
    \ {\n      if (dist[i][k] == inf) continue;\n      for (int j = 0; j < n; j++)\
    \ {\n        if (dist[k][j] == inf) continue;\n        dist[i][j] = min(dist[i][j],\
    \ dist[i][k] + dist[k][j]);\n      }\n    }\n  }\n  return dist;\n}\n"
  dependsOn:
  - graph/graph.hpp
  isVerificationFile: false
  path: graph/floyd_warshall.hpp
  requiredBy: []
  timestamp: '2024-05-15 19:00:18+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/floyd_warshall.hpp
layout: document
redirect_from:
- /library/graph/floyd_warshall.hpp
- /library/graph/floyd_warshall.hpp.html
title: graph/floyd_warshall.hpp
---
