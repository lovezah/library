---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/binomial.hpp\"\n\n#line 2 \"mod/modint.hpp\"\n\ntemplate\
    \ <int P>\nstruct modint {\n  int v;\n  constexpr modint() : v {0} {}\n  constexpr\
    \ modint(int64_t _v) : v {int(_v % mod())} { if (v < 0) v += mod(); }\n\n  static\
    \ int MOD;\n  constexpr static int mod() {\n    if (P > 0) {\n      return P;\n\
    \    } else {\n      return MOD;\n    }\n  }\n  constexpr static void set_mod(int\
    \ MOD_) {\n    MOD = MOD_;\n  }\n\n  explicit operator int() const { return v;\
    \ }\n  friend std::ostream& operator << (std::ostream& out, const modint &n) {\n\
    \    return out << int(n);\n  }\n  friend std::istream& operator >> (std::istream&\
    \ in, modint &n) {\n    int64_t v_;\n    in >> v_;\n    n = modint(v_);\n    return\
    \ in;\n  }\n  friend bool operator == (const modint &a, const modint &b) {\n \
    \   return a.v == b.v;\n  }\n  friend bool operator != (const modint &a, const\
    \ modint &b) {\n    return a.v != b.v;\n  }\n\n  constexpr modint inv() const\
    \ {\n    int a = v, b = mod(), x = 1, y = 0, t;\n    while (b > 0) {\n      t\
    \ = a / b;\n      swap(a -= t * b, b), swap(x -= t * y, y);\n    }\n    return\
    \ modint(x);\n  }\n  friend modint inv(const modint &m) {\n    return m.inv();\n\
    \  }\n  modint operator-() const {\n    modint res;\n    res.v = v ? mod() - v\
    \ : 0;\n    return res;\n  }\n  modint operator+() const {\n    return modint(*this);\n\
    \  }\n  modint& operator ++ () {\n    v++;\n    if (v == mod()) v = 0;\n    return\
    \ *this;\n  }\n  modint& operator -- () {\n    if (v == 0) v = mod();\n    v--;\n\
    \    return *this;\n  }\n  modint& operator += (const modint &o) {\n    v -= mod()\
    \ - o.v;\n    v = v < 0 ? v + mod() : v;\n    return *this;\n  }\n  modint& operator\
    \ -= (const modint &o) {\n    v -= o.v;\n    v = v < 0 ? v + mod() : v;\n    return\
    \ *this;\n  }\n  modint& operator *= (const modint &o) {\n    v = int(int64_t(v)\
    \ * int64_t(o.v) % mod());\n    return *this;\n  }\n  modint& operator /= (const\
    \ modint &o) {\n    return *this *= o.inv();\n  }\n\n  friend modint operator\
    \ ++ (modint &a, int) {\n    modint res = a;\n    ++a;\n    return res;\n  }\n\
    \  friend modint operator -- (modint &a, int) {\n    modint res = a;\n    --a;\n\
    \    return res;\n  }\n  friend modint operator + (const modint &a, const modint\
    \ &b) {\n    return modint(a) += b;\n  }\n  friend modint operator - (const modint\
    \ &a, const modint &b) {\n    return modint(a) -= b;\n  }\n  friend modint operator\
    \ * (const modint &a, const modint &b) {\n    return modint(a) *= b;\n  }\n  friend\
    \ modint operator / (const modint &a, const modint &b) {\n    return modint(a)\
    \ /= b;\n  }\n};\n\ntemplate <typename T> T pow(T a, int64_t b) {\n  assert(b\
    \ >= 0);\n  T r = 1;\n  while (b) {\n    if (b & 1) r *= a;\n    b >>= 1;\n  \
    \  a *= a;\n  }\n  return r;\n}\n\ntemplate<>\nint modint<0>::MOD = 998244353;\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    using modint000 = modint<0>;\n#line 4 \"mod/binomial.hpp\"\n\nstruct {\n  int\
    \ n = 0;\n  vector<mint> _fac, _ifac, _inv;\n\n  void init(int m) {\n    if (m\
    \ <= n) return;\n    _fac.resize(m + 1);\n    _ifac.resize(m + 1);\n    _inv.resize(m\
    \ + 1);\n    _fac[0] = 1;\n    for (int i = n + 1; i <= m; i++) {\n      _fac[i]\
    \ = _fac[i - 1] * i;\n    }\n    _ifac[m] = _fac[m].inv();\n    for (int i = m;\
    \ i > n; i--) {\n      _ifac[i - 1] = _ifac[i] * i;\n      _inv[i] = _ifac[i]\
    \ * _fac[i - 1];\n    }\n    n = m;\n  }\n  mint fac(int m) {\n    if (m >= n)\
    \ init(m | 1);\n    return _fac[m];\n  }\n  mint ifac(int m) {\n    if (m >= n)\
    \ init(m | 1);\n    return _ifac[m];\n  }\n  mint inv(int m) {\n    if (m >= n)\
    \ init(m | 1);\n    return _inv[m];\n  }\n  mint C(int a, int b) {\n    if (a\
    \ < b || b < 0) return 0;\n    return fac(a) * ifac(b) * ifac(a - b);\n  }\n \
    \ mint P(int a, int b) {\n    if (a < b || b < 0) return 0;\n    return fac(a)\
    \ * ifac(a - b);\n  }\n} binom;\n"
  code: "#pragma once\n\n#include \"mod/modint.hpp\"\n\nstruct {\n  int n = 0;\n \
    \ vector<mint> _fac, _ifac, _inv;\n\n  void init(int m) {\n    if (m <= n) return;\n\
    \    _fac.resize(m + 1);\n    _ifac.resize(m + 1);\n    _inv.resize(m + 1);\n\
    \    _fac[0] = 1;\n    for (int i = n + 1; i <= m; i++) {\n      _fac[i] = _fac[i\
    \ - 1] * i;\n    }\n    _ifac[m] = _fac[m].inv();\n    for (int i = m; i > n;\
    \ i--) {\n      _ifac[i - 1] = _ifac[i] * i;\n      _inv[i] = _ifac[i] * _fac[i\
    \ - 1];\n    }\n    n = m;\n  }\n  mint fac(int m) {\n    if (m >= n) init(m |\
    \ 1);\n    return _fac[m];\n  }\n  mint ifac(int m) {\n    if (m >= n) init(m\
    \ | 1);\n    return _ifac[m];\n  }\n  mint inv(int m) {\n    if (m >= n) init(m\
    \ | 1);\n    return _inv[m];\n  }\n  mint C(int a, int b) {\n    if (a < b ||\
    \ b < 0) return 0;\n    return fac(a) * ifac(b) * ifac(a - b);\n  }\n  mint P(int\
    \ a, int b) {\n    if (a < b || b < 0) return 0;\n    return fac(a) * ifac(a -\
    \ b);\n  }\n} binom;\n"
  dependsOn:
  - mod/modint.hpp
  isVerificationFile: false
  path: mod/binomial.hpp
  requiredBy: []
  timestamp: '2024-05-29 19:40:50+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/binomial.hpp
layout: document
redirect_from:
- /library/mod/binomial.hpp
- /library/mod/binomial.hpp.html
title: mod/binomial.hpp
---
