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
  bundledCode: "#line 1 \"strings/rolling_hash.hpp\"\nconst int mod1 = 1000000009;\n\
    const int mod2 = 993244853;\nstruct hashv {\n  int f, s;\n  hashv() {}\n  hashv(int\
    \ _f, int _s) : f(_f), s(_s) {}\n  friend bool operator==(hashv a, hashv b) {\n\
    \    return a.f == b.f && a.s == b.s;\n  }\n  friend bool operator!=(hashv a,\
    \ hashv b) {\n    return a.f != b.f || a.s != b.s;\n  }\n  friend hashv operator+(hashv\
    \ a, hashv b) {\n    hashv c = hashv(a.f + b.f, a.s + b.s);\n    if (c.f >= mod1)\
    \ c.f -= mod1;\n    if (c.s >= mod2) c.s -= mod2;\n    return c;\n  }\n  friend\
    \ hashv operator-(hashv a, hashv b) {\n    hashv c = hashv(a.f - b.f, a.s - b.s);\n\
    \    if (c.f < 0) c.f += mod1;\n    if (c.s < 0) c.s += mod2;\n    return c;\n\
    \  }\n  friend hashv operator*(hashv a, hashv b) {\n    return hashv(1ll * a.f\
    \ * b.f % mod1, 1ll * a.s * b.s % mod2);\n  }  \n};\n"
  code: "const int mod1 = 1000000009;\nconst int mod2 = 993244853;\nstruct hashv {\n\
    \  int f, s;\n  hashv() {}\n  hashv(int _f, int _s) : f(_f), s(_s) {}\n  friend\
    \ bool operator==(hashv a, hashv b) {\n    return a.f == b.f && a.s == b.s;\n\
    \  }\n  friend bool operator!=(hashv a, hashv b) {\n    return a.f != b.f || a.s\
    \ != b.s;\n  }\n  friend hashv operator+(hashv a, hashv b) {\n    hashv c = hashv(a.f\
    \ + b.f, a.s + b.s);\n    if (c.f >= mod1) c.f -= mod1;\n    if (c.s >= mod2)\
    \ c.s -= mod2;\n    return c;\n  }\n  friend hashv operator-(hashv a, hashv b)\
    \ {\n    hashv c = hashv(a.f - b.f, a.s - b.s);\n    if (c.f < 0) c.f += mod1;\n\
    \    if (c.s < 0) c.s += mod2;\n    return c;\n  }\n  friend hashv operator*(hashv\
    \ a, hashv b) {\n    return hashv(1ll * a.f * b.f % mod1, 1ll * a.s * b.s % mod2);\n\
    \  }  \n};"
  dependsOn: []
  isVerificationFile: false
  path: strings/rolling_hash.hpp
  requiredBy: []
  timestamp: '2024-06-10 03:36:27+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: strings/rolling_hash.hpp
layout: document
redirect_from:
- /library/strings/rolling_hash.hpp
- /library/strings/rolling_hash.hpp.html
title: strings/rolling_hash.hpp
---
