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
  bundledCode: "#line 2 \"ds/union_find.hpp\"\n\nstruct union_find {\n  int n, comp;\n\
    \  vector<int> p;\n  union_find(int m = 0) : n(m) {\n    p.assign(n, -1);\n  }\n\
    \  int get(int x) {\n    while (p[x] >= 0) {\n      if (p[p[x]] >= 0) p[x] = p[p[x]];\n\
    \      x = p[x];\n    }\n    return x;\n  }\n  bool merge(int x, int y) {\n  \
    \  x = get(x), y = get(y);\n    if (x == y) return false;\n    if (-p[x] < -p[y])\
    \ swap(x, y);\n    p[x] += p[y];\n    p[y] = x;\n    comp--;\n    return true;\n\
    \  }\n  int size(int x) {\n    x = get(x);\n    return -p[x];\n  }\n};\n"
  code: "#pragma once\n\nstruct union_find {\n  int n, comp;\n  vector<int> p;\n \
    \ union_find(int m = 0) : n(m) {\n    p.assign(n, -1);\n  }\n  int get(int x)\
    \ {\n    while (p[x] >= 0) {\n      if (p[p[x]] >= 0) p[x] = p[p[x]];\n      x\
    \ = p[x];\n    }\n    return x;\n  }\n  bool merge(int x, int y) {\n    x = get(x),\
    \ y = get(y);\n    if (x == y) return false;\n    if (-p[x] < -p[y]) swap(x, y);\n\
    \    p[x] += p[y];\n    p[y] = x;\n    comp--;\n    return true;\n  }\n  int size(int\
    \ x) {\n    x = get(x);\n    return -p[x];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/union_find.hpp
  requiredBy: []
  timestamp: '2024-05-15 16:33:34+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/union_find.hpp
layout: document
redirect_from:
- /library/ds/union_find.hpp
- /library/ds/union_find.hpp.html
title: ds/union_find.hpp
---
