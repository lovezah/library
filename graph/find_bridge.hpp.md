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
  bundledCode: "#line 1 \"graph/find_bridge.hpp\"\nvector<int> find_bridge(const vector<vector<pair<int,\
    \ int>>> &g) {\n  int n = (int) g.size();\n  vector<int> tin(n), low(n), in_stack(n),\
    \ stack;\n  vector<int> res;\n  int timer = 0;\n  \n  function<void(int, int)>\
    \ dfs = [&](int v, int pid) {\n    tin[v] = low[v] = ++timer;\n    stack.push_back(v);\n\
    \    in_stack[v] = true;\n    for (int u : g[v]) {\n      if (!tin[u]) {\n   \
    \     dfs(u);\n        low[v] = min(low[v], low[u]);\n      } else if (in_stack[u])\
    \ {\n        low[v] = min(low[v], tin[u]);\n      }\n    }\n    if (low[v] ==\
    \ tin[v] && pid != -1) {\n      res.push_back(pid);\n    }\n  };\n\n  for (int\
    \ i = 0; i < n; i++) {\n    if (tin[i] == 0) {\n      dfs(i, -1);\n    }\n  }\n\
    \n  return res;\n}\n"
  code: "vector<int> find_bridge(const vector<vector<pair<int, int>>> &g) {\n  int\
    \ n = (int) g.size();\n  vector<int> tin(n), low(n), in_stack(n), stack;\n  vector<int>\
    \ res;\n  int timer = 0;\n  \n  function<void(int, int)> dfs = [&](int v, int\
    \ pid) {\n    tin[v] = low[v] = ++timer;\n    stack.push_back(v);\n    in_stack[v]\
    \ = true;\n    for (int u : g[v]) {\n      if (!tin[u]) {\n        dfs(u);\n \
    \       low[v] = min(low[v], low[u]);\n      } else if (in_stack[u]) {\n     \
    \   low[v] = min(low[v], tin[u]);\n      }\n    }\n    if (low[v] == tin[v] &&\
    \ pid != -1) {\n      res.push_back(pid);\n    }\n  };\n\n  for (int i = 0; i\
    \ < n; i++) {\n    if (tin[i] == 0) {\n      dfs(i, -1);\n    }\n  }\n\n  return\
    \ res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/find_bridge.hpp
  requiredBy: []
  timestamp: '2024-06-29 12:36:30+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/find_bridge.hpp
layout: document
redirect_from:
- /library/graph/find_bridge.hpp
- /library/graph/find_bridge.hpp.html
title: graph/find_bridge.hpp
---
