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
  bundledCode: "#line 1 \"mod/modint.cpp\"\n\n// template from maspy\ntemplate <int\
    \ mod>\nstruct modint {\n  static constexpr u32 umod = u32(mod);\n  static_assert(umod\
    \ < u32(1) << 31);\n  u32 val;\n  friend ostream& operator << (ostream& out, const\
    \ modint& n) { \n    return out << u32(n); \n  }\n  friend istream& operator >>\
    \ (istream& in, modint& n) { \n    ll v_; in >> v_; n = modint(v_); return in;\
    \ \n  }\n  static modint raw(u32 v) {\n    modint x;\n    x.val = v;\n    return\
    \ x;\n  }\n  constexpr modint() : val(0) {}\n  constexpr modint(u32 x) : val(x\
    \ % umod) {}\n  constexpr modint(u64 x) : val(x % umod) {}\n  constexpr modint(int\
    \ x) : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint(ll x) : val((x\
    \ %= mod) < 0 ? x + mod : x){};\n  constexpr modint(i128 x) : val((x %= mod) <\
    \ 0 ? x + mod : x){};\n  bool operator<(const modint &other) const { return val\
    \ < other.val; }\n  modint &operator+=(const modint &p) {\n    if ((val += p.val)\
    \ >= umod) val -= umod;\n    return *this;\n  }\n  modint &operator-=(const modint\
    \ &p) {\n    if ((val += umod - p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  modint &operator*=(const modint &p) {\n    val = u64(val) * p.val % umod;\n\
    \    return *this;\n  }\n  modint &operator/=(const modint &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  modint operator-() const { return modint::raw(val\
    \ ? mod - val : u32(0)); }\n  modint operator+(const modint &p) const { return\
    \ modint(*this) += p; }\n  modint operator-(const modint &p) const { return modint(*this)\
    \ -= p; }\n  modint operator*(const modint &p) const { return modint(*this) *=\
    \ p; }\n  modint operator/(const modint &p) const { return modint(*this) /= p;\
    \ }\n  bool operator==(const modint &p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint &p) const { return val != p.val; }\n  modint inv() const\
    \ {\n    int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n      t\
    \ = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n    return\
    \ modint(u);\n  }\n  modint pow(ll n) const {\n    assert(n >= 0);\n    modint\
    \ ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n     \
    \ mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n  static constexpr\
    \ int get_mod() { return mod; }\n  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\
    \n  static constexpr pair<int, int> ntt_info() {\n    if (mod == 120586241) return\
    \ {20, 74066978};\n    if (mod == 167772161) return {25, 17};\n    if (mod ==\
    \ 469762049) return {26, 30};\n    if (mod == 754974721) return {24, 362};\n \
    \   if (mod == 880803841) return {23, 211};\n    if (mod == 943718401) return\
    \ {22, 663003469};\n    if (mod == 998244353) return {23, 31};\n    if (mod ==\
    \ 1045430273) return {20, 363};\n    if (mod == 1051721729) return {20, 330};\n\
    \    if (mod == 1053818881) return {20, 2789};\n    return {-1, -1};\n  }\n  static\
    \ constexpr bool can_ntt() { return ntt_info().f != -1; }\n};\n\nusing mint =\
    \ modint<1000000007>;\n// using mint = modint<998244353>;\n"
  code: "\n// template from maspy\ntemplate <int mod>\nstruct modint {\n  static constexpr\
    \ u32 umod = u32(mod);\n  static_assert(umod < u32(1) << 31);\n  u32 val;\n  friend\
    \ ostream& operator << (ostream& out, const modint& n) { \n    return out << u32(n);\
    \ \n  }\n  friend istream& operator >> (istream& in, modint& n) { \n    ll v_;\
    \ in >> v_; n = modint(v_); return in; \n  }\n  static modint raw(u32 v) {\n \
    \   modint x;\n    x.val = v;\n    return x;\n  }\n  constexpr modint() : val(0)\
    \ {}\n  constexpr modint(u32 x) : val(x % umod) {}\n  constexpr modint(u64 x)\
    \ : val(x % umod) {}\n  constexpr modint(int x) : val((x %= mod) < 0 ? x + mod\
    \ : x){};\n  constexpr modint(ll x) : val((x %= mod) < 0 ? x + mod : x){};\n \
    \ constexpr modint(i128 x) : val((x %= mod) < 0 ? x + mod : x){};\n  bool operator<(const\
    \ modint &other) const { return val < other.val; }\n  modint &operator+=(const\
    \ modint &p) {\n    if ((val += p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  modint &operator-=(const modint &p) {\n    if ((val += umod - p.val) >=\
    \ umod) val -= umod;\n    return *this;\n  }\n  modint &operator*=(const modint\
    \ &p) {\n    val = u64(val) * p.val % umod;\n    return *this;\n  }\n  modint\
    \ &operator/=(const modint &p) {\n    *this *= p.inverse();\n    return *this;\n\
    \  }\n  modint operator-() const { return modint::raw(val ? mod - val : u32(0));\
    \ }\n  modint operator+(const modint &p) const { return modint(*this) += p; }\n\
    \  modint operator-(const modint &p) const { return modint(*this) -= p; }\n  modint\
    \ operator*(const modint &p) const { return modint(*this) *= p; }\n  modint operator/(const\
    \ modint &p) const { return modint(*this) /= p; }\n  bool operator==(const modint\
    \ &p) const { return val == p.val; }\n  bool operator!=(const modint &p) const\
    \ { return val != p.val; }\n  modint inv() const {\n    int a = val, b = mod,\
    \ u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t *\
    \ b, b), swap(u -= t * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(ll\
    \ n) const {\n    assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n  \
    \  }\n    return ret;\n  }\n  static constexpr int get_mod() { return mod; }\n\
    \  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int,\
    \ int> ntt_info() {\n    if (mod == 120586241) return {20, 74066978};\n    if\
    \ (mod == 167772161) return {25, 17};\n    if (mod == 469762049) return {26, 30};\n\
    \    if (mod == 754974721) return {24, 362};\n    if (mod == 880803841) return\
    \ {23, 211};\n    if (mod == 943718401) return {22, 663003469};\n    if (mod ==\
    \ 998244353) return {23, 31};\n    if (mod == 1045430273) return {20, 363};\n\
    \    if (mod == 1051721729) return {20, 330};\n    if (mod == 1053818881) return\
    \ {20, 2789};\n    return {-1, -1};\n  }\n  static constexpr bool can_ntt() {\
    \ return ntt_info().f != -1; }\n};\n\nusing mint = modint<1000000007>;\n// using\
    \ mint = modint<998244353>;"
  dependsOn: []
  isVerificationFile: false
  path: mod/modint.cpp
  requiredBy: []
  timestamp: '2024-05-05 06:56:14+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/modint.cpp
layout: document
redirect_from:
- /library/mod/modint.cpp
- /library/mod/modint.cpp.html
title: mod/modint.cpp
---
