---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/floyd.hpp\"\ntemplate <typename T, typename GT>\n\
    vector<vector<T>> floyd(GT &g) {\n  const T inf = numeric_limits<T>::max() / 2;\n\
    \  int n = g.n;\n  vector<vector<T>> dist(n, vector<T>(n, inf));\n  for (int i\
    \ = 0; i < n; i++) {\n    dist[i][i] = 0;\n    for (int id : g.g[i]) {\n     \
    \ auto e = g.edges[id];\n      dist[i][e.to] = min<T>(dist[i][e.to], e.cost);\n\
    \    }\n  }\n  for (int k = 0; k < n; k++) {\n    for (int i = 0; i < n; i++)\
    \ {\n      if (dist[i][k] == inf) continue;\n      for (int j = 0; j < n; j++)\
    \ {\n        if (dist[k][j] == inf) continue;\n        dist[i][j] = min(dist[i][j],\
    \ dist[i][k] + dist[k][j]);\n      }\n    }\n  }\n  return dist;\n}\n"
  code: "template <typename T, typename GT>\nvector<vector<T>> floyd(GT &g) {\n  const\
    \ T inf = numeric_limits<T>::max() / 2;\n  int n = g.n;\n  vector<vector<T>> dist(n,\
    \ vector<T>(n, inf));\n  for (int i = 0; i < n; i++) {\n    dist[i][i] = 0;\n\
    \    for (int id : g.g[i]) {\n      auto e = g.edges[id];\n      dist[i][e.to]\
    \ = min<T>(dist[i][e.to], e.cost);\n    }\n  }\n  for (int k = 0; k < n; k++)\
    \ {\n    for (int i = 0; i < n; i++) {\n      if (dist[i][k] == inf) continue;\n\
    \      for (int j = 0; j < n; j++) {\n        if (dist[k][j] == inf) continue;\n\
    \        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);\n      }\n   \
    \ }\n  }\n  return dist;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/floyd.hpp
  requiredBy: []
  timestamp: '2024-06-07 21:27:30+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/floyd.hpp
layout: document
redirect_from:
- /library/graph/floyd.hpp
- /library/graph/floyd.hpp.html
title: graph/floyd.hpp
---
