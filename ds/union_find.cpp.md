---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/union_find.cpp\"\n\nstruct union_find {\n  int n, comp;\n\
    \  vt<int> p;\n  union_find(int m = 0) {\n    init(m);\n  }\n  void init(int m)\
    \ {\n    n = m;\n    comp = m;\n    p.assign(n, -1);\n  }\n  void reset() { init(n);\
    \ }\n  int operator[](int x) {\n    while (p[x] >= 0) {\n      if (p[p[x]] >=\
    \ 0) p[x] = p[p[x]];\n      x = p[x];\n    }\n    return x;\n  }\n  bool merge(int\
    \ x, int y) {\n    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n\
    \    if (-p[x] < -p[y]) swap(x, y);\n    p[x] += p[y];\n    p[y] = x;\n    comp--;\n\
    \    return true;\n  }\n  ll size(int x) {\n    return -p[(*this)[x]];\n  }\n\
    \  vt<int> get_all() {\n    vt<int> par(n);\n    rep(i, n) par[i] = (*this)[i];\n\
    \    return par;\n  }\n};\n"
  code: "#pragma once\n\nstruct union_find {\n  int n, comp;\n  vt<int> p;\n  union_find(int\
    \ m = 0) {\n    init(m);\n  }\n  void init(int m) {\n    n = m;\n    comp = m;\n\
    \    p.assign(n, -1);\n  }\n  void reset() { init(n); }\n  int operator[](int\
    \ x) {\n    while (p[x] >= 0) {\n      if (p[p[x]] >= 0) p[x] = p[p[x]];\n   \
    \   x = p[x];\n    }\n    return x;\n  }\n  bool merge(int x, int y) {\n    x\
    \ = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n    if (-p[x]\
    \ < -p[y]) swap(x, y);\n    p[x] += p[y];\n    p[y] = x;\n    comp--;\n    return\
    \ true;\n  }\n  ll size(int x) {\n    return -p[(*this)[x]];\n  }\n  vt<int> get_all()\
    \ {\n    vt<int> par(n);\n    rep(i, n) par[i] = (*this)[i];\n    return par;\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/union_find.cpp
  requiredBy: []
  timestamp: '2024-05-08 17:23:17+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/union_find.cpp
layout: document
redirect_from:
- /library/ds/union_find.cpp
- /library/ds/union_find.cpp.html
title: ds/union_find.cpp
---
