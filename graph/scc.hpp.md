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
  bundledCode: "#line 1 \"graph/scc.hpp\"\ntemplate <typename GT>\nvector<int> find_scc(const\
    \ GT &g, int &cnt) {\n  int n = g.n;\n  cnt = 0;\n  vector<int> done(n);\n  vector<int>\
    \ dfn(n);\n  vector<int> bel(n);\n  vector<int> stack;\n  auto dfs = [&](auto\
    \ self, int v) -> int {\n    int low = dfn[v] = (int) stack.size();\n    stack.push_back(v);\n\
    \    for (const auto &i : g.g[v]) {\n      int u = g.edges[i].to;\n      if (!done[u])\
    \ low = min(low, !dfn[u] ? self(self, u) : dfn[u]);\n    }\n    if (low == dfn[v])\
    \ {\n      vector<int> who{stack.begin() + low, stack.end()};\n      for (int\
    \ w : who) done[w] = true, bel[w] = cnt;\n      stack.resize(low);\n      ++cnt;\n\
    \    }\n    return low;\n  };\n  for (int i = 0; i < n; i++) {\n    if (!done[i])\
    \ {\n      dfs(dfs, i);\n    }\n  }\n  return bel;\n}\n"
  code: "template <typename GT>\nvector<int> find_scc(const GT &g, int &cnt) {\n \
    \ int n = g.n;\n  cnt = 0;\n  vector<int> done(n);\n  vector<int> dfn(n);\n  vector<int>\
    \ bel(n);\n  vector<int> stack;\n  auto dfs = [&](auto self, int v) -> int {\n\
    \    int low = dfn[v] = (int) stack.size();\n    stack.push_back(v);\n    for\
    \ (const auto &i : g.g[v]) {\n      int u = g.edges[i].to;\n      if (!done[u])\
    \ low = min(low, !dfn[u] ? self(self, u) : dfn[u]);\n    }\n    if (low == dfn[v])\
    \ {\n      vector<int> who{stack.begin() + low, stack.end()};\n      for (int\
    \ w : who) done[w] = true, bel[w] = cnt;\n      stack.resize(low);\n      ++cnt;\n\
    \    }\n    return low;\n  };\n  for (int i = 0; i < n; i++) {\n    if (!done[i])\
    \ {\n      dfs(dfs, i);\n    }\n  }\n  return bel;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/scc.hpp
  requiredBy: []
  timestamp: '2024-06-13 12:32:35+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/scc.hpp
layout: document
redirect_from:
- /library/graph/scc.hpp
- /library/graph/scc.hpp.html
title: graph/scc.hpp
---
