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
  bundledCode: "#line 1 \"mod/binom.hpp\"\nvector<mint> fact, ifact;\n\nvoid init()\
    \ {\n  int N = 110000;\n  fact.resize(N);\n  fact[0] = 1;\n  for (int i = 1; i\
    \ < N; i++) fact[i] = fact[i-1] * i;\n  ifact.resize(N);\n  ifact.back() = 1 /\
    \ fact.back();\n  for (int i = N - 1; i > 0; i--) ifact[i-1] = ifact[i] * i;\n\
    }\n\nmint ncr(int n, int k) {\n  if (k < 0 || k > n) return 0;\n  return fact[n]\
    \ * ifact[k] * ifact[n-k];\n}\n"
  code: "vector<mint> fact, ifact;\n\nvoid init() {\n  int N = 110000;\n  fact.resize(N);\n\
    \  fact[0] = 1;\n  for (int i = 1; i < N; i++) fact[i] = fact[i-1] * i;\n  ifact.resize(N);\n\
    \  ifact.back() = 1 / fact.back();\n  for (int i = N - 1; i > 0; i--) ifact[i-1]\
    \ = ifact[i] * i;\n}\n\nmint ncr(int n, int k) {\n  if (k < 0 || k > n) return\
    \ 0;\n  return fact[n] * ifact[k] * ifact[n-k];\n}"
  dependsOn: []
  isVerificationFile: false
  path: mod/binom.hpp
  requiredBy: []
  timestamp: '2024-07-07 14:22:33+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/binom.hpp
layout: document
redirect_from:
- /library/mod/binom.hpp
- /library/mod/binom.hpp.html
title: mod/binom.hpp
---
