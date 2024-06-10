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
  bundledCode: "#line 1 \"mod/modint.hpp\"\ntemplate <int P>\nstruct modint {\n  int\
    \ v;\n  constexpr modint() : v {0} {}\n  constexpr modint(int64_t _v) : v {int(_v\
    \ % mod())} { if (v < 0) v += mod(); }\n\n  static int MOD;\n  constexpr static\
    \ int mod() {\n    if (P > 0) {\n      return P;\n    } else {\n      return MOD;\n\
    \    }\n  }\n  constexpr static void set_mod(int MOD_) {\n    MOD = MOD_;\n  }\n\
    \n  explicit operator int() const { return v; }\n  friend std::ostream& operator\
    \ << (std::ostream& out, const modint &n) {\n    return out << int(n);\n  }\n\
    \  friend std::istream& operator >> (std::istream& in, modint &n) {\n    int64_t\
    \ v_;\n    in >> v_;\n    n = modint(v_);\n    return in;\n  }\n  friend bool\
    \ operator == (const modint &a, const modint &b) {\n    return a.v == b.v;\n \
    \ }\n  friend bool operator != (const modint &a, const modint &b) {\n    return\
    \ a.v != b.v;\n  }\n\n  constexpr modint inv() const {\n    int a = v, b = mod(),\
    \ x = 1, y = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t *\
    \ b, b), swap(x -= t * y, y);\n    }\n    return modint(x);\n  }\n  friend modint\
    \ inv(const modint &m) {\n    return m.inv();\n  }\n  modint operator-() const\
    \ {\n    modint res;\n    res.v = v ? mod() - v : 0;\n    return res;\n  }\n \
    \ modint operator+() const {\n    return modint(*this);\n  }\n  modint& operator\
    \ ++ () {\n    v++;\n    if (v == mod()) v = 0;\n    return *this;\n  }\n  modint&\
    \ operator -- () {\n    if (v == 0) v = mod();\n    v--;\n    return *this;\n\
    \  }\n  modint& operator += (const modint &o) {\n    v -= mod() - o.v;\n    v\
    \ = v < 0 ? v + mod() : v;\n    return *this;\n  }\n  modint& operator -= (const\
    \ modint &o) {\n    v -= o.v;\n    v = v < 0 ? v + mod() : v;\n    return *this;\n\
    \  }\n  modint& operator *= (const modint &o) {\n    v = int(int64_t(v) * int64_t(o.v)\
    \ % mod());\n    return *this;\n  }\n  modint& operator /= (const modint &o) {\n\
    \    return *this *= o.inv();\n  }\n\n  friend modint operator ++ (modint &a,\
    \ int) {\n    modint res = a;\n    ++a;\n    return res;\n  }\n  friend modint\
    \ operator -- (modint &a, int) {\n    modint res = a;\n    --a;\n    return res;\n\
    \  }\n  friend modint operator + (const modint &a, const modint &b) {\n    return\
    \ modint(a) += b;\n  }\n  friend modint operator - (const modint &a, const modint\
    \ &b) {\n    return modint(a) -= b;\n  }\n  friend modint operator * (const modint\
    \ &a, const modint &b) {\n    return modint(a) *= b;\n  }\n  friend modint operator\
    \ / (const modint &a, const modint &b) {\n    return modint(a) /= b;\n  }\n};\n\
    \ntemplate <typename T> T pow(T a, int64_t b) {\n  assert(b >= 0);\n  T r = 1;\n\
    \  while (b) {\n    if (b & 1) r *= a;\n    b >>= 1;\n    a *= a;\n  }\n  return\
    \ r;\n}\n\ntemplate <int P>\nstring to_string(const modint<P> x) {\n  return to_string(x.v);\n\
    }\n\ntemplate<>\nint modint<0>::MOD = 998244353;\n\nusing modint107 = modint<1000000007>;\n\
    using modint998 = modint<998244353>;\nusing modint000 = modint<0>;\n"
  code: "template <int P>\nstruct modint {\n  int v;\n  constexpr modint() : v {0}\
    \ {}\n  constexpr modint(int64_t _v) : v {int(_v % mod())} { if (v < 0) v += mod();\
    \ }\n\n  static int MOD;\n  constexpr static int mod() {\n    if (P > 0) {\n \
    \     return P;\n    } else {\n      return MOD;\n    }\n  }\n  constexpr static\
    \ void set_mod(int MOD_) {\n    MOD = MOD_;\n  }\n\n  explicit operator int()\
    \ const { return v; }\n  friend std::ostream& operator << (std::ostream& out,\
    \ const modint &n) {\n    return out << int(n);\n  }\n  friend std::istream& operator\
    \ >> (std::istream& in, modint &n) {\n    int64_t v_;\n    in >> v_;\n    n =\
    \ modint(v_);\n    return in;\n  }\n  friend bool operator == (const modint &a,\
    \ const modint &b) {\n    return a.v == b.v;\n  }\n  friend bool operator != (const\
    \ modint &a, const modint &b) {\n    return a.v != b.v;\n  }\n\n  constexpr modint\
    \ inv() const {\n    int a = v, b = mod(), x = 1, y = 0, t;\n    while (b > 0)\
    \ {\n      t = a / b;\n      swap(a -= t * b, b), swap(x -= t * y, y);\n    }\n\
    \    return modint(x);\n  }\n  friend modint inv(const modint &m) {\n    return\
    \ m.inv();\n  }\n  modint operator-() const {\n    modint res;\n    res.v = v\
    \ ? mod() - v : 0;\n    return res;\n  }\n  modint operator+() const {\n    return\
    \ modint(*this);\n  }\n  modint& operator ++ () {\n    v++;\n    if (v == mod())\
    \ v = 0;\n    return *this;\n  }\n  modint& operator -- () {\n    if (v == 0)\
    \ v = mod();\n    v--;\n    return *this;\n  }\n  modint& operator += (const modint\
    \ &o) {\n    v -= mod() - o.v;\n    v = v < 0 ? v + mod() : v;\n    return *this;\n\
    \  }\n  modint& operator -= (const modint &o) {\n    v -= o.v;\n    v = v < 0\
    \ ? v + mod() : v;\n    return *this;\n  }\n  modint& operator *= (const modint\
    \ &o) {\n    v = int(int64_t(v) * int64_t(o.v) % mod());\n    return *this;\n\
    \  }\n  modint& operator /= (const modint &o) {\n    return *this *= o.inv();\n\
    \  }\n\n  friend modint operator ++ (modint &a, int) {\n    modint res = a;\n\
    \    ++a;\n    return res;\n  }\n  friend modint operator -- (modint &a, int)\
    \ {\n    modint res = a;\n    --a;\n    return res;\n  }\n  friend modint operator\
    \ + (const modint &a, const modint &b) {\n    return modint(a) += b;\n  }\n  friend\
    \ modint operator - (const modint &a, const modint &b) {\n    return modint(a)\
    \ -= b;\n  }\n  friend modint operator * (const modint &a, const modint &b) {\n\
    \    return modint(a) *= b;\n  }\n  friend modint operator / (const modint &a,\
    \ const modint &b) {\n    return modint(a) /= b;\n  }\n};\n\ntemplate <typename\
    \ T> T pow(T a, int64_t b) {\n  assert(b >= 0);\n  T r = 1;\n  while (b) {\n \
    \   if (b & 1) r *= a;\n    b >>= 1;\n    a *= a;\n  }\n  return r;\n}\n\ntemplate\
    \ <int P>\nstring to_string(const modint<P> x) {\n  return to_string(x.v);\n}\n\
    \ntemplate<>\nint modint<0>::MOD = 998244353;\n\nusing modint107 = modint<1000000007>;\n\
    using modint998 = modint<998244353>;\nusing modint000 = modint<0>;"
  dependsOn: []
  isVerificationFile: false
  path: mod/modint.hpp
  requiredBy: []
  timestamp: '2024-06-11 04:29:30+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/modint.hpp
layout: document
redirect_from:
- /library/mod/modint.hpp
- /library/mod/modint.hpp.html
title: mod/modint.hpp
---
