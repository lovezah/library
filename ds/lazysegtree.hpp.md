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
  bundledCode: "#line 1 \"ds/lazysegtree.hpp\"\ntemplate <class X, X(* op)(X, X),\
    \ X (*e)(), class F, X (*mapping)(X, F), F (*composition)(F, F), F (*id)()>\n\
    struct lazysegtree {\n  int n;\n  vector<X> v;\n  vector<F> lz;\n  lazysegtree(int\
    \ m = 0) {\n    init(vector<X>(m, e()));\n  }\n  lazysegtree(const vector<X> &dat)\
    \ {\n    init(dat);\n  }\n  void init(vector<X> dat) {\n    n = len(dat);\n  \
    \  v.assign(4 << (int)(log2(n)), e());\n    lz.assign(4 << (int)(log2(n)), id());\n\
    \    function<void(int, int, int)> build = [&](int p, int l, int r) {\n      if\
    \ (r - l == 1) {\n        v[p] = dat[l];\n        return;\n      }\n      int\
    \ m = (l + r) / 2;\n      build(p * 2, l, m);\n      build(p * 2 + 1, m, r);\n\
    \      pull(p);\n    };\n    build(1, 0, n);\n  }\n  void pull(int p) {\n    v[p]\
    \ = op(v[p * 2], v[p * 2 + 1]);\n  }\n  void all_apply(int p, F f) {\n    v[p]\
    \ = mapping(v[p], f);\n    lz[p] = composition(lz[p], f);\n  }\n  void push(int\
    \ p) {\n    all_apply(p * 2, lz[p]);\n    all_apply(p * 2 + 1, lz[p]);\n    lz[p]\
    \ = id();\n  }\n  void set(int p, int l, int r, int x, X c) {\n    if (r - l ==\
    \ 1) {\n      v[p] = c;\n      return;\n    }\n    push(p);\n    int m = (l +\
    \ r) / 2;\n    if (x < m) set(p * 2, l, m, x, c);\n    else set(p * 2 + 1, m,\
    \ r, x, c);\n    pull(p);\n  }\n  void apply(int p, int l, int r, int x, F f)\
    \ {\n    if (r - l == 1) {\n      all_apply(p, f);\n      return;\n    }\n   \
    \ push(p);\n    int m = (l + r) / 2;\n    if (x < m) apply(p * 2, l, m, x, f);\n\
    \    else apply(p * 2 + 1, m, r, x, f);\n    pull(p);\n  }\n  void apply(int p,\
    \ int l, int r, int ql, int qr, F f) {\n    if (qr <= l || r <= ql) return;\n\
    \    if (ql <= l && r <= qr) {\n      all_apply(p, f);\n      return;\n    }\n\
    \    push(p);\n    int m = (l + r) / 2;\n    apply(p * 2, l, m, ql, qr, f);\n\
    \    apply(p * 2 + 1, m, r, ql, qr, f);\n    pull(p);\n  }\n  X get(int p, int\
    \ l, int r, int x) {\n    if (r - l == 1) {\n      return v[p];\n    }\n    push(p);\n\
    \    int m = (l + r) / 2;\n    if (x < m) return get(p * 2, l, m, x);\n    else\
    \ return get(p * 2 + 1, m, r, x);\n  }\n  X query(int p, int l, int r, int ql,\
    \ int qr) {\n    if (qr <= l || r <= ql) return e();\n    if (ql <= l && r <=\
    \ qr) return v[p];\n    push(p);\n    int m = (l + r) / 2;\n    return op(query(p\
    \ * 2, l, m, ql, qr), query(p * 2 + 1, m, r, ql, qr));\n  }\n  template <class\
    \ F>\n  int find_first(int p, int l, int r, int ql, int qr, F &f) {\n    if (qr\
    \ <= l || r <= ql) return -1;\n    if (ql <= l && r <= qr && !f(v[p])) return\
    \ -1;\n    if (r - l == 1) return l;\n    push(p);\n    int m = (l + r) / 2;\n\
    \    int res = find_first(p * 2, l, m, ql, qr, f);\n    if (res == -1) {\n   \
    \   res = find_first(p * 2 + 1, m, r, ql, qr, f);\n    }\n    return res;\n  }\n\
    \  template <class F>\n  int find_last(int p, int l, int r, int ql, int qr, F\
    \ &f) {\n    if (qr <= l || r <= ql) return -1;\n    if (ql <= l && r <= qr &&\
    \ !f(v[p])) return -1;\n    if (r - l == 1) return l;\n    push(p);\n    int m\
    \ = (l + r) / 2;\n    int res = find_last(p * 2 + 1, m, r, ql, qr, f);\n    if\
    \ (res == -1) {\n      res = find_last(p * 2, l, m, ql, qr, f);\n    }\n    return\
    \ res;\n  }\n  // public \n  void set(int p, X x) {\n    assert(0 <= p && p <\
    \ n);\n    set(1, 0, n, p, x);\n  }\n  void apply(int p, F f) {\n    assert(0\
    \ <= p && p < n);\n    apply(1, 0, n, p, f);\n  }\n  void apply(int l, int r,\
    \ F f) {\n    assert(0 <= l && l < r && r <= n);\n    apply(1, 0, n, l, r, f);\n\
    \  }\n  X get(int p) {\n    assert(0 <= p && p < n);\n    return get(1, 0, n,\
    \ p);\n  }\n  X query(int l, int r) {\n    assert(0 <= l && l < r && r <= n);\n\
    \    return query(1, 0, n, l, r);\n  }\n  template <class F>\n  int find_first(int\
    \ l, int r, F &f) {\n    assert(0 <= l && l < r && r <= n);\n    return find_first(1,\
    \ 0, n, l, r, f);\n  }\n  template <class F>\n  int find_last(int l, int r, F\
    \ &f) {\n    assert(0 <= l && l < r && r <= n);\n    return find_last(1, 0, n,\
    \ l, r, f);\n  }\n};\n"
  code: "template <class X, X(* op)(X, X), X (*e)(), class F, X (*mapping)(X, F),\
    \ F (*composition)(F, F), F (*id)()>\nstruct lazysegtree {\n  int n;\n  vector<X>\
    \ v;\n  vector<F> lz;\n  lazysegtree(int m = 0) {\n    init(vector<X>(m, e()));\n\
    \  }\n  lazysegtree(const vector<X> &dat) {\n    init(dat);\n  }\n  void init(vector<X>\
    \ dat) {\n    n = len(dat);\n    v.assign(4 << (int)(log2(n)), e());\n    lz.assign(4\
    \ << (int)(log2(n)), id());\n    function<void(int, int, int)> build = [&](int\
    \ p, int l, int r) {\n      if (r - l == 1) {\n        v[p] = dat[l];\n      \
    \  return;\n      }\n      int m = (l + r) / 2;\n      build(p * 2, l, m);\n \
    \     build(p * 2 + 1, m, r);\n      pull(p);\n    };\n    build(1, 0, n);\n \
    \ }\n  void pull(int p) {\n    v[p] = op(v[p * 2], v[p * 2 + 1]);\n  }\n  void\
    \ all_apply(int p, F f) {\n    v[p] = mapping(v[p], f);\n    lz[p] = composition(lz[p],\
    \ f);\n  }\n  void push(int p) {\n    all_apply(p * 2, lz[p]);\n    all_apply(p\
    \ * 2 + 1, lz[p]);\n    lz[p] = id();\n  }\n  void set(int p, int l, int r, int\
    \ x, X c) {\n    if (r - l == 1) {\n      v[p] = c;\n      return;\n    }\n  \
    \  push(p);\n    int m = (l + r) / 2;\n    if (x < m) set(p * 2, l, m, x, c);\n\
    \    else set(p * 2 + 1, m, r, x, c);\n    pull(p);\n  }\n  void apply(int p,\
    \ int l, int r, int x, F f) {\n    if (r - l == 1) {\n      all_apply(p, f);\n\
    \      return;\n    }\n    push(p);\n    int m = (l + r) / 2;\n    if (x < m)\
    \ apply(p * 2, l, m, x, f);\n    else apply(p * 2 + 1, m, r, x, f);\n    pull(p);\n\
    \  }\n  void apply(int p, int l, int r, int ql, int qr, F f) {\n    if (qr <=\
    \ l || r <= ql) return;\n    if (ql <= l && r <= qr) {\n      all_apply(p, f);\n\
    \      return;\n    }\n    push(p);\n    int m = (l + r) / 2;\n    apply(p * 2,\
    \ l, m, ql, qr, f);\n    apply(p * 2 + 1, m, r, ql, qr, f);\n    pull(p);\n  }\n\
    \  X get(int p, int l, int r, int x) {\n    if (r - l == 1) {\n      return v[p];\n\
    \    }\n    push(p);\n    int m = (l + r) / 2;\n    if (x < m) return get(p *\
    \ 2, l, m, x);\n    else return get(p * 2 + 1, m, r, x);\n  }\n  X query(int p,\
    \ int l, int r, int ql, int qr) {\n    if (qr <= l || r <= ql) return e();\n \
    \   if (ql <= l && r <= qr) return v[p];\n    push(p);\n    int m = (l + r) /\
    \ 2;\n    return op(query(p * 2, l, m, ql, qr), query(p * 2 + 1, m, r, ql, qr));\n\
    \  }\n  template <class F>\n  int find_first(int p, int l, int r, int ql, int\
    \ qr, F &f) {\n    if (qr <= l || r <= ql) return -1;\n    if (ql <= l && r <=\
    \ qr && !f(v[p])) return -1;\n    if (r - l == 1) return l;\n    push(p);\n  \
    \  int m = (l + r) / 2;\n    int res = find_first(p * 2, l, m, ql, qr, f);\n \
    \   if (res == -1) {\n      res = find_first(p * 2 + 1, m, r, ql, qr, f);\n  \
    \  }\n    return res;\n  }\n  template <class F>\n  int find_last(int p, int l,\
    \ int r, int ql, int qr, F &f) {\n    if (qr <= l || r <= ql) return -1;\n   \
    \ if (ql <= l && r <= qr && !f(v[p])) return -1;\n    if (r - l == 1) return l;\n\
    \    push(p);\n    int m = (l + r) / 2;\n    int res = find_last(p * 2 + 1, m,\
    \ r, ql, qr, f);\n    if (res == -1) {\n      res = find_last(p * 2, l, m, ql,\
    \ qr, f);\n    }\n    return res;\n  }\n  // public \n  void set(int p, X x) {\n\
    \    assert(0 <= p && p < n);\n    set(1, 0, n, p, x);\n  }\n  void apply(int\
    \ p, F f) {\n    assert(0 <= p && p < n);\n    apply(1, 0, n, p, f);\n  }\n  void\
    \ apply(int l, int r, F f) {\n    assert(0 <= l && l < r && r <= n);\n    apply(1,\
    \ 0, n, l, r, f);\n  }\n  X get(int p) {\n    assert(0 <= p && p < n);\n    return\
    \ get(1, 0, n, p);\n  }\n  X query(int l, int r) {\n    assert(0 <= l && l < r\
    \ && r <= n);\n    return query(1, 0, n, l, r);\n  }\n  template <class F>\n \
    \ int find_first(int l, int r, F &f) {\n    assert(0 <= l && l < r && r <= n);\n\
    \    return find_first(1, 0, n, l, r, f);\n  }\n  template <class F>\n  int find_last(int\
    \ l, int r, F &f) {\n    assert(0 <= l && l < r && r <= n);\n    return find_last(1,\
    \ 0, n, l, r, f);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/lazysegtree.hpp
  requiredBy: []
  timestamp: '2024-06-11 04:33:23+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/lazysegtree.hpp
layout: document
redirect_from:
- /library/ds/lazysegtree.hpp
- /library/ds/lazysegtree.hpp.html
title: ds/lazysegtree.hpp
---
