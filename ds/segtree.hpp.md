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
  bundledCode: "#line 1 \"ds/segtree.hpp\"\ntemplate <class X, X(* op)(X, X), X (*e)()>\n\
    struct segtree {\n  int n;\n  vector<X> v;\n  segtree(int m = 0) {\n    init(vector<X>(m,\
    \ e()));\n  }\n  segtree(const vector<X> &dat) {\n    init(dat);\n  }\n  void\
    \ init(vector<X> dat) {\n    n = len(dat);\n    v.assign(4 << (int)(log2(n)),\
    \ e());\n    function<void(int, int, int)> build = [&](int p, int l, int r) {\n\
    \      if (r - l == 1) {\n        v[p] = dat[l];\n        return;\n      }\n \
    \     int m = (l + r) / 2;\n      build(p * 2, l, m);\n      build(p * 2 + 1,\
    \ m, r);\n      pull(p);\n    };\n    build(1, 0, n);\n  }\n  void pull(int p)\
    \ {\n    v[p] = op(v[p * 2], v[p * 2 + 1]);\n  }\n  void set(int p, int l, int\
    \ r, int x, X c) {\n    if (r - l == 1) {\n      v[p] = c;\n      return;\n  \
    \  }\n    int m = (l + r) / 2;\n    if (x < m) set(p * 2, l, m, x, c);\n    else\
    \ set(p * 2 + 1, m, r, x, c);\n    pull(p);\n  }\n  void add(int p, int l, int\
    \ r, int x, X c) {\n    if (r - l == 1) {\n      v[p] += c;\n      return;\n \
    \   }\n    int m = (l + r) / 2;\n    if (x < m) add(p * 2, l, m, x, c);\n    else\
    \ add(p * 2 + 1, m, r, x, c);\n    pull(p);\n  }\n  X get(int p, int l, int r,\
    \ int x) {\n    if (r - l == 1) {\n      return v[p];\n    }\n    int m = (l +\
    \ r) / 2;\n    if (x < m) return get(p * 2, l, m, x);\n    else return get(p *\
    \ 2 + 1, m, r, x);\n  }\n  X query(int p, int l, int r, int ql, int qr) {\n  \
    \  if (qr <= l || r <= ql) return e();\n    if (ql <= l && r <= qr) return v[p];\n\
    \    int m = (l + r) / 2;\n    return op(query(p * 2, l, m, ql, qr), query(p *\
    \ 2 + 1, m, r, ql, qr));\n  }\n  X all() {\n    return v[1];\n  }\n  template\
    \ <class F>\n  int find_first(int p, int l, int r, int ql, int qr, F &f) {\n \
    \   if (qr <= l || r <= ql) return -1;\n    if (ql <= l && r <= qr && !f(v[p]))\
    \ return -1;\n    if (r - l == 1) return l;\n    int m = (l + r) / 2;\n    int\
    \ res = find_first(p * 2, l, m, ql, qr, f);\n    if (res == -1) {\n      res =\
    \ find_first(p * 2 + 1, m, r, ql, qr, f);\n    }\n    return res;\n  }\n  template\
    \ <class F>\n  int find_last(int p, int l, int r, int ql, int qr, F &f) {\n  \
    \  if (qr <= l || r <= ql) return -1;\n    if (ql <= l && r <= qr && !f(v[p]))\
    \ return -1;\n    if (r - l == 1) return l;\n    int m = (l + r) / 2;\n    int\
    \ res = find_last(p * 2 + 1, m, r, ql, qr, f);\n    if (res == -1) {\n      res\
    \ = find_last(p * 2, l, m, ql, qr, f);\n    }\n    return res;\n  }\n  // public\
    \ \n  void set(int p, X x) {\n    assert(0 <= p && p < n);\n    set(1, 0, n, p,\
    \ x);\n  }  \n  void add(int p, X x) {\n    assert(0 <= p && p < n);\n    add(1,\
    \ 0, n, p, x);\n  }\n  X get(int p) {\n    assert(0 <= p && p < n);\n    return\
    \ get(1, 0, n, p);\n  }\n  X query(int l, int r) {\n    assert(0 <= l && l < r\
    \ && r <= n);\n    return query(1, 0, n, l, r);\n  }\n  template <class F>\n \
    \ int find_first(int l, int r, F &f) {\n    assert(0 <= l && l < r && r <= n);\n\
    \    return find_first(1, 0, n, l, r, f);\n  }\n  template <class F>\n  int find_last(int\
    \ l, int r, F &f) {\n    assert(0 <= l && l < r && r <= n);\n    return find_last(1,\
    \ 0, n, l, r, f);\n  }\n};\n"
  code: "template <class X, X(* op)(X, X), X (*e)()>\nstruct segtree {\n  int n;\n\
    \  vector<X> v;\n  segtree(int m = 0) {\n    init(vector<X>(m, e()));\n  }\n \
    \ segtree(const vector<X> &dat) {\n    init(dat);\n  }\n  void init(vector<X>\
    \ dat) {\n    n = len(dat);\n    v.assign(4 << (int)(log2(n)), e());\n    function<void(int,\
    \ int, int)> build = [&](int p, int l, int r) {\n      if (r - l == 1) {\n   \
    \     v[p] = dat[l];\n        return;\n      }\n      int m = (l + r) / 2;\n \
    \     build(p * 2, l, m);\n      build(p * 2 + 1, m, r);\n      pull(p);\n   \
    \ };\n    build(1, 0, n);\n  }\n  void pull(int p) {\n    v[p] = op(v[p * 2],\
    \ v[p * 2 + 1]);\n  }\n  void set(int p, int l, int r, int x, X c) {\n    if (r\
    \ - l == 1) {\n      v[p] = c;\n      return;\n    }\n    int m = (l + r) / 2;\n\
    \    if (x < m) set(p * 2, l, m, x, c);\n    else set(p * 2 + 1, m, r, x, c);\n\
    \    pull(p);\n  }\n  void add(int p, int l, int r, int x, X c) {\n    if (r -\
    \ l == 1) {\n      v[p] += c;\n      return;\n    }\n    int m = (l + r) / 2;\n\
    \    if (x < m) add(p * 2, l, m, x, c);\n    else add(p * 2 + 1, m, r, x, c);\n\
    \    pull(p);\n  }\n  X get(int p, int l, int r, int x) {\n    if (r - l == 1)\
    \ {\n      return v[p];\n    }\n    int m = (l + r) / 2;\n    if (x < m) return\
    \ get(p * 2, l, m, x);\n    else return get(p * 2 + 1, m, r, x);\n  }\n  X query(int\
    \ p, int l, int r, int ql, int qr) {\n    if (qr <= l || r <= ql) return e();\n\
    \    if (ql <= l && r <= qr) return v[p];\n    int m = (l + r) / 2;\n    return\
    \ op(query(p * 2, l, m, ql, qr), query(p * 2 + 1, m, r, ql, qr));\n  }\n  X all()\
    \ {\n    return v[1];\n  }\n  template <class F>\n  int find_first(int p, int\
    \ l, int r, int ql, int qr, F &f) {\n    if (qr <= l || r <= ql) return -1;\n\
    \    if (ql <= l && r <= qr && !f(v[p])) return -1;\n    if (r - l == 1) return\
    \ l;\n    int m = (l + r) / 2;\n    int res = find_first(p * 2, l, m, ql, qr,\
    \ f);\n    if (res == -1) {\n      res = find_first(p * 2 + 1, m, r, ql, qr, f);\n\
    \    }\n    return res;\n  }\n  template <class F>\n  int find_last(int p, int\
    \ l, int r, int ql, int qr, F &f) {\n    if (qr <= l || r <= ql) return -1;\n\
    \    if (ql <= l && r <= qr && !f(v[p])) return -1;\n    if (r - l == 1) return\
    \ l;\n    int m = (l + r) / 2;\n    int res = find_last(p * 2 + 1, m, r, ql, qr,\
    \ f);\n    if (res == -1) {\n      res = find_last(p * 2, l, m, ql, qr, f);\n\
    \    }\n    return res;\n  }\n  // public \n  void set(int p, X x) {\n    assert(0\
    \ <= p && p < n);\n    set(1, 0, n, p, x);\n  }  \n  void add(int p, X x) {\n\
    \    assert(0 <= p && p < n);\n    add(1, 0, n, p, x);\n  }\n  X get(int p) {\n\
    \    assert(0 <= p && p < n);\n    return get(1, 0, n, p);\n  }\n  X query(int\
    \ l, int r) {\n    assert(0 <= l && l < r && r <= n);\n    return query(1, 0,\
    \ n, l, r);\n  }\n  template <class F>\n  int find_first(int l, int r, F &f) {\n\
    \    assert(0 <= l && l < r && r <= n);\n    return find_first(1, 0, n, l, r,\
    \ f);\n  }\n  template <class F>\n  int find_last(int l, int r, F &f) {\n    assert(0\
    \ <= l && l < r && r <= n);\n    return find_last(1, 0, n, l, r, f);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree.hpp
  requiredBy: []
  timestamp: '2024-06-11 15:09:35+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree.hpp
- /library/ds/segtree.hpp.html
title: ds/segtree.hpp
---
