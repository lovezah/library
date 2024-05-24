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
  bundledCode: "#line 1 \"flows/flow.hpp\"\ntemplate <typename T = int64_t>\nstruct\
    \ flow {\n  struct edge {\n    int to;\n    T cap;\n    edge(int _to, T _cap)\
    \ : to(_to), cap(_cap) {}\n  };\n  int n;\n  vector<int> cur, lev;\n  vector<edge>\
    \ edges;\n  vector<vector<int>> g;\n  flow(int _n) : n(_n) {\n    g.resize(n);\n\
    \  }\n  void add(int from, int to, T c) {\n    g[from].push_back((int) edges.size());\n\
    \    edges.emplace_back(to, c);\n    g[to].push_back((int) edges.size());\n  \
    \  edges.emplace_back(from, 0);\n  }\n  bool bfs(int s, int t) {\n    lev.assign(n,\
    \ -1);\n    queue<int> que;\n    que.push(s);\n    lev[s] = 0;\n    while (!que.empty())\
    \ {\n      int u = que.front();\n      que.pop();\n      for (int i : g[u]) {\n\
    \        const auto &[v, c] = edges[i];\n        if (c > 0 && lev[v] == -1) {\n\
    \          lev[v] = lev[u] + 1;\n          if (v == t) {\n            return true;\n\
    \          }\n          que.push(v);\n        }\n      }\n    }\n    return false;\n\
    \  }\n  T dfs(int u, int t, T f) {\n    if (u == t) {\n      return f;\n    }\n\
    \    auto r = f;\n    for (int &i = cur[u]; i < (int) g[u].size(); i++) {\n  \
    \    const int j = g[u][i];\n      const auto &[v, c] = edges[j];\n      if (c\
    \ > 0 && lev[v] == lev[u] + 1) {\n        auto a = dfs(v, t, std::min(r, c));\n\
    \        edges[j].cap -= a;\n        edges[j ^ 1].cap += a;\n        r -= a;\n\
    \        if (r == 0) {\n          return f;\n        }\n      }\n    }\n    return\
    \ f - r;\n  }\n  T dinic(int s, int t) {\n    T ans = 0;\n    while (bfs(s, t))\
    \ {\n      cur.assign(n, 0);\n      ans += dfs(s, t, std::numeric_limits<T>::max());\n\
    \    }\n    return ans;\n  }\n};\n"
  code: "template <typename T = int64_t>\nstruct flow {\n  struct edge {\n    int\
    \ to;\n    T cap;\n    edge(int _to, T _cap) : to(_to), cap(_cap) {}\n  };\n \
    \ int n;\n  vector<int> cur, lev;\n  vector<edge> edges;\n  vector<vector<int>>\
    \ g;\n  flow(int _n) : n(_n) {\n    g.resize(n);\n  }\n  void add(int from, int\
    \ to, T c) {\n    g[from].push_back((int) edges.size());\n    edges.emplace_back(to,\
    \ c);\n    g[to].push_back((int) edges.size());\n    edges.emplace_back(from,\
    \ 0);\n  }\n  bool bfs(int s, int t) {\n    lev.assign(n, -1);\n    queue<int>\
    \ que;\n    que.push(s);\n    lev[s] = 0;\n    while (!que.empty()) {\n      int\
    \ u = que.front();\n      que.pop();\n      for (int i : g[u]) {\n        const\
    \ auto &[v, c] = edges[i];\n        if (c > 0 && lev[v] == -1) {\n          lev[v]\
    \ = lev[u] + 1;\n          if (v == t) {\n            return true;\n         \
    \ }\n          que.push(v);\n        }\n      }\n    }\n    return false;\n  }\n\
    \  T dfs(int u, int t, T f) {\n    if (u == t) {\n      return f;\n    }\n   \
    \ auto r = f;\n    for (int &i = cur[u]; i < (int) g[u].size(); i++) {\n     \
    \ const int j = g[u][i];\n      const auto &[v, c] = edges[j];\n      if (c >\
    \ 0 && lev[v] == lev[u] + 1) {\n        auto a = dfs(v, t, std::min(r, c));\n\
    \        edges[j].cap -= a;\n        edges[j ^ 1].cap += a;\n        r -= a;\n\
    \        if (r == 0) {\n          return f;\n        }\n      }\n    }\n    return\
    \ f - r;\n  }\n  T dinic(int s, int t) {\n    T ans = 0;\n    while (bfs(s, t))\
    \ {\n      cur.assign(n, 0);\n      ans += dfs(s, t, std::numeric_limits<T>::max());\n\
    \    }\n    return ans;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: flows/flow.hpp
  requiredBy: []
  timestamp: '2024-05-24 16:43:57+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flows/flow.hpp
layout: document
redirect_from:
- /library/flows/flow.hpp
- /library/flows/flow.hpp.html
title: flows/flow.hpp
---
