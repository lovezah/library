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
  bundledCode: "#line 1 \"ds/atcoder_segtree.hpp\"\nnamespace atcoder {\n\nnamespace\
    \ internal {\n\nunsigned int bit_ceil(unsigned int n) {\n  unsigned int x = 1;\n\
    \  while (x < (unsigned int)(n)) x *= 2;\n  return x;\n}\n\n} // namespace internal\n\
    \ntemplate <class S, S (*op)(S, S), S (*e)()> struct segtree {\n  public:\n  \
    \  segtree() : segtree(0) {}\n    explicit segtree(int n) : segtree(std::vector<S>(n,\
    \ e())) {}\n    explicit segtree(const std::vector<S>& v) : _n(int(v.size()))\
    \ {\n      size = (int)internal::bit_ceil((unsigned int)(_n));\n      log = internal::countr_zero((unsigned\
    \ int)size);\n      d = std::vector<S>(2 * size, e());\n      for (int i = 0;\
    \ i < _n; i++) d[size + i] = v[i];\n      for (int i = size - 1; i >= 1; i--)\
    \ {\n        update(i);\n      }\n    }\n\n    void set(int p, S x) {\n      assert(0\
    \ <= p && p < _n);\n      p += size;\n      d[p] = x;\n      for (int i = 1; i\
    \ <= log; i++) update(p >> i);\n    }\n\n    S get(int p) const {\n      assert(0\
    \ <= p && p < _n);\n      return d[p + size];\n    }\n\n    S prod(int l, int\
    \ r) const {\n      assert(0 <= l && l <= r && r <= _n);\n      S sml = e(), smr\
    \ = e();\n      l += size;\n      r += size;\n\n      while (l < r) {\n      \
    \  if (l & 1) sml = op(sml, d[l++]);\n        if (r & 1) smr = op(d[--r], smr);\n\
    \        l >>= 1;\n        r >>= 1;\n      }\n      return op(sml, smr);\n   \
    \ }\n\n    S all_prod() const { return d[1]; }\n\n    template <bool (*f)(S)>\
    \ int max_right(int l) const {\n      return max_right(l, [](S x) { return f(x);\
    \ });\n    }\n    template <class F> int max_right(int l, F f) const {\n     \
    \ assert(0 <= l && l <= _n);\n      assert(f(e()));\n      if (l == _n) return\
    \ _n;\n      l += size;\n      S sm = e();\n      do {\n        while (l % 2 ==\
    \ 0) l >>= 1;\n        if (!f(op(sm, d[l]))) {\n          while (l < size) {\n\
    \            l = (2 * l);\n            if (f(op(sm, d[l]))) {\n              sm\
    \ = op(sm, d[l]);\n              l++;\n            }\n          }\n          return\
    \ l - size;\n        }\n        sm = op(sm, d[l]);\n        l++;\n      } while\
    \ ((l & -l) != l);\n      return _n;\n    }\n\n    template <bool (*f)(S)> int\
    \ min_left(int r) const {\n      return min_left(r, [](S x) { return f(x); });\n\
    \    }\n    template <class F> int min_left(int r, F f) const {\n      assert(0\
    \ <= r && r <= _n);\n      assert(f(e()));\n      if (r == 0) return 0;\n    \
    \  r += size;\n      S sm = e();\n      do {\n        r--;\n        while (r >\
    \ 1 && (r % 2)) r >>= 1;\n        if (!f(op(d[r], sm))) {\n          while (r\
    \ < size) {\n            r = (2 * r + 1);\n            if (f(op(d[r], sm))) {\n\
    \              sm = op(d[r], sm);\n              r--;\n            }\n       \
    \   }\n          return r + 1 - size;\n        }\n        sm = op(d[r], sm);\n\
    \      } while ((r & -r) != r);\n      return 0;\n    }\n\n  private:\n    int\
    \ _n, size, log;\n    std::vector<S> d;\n\n    void update(int k) { d[k] = op(d[2\
    \ * k], d[2 * k + 1]); }\n};\n\n}  // namespace atcoder\n"
  code: "namespace atcoder {\n\nnamespace internal {\n\nunsigned int bit_ceil(unsigned\
    \ int n) {\n  unsigned int x = 1;\n  while (x < (unsigned int)(n)) x *= 2;\n \
    \ return x;\n}\n\n} // namespace internal\n\ntemplate <class S, S (*op)(S, S),\
    \ S (*e)()> struct segtree {\n  public:\n    segtree() : segtree(0) {}\n    explicit\
    \ segtree(int n) : segtree(std::vector<S>(n, e())) {}\n    explicit segtree(const\
    \ std::vector<S>& v) : _n(int(v.size())) {\n      size = (int)internal::bit_ceil((unsigned\
    \ int)(_n));\n      log = internal::countr_zero((unsigned int)size);\n      d\
    \ = std::vector<S>(2 * size, e());\n      for (int i = 0; i < _n; i++) d[size\
    \ + i] = v[i];\n      for (int i = size - 1; i >= 1; i--) {\n        update(i);\n\
    \      }\n    }\n\n    void set(int p, S x) {\n      assert(0 <= p && p < _n);\n\
    \      p += size;\n      d[p] = x;\n      for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n\n    S get(int p) const {\n      assert(0 <= p && p < _n);\n\
    \      return d[p + size];\n    }\n\n    S prod(int l, int r) const {\n      assert(0\
    \ <= l && l <= r && r <= _n);\n      S sml = e(), smr = e();\n      l += size;\n\
    \      r += size;\n\n      while (l < r) {\n        if (l & 1) sml = op(sml, d[l++]);\n\
    \        if (r & 1) smr = op(d[--r], smr);\n        l >>= 1;\n        r >>= 1;\n\
    \      }\n      return op(sml, smr);\n    }\n\n    S all_prod() const { return\
    \ d[1]; }\n\n    template <bool (*f)(S)> int max_right(int l) const {\n      return\
    \ max_right(l, [](S x) { return f(x); });\n    }\n    template <class F> int max_right(int\
    \ l, F f) const {\n      assert(0 <= l && l <= _n);\n      assert(f(e()));\n \
    \     if (l == _n) return _n;\n      l += size;\n      S sm = e();\n      do {\n\
    \        while (l % 2 == 0) l >>= 1;\n        if (!f(op(sm, d[l]))) {\n      \
    \    while (l < size) {\n            l = (2 * l);\n            if (f(op(sm, d[l])))\
    \ {\n              sm = op(sm, d[l]);\n              l++;\n            }\n   \
    \       }\n          return l - size;\n        }\n        sm = op(sm, d[l]);\n\
    \        l++;\n      } while ((l & -l) != l);\n      return _n;\n    }\n\n   \
    \ template <bool (*f)(S)> int min_left(int r) const {\n      return min_left(r,\
    \ [](S x) { return f(x); });\n    }\n    template <class F> int min_left(int r,\
    \ F f) const {\n      assert(0 <= r && r <= _n);\n      assert(f(e()));\n    \
    \  if (r == 0) return 0;\n      r += size;\n      S sm = e();\n      do {\n  \
    \      r--;\n        while (r > 1 && (r % 2)) r >>= 1;\n        if (!f(op(d[r],\
    \ sm))) {\n          while (r < size) {\n            r = (2 * r + 1);\n      \
    \      if (f(op(d[r], sm))) {\n              sm = op(d[r], sm);\n            \
    \  r--;\n            }\n          }\n          return r + 1 - size;\n        }\n\
    \        sm = op(d[r], sm);\n      } while ((r & -r) != r);\n      return 0;\n\
    \    }\n\n  private:\n    int _n, size, log;\n    std::vector<S> d;\n\n    void\
    \ update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n};\n\n}  // namespace\
    \ atcoder"
  dependsOn: []
  isVerificationFile: false
  path: ds/atcoder_segtree.hpp
  requiredBy: []
  timestamp: '2024-07-12 17:24:00+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/atcoder_segtree.hpp
layout: document
redirect_from:
- /library/ds/atcoder_segtree.hpp
- /library/ds/atcoder_segtree.hpp.html
title: ds/atcoder_segtree.hpp
---
