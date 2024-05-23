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
  bundledCode: "#line 1 \"ds/fenwick.hpp\"\ntemplate <typename T>\nstruct fenwick\
    \ {\n  int n;\n  vector<T> fen;\n  fenwick(int _n) : n(_n) {\n    fen.resize(n);\n\
    \  }\n  void modify(int x, T v) {\n    assert(0 <= x && x < n);\n    for (int\
    \ i = x + 1; i <= n; i += i & -i) {\n      fen[i - 1] += v;\n    }\n  }\n  T query(int\
    \ r) {\n    T res = 0;\n    for (int i = r; i > 0; i -= i & -i) {\n      res +=\
    \ fen[i - 1];\n    }\n    return res;\n  }\n  T query(int l, int r) {\n    assert(0\
    \ <= l && l <= r && r <= n);\n    return query(r) - query(l);\n  }\n  int kth(const\
    \ T &k) {\n    int x = 0;\n    T res = 0;\n    for (int d = 1 << (int) log2(n);\
    \ d > 0; d /= 2) {\n      if (x + d <= n && res + fen[x + d - 1] <= k) {\n   \
    \     x += d;\n        res += fen[x - 1];\n      }\n    }\n    return x;\n  }\n\
    };\n"
  code: "template <typename T>\nstruct fenwick {\n  int n;\n  vector<T> fen;\n  fenwick(int\
    \ _n) : n(_n) {\n    fen.resize(n);\n  }\n  void modify(int x, T v) {\n    assert(0\
    \ <= x && x < n);\n    for (int i = x + 1; i <= n; i += i & -i) {\n      fen[i\
    \ - 1] += v;\n    }\n  }\n  T query(int r) {\n    T res = 0;\n    for (int i =\
    \ r; i > 0; i -= i & -i) {\n      res += fen[i - 1];\n    }\n    return res;\n\
    \  }\n  T query(int l, int r) {\n    assert(0 <= l && l <= r && r <= n);\n   \
    \ return query(r) - query(l);\n  }\n  int kth(const T &k) {\n    int x = 0;\n\
    \    T res = 0;\n    for (int d = 1 << (int) log2(n); d > 0; d /= 2) {\n     \
    \ if (x + d <= n && res + fen[x + d - 1] <= k) {\n        x += d;\n        res\
    \ += fen[x - 1];\n      }\n    }\n    return x;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/fenwick.hpp
  requiredBy: []
  timestamp: '2024-05-23 16:48:28+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/fenwick.hpp
layout: document
redirect_from:
- /library/ds/fenwick.hpp
- /library/ds/fenwick.hpp.html
title: ds/fenwick.hpp
---
