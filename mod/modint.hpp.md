---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: mod/binomial.hpp
    title: mod/binomial.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ mod/modint.hpp: line 2: #pragma once found in a non-first line\n"
  code: "\n#pragma once\n\n// template from maspy\ntemplate <int mod>\nstruct modint\
    \ {\n  static constexpr u32 umod = u32(mod);\n  static_assert(umod < u32(1) <<\
    \ 31);\n  u32 val;\n  static u32 MOD;\n  constexpr static u32 get_mod() {\n  \
    \  if (mod > 0) {\n      return umod;\n    } else {\n      return MOD;\n    }\n\
    \  }\n  constexpr static void set_mod(int x) {\n    MOD = u32(x);\n  }\n  friend\
    \ ostream& operator << (ostream& out, const modint& n) { \n    return out << u32(n.val);\
    \ \n  }\n  friend istream& operator >> (istream& in, modint& n) { \n    ll v_;\
    \ in >> v_; n = modint(v_); return in; \n  }\n  static modint raw(u32 v) {\n \
    \   modint x;\n    x.val = v;\n    return x;\n  }\n  constexpr modint() : val(0)\
    \ {}\n  constexpr modint(u32 x) : val(x % get_mod()) {}\n  constexpr modint(u64\
    \ x) : val(x % get_mod()) {}\n  constexpr modint(int x) : val((x %= get_mod())\
    \ < 0 ? x + get_mod() : x){};\n  constexpr modint(ll x) : val((x %= get_mod())\
    \ < 0 ? x + get_mod() : x){};\n  constexpr modint(i128 x) : val((x %= get_mod())\
    \ < 0 ? x + get_mod() : x){};\n  bool operator<(const modint &other) const { return\
    \ val < other.val; }\n  modint &operator+=(const modint &p) {\n    if ((val +=\
    \ p.val) >= get_mod()) val -= get_mod();\n    return *this;\n  }\n  modint &operator-=(const\
    \ modint &p) {\n    if ((val += get_mod() - p.val) >= get_mod()) val -= get_mod();\n\
    \    return *this;\n  }\n  modint &operator*=(const modint &p) {\n    val = u64(val)\
    \ * p.val % get_mod();\n    return *this;\n  }\n  modint &operator/=(const modint\
    \ &p) {\n    *this *= p.inverse();\n    return *this;\n  }\n  modint operator-()\
    \ const { return modint::raw(val ? get_mod() - val : u32(0)); }\n  modint operator+(const\
    \ modint &p) const { return modint(*this) += p; }\n  modint operator-(const modint\
    \ &p) const { return modint(*this) -= p; }\n  modint operator*(const modint &p)\
    \ const { return modint(*this) *= p; }\n  modint operator/(const modint &p) const\
    \ { return modint(*this) /= p; }\n  bool operator==(const modint &p) const { return\
    \ val == p.val; }\n  bool operator!=(const modint &p) const { return val != p.val;\
    \ }\n  modint inv() const {\n    int a = val, b = get_mod(), u = 1, v = 0, t;\n\
    \    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u -= t\
    \ * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(ll n) const {\n  \
    \  assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n > 0) {\n      if\
    \ (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n\
    \  }\n};\ntemplate <int mod>\nu32 modint<mod>::MOD;\n\ntemplate <> \nu32 modint<0>::MOD\
    \ = 998244353;\n\nconstexpr int MOD = 1000000007;\n// constexpr int MOD = 998244353;\n\
    using mint = modint<MOD>;\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/modint.hpp
  requiredBy:
  - mod/binomial.hpp
  timestamp: '2024-05-06 00:02:18+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/modint.hpp
layout: document
redirect_from:
- /library/mod/modint.hpp
- /library/mod/modint.hpp.html
title: mod/modint.hpp
---
