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
  bundledCode: "#line 1 \"graph/find_scc.hpp\"\nvector<vector<int>> find_scc(const\
    \ vector<vector<int>> &g) {\n  int n = (int) g.size();\n  vector<int> tin(n),\
    \ low(n), in_stack(n), stack;\n  vector<vector<int>> res;\n  int timer = 0;\n\
    \  \n  function<void(int)> dfs = [&](int v) {\n    tin[v] = low[v] = ++timer;\n\
    \    stack.push_back(v);\n    in_stack[v] = true;\n    for (int u : g[v]) {\n\
    \      if (!tin[u]) {\n        dfs(u);\n        low[v] = min(low[v], low[u]);\n\
    \      } else if (in_stack[u]) {\n        low[v] = min(low[v], tin[u]);\n    \
    \  }\n    }\n    if (low[v] == tin[v]) {\n      vector<int> r;\n      while (true)\
    \ {\n        int u = stack.back();\n        stack.pop_back();\n        r.push_back(u);\n\
    \        in_stack[u] = false;\n        if (u == v) break;\n      }\n      res.push_back(r);\n\
    \    }\n  };\n\n  for (int i = 0; i < n; i++) {\n    if (tin[i] == 0) {\n    \
    \  dfs(i);\n    }\n  }\n\n  return res;\n}\n"
  code: "vector<vector<int>> find_scc(const vector<vector<int>> &g) {\n  int n = (int)\
    \ g.size();\n  vector<int> tin(n), low(n), in_stack(n), stack;\n  vector<vector<int>>\
    \ res;\n  int timer = 0;\n  \n  function<void(int)> dfs = [&](int v) {\n    tin[v]\
    \ = low[v] = ++timer;\n    stack.push_back(v);\n    in_stack[v] = true;\n    for\
    \ (int u : g[v]) {\n      if (!tin[u]) {\n        dfs(u);\n        low[v] = min(low[v],\
    \ low[u]);\n      } else if (in_stack[u]) {\n        low[v] = min(low[v], tin[u]);\n\
    \      }\n    }\n    if (low[v] == tin[v]) {\n      vector<int> r;\n      while\
    \ (true) {\n        int u = stack.back();\n        stack.pop_back();\n       \
    \ r.push_back(u);\n        in_stack[u] = false;\n        if (u == v) break;\n\
    \      }\n      res.push_back(r);\n    }\n  };\n\n  for (int i = 0; i < n; i++)\
    \ {\n    if (tin[i] == 0) {\n      dfs(i);\n    }\n  }\n\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/find_scc.hpp
  requiredBy: []
  timestamp: '2024-06-29 12:36:30+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/find_scc.hpp
layout: document
redirect_from:
- /library/graph/find_scc.hpp
- /library/graph/find_scc.hpp.html
title: graph/find_scc.hpp
---
