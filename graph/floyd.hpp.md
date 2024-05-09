---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/abc073d.test.cpp
    title: test/atcoder/abc073d.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc073d.test.cpp
    title: test_atcoder/abc073d.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T> \nstruct Edge\
    \ {\n  int from, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = ll, bool\
    \ directed = false>\nstruct Graph {\n  static constexpr bool is_directed = directed;\n\
    \  bool prepared;\n  int n, m;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n\
    \  vt<edge_type> edges;\n  vt<int> indptr;\n  vt<edge_type> csr_edges;\n\n  class\
    \ outgoing_edges {\n   private:\n    const Graph* G;\n    int l, r;\n\n   public:\n\
    \    outgoing_edges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}\n    const\
    \ edge_type* begin() const {\n      if (l == r) return 0;\n      return &G->csr_edges[l];\n\
    \    }\n    const edge_type* end() const {\n      if (l == r) return 0;\n    \
    \  return &G->csr_edges[r];\n    }\n  };\n\n  Graph() : n(0), m(0), prepared(0)\
    \ {}\n  Graph(int n) : n(n), m(0), prepared(0) {}\n\n  void add(int from, int\
    \ to, T cost = 1, int i = -1) {\n    assert(0 <= from && from < n && 0 <= to &&\
    \ to < n);\n    if (i == -1) i = m;\n    auto e = edge_type({from, to, cost, i});\n\
    \    edges.eb(e);\n    ++m;\n  }\n\n  void read_tree(bool wt = false, int off\
    \ = 1) { read_graph(n - 1, wt, off); }\n  void read_graph(int mm, bool wt = false,\
    \ int off = 1) {\n    for (int i = 0; i < mm; i++) {\n      ints(a, b);\n    \
    \  a -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n      } else {\n\
    \        T c;\n        read(c);\n        add(a, b, c);\n      }\n    }\n    build();\n\
    \  }  \n  void build() {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(n\
    \ + 1, 0);\n    for (auto e : edges) {\n      indptr[e.from + 1]++;\n      if\
    \ (!directed) indptr[e.to + 1]++;\n    }\n    for (int u = 0; u < n; u++) indptr[u\
    \ + 1] += indptr[u];\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto e : edges) {\n      csr_edges[counter[e.from]++] = e;\n\
    \      if (!directed) {\n        csr_edges[counter[e.to]++] = edge_type({e.to,\
    \ e.from, e.cost, e.id});\n      }\n    }\n  }\n  outgoing_edges operator[](int\
    \ u) const {\n    assert(prepared);\n    return {this, indptr[u], indptr[u + 1]};\n\
    \  }\n};\n#line 3 \"graph/floyd.hpp\"\n\ntemplate <typename T, typename GT>\n\
    vt<vt<T>> floyd(GT &G) {\n  int n = G.n;\n  vv(T, dist, n, n, infty<T>);\n  rep(i,\
    \ n) {\n    dist[i][i] = 0;\n    for (auto e : G[i]) ckmin(dist[i][e.to], e.cost);\n\
    \  }\n  rep(k, n) rep(i, n) {\n    if (dist[i][k] == infty<T>) continue;\n   \
    \ rep(j, n) {\n      if (dist[k][j] == infty<T>) continue;\n      ckmin(dist[i][j],\
    \ dist[i][k] + dist[k][j]);\n    }\n  }\n  return dist;\n}\n"
  code: "#pragma once\n#include \"graph/base.hpp\"\n\ntemplate <typename T, typename\
    \ GT>\nvt<vt<T>> floyd(GT &G) {\n  int n = G.n;\n  vv(T, dist, n, n, infty<T>);\n\
    \  rep(i, n) {\n    dist[i][i] = 0;\n    for (auto e : G[i]) ckmin(dist[i][e.to],\
    \ e.cost);\n  }\n  rep(k, n) rep(i, n) {\n    if (dist[i][k] == infty<T>) continue;\n\
    \    rep(j, n) {\n      if (dist[k][j] == infty<T>) continue;\n      ckmin(dist[i][j],\
    \ dist[i][k] + dist[k][j]);\n    }\n  }\n  return dist;\n}\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/floyd.hpp
  requiredBy: []
  timestamp: '2024-05-10 00:32:11+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/atcoder/abc073d.test.cpp
  - test_atcoder/abc073d.test.cpp
documentation_of: graph/floyd.hpp
layout: document
redirect_from:
- /library/graph/floyd.hpp
- /library/graph/floyd.hpp.html
title: graph/floyd.hpp
---
