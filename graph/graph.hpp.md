---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/floyd.hpp
    title: graph/floyd.hpp
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
    \      edges.push_back(edge_type({to, from, cost, i}));\n    }\n  }\n};\n"
  code: "#pragma once\n\ntemplate <typename T> \nstruct Edge {\n  int from, to;\n\
    \  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool directed = false>\n\
    struct graph {\n  static constexpr bool is_directed = directed;\n  int n, m;\n\
    \  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n\
    \  vector<vector<int>> g;\n\n  graph(int _n) : n(_n), m(0) {\n    g.resize(n);\n\
    \  }\n\n  void add(int from, int to, T cost = 1, int i = -1) {\n    assert(0 <=\
    \ from && from < n && 0 <= to && to < n);\n    if (i == -1) i = m++;\n    g[from].push_back((int)\
    \ edges.size());\n    edges.push_back(edge_type({from, to, cost, i}));\n    if\
    \ (!is_directed) {\n      g[to].push_back((int) edges.size());\n      edges.push_back(edge_type({to,\
    \ from, cost, i}));\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph.hpp
  requiredBy:
  - graph/floyd.hpp
  timestamp: '2024-05-15 19:00:18+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph.hpp
layout: document
redirect_from:
- /library/graph/graph.hpp
- /library/graph/graph.hpp.html
title: graph/graph.hpp
---
