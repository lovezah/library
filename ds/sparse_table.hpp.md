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
  bundledCode: "#line 1 \"ds/sparse_table.hpp\"\ntemplate <typename T, bool maximum\
    \ = false>\nstruct sparse_table {\n  static int highest_bit(int x) {\n    return\
    \ (x == 0 ? -1 : 31 - __builtin_clz(x));\n  }\n  int n;\n  vector<T> vals;\n \
    \ vector<vector<int>> f;\n  \n  sparse_table(const vector<T> &_vals = {}) {\n\
    \    init(_vals);\n  }\n  int better_index(int x, int y) {\n    if (maximum) return\
    \ (vals[x] < vals[y] ? y : x);\n    else return (vals[x] < vals[y] ? x : y);\n\
    \  }\n  void init(const vector<T> &_vals) {\n    vals = _vals;\n    n = (int)\
    \ vals.size();\n    int level = highest_bit(n) + 1;\n    f = vector<vector<int>>(level,\
    \ vector<int>(n));\n    for (int i = 0; i < n; i++) {\n      f[0][i] = i;\n  \
    \  }\n    for (int b = 1; b < level; b++) {\n      for (int i = 0; i + (1 << b)\
    \ - 1 < n; i++) {\n        f[b][i] = better_index(f[b - 1][i], f[b - 1][i + (1\
    \ << (b - 1))]);\n      }\n    }\n  }\n  int query_index(int x, int y) {\n   \
    \ assert(0 <= x && x < y && y <= n);\n    int level = highest_bit(y - x);\n  \
    \  return better_index(f[level][x], f[level][y - (1 << level)]);\n  }\n  T query_value(int\
    \ x, int y) {\n    return vals[query_index(x, y)];\n  }\n};\n"
  code: "template <typename T, bool maximum = false>\nstruct sparse_table {\n  static\
    \ int highest_bit(int x) {\n    return (x == 0 ? -1 : 31 - __builtin_clz(x));\n\
    \  }\n  int n;\n  vector<T> vals;\n  vector<vector<int>> f;\n  \n  sparse_table(const\
    \ vector<T> &_vals = {}) {\n    init(_vals);\n  }\n  int better_index(int x, int\
    \ y) {\n    if (maximum) return (vals[x] < vals[y] ? y : x);\n    else return\
    \ (vals[x] < vals[y] ? x : y);\n  }\n  void init(const vector<T> &_vals) {\n \
    \   vals = _vals;\n    n = (int) vals.size();\n    int level = highest_bit(n)\
    \ + 1;\n    f = vector<vector<int>>(level, vector<int>(n));\n    for (int i =\
    \ 0; i < n; i++) {\n      f[0][i] = i;\n    }\n    for (int b = 1; b < level;\
    \ b++) {\n      for (int i = 0; i + (1 << b) - 1 < n; i++) {\n        f[b][i]\
    \ = better_index(f[b - 1][i], f[b - 1][i + (1 << (b - 1))]);\n      }\n    }\n\
    \  }\n  int query_index(int x, int y) {\n    assert(0 <= x && x < y && y <= n);\n\
    \    int level = highest_bit(y - x);\n    return better_index(f[level][x], f[level][y\
    \ - (1 << level)]);\n  }\n  T query_value(int x, int y) {\n    return vals[query_index(x,\
    \ y)];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/sparse_table.hpp
  requiredBy: []
  timestamp: '2024-06-07 21:25:28+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/sparse_table.hpp
layout: document
redirect_from:
- /library/ds/sparse_table.hpp
- /library/ds/sparse_table.hpp.html
title: ds/sparse_table.hpp
---
